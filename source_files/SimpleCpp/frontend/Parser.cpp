/**
 * Parser class for a simple interpreter.
 *
 * (c) 2020 by Ronald Mak
 * Department of Computer Science
 * San Jose State University
 */
#include <string>
#include <map>

#include "Token.h"
#include "Parser.h"

namespace frontend {

using namespace std;

set<TokenType> Parser::statementStarters;
set<TokenType> Parser::statementFollowers;
set<TokenType> Parser::relationalOperators;
set<TokenType> Parser::booleanOperators;
set<TokenType> Parser::simpleExpressionOperators;
set<TokenType> Parser::termOperators;

void Parser::initialize()
{
    statementStarters.insert(TokenType::BEGIN);
    statementStarters.insert(TokenType::IDENTIFIER);
    statementStarters.insert(TokenType::REPEAT);
    statementStarters.insert(TokenType::WHILE);                 //assignment 3 extension
    statementStarters.insert(TokenType::WRITE);
    statementStarters.insert(TokenType::WRITELN);

    statementFollowers.insert(TokenType::SEMICOLON);
    statementFollowers.insert(TokenType::END);
    statementFollowers.insert(TokenType::UNTIL);
    statementFollowers.insert(TokenType::END_OF_FILE);
    statementFollowers.insert(TokenType::DO);                   //assignment 3 extension
    statementFollowers.insert(TokenType::OF);                   //assignment 3 extension

    relationalOperators.insert(TokenType::EQUALS);
    relationalOperators.insert(TokenType::NOT_EQUALS);          //assignment 3 extension
    relationalOperators.insert(TokenType::LESS_THAN);
    relationalOperators.insert(TokenType::LESS_THAN_EQUALS);    //assignment 3 extension
    relationalOperators.insert(TokenType::GREATER_THAN);        //assignment 3 extension
    relationalOperators.insert(TokenType::GREATER_THAN_EQUALS); //assignment 3 extension

    booleanOperators.insert(TokenType::NOT);                    //assignment 3 extension
    booleanOperators.insert(TokenType::AND);                    //assignment 3 extension
    booleanOperators.insert(TokenType::OR);                     //assignment 3 extension

    simpleExpressionOperators.insert(TokenType::PLUS);
    simpleExpressionOperators.insert(TokenType::MINUS);
    

    termOperators.insert(TokenType::STAR);
    termOperators.insert(TokenType::SLASH);
}

Node *Parser::parseProgram()
{
    Node *programNode = new Node(NodeType::PROGRAM);

    currentToken = scanner->nextToken();  // first token!

    if (currentToken->type == TokenType::PROGRAM)
    {
        currentToken = scanner->nextToken();  // consume PROGRAM
    }
    else syntaxError("Expecting PROGRAM");

    if (currentToken->type == IDENTIFIER)
    {
        string programName = currentToken->text;
        symtab->enter(programName);
        programNode->text = programName;

        currentToken = scanner->nextToken();  // consume program name
    }
    else syntaxError("Expecting program name");

    if (currentToken->type == SEMICOLON)
    {
        currentToken = scanner->nextToken();  // consume ;
    }
    else syntaxError("Missing ;");

    if (currentToken->type != BEGIN) syntaxError("Expecting BEGIN");

    // The PROGRAM node adopts the COMPOUND tree.
    programNode->adopt(parseCompoundStatement());

    if (currentToken->type == SEMICOLON) syntaxError("Expecting .");
    return programNode;
}

Node *Parser::parseCompoundStatement()
{
    Node *compoundNode = new Node(COMPOUND);
    compoundNode->lineNumber = currentToken->lineNumber;

    currentToken = scanner->nextToken();  // consume BEGIN
    parseStatementList(compoundNode, END);

    if (currentToken->type == END)
    {
        currentToken = scanner->nextToken();  // consume END
    }
    else syntaxError("Expecting END");

    return compoundNode;
}

void Parser::parseStatementList(Node *parentNode, TokenType terminalType)
{
    while (   (currentToken->type != terminalType)
           && (currentToken->type != END_OF_FILE))
    {
        Node *stmtNode = parseStatement();
        if (stmtNode != nullptr) parentNode->adopt(stmtNode);

        // A semicolon separates statements.
        if (currentToken->type == SEMICOLON)
        {
            while (currentToken->type == SEMICOLON)
            {
                currentToken = scanner->nextToken();  // consume ;
            }
        }
        else if (statementStarters.find(currentToken->type) !=
                                                        statementStarters.end())
        {
            syntaxError("Missing ;");
        }
    }
}

Node *Parser::parseStatement()
{
    Node *stmtNode = nullptr;
    int savedLineNumber = currentToken->lineNumber;
    lineNumber = savedLineNumber;

    switch (currentToken->type)
    {
        case IDENTIFIER : stmtNode = parseAssignmentStatement();    break;
        case BEGIN      : stmtNode = parseCompoundStatement();      break;
        case REPEAT     : stmtNode = parseRepeatStatement();        break;
        case WHILE      : stmtNode = parseWhileStatement();         break;     //assignment 3 extension
        case IF         : stmtNode = parseIfStatement();            break;     //assignment 3 extension
        case FOR        : stmtNode = parseForStatement();           break;     //assignment 3 extension
        case WRITE      : stmtNode = parseWriteStatement();         break;
        case WRITELN    : stmtNode = parseWritelnStatement();       break;
        case SEMICOLON  : stmtNode = nullptr; break;  // empty statement

        default : syntaxError("Unexpected token");
    }

    if (stmtNode != nullptr) stmtNode->lineNumber = savedLineNumber;
    return stmtNode;
}

Node *Parser::parseAssignmentStatement()
{
    // The current token should now be the left-hand-side variable name.

    Node *assignmentNode = new Node(ASSIGN);

    // The assignment Node *adopts the variable Node *as its first child.
    Node *lhsNode = new Node(VARIABLE);
    string variableName = currentToken->text;
    SymtabEntry *variableId = symtab->enter(toLowerCase(variableName));

    lhsNode->text  = variableName;
    lhsNode->entry = variableId;
    assignmentNode->adopt(lhsNode);

    currentToken = scanner->nextToken();  // consume the LHS variable;

    if (currentToken->type == COLON_EQUALS)
    {
        currentToken = scanner->nextToken();  // consume :=
    }
    else syntaxError("Missing :=");

    // The assignment Node *adopts the expression Node *as its second child.
    Node *rhsNode = parseExpression();
    assignmentNode->adopt(rhsNode);

    return assignmentNode;
}

Node *Parser::parseRepeatStatement()
{
    // The current token should now be REPEAT.

    // Create a LOOP node->
    Node *loopNode = new Node(LOOP);
    currentToken = scanner->nextToken();  // consume REPEAT

    parseStatementList(loopNode, UNTIL);

    if (currentToken->type == UNTIL)
    {
        // Create a TEST node-> It adopts the test expression node->
        Node *testNode = new Node(TEST);
        lineNumber = currentToken->lineNumber;
        testNode->lineNumber = lineNumber;
        currentToken = scanner->nextToken();  // consume UNTIL

        testNode->adopt(parseExpression());

        // The LOOP Node *adopts the TEST Node *as its final child.
        loopNode->adopt(testNode);
    }
    else syntaxError("Expecting UNTIL");

    return loopNode;
}

Node *Parser::parseWhileStatement(){
    Node *loopNode = new Node(LOOP);
    currentToken = scanner->nextToken(); // consume WHILE


    Node *testNode = new Node(TEST);
    lineNumber = currentToken->lineNumber;
    testNode->lineNumber = lineNumber;
    
    Node *notNode = new Node(NodeType::NOT);              //add NOT node to adjust to our executor (smarter parser)
    notNode->adopt(parseExpression()); 
    testNode->adopt(notNode);
    loopNode->adopt(testNode);

    if (currentToken->type == DO)
        currentToken = scanner->nextToken(); // just consume DO not much else to do ahah get it pun intended lol
    else
        syntaxError("Expecting DO");
    
    if (currentToken->type == BEGIN) 
        loopNode->adopt(parseCompoundStatement());
    else //meaning only single statement then
        loopNode->adopt(parseStatement()); 
    
    return loopNode;
}

Node *Parser::parseForStatement() {
    Node *compoundNode = new Node(COMPOUND);

    Node *newValue = new Node(INTEGER_CONSTANT);

    SymtabEntry *a;
    Node *oldVariable = new Node(VARIABLE);
    if(currentToken -> type == FOR)
    {
        currentToken = scanner -> nextToken(); //consume For
        //store old variables since FOR statement needs to keep track
        oldVariable -> value = currentToken -> value;
        string variableName = toLowerCase(currentToken -> text);
        oldVariable -> text = currentToken -> text;

        compoundNode -> adopt(parseAssignmentStatement());
        a = symtab -> lookup(variableName);
        oldVariable -> entry = a;
    }

    else{
        syntaxError("Expecting FOR");
    }

    if(currentToken -> type == TO || currentToken -> type == DOWNTO)
    {
        Node *gtltNode; //Node creation for greater than less than
        if(currentToken -> type == TO)
        {
            gtltNode = new Node(GT);
        }
        else
        {
            gtltNode = new Node(LT);

        }

        Node *addNode; //case for addition and subtraction
        if(currentToken -> type == TO)
        {
            addNode = new Node(ADD);
        }
        else
        {
            addNode = new Node(SUBTRACT);
        }

        currentToken = scanner -> nextToken(); //consumes To/Downto

        newValue -> value = currentToken -> value;
        currentToken = scanner -> nextToken();

        gtltNode -> adopt(oldVariable);
        gtltNode -> adopt(newValue);

        Node *testNode = new Node(TEST); //test Node
        testNode -> adopt(gtltNode);

        Node *loopNode = new Node(LOOP); //create loop in parse tree
        loopNode -> adopt(testNode); //adopt the left hand side of tree

        currentToken = scanner -> nextToken();
        
        loopNode -> adopt(parseStatement()); //adopt middle part of tree (do statement)

        addNode -> adopt(oldVariable);

        int constant = 1;
        Node *Constant = new Node(INTEGER_CONSTANT);
        Constant -> value.D = constant;
        addNode -> adopt(Constant);

        Node *assignNode = new Node(ASSIGN);
        compoundNode -> adopt(loopNode); //adopt the loop to the right side of tree
        assignNode -> adopt(oldVariable);
        loopNode -> adopt(assignNode);
        assignNode -> adopt(addNode);
    }
    else
    {
        syntaxError("Expecting TO/DOWNTO");
    }

    return compoundNode;
}

Node *Parser::parseIfStatement() {

    Node* ifNode = new Node(NodeType::IF);
    lineNumber = currentToken->lineNumber;
    currentToken = scanner->nextToken(); //consume IF

    ifNode->adopt(parseExpression()); //adopt condition

    if (currentToken->type == THEN)
        currentToken = scanner->nextToken(); //consume THEN
    else
        syntaxError("Expecting THEN");
    
    if (currentToken->type == BEGIN)
        ifNode->adopt(parseCompoundStatement());
    else //must be oneline statement
        ifNode->adopt(parseStatement());
    
    if (currentToken->type == ELSE) 
    {
        currentToken = scanner->nextToken(); //consume ELSE
         if (currentToken->type == BEGIN)
            ifNode->adopt(parseCompoundStatement());
        else //must be one line statement
            ifNode->adopt(parseStatement());
    }

    return ifNode;
}

Node *Parser::parseWriteStatement()
{
    // The current token should now be WRITE.

    // Create a WRITE node-> It adopts the variable or string node->
    Node *writeNode = new Node(NodeType::WRITE);
    currentToken = scanner->nextToken();  // consume WRITE

    parseWriteArguments(writeNode);
    if (writeNode->children.size() == 0)
    {
        syntaxError("Invalid WRITE statement");
    }

    return writeNode;
}

Node *Parser::parseWritelnStatement()
{
    // The current token should now be WRITELN.

    // Create a WRITELN node-> It adopts the variable or string node->
    Node *writelnNode = new Node(NodeType::WRITELN);
    currentToken = scanner->nextToken();  // consume WRITELN

    if (currentToken->type == LPAREN) parseWriteArguments(writelnNode);
    return writelnNode;
}

void Parser::parseWriteArguments(Node *node)
{
    // The current token should now be (

    bool hasArgument = false;

    if (currentToken->type == LPAREN)
    {
        currentToken = scanner->nextToken();  // consume (
    }
    else syntaxError("Missing left parenthesis");

    if (currentToken->type == IDENTIFIER)
    {
        node->adopt(parseVariable());
        hasArgument = true;
    }
    else if (currentToken->type == STRING)
    {
        node->adopt(parseStringConstant());
        hasArgument = true;
    }
    else if (currentToken->type == CHARACTER)
        node->adopt(parseCharacterConstant());
    else syntaxError("Invalid WRITE or WRITELN statement");

    // Look for a field width and a count of decimal places.
    if (hasArgument)
    {
        if (currentToken->type == COLON)
        {
            currentToken = scanner->nextToken();  // consume ,

            if (currentToken->type == INTEGER)
            {
                // Field width
                node->adopt(parseIntegerConstant());

                if (currentToken->type == COLON)
                {
                    currentToken = scanner->nextToken();  // consume ,

                    if (currentToken->type == INTEGER)
                    {
                        // Count of decimal places
                        node->adopt(parseIntegerConstant());
                    }
                    else syntaxError("Invalid count of decimal places");
                }
            }
            else syntaxError("Invalid field width");
        }
    }

    if (currentToken->type == RPAREN)
    {
        currentToken = scanner->nextToken();  // consume )
    }
    else syntaxError("Missing right parenthesis");
}


Node *Parser::parseExpression()
{
    // The current token should now be an identifier or a number.
    TokenType tokenType;
    // The expression's root node->
    Node* notNode = nullptr;

    //if there's an boolean operator {NOT, AND, OR}
    if (currentToken->type == TokenType::NOT) {
        notNode = new Node(NodeType::NOT);
        currentToken = scanner->nextToken(); //consume NOT
    }
    Node* exprNode = parseSimpleExpression();

    // The current token might now be a relational operator.
    if (relationalOperators.find(currentToken->type) != relationalOperators.end()
    || booleanOperators.find(currentToken->type) != booleanOperators.end())
    {
        tokenType = currentToken->type;
        Node *opNode = tokenType == EQUALS    ? new Node(EQ)
                     : tokenType == NOT_EQUALS ? new Node(NEQ)              //assignment 3 extension
                     : tokenType == LESS_THAN ? new Node(LT)
                     : tokenType == LESS_THAN_EQUALS ? new Node(LTEQ)       //assignment 3 extension
                     : tokenType == GREATER_THAN ? new Node(GT)             //assignment 3 extension
                     : tokenType == GREATER_THAN_EQUALS ? new Node(GTEQ)    //assignment 3 extension
                     : tokenType == AND ? new Node(NodeType::AND)           //assignment 3 extension
                     : tokenType == OR ? new Node(NodeType::OR)             //assignment 3 extension
                     :             nullptr;

        currentToken = scanner->nextToken();  // consume relational operator

        // The relational operator Node *adopts the first simple expression
        // Node *as its first child and the second simple expression node
        // as its second child. Then it becomes the expression's root node->
        if (opNode != nullptr)
        {
            opNode->adopt(exprNode);
            opNode->adopt(parseSimpleExpression());
            exprNode = opNode;
        }
        
    }

    if (notNode != nullptr) {
        notNode->adopt(exprNode);
        exprNode = notNode;
    }



    return exprNode;
}

Node *Parser::parseSimpleExpression()
{
    // The current token should now be an identifier or a number.

    // The simple expression's root node->
    Node *simpExprNode = parseTerm();

    // Keep parsing more terms as long as the current token
    // is a + or - operator.
    while (simpleExpressionOperators.find(currentToken->type) !=
                                                simpleExpressionOperators.end())
    {
        Node *opNode = currentToken->type == PLUS ? new Node(ADD)
                                                : new Node(SUBTRACT);

        currentToken = scanner->nextToken();  // consume the operator

        // The add or subtract Node *adopts the first term Node *as its
        // first child and the next term Node *as its second child.
        // Then it becomes the simple expression's root node->
        opNode->adopt(simpExprNode);
        opNode->adopt(parseTerm());
        simpExprNode = opNode;
    }

    return simpExprNode;
}

Node *Parser::parseTerm()
{
    // The current token should now be an identifier or a number.

    // The term's root node->
    Node *termNode = parseFactor();

    // Keep parsing more factor as long as the current token
    // is a * or / operator.
    while (termOperators.find(currentToken->type) != termOperators.end())
    {
        Node *opNode = currentToken->type == STAR ? new Node(MULTIPLY)
                                                : new Node(DIVIDE);

        currentToken = scanner->nextToken();  // consume the operator

        // The multiply or dive Node *adopts the first factor Node *as its
        // as its first child and the next factor Node *as its second child.
        // Then it becomes the term's root node->
        opNode->adopt(termNode);
        opNode->adopt(parseFactor());
        termNode = opNode;
    }

    return termNode;
}

Node *Parser::parseFactor()
{
    // The current token should now be an identifier or a number or (

    if      (currentToken->type == IDENTIFIER) return parseVariable();
    else if (currentToken->type == INTEGER)    return parseIntegerConstant();
    else if (currentToken->type == REAL)       return parseRealConstant();

    else if (currentToken->type == LPAREN)
    {
        currentToken = scanner->nextToken();  // consume (
        Node *exprNode = parseExpression();

        if (currentToken->type == RPAREN)
        {
            currentToken = scanner->nextToken();  // consume )
        }
        else syntaxError("Expecting )");

        return exprNode;
    }

    else syntaxError("Unexpected token");
    return nullptr;
}

Node *Parser::parseVariable()
{
    // The current token should now be an identifier.

    string variableName = currentToken->text;
    SymtabEntry *variableId = symtab->lookup(toLowerCase(variableName));

    if (variableId == nullptr) semanticError("Undeclared identifier");

    Node *node = new Node(VARIABLE);
    node->text = variableName;

    currentToken = scanner->nextToken();  // consume the identifier
    return node;
}

Node *Parser::parseIntegerConstant()
{
    // The current token should now be a number.

    Node *integerNode = new Node(INTEGER_CONSTANT);
    integerNode->value = currentToken->value;

    currentToken = scanner->nextToken();  // consume the number
    return integerNode;
}

Node *Parser::parseRealConstant()
{
    // The current token should now be a number.

    Node *realNode = new Node(REAL_CONSTANT);
    realNode->value = currentToken->value;

    currentToken = scanner->nextToken();  // consume the number
    return realNode;
}

Node *Parser::parseStringConstant()
{
    // The current token should now be string.

    Node *stringNode = new Node(STRING_CONSTANT);
    stringNode->value = currentToken->value;

    currentToken = scanner->nextToken();  // consume the string
    return stringNode;
}

Node *Parser::parseCharacterConstant()
{
    Node * characterNode = new Node(CHARACTER_CONSTANT);
    characterNode->value = currentToken->value;

    currentToken = scanner->nextToken(); //consume the character
    return characterNode;
}

void Parser::syntaxError(string message)
{
    printf("SYNTAX ERROR at line %d: %s at '%s'\n",
           lineNumber, message.c_str(), currentToken->text.c_str());
    errorCount++;

    // Recover by skipping the rest of the statement.
    // Skip to a statement follower token.
    while (statementFollowers.find(currentToken->type) ==
                                                    statementFollowers.end())
    {
        currentToken = scanner->nextToken();
    }
}

void Parser::semanticError(string message)
{
    printf("SEMANTIC ERROR at line %d: %s at '%s'\n",
           lineNumber, message.c_str(), currentToken->text.c_str());
    errorCount++;
}

}  // namespace frontend
