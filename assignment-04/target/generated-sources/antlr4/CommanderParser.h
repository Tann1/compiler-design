
// Generated from Commander.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  CommanderParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, BREAK = 5, UNBREAK = 6, WATCH = 7, 
    UNWATCH = 8, SHOW = 9, STACK = 10, STEP = 11, GO = 12, QUIT = 13, IDENTIFIER = 14, 
    INTEGER = 15, NEWLINE = 16, WS = 17
  };

  enum {
    RuleCommand = 0, RuleGoCommand = 1, RuleStepCommand = 2, RuleQuitCommand = 3, 
    RuleBreakCommand = 4, RuleUnbreakCommand = 5, RuleShowCommand = 6, RuleStackCommand = 7, 
    RuleWatchCommand = 8, RuleUnwatchCommand = 9, RuleLineNumberList = 10, 
    RuleVariableList = 11, RuleSimpleVariableList = 12, RuleLineNumber = 13, 
    RuleSimpleVariable = 14, RuleVariable = 15, RuleModifier = 16, RuleIndexList = 17, 
    RuleIndex = 18, RuleField = 19
  };

  CommanderParser(antlr4::TokenStream *input);
  ~CommanderParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class CommandContext;
  class GoCommandContext;
  class StepCommandContext;
  class QuitCommandContext;
  class BreakCommandContext;
  class UnbreakCommandContext;
  class ShowCommandContext;
  class StackCommandContext;
  class WatchCommandContext;
  class UnwatchCommandContext;
  class LineNumberListContext;
  class VariableListContext;
  class SimpleVariableListContext;
  class LineNumberContext;
  class SimpleVariableContext;
  class VariableContext;
  class ModifierContext;
  class IndexListContext;
  class IndexContext;
  class FieldContext; 

  class  CommandContext : public antlr4::ParserRuleContext {
  public:
    CommandContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    GoCommandContext *goCommand();
    StepCommandContext *stepCommand();
    QuitCommandContext *quitCommand();
    BreakCommandContext *breakCommand();
    UnbreakCommandContext *unbreakCommand();
    ShowCommandContext *showCommand();
    StackCommandContext *stackCommand();
    WatchCommandContext *watchCommand();
    UnwatchCommandContext *unwatchCommand();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CommandContext* command();

  class  GoCommandContext : public antlr4::ParserRuleContext {
  public:
    GoCommandContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *GO();
    antlr4::tree::TerminalNode *NEWLINE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GoCommandContext* goCommand();

  class  StepCommandContext : public antlr4::ParserRuleContext {
  public:
    StepCommandContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *STEP();
    antlr4::tree::TerminalNode *NEWLINE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StepCommandContext* stepCommand();

  class  QuitCommandContext : public antlr4::ParserRuleContext {
  public:
    QuitCommandContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *QUIT();
    antlr4::tree::TerminalNode *NEWLINE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QuitCommandContext* quitCommand();

  class  BreakCommandContext : public antlr4::ParserRuleContext {
  public:
    BreakCommandContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BREAK();
    antlr4::tree::TerminalNode *NEWLINE();
    LineNumberListContext *lineNumberList();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BreakCommandContext* breakCommand();

  class  UnbreakCommandContext : public antlr4::ParserRuleContext {
  public:
    UnbreakCommandContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *UNBREAK();
    LineNumberListContext *lineNumberList();
    antlr4::tree::TerminalNode *NEWLINE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UnbreakCommandContext* unbreakCommand();

  class  ShowCommandContext : public antlr4::ParserRuleContext {
  public:
    ShowCommandContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SHOW();
    VariableListContext *variableList();
    antlr4::tree::TerminalNode *NEWLINE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ShowCommandContext* showCommand();

  class  StackCommandContext : public antlr4::ParserRuleContext {
  public:
    StackCommandContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *STACK();
    antlr4::tree::TerminalNode *NEWLINE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StackCommandContext* stackCommand();

  class  WatchCommandContext : public antlr4::ParserRuleContext {
  public:
    WatchCommandContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WATCH();
    antlr4::tree::TerminalNode *NEWLINE();
    SimpleVariableListContext *simpleVariableList();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  WatchCommandContext* watchCommand();

  class  UnwatchCommandContext : public antlr4::ParserRuleContext {
  public:
    UnwatchCommandContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *UNWATCH();
    SimpleVariableListContext *simpleVariableList();
    antlr4::tree::TerminalNode *NEWLINE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UnwatchCommandContext* unwatchCommand();

  class  LineNumberListContext : public antlr4::ParserRuleContext {
  public:
    LineNumberListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<LineNumberContext *> lineNumber();
    LineNumberContext* lineNumber(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LineNumberListContext* lineNumberList();

  class  VariableListContext : public antlr4::ParserRuleContext {
  public:
    VariableListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<VariableContext *> variable();
    VariableContext* variable(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VariableListContext* variableList();

  class  SimpleVariableListContext : public antlr4::ParserRuleContext {
  public:
    SimpleVariableListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<SimpleVariableContext *> simpleVariable();
    SimpleVariableContext* simpleVariable(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SimpleVariableListContext* simpleVariableList();

  class  LineNumberContext : public antlr4::ParserRuleContext {
  public:
    LineNumberContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INTEGER();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LineNumberContext* lineNumber();

  class  SimpleVariableContext : public antlr4::ParserRuleContext {
  public:
    SimpleVariableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SimpleVariableContext* simpleVariable();

  class  VariableContext : public antlr4::ParserRuleContext {
  public:
    VariableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    std::vector<ModifierContext *> modifier();
    ModifierContext* modifier(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VariableContext* variable();

  class  ModifierContext : public antlr4::ParserRuleContext {
  public:
    ModifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IndexListContext *indexList();
    FieldContext *field();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ModifierContext* modifier();

  class  IndexListContext : public antlr4::ParserRuleContext {
  public:
    IndexListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<IndexContext *> index();
    IndexContext* index(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IndexListContext* indexList();

  class  IndexContext : public antlr4::ParserRuleContext {
  public:
    IndexContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INTEGER();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IndexContext* index();

  class  FieldContext : public antlr4::ParserRuleContext {
  public:
    FieldContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FieldContext* field();


private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

