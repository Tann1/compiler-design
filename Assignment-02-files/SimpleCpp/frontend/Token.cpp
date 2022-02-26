/**
 * Token class for a simple interpreter.
 *
 * (c) 2020 by Ronald Mak
 * Department of Computer Science
 * San Jose State University
 */
#include <string>
#include <map>
#include <ctype.h>

#include "../Object.h"
#include "Token.h"

namespace frontend {

using namespace std;

map<string, TokenType> Token::reservedWords;

void Token::initialize()
{
    reservedWords["PROGRAM"] = PROGRAM;
    reservedWords["BEGIN"]   = BEGIN;
    reservedWords["END"]     = END;
    reservedWords["REPEAT"]  = REPEAT;
    reservedWords["UNTIL"]   = UNTIL;
    reservedWords["WRITE"]   = WRITE;
    reservedWords["WRITELN"] = WRITELN;
    reservedWords["DIV"] = DIV;
    reservedWords["MOD"] = MOD;
    reservedWords["AND"] = AND;
    reservedWords["OR"] = OR;
    reservedWords["NOT"] = NOT;
    reservedWords["CONST"] = CONST;
    reservedWords["TYPE"] = TYPE;
    reservedWords["VAR"] = VAR;
    reservedWords["PROCEDURE"] = PROCEDURE;
    reservedWords["FUNCTION"] = FUNCTION;
    reservedWords["WHILE"] = WHILE;
    reservedWords["DO"] = DO;
    reservedWords["FOR"] = FOR;
    reservedWords["TO"] = TO;
    reservedWords["DOWNTO"] = DOWNTO;
    reservedWords["IF"] = IF;
    reservedWords["THEN"] = THEN;
    reservedWords["ELSE"] = ELSE;
    reservedWords["CASE"] = CASE;
    reservedWords["OF"] = OF;
}

Token *Token::Word(char firstChar, Source *source)
{
    Token *token = new Token(firstChar);
    token->lineNumber = source->lineNumber();

    // Loop to get the rest of the characters of the word token.
    // Append letters and digits to the token.
    for (char ch = source->nextChar(); isalnum(ch); ch = source->nextChar())
    {
        token->text += ch;
    }

    // Is it a reserved word or an identifier?
    string upper = toUpperCase(token->text);
    if (Token::reservedWords.find(upper) != Token::reservedWords.end())
    {
        token->type = Token::reservedWords[upper];
    }
    else
    {
        token->type = TokenType::IDENTIFIER;
    }

    return token;
}

Token *Token::Number(char firstChar, Source *source)
{
    Token *token = new Token(firstChar);
    token->lineNumber = source->lineNumber();
    int pointCount = 0;

    // Loop to get the rest of the characters of the number token.
    // Append digits to the token.
    for (char ch = source->nextChar();
         isdigit(ch) || (ch == '.');
         ch = source->nextChar())
    {
        if (ch == '.') pointCount++;
        token->text += ch;
    }

    // Integer constant.
    if (pointCount == 0)
    {
        token->type    = TokenType::INTEGER;
        token->value.L = stol(token->text);
        token->value.D = token->value.L;  // allow using integer value as double
    }

    // Real constant.
    else if (pointCount == 1)
    {
        token->type    = TokenType::REAL;
        token->value.D = stod(token->text);
    }

    else tokenError(token, "Invalid number");

    return token;
}

Token *Token::String(char firstChar, Source *source)
{
    Token *token = new Token(firstChar);  // the leading '
    token->lineNumber = source->lineNumber();
    // variables currentChar and nextChar
    char currentChar = source->currentChar() ;
    char nextChar = source->nextChar() ;
    //increment pointers to not point at currentChar: '
    currentChar = source->currentChar() ;
    nextChar = source->nextChar() ;
    //count to determine if the string is a character or not
    int count = 0 ;
    bool endFlag = false ;

    while(1) {
        if(currentChar == '\'') { // bracket found

            if(nextChar == '\'') { // double bracket condition 
                token->text += currentChar; // take only one of the double brackets into token and increment ptrs
                count++ ; 
                currentChar = source->currentChar() ; // increment ptrs 
                nextChar = source->nextChar() ;
            } else {
                break ; // if there isn't a second bracket the string has been completed so stop loop 
                
            }
        } else if(currentChar == -1){
            endFlag = true ;
            break ;
        } else {
            token->text += currentChar;
            count++ ;
        }
        currentChar = source->currentChar() ; // increment ptrs 
        nextChar = source->nextChar() ;
    
    }
 

    // variables currentChar and nextChar
    char currentChar = source->currentChar() ;
    char nextChar = source->nextChar() ;
    //increment pointers to not point at currentChar: '
    currentChar = source->currentChar() ;
    nextChar = source->nextChar() ;
    //count to determine if the string is a character or not
    int count = 0 ;
    bool endFlag = false ;

    while(1) {
        if(currentChar == '\'') { // bracket found

            if(nextChar == '\'') { // double bracket condition 
                token->text += currentChar; // take only one of the double brackets into token and increment ptrs
                count++ ; 
                currentChar = source->currentChar() ; // increment ptrs 
                nextChar = source->nextChar() ;
            } else {
                break ; // if there isn't a second bracket the string has been completed so stop loop 
                
            }
        } else if(currentChar == -1){
            endFlag = true ;
            break ;
        } else {
            token->text += currentChar;
            count++ ;
        }
        currentChar = source->currentChar() ; // increment ptrs 
        nextChar = source->nextChar() ;
    
    }
 

    // Loop to append the rest of the characters of the string,
    // up to but not including the closing quote.
    
    /*
    for (char ch = source->nextChar(); ch != '\''; ch = source->nextChar())
    {
        token->text += ch;
    }
    */
   if(endFlag) {
       token->type = TokenType::ERROR;
       tokenError(token, "string not closed");
   } else {
    token->text += '\'';  // the closing quote
    source->nextChar();  // consume the closing quote
    if(count == 1) {
        token->type = TokenType::CHARACTER;
    } else {
        token->type = TokenType::STRING;
    }
   }

    

    // Don't include the leading and trailing '.
    token->value.S = token->text.substr(1, token->text.length() - 2);

    return token;
}

Token *Token::SpecialSymbol(char firstChar, Source *source)
{
    Token *token = new Token(firstChar);
    token->lineNumber = source->lineNumber();

    switch (firstChar)
    {
        case ';' : token->type = TokenType::SEMICOLON;  break;
        case '+' : token->type = TokenType::PLUS;       break;
        case '-' : token->type = TokenType::MINUS;      break;
        case '*' : token->type = TokenType::STAR;       break;
        case '/' : token->type = TokenType::SLASH;      break;
        case '=' : token->type = TokenType::EQUALS;     break;
        case '(' : token->type = TokenType::LPAREN;     break;
        case ')' : token->type = TokenType::RPAREN;     break;
        case ',' : token->type = TokenType::COMMA;      break;
        case '`' : token->type = TokenType::BACKTICK;   break;
        case '[' : token->type = TokenType::LBRACK;     break;
        case ']' : token->type = TokenType::RBRACK;     break;
        case '^' : token->type = TokenType::CARROT;     break;

        case ':' :
        {
            char nextChar = source->nextChar();
            

            // Is it the := symbol?
            if (nextChar == '=')
            {
                token->type = TokenType::COLON_EQUALS;
                token->text += nextChar;
            }

            // No, it's just the : symbol.
            else
            {
                token->type = TokenType::COLON;
                return token;  // already consumed :
            }

            break;
        }

        case '.' : 
        {
            char nextChar = source -> nextChar();
            //check if it is a double period or not
            if (nextChar == '.')
            {
                token -> type = TokenType::DOUBLE_PERIOD;
                token -> text += nextChar;
            }
            //meaning it is just a period
            else
            {
                token->type = TokenType::PERIOD;     
                return token;
            }

            break;
        }

        case '<' : 
        {
            char nextChar = source -> nextChar();
            //Check if it is NOT EQUALS by looking for '>'
            if(nextChar == '>')
            {
                token -> type = TokenType::NOT_EQUALS;
                token -> text += nextChar;
            }

            //Check if it is LESS THAN EQUALS by looking for '='
            else if(nextChar == '=')
            {
                token -> type = TokenType::LESS_THAN_EQUALS;
                token -> text += nextChar;
            }

            //if not then it is just less than
            else
            {
                token->type = TokenType::LESS_THAN;  
                return token;
            }

            break;
        }

        case '>' :
        {
            char nextChar = source -> nextChar();

            //check if greater than equal to by checking for '='
            if(nextChar == '=')
            {
                token->type = TokenType::GREATER_THAN_EQUALS;
                token -> text += nextChar;
            }
            //if not then it is just greater than
            else
            {
                token->type = TokenType::GREATER_THAN;
                return token;
            }

            break;
        }


        

        case EOF : token->type = END_OF_FILE; break;

        default: token->type = TokenType::ERROR;
    }

    source->nextChar();  // consume the special symbol
    return token;
}

void Token::tokenError(Token *token, string message)
{
    printf("TOKEN ERROR at line %d: %s at '%s'\n",
           token->lineNumber, message.c_str(), token->text.c_str());
}

}  // namespace frontend