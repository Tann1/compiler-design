
// Generated from Commander.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "CommanderParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by CommanderParser.
 */
class  CommanderVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by CommanderParser.
   */
    virtual antlrcpp::Any visitCommand(CommanderParser::CommandContext *context) = 0;

    virtual antlrcpp::Any visitGoCommand(CommanderParser::GoCommandContext *context) = 0;

    virtual antlrcpp::Any visitStepCommand(CommanderParser::StepCommandContext *context) = 0;

    virtual antlrcpp::Any visitQuitCommand(CommanderParser::QuitCommandContext *context) = 0;

    virtual antlrcpp::Any visitBreakCommand(CommanderParser::BreakCommandContext *context) = 0;

    virtual antlrcpp::Any visitUnbreakCommand(CommanderParser::UnbreakCommandContext *context) = 0;

    virtual antlrcpp::Any visitShowCommand(CommanderParser::ShowCommandContext *context) = 0;

    virtual antlrcpp::Any visitStackCommand(CommanderParser::StackCommandContext *context) = 0;

    virtual antlrcpp::Any visitWatchCommand(CommanderParser::WatchCommandContext *context) = 0;

    virtual antlrcpp::Any visitUnwatchCommand(CommanderParser::UnwatchCommandContext *context) = 0;

    virtual antlrcpp::Any visitLineNumberList(CommanderParser::LineNumberListContext *context) = 0;

    virtual antlrcpp::Any visitVariableList(CommanderParser::VariableListContext *context) = 0;

    virtual antlrcpp::Any visitSimpleVariableList(CommanderParser::SimpleVariableListContext *context) = 0;

    virtual antlrcpp::Any visitLineNumber(CommanderParser::LineNumberContext *context) = 0;

    virtual antlrcpp::Any visitSimpleVariable(CommanderParser::SimpleVariableContext *context) = 0;

    virtual antlrcpp::Any visitVariable(CommanderParser::VariableContext *context) = 0;

    virtual antlrcpp::Any visitModifier(CommanderParser::ModifierContext *context) = 0;

    virtual antlrcpp::Any visitIndexList(CommanderParser::IndexListContext *context) = 0;

    virtual antlrcpp::Any visitIndex(CommanderParser::IndexContext *context) = 0;

    virtual antlrcpp::Any visitField(CommanderParser::FieldContext *context) = 0;


};

