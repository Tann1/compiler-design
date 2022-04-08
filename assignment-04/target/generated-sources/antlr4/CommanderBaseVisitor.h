
// Generated from Commander.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "CommanderVisitor.h"


/**
 * This class provides an empty implementation of CommanderVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  CommanderBaseVisitor : public CommanderVisitor {
public:

  virtual antlrcpp::Any visitCommand(CommanderParser::CommandContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGoCommand(CommanderParser::GoCommandContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStepCommand(CommanderParser::StepCommandContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitQuitCommand(CommanderParser::QuitCommandContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBreakCommand(CommanderParser::BreakCommandContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnbreakCommand(CommanderParser::UnbreakCommandContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitShowCommand(CommanderParser::ShowCommandContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStackCommand(CommanderParser::StackCommandContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWatchCommand(CommanderParser::WatchCommandContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnwatchCommand(CommanderParser::UnwatchCommandContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLineNumberList(CommanderParser::LineNumberListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariableList(CommanderParser::VariableListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSimpleVariableList(CommanderParser::SimpleVariableListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLineNumber(CommanderParser::LineNumberContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSimpleVariable(CommanderParser::SimpleVariableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariable(CommanderParser::VariableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitModifier(CommanderParser::ModifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIndexList(CommanderParser::IndexListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIndex(CommanderParser::IndexContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitField(CommanderParser::FieldContext *ctx) override {
    return visitChildren(ctx);
  }


};

