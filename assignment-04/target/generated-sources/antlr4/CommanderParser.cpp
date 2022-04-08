
// Generated from Commander.g4 by ANTLR 4.7.2


#include "CommanderVisitor.h"

#include "CommanderParser.h"


using namespace antlrcpp;
using namespace antlr4;

CommanderParser::CommanderParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

CommanderParser::~CommanderParser() {
  delete _interpreter;
}

std::string CommanderParser::getGrammarFileName() const {
  return "Commander.g4";
}

const std::vector<std::string>& CommanderParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& CommanderParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- CommandContext ------------------------------------------------------------------

CommanderParser::CommandContext::CommandContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CommanderParser::GoCommandContext* CommanderParser::CommandContext::goCommand() {
  return getRuleContext<CommanderParser::GoCommandContext>(0);
}

CommanderParser::StepCommandContext* CommanderParser::CommandContext::stepCommand() {
  return getRuleContext<CommanderParser::StepCommandContext>(0);
}

CommanderParser::QuitCommandContext* CommanderParser::CommandContext::quitCommand() {
  return getRuleContext<CommanderParser::QuitCommandContext>(0);
}

CommanderParser::BreakCommandContext* CommanderParser::CommandContext::breakCommand() {
  return getRuleContext<CommanderParser::BreakCommandContext>(0);
}

CommanderParser::UnbreakCommandContext* CommanderParser::CommandContext::unbreakCommand() {
  return getRuleContext<CommanderParser::UnbreakCommandContext>(0);
}

CommanderParser::ShowCommandContext* CommanderParser::CommandContext::showCommand() {
  return getRuleContext<CommanderParser::ShowCommandContext>(0);
}

CommanderParser::StackCommandContext* CommanderParser::CommandContext::stackCommand() {
  return getRuleContext<CommanderParser::StackCommandContext>(0);
}

CommanderParser::WatchCommandContext* CommanderParser::CommandContext::watchCommand() {
  return getRuleContext<CommanderParser::WatchCommandContext>(0);
}

CommanderParser::UnwatchCommandContext* CommanderParser::CommandContext::unwatchCommand() {
  return getRuleContext<CommanderParser::UnwatchCommandContext>(0);
}


size_t CommanderParser::CommandContext::getRuleIndex() const {
  return CommanderParser::RuleCommand;
}


antlrcpp::Any CommanderParser::CommandContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CommanderVisitor*>(visitor))
    return parserVisitor->visitCommand(this);
  else
    return visitor->visitChildren(this);
}

CommanderParser::CommandContext* CommanderParser::command() {
  CommandContext *_localctx = _tracker.createInstance<CommandContext>(_ctx, getState());
  enterRule(_localctx, 0, CommanderParser::RuleCommand);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(49);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CommanderParser::GO: {
        enterOuterAlt(_localctx, 1);
        setState(40);
        goCommand();
        break;
      }

      case CommanderParser::STEP:
      case CommanderParser::NEWLINE: {
        enterOuterAlt(_localctx, 2);
        setState(41);
        stepCommand();
        break;
      }

      case CommanderParser::QUIT: {
        enterOuterAlt(_localctx, 3);
        setState(42);
        quitCommand();
        break;
      }

      case CommanderParser::BREAK: {
        enterOuterAlt(_localctx, 4);
        setState(43);
        breakCommand();
        break;
      }

      case CommanderParser::UNBREAK: {
        enterOuterAlt(_localctx, 5);
        setState(44);
        unbreakCommand();
        break;
      }

      case CommanderParser::SHOW: {
        enterOuterAlt(_localctx, 6);
        setState(45);
        showCommand();
        break;
      }

      case CommanderParser::STACK: {
        enterOuterAlt(_localctx, 7);
        setState(46);
        stackCommand();
        break;
      }

      case CommanderParser::WATCH: {
        enterOuterAlt(_localctx, 8);
        setState(47);
        watchCommand();
        break;
      }

      case CommanderParser::UNWATCH: {
        enterOuterAlt(_localctx, 9);
        setState(48);
        unwatchCommand();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GoCommandContext ------------------------------------------------------------------

CommanderParser::GoCommandContext::GoCommandContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CommanderParser::GoCommandContext::GO() {
  return getToken(CommanderParser::GO, 0);
}

tree::TerminalNode* CommanderParser::GoCommandContext::NEWLINE() {
  return getToken(CommanderParser::NEWLINE, 0);
}


size_t CommanderParser::GoCommandContext::getRuleIndex() const {
  return CommanderParser::RuleGoCommand;
}


antlrcpp::Any CommanderParser::GoCommandContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CommanderVisitor*>(visitor))
    return parserVisitor->visitGoCommand(this);
  else
    return visitor->visitChildren(this);
}

CommanderParser::GoCommandContext* CommanderParser::goCommand() {
  GoCommandContext *_localctx = _tracker.createInstance<GoCommandContext>(_ctx, getState());
  enterRule(_localctx, 2, CommanderParser::RuleGoCommand);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(51);
    match(CommanderParser::GO);
    setState(52);
    match(CommanderParser::NEWLINE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StepCommandContext ------------------------------------------------------------------

CommanderParser::StepCommandContext::StepCommandContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CommanderParser::StepCommandContext::STEP() {
  return getToken(CommanderParser::STEP, 0);
}

tree::TerminalNode* CommanderParser::StepCommandContext::NEWLINE() {
  return getToken(CommanderParser::NEWLINE, 0);
}


size_t CommanderParser::StepCommandContext::getRuleIndex() const {
  return CommanderParser::RuleStepCommand;
}


antlrcpp::Any CommanderParser::StepCommandContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CommanderVisitor*>(visitor))
    return parserVisitor->visitStepCommand(this);
  else
    return visitor->visitChildren(this);
}

CommanderParser::StepCommandContext* CommanderParser::stepCommand() {
  StepCommandContext *_localctx = _tracker.createInstance<StepCommandContext>(_ctx, getState());
  enterRule(_localctx, 4, CommanderParser::RuleStepCommand);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(57);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CommanderParser::STEP: {
        enterOuterAlt(_localctx, 1);
        setState(54);
        match(CommanderParser::STEP);
        setState(55);
        match(CommanderParser::NEWLINE);
        break;
      }

      case CommanderParser::NEWLINE: {
        enterOuterAlt(_localctx, 2);
        setState(56);
        match(CommanderParser::NEWLINE);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QuitCommandContext ------------------------------------------------------------------

CommanderParser::QuitCommandContext::QuitCommandContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CommanderParser::QuitCommandContext::QUIT() {
  return getToken(CommanderParser::QUIT, 0);
}

tree::TerminalNode* CommanderParser::QuitCommandContext::NEWLINE() {
  return getToken(CommanderParser::NEWLINE, 0);
}


size_t CommanderParser::QuitCommandContext::getRuleIndex() const {
  return CommanderParser::RuleQuitCommand;
}


antlrcpp::Any CommanderParser::QuitCommandContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CommanderVisitor*>(visitor))
    return parserVisitor->visitQuitCommand(this);
  else
    return visitor->visitChildren(this);
}

CommanderParser::QuitCommandContext* CommanderParser::quitCommand() {
  QuitCommandContext *_localctx = _tracker.createInstance<QuitCommandContext>(_ctx, getState());
  enterRule(_localctx, 6, CommanderParser::RuleQuitCommand);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(59);
    match(CommanderParser::QUIT);
    setState(60);
    match(CommanderParser::NEWLINE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BreakCommandContext ------------------------------------------------------------------

CommanderParser::BreakCommandContext::BreakCommandContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CommanderParser::BreakCommandContext::BREAK() {
  return getToken(CommanderParser::BREAK, 0);
}

tree::TerminalNode* CommanderParser::BreakCommandContext::NEWLINE() {
  return getToken(CommanderParser::NEWLINE, 0);
}

CommanderParser::LineNumberListContext* CommanderParser::BreakCommandContext::lineNumberList() {
  return getRuleContext<CommanderParser::LineNumberListContext>(0);
}


size_t CommanderParser::BreakCommandContext::getRuleIndex() const {
  return CommanderParser::RuleBreakCommand;
}


antlrcpp::Any CommanderParser::BreakCommandContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CommanderVisitor*>(visitor))
    return parserVisitor->visitBreakCommand(this);
  else
    return visitor->visitChildren(this);
}

CommanderParser::BreakCommandContext* CommanderParser::breakCommand() {
  BreakCommandContext *_localctx = _tracker.createInstance<BreakCommandContext>(_ctx, getState());
  enterRule(_localctx, 8, CommanderParser::RuleBreakCommand);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(62);
    match(CommanderParser::BREAK);
    setState(64);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CommanderParser::INTEGER) {
      setState(63);
      lineNumberList();
    }
    setState(66);
    match(CommanderParser::NEWLINE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnbreakCommandContext ------------------------------------------------------------------

CommanderParser::UnbreakCommandContext::UnbreakCommandContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CommanderParser::UnbreakCommandContext::UNBREAK() {
  return getToken(CommanderParser::UNBREAK, 0);
}

CommanderParser::LineNumberListContext* CommanderParser::UnbreakCommandContext::lineNumberList() {
  return getRuleContext<CommanderParser::LineNumberListContext>(0);
}

tree::TerminalNode* CommanderParser::UnbreakCommandContext::NEWLINE() {
  return getToken(CommanderParser::NEWLINE, 0);
}


size_t CommanderParser::UnbreakCommandContext::getRuleIndex() const {
  return CommanderParser::RuleUnbreakCommand;
}


antlrcpp::Any CommanderParser::UnbreakCommandContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CommanderVisitor*>(visitor))
    return parserVisitor->visitUnbreakCommand(this);
  else
    return visitor->visitChildren(this);
}

CommanderParser::UnbreakCommandContext* CommanderParser::unbreakCommand() {
  UnbreakCommandContext *_localctx = _tracker.createInstance<UnbreakCommandContext>(_ctx, getState());
  enterRule(_localctx, 10, CommanderParser::RuleUnbreakCommand);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(68);
    match(CommanderParser::UNBREAK);
    setState(69);
    lineNumberList();
    setState(70);
    match(CommanderParser::NEWLINE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ShowCommandContext ------------------------------------------------------------------

CommanderParser::ShowCommandContext::ShowCommandContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CommanderParser::ShowCommandContext::SHOW() {
  return getToken(CommanderParser::SHOW, 0);
}

CommanderParser::VariableListContext* CommanderParser::ShowCommandContext::variableList() {
  return getRuleContext<CommanderParser::VariableListContext>(0);
}

tree::TerminalNode* CommanderParser::ShowCommandContext::NEWLINE() {
  return getToken(CommanderParser::NEWLINE, 0);
}


size_t CommanderParser::ShowCommandContext::getRuleIndex() const {
  return CommanderParser::RuleShowCommand;
}


antlrcpp::Any CommanderParser::ShowCommandContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CommanderVisitor*>(visitor))
    return parserVisitor->visitShowCommand(this);
  else
    return visitor->visitChildren(this);
}

CommanderParser::ShowCommandContext* CommanderParser::showCommand() {
  ShowCommandContext *_localctx = _tracker.createInstance<ShowCommandContext>(_ctx, getState());
  enterRule(_localctx, 12, CommanderParser::RuleShowCommand);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(72);
    match(CommanderParser::SHOW);
    setState(73);
    variableList();
    setState(74);
    match(CommanderParser::NEWLINE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StackCommandContext ------------------------------------------------------------------

CommanderParser::StackCommandContext::StackCommandContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CommanderParser::StackCommandContext::STACK() {
  return getToken(CommanderParser::STACK, 0);
}

tree::TerminalNode* CommanderParser::StackCommandContext::NEWLINE() {
  return getToken(CommanderParser::NEWLINE, 0);
}


size_t CommanderParser::StackCommandContext::getRuleIndex() const {
  return CommanderParser::RuleStackCommand;
}


antlrcpp::Any CommanderParser::StackCommandContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CommanderVisitor*>(visitor))
    return parserVisitor->visitStackCommand(this);
  else
    return visitor->visitChildren(this);
}

CommanderParser::StackCommandContext* CommanderParser::stackCommand() {
  StackCommandContext *_localctx = _tracker.createInstance<StackCommandContext>(_ctx, getState());
  enterRule(_localctx, 14, CommanderParser::RuleStackCommand);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(76);
    match(CommanderParser::STACK);
    setState(77);
    match(CommanderParser::NEWLINE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WatchCommandContext ------------------------------------------------------------------

CommanderParser::WatchCommandContext::WatchCommandContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CommanderParser::WatchCommandContext::WATCH() {
  return getToken(CommanderParser::WATCH, 0);
}

tree::TerminalNode* CommanderParser::WatchCommandContext::NEWLINE() {
  return getToken(CommanderParser::NEWLINE, 0);
}

CommanderParser::SimpleVariableListContext* CommanderParser::WatchCommandContext::simpleVariableList() {
  return getRuleContext<CommanderParser::SimpleVariableListContext>(0);
}


size_t CommanderParser::WatchCommandContext::getRuleIndex() const {
  return CommanderParser::RuleWatchCommand;
}


antlrcpp::Any CommanderParser::WatchCommandContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CommanderVisitor*>(visitor))
    return parserVisitor->visitWatchCommand(this);
  else
    return visitor->visitChildren(this);
}

CommanderParser::WatchCommandContext* CommanderParser::watchCommand() {
  WatchCommandContext *_localctx = _tracker.createInstance<WatchCommandContext>(_ctx, getState());
  enterRule(_localctx, 16, CommanderParser::RuleWatchCommand);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(79);
    match(CommanderParser::WATCH);
    setState(81);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CommanderParser::IDENTIFIER) {
      setState(80);
      simpleVariableList();
    }
    setState(83);
    match(CommanderParser::NEWLINE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnwatchCommandContext ------------------------------------------------------------------

CommanderParser::UnwatchCommandContext::UnwatchCommandContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CommanderParser::UnwatchCommandContext::UNWATCH() {
  return getToken(CommanderParser::UNWATCH, 0);
}

CommanderParser::SimpleVariableListContext* CommanderParser::UnwatchCommandContext::simpleVariableList() {
  return getRuleContext<CommanderParser::SimpleVariableListContext>(0);
}

tree::TerminalNode* CommanderParser::UnwatchCommandContext::NEWLINE() {
  return getToken(CommanderParser::NEWLINE, 0);
}


size_t CommanderParser::UnwatchCommandContext::getRuleIndex() const {
  return CommanderParser::RuleUnwatchCommand;
}


antlrcpp::Any CommanderParser::UnwatchCommandContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CommanderVisitor*>(visitor))
    return parserVisitor->visitUnwatchCommand(this);
  else
    return visitor->visitChildren(this);
}

CommanderParser::UnwatchCommandContext* CommanderParser::unwatchCommand() {
  UnwatchCommandContext *_localctx = _tracker.createInstance<UnwatchCommandContext>(_ctx, getState());
  enterRule(_localctx, 18, CommanderParser::RuleUnwatchCommand);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(85);
    match(CommanderParser::UNWATCH);
    setState(86);
    simpleVariableList();
    setState(87);
    match(CommanderParser::NEWLINE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LineNumberListContext ------------------------------------------------------------------

CommanderParser::LineNumberListContext::LineNumberListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CommanderParser::LineNumberContext *> CommanderParser::LineNumberListContext::lineNumber() {
  return getRuleContexts<CommanderParser::LineNumberContext>();
}

CommanderParser::LineNumberContext* CommanderParser::LineNumberListContext::lineNumber(size_t i) {
  return getRuleContext<CommanderParser::LineNumberContext>(i);
}


size_t CommanderParser::LineNumberListContext::getRuleIndex() const {
  return CommanderParser::RuleLineNumberList;
}


antlrcpp::Any CommanderParser::LineNumberListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CommanderVisitor*>(visitor))
    return parserVisitor->visitLineNumberList(this);
  else
    return visitor->visitChildren(this);
}

CommanderParser::LineNumberListContext* CommanderParser::lineNumberList() {
  LineNumberListContext *_localctx = _tracker.createInstance<LineNumberListContext>(_ctx, getState());
  enterRule(_localctx, 20, CommanderParser::RuleLineNumberList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(89);
    lineNumber();
    setState(96);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CommanderParser::T__0

    || _la == CommanderParser::INTEGER) {
      setState(91);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CommanderParser::T__0) {
        setState(90);
        match(CommanderParser::T__0);
      }
      setState(93);
      lineNumber();
      setState(98);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableListContext ------------------------------------------------------------------

CommanderParser::VariableListContext::VariableListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CommanderParser::VariableContext *> CommanderParser::VariableListContext::variable() {
  return getRuleContexts<CommanderParser::VariableContext>();
}

CommanderParser::VariableContext* CommanderParser::VariableListContext::variable(size_t i) {
  return getRuleContext<CommanderParser::VariableContext>(i);
}


size_t CommanderParser::VariableListContext::getRuleIndex() const {
  return CommanderParser::RuleVariableList;
}


antlrcpp::Any CommanderParser::VariableListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CommanderVisitor*>(visitor))
    return parserVisitor->visitVariableList(this);
  else
    return visitor->visitChildren(this);
}

CommanderParser::VariableListContext* CommanderParser::variableList() {
  VariableListContext *_localctx = _tracker.createInstance<VariableListContext>(_ctx, getState());
  enterRule(_localctx, 22, CommanderParser::RuleVariableList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(99);
    variable();
    setState(106);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CommanderParser::T__0

    || _la == CommanderParser::IDENTIFIER) {
      setState(101);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CommanderParser::T__0) {
        setState(100);
        match(CommanderParser::T__0);
      }
      setState(103);
      variable();
      setState(108);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SimpleVariableListContext ------------------------------------------------------------------

CommanderParser::SimpleVariableListContext::SimpleVariableListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CommanderParser::SimpleVariableContext *> CommanderParser::SimpleVariableListContext::simpleVariable() {
  return getRuleContexts<CommanderParser::SimpleVariableContext>();
}

CommanderParser::SimpleVariableContext* CommanderParser::SimpleVariableListContext::simpleVariable(size_t i) {
  return getRuleContext<CommanderParser::SimpleVariableContext>(i);
}


size_t CommanderParser::SimpleVariableListContext::getRuleIndex() const {
  return CommanderParser::RuleSimpleVariableList;
}


antlrcpp::Any CommanderParser::SimpleVariableListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CommanderVisitor*>(visitor))
    return parserVisitor->visitSimpleVariableList(this);
  else
    return visitor->visitChildren(this);
}

CommanderParser::SimpleVariableListContext* CommanderParser::simpleVariableList() {
  SimpleVariableListContext *_localctx = _tracker.createInstance<SimpleVariableListContext>(_ctx, getState());
  enterRule(_localctx, 24, CommanderParser::RuleSimpleVariableList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(109);
    simpleVariable();
    setState(116);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CommanderParser::T__0

    || _la == CommanderParser::IDENTIFIER) {
      setState(111);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CommanderParser::T__0) {
        setState(110);
        match(CommanderParser::T__0);
      }
      setState(113);
      simpleVariable();
      setState(118);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LineNumberContext ------------------------------------------------------------------

CommanderParser::LineNumberContext::LineNumberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CommanderParser::LineNumberContext::INTEGER() {
  return getToken(CommanderParser::INTEGER, 0);
}


size_t CommanderParser::LineNumberContext::getRuleIndex() const {
  return CommanderParser::RuleLineNumber;
}


antlrcpp::Any CommanderParser::LineNumberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CommanderVisitor*>(visitor))
    return parserVisitor->visitLineNumber(this);
  else
    return visitor->visitChildren(this);
}

CommanderParser::LineNumberContext* CommanderParser::lineNumber() {
  LineNumberContext *_localctx = _tracker.createInstance<LineNumberContext>(_ctx, getState());
  enterRule(_localctx, 26, CommanderParser::RuleLineNumber);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(119);
    match(CommanderParser::INTEGER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SimpleVariableContext ------------------------------------------------------------------

CommanderParser::SimpleVariableContext::SimpleVariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CommanderParser::SimpleVariableContext::IDENTIFIER() {
  return getToken(CommanderParser::IDENTIFIER, 0);
}


size_t CommanderParser::SimpleVariableContext::getRuleIndex() const {
  return CommanderParser::RuleSimpleVariable;
}


antlrcpp::Any CommanderParser::SimpleVariableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CommanderVisitor*>(visitor))
    return parserVisitor->visitSimpleVariable(this);
  else
    return visitor->visitChildren(this);
}

CommanderParser::SimpleVariableContext* CommanderParser::simpleVariable() {
  SimpleVariableContext *_localctx = _tracker.createInstance<SimpleVariableContext>(_ctx, getState());
  enterRule(_localctx, 28, CommanderParser::RuleSimpleVariable);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(121);
    match(CommanderParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableContext ------------------------------------------------------------------

CommanderParser::VariableContext::VariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CommanderParser::VariableContext::IDENTIFIER() {
  return getToken(CommanderParser::IDENTIFIER, 0);
}

std::vector<CommanderParser::ModifierContext *> CommanderParser::VariableContext::modifier() {
  return getRuleContexts<CommanderParser::ModifierContext>();
}

CommanderParser::ModifierContext* CommanderParser::VariableContext::modifier(size_t i) {
  return getRuleContext<CommanderParser::ModifierContext>(i);
}


size_t CommanderParser::VariableContext::getRuleIndex() const {
  return CommanderParser::RuleVariable;
}


antlrcpp::Any CommanderParser::VariableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CommanderVisitor*>(visitor))
    return parserVisitor->visitVariable(this);
  else
    return visitor->visitChildren(this);
}

CommanderParser::VariableContext* CommanderParser::variable() {
  VariableContext *_localctx = _tracker.createInstance<VariableContext>(_ctx, getState());
  enterRule(_localctx, 30, CommanderParser::RuleVariable);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(123);
    match(CommanderParser::IDENTIFIER);
    setState(127);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CommanderParser::T__1

    || _la == CommanderParser::T__3) {
      setState(124);
      modifier();
      setState(129);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ModifierContext ------------------------------------------------------------------

CommanderParser::ModifierContext::ModifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CommanderParser::IndexListContext* CommanderParser::ModifierContext::indexList() {
  return getRuleContext<CommanderParser::IndexListContext>(0);
}

CommanderParser::FieldContext* CommanderParser::ModifierContext::field() {
  return getRuleContext<CommanderParser::FieldContext>(0);
}


size_t CommanderParser::ModifierContext::getRuleIndex() const {
  return CommanderParser::RuleModifier;
}


antlrcpp::Any CommanderParser::ModifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CommanderVisitor*>(visitor))
    return parserVisitor->visitModifier(this);
  else
    return visitor->visitChildren(this);
}

CommanderParser::ModifierContext* CommanderParser::modifier() {
  ModifierContext *_localctx = _tracker.createInstance<ModifierContext>(_ctx, getState());
  enterRule(_localctx, 32, CommanderParser::RuleModifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(136);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CommanderParser::T__1: {
        enterOuterAlt(_localctx, 1);
        setState(130);
        match(CommanderParser::T__1);
        setState(131);
        indexList();
        setState(132);
        match(CommanderParser::T__2);
        break;
      }

      case CommanderParser::T__3: {
        enterOuterAlt(_localctx, 2);
        setState(134);
        match(CommanderParser::T__3);
        setState(135);
        field();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IndexListContext ------------------------------------------------------------------

CommanderParser::IndexListContext::IndexListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CommanderParser::IndexContext *> CommanderParser::IndexListContext::index() {
  return getRuleContexts<CommanderParser::IndexContext>();
}

CommanderParser::IndexContext* CommanderParser::IndexListContext::index(size_t i) {
  return getRuleContext<CommanderParser::IndexContext>(i);
}


size_t CommanderParser::IndexListContext::getRuleIndex() const {
  return CommanderParser::RuleIndexList;
}


antlrcpp::Any CommanderParser::IndexListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CommanderVisitor*>(visitor))
    return parserVisitor->visitIndexList(this);
  else
    return visitor->visitChildren(this);
}

CommanderParser::IndexListContext* CommanderParser::indexList() {
  IndexListContext *_localctx = _tracker.createInstance<IndexListContext>(_ctx, getState());
  enterRule(_localctx, 34, CommanderParser::RuleIndexList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(138);
    index();
    setState(143);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CommanderParser::T__0) {
      setState(139);
      match(CommanderParser::T__0);
      setState(140);
      index();
      setState(145);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IndexContext ------------------------------------------------------------------

CommanderParser::IndexContext::IndexContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CommanderParser::IndexContext::INTEGER() {
  return getToken(CommanderParser::INTEGER, 0);
}


size_t CommanderParser::IndexContext::getRuleIndex() const {
  return CommanderParser::RuleIndex;
}


antlrcpp::Any CommanderParser::IndexContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CommanderVisitor*>(visitor))
    return parserVisitor->visitIndex(this);
  else
    return visitor->visitChildren(this);
}

CommanderParser::IndexContext* CommanderParser::index() {
  IndexContext *_localctx = _tracker.createInstance<IndexContext>(_ctx, getState());
  enterRule(_localctx, 36, CommanderParser::RuleIndex);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(146);
    match(CommanderParser::INTEGER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FieldContext ------------------------------------------------------------------

CommanderParser::FieldContext::FieldContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CommanderParser::FieldContext::IDENTIFIER() {
  return getToken(CommanderParser::IDENTIFIER, 0);
}


size_t CommanderParser::FieldContext::getRuleIndex() const {
  return CommanderParser::RuleField;
}


antlrcpp::Any CommanderParser::FieldContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CommanderVisitor*>(visitor))
    return parserVisitor->visitField(this);
  else
    return visitor->visitChildren(this);
}

CommanderParser::FieldContext* CommanderParser::field() {
  FieldContext *_localctx = _tracker.createInstance<FieldContext>(_ctx, getState());
  enterRule(_localctx, 38, CommanderParser::RuleField);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(148);
    match(CommanderParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> CommanderParser::_decisionToDFA;
atn::PredictionContextCache CommanderParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN CommanderParser::_atn;
std::vector<uint16_t> CommanderParser::_serializedATN;

std::vector<std::string> CommanderParser::_ruleNames = {
  "command", "goCommand", "stepCommand", "quitCommand", "breakCommand", 
  "unbreakCommand", "showCommand", "stackCommand", "watchCommand", "unwatchCommand", 
  "lineNumberList", "variableList", "simpleVariableList", "lineNumber", 
  "simpleVariable", "variable", "modifier", "indexList", "index", "field"
};

std::vector<std::string> CommanderParser::_literalNames = {
  "", "','", "'['", "']'", "'.'"
};

std::vector<std::string> CommanderParser::_symbolicNames = {
  "", "", "", "", "", "BREAK", "UNBREAK", "WATCH", "UNWATCH", "SHOW", "STACK", 
  "STEP", "GO", "QUIT", "IDENTIFIER", "INTEGER", "NEWLINE", "WS"
};

dfa::Vocabulary CommanderParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> CommanderParser::_tokenNames;

CommanderParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x13, 0x99, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 
    0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 0x12, 
    0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 0x9, 
    0x15, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x2, 0x5, 0x2, 0x34, 0xa, 0x2, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x3c, 0xa, 0x4, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x43, 0xa, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 
    0x3, 0xa, 0x5, 0xa, 0x54, 0xa, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 
    0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0x5e, 0xa, 0xc, 
    0x3, 0xc, 0x7, 0xc, 0x61, 0xa, 0xc, 0xc, 0xc, 0xe, 0xc, 0x64, 0xb, 0xc, 
    0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0x68, 0xa, 0xd, 0x3, 0xd, 0x7, 0xd, 0x6b, 
    0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 0x6e, 0xb, 0xd, 0x3, 0xe, 0x3, 0xe, 0x5, 
    0xe, 0x72, 0xa, 0xe, 0x3, 0xe, 0x7, 0xe, 0x75, 0xa, 0xe, 0xc, 0xe, 0xe, 
    0xe, 0x78, 0xb, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 
    0x11, 0x3, 0x11, 0x7, 0x11, 0x80, 0xa, 0x11, 0xc, 0x11, 0xe, 0x11, 0x83, 
    0xb, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 
    0x12, 0x5, 0x12, 0x8b, 0xa, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x7, 
    0x13, 0x90, 0xa, 0x13, 0xc, 0x13, 0xe, 0x13, 0x93, 0xb, 0x13, 0x3, 0x14, 
    0x3, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x2, 0x2, 0x16, 0x2, 0x4, 
    0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 
    0x20, 0x22, 0x24, 0x26, 0x28, 0x2, 0x2, 0x2, 0x98, 0x2, 0x33, 0x3, 0x2, 
    0x2, 0x2, 0x4, 0x35, 0x3, 0x2, 0x2, 0x2, 0x6, 0x3b, 0x3, 0x2, 0x2, 0x2, 
    0x8, 0x3d, 0x3, 0x2, 0x2, 0x2, 0xa, 0x40, 0x3, 0x2, 0x2, 0x2, 0xc, 0x46, 
    0x3, 0x2, 0x2, 0x2, 0xe, 0x4a, 0x3, 0x2, 0x2, 0x2, 0x10, 0x4e, 0x3, 
    0x2, 0x2, 0x2, 0x12, 0x51, 0x3, 0x2, 0x2, 0x2, 0x14, 0x57, 0x3, 0x2, 
    0x2, 0x2, 0x16, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x18, 0x65, 0x3, 0x2, 0x2, 
    0x2, 0x1a, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x79, 0x3, 0x2, 0x2, 0x2, 
    0x1e, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x20, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x22, 
    0x8a, 0x3, 0x2, 0x2, 0x2, 0x24, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x26, 0x94, 
    0x3, 0x2, 0x2, 0x2, 0x28, 0x96, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x34, 0x5, 
    0x4, 0x3, 0x2, 0x2b, 0x34, 0x5, 0x6, 0x4, 0x2, 0x2c, 0x34, 0x5, 0x8, 
    0x5, 0x2, 0x2d, 0x34, 0x5, 0xa, 0x6, 0x2, 0x2e, 0x34, 0x5, 0xc, 0x7, 
    0x2, 0x2f, 0x34, 0x5, 0xe, 0x8, 0x2, 0x30, 0x34, 0x5, 0x10, 0x9, 0x2, 
    0x31, 0x34, 0x5, 0x12, 0xa, 0x2, 0x32, 0x34, 0x5, 0x14, 0xb, 0x2, 0x33, 
    0x2a, 0x3, 0x2, 0x2, 0x2, 0x33, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x33, 0x2c, 
    0x3, 0x2, 0x2, 0x2, 0x33, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x33, 0x2e, 0x3, 
    0x2, 0x2, 0x2, 0x33, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x33, 0x30, 0x3, 0x2, 
    0x2, 0x2, 0x33, 0x31, 0x3, 0x2, 0x2, 0x2, 0x33, 0x32, 0x3, 0x2, 0x2, 
    0x2, 0x34, 0x3, 0x3, 0x2, 0x2, 0x2, 0x35, 0x36, 0x7, 0xe, 0x2, 0x2, 
    0x36, 0x37, 0x7, 0x12, 0x2, 0x2, 0x37, 0x5, 0x3, 0x2, 0x2, 0x2, 0x38, 
    0x39, 0x7, 0xd, 0x2, 0x2, 0x39, 0x3c, 0x7, 0x12, 0x2, 0x2, 0x3a, 0x3c, 
    0x7, 0x12, 0x2, 0x2, 0x3b, 0x38, 0x3, 0x2, 0x2, 0x2, 0x3b, 0x3a, 0x3, 
    0x2, 0x2, 0x2, 0x3c, 0x7, 0x3, 0x2, 0x2, 0x2, 0x3d, 0x3e, 0x7, 0xf, 
    0x2, 0x2, 0x3e, 0x3f, 0x7, 0x12, 0x2, 0x2, 0x3f, 0x9, 0x3, 0x2, 0x2, 
    0x2, 0x40, 0x42, 0x7, 0x7, 0x2, 0x2, 0x41, 0x43, 0x5, 0x16, 0xc, 0x2, 
    0x42, 0x41, 0x3, 0x2, 0x2, 0x2, 0x42, 0x43, 0x3, 0x2, 0x2, 0x2, 0x43, 
    0x44, 0x3, 0x2, 0x2, 0x2, 0x44, 0x45, 0x7, 0x12, 0x2, 0x2, 0x45, 0xb, 
    0x3, 0x2, 0x2, 0x2, 0x46, 0x47, 0x7, 0x8, 0x2, 0x2, 0x47, 0x48, 0x5, 
    0x16, 0xc, 0x2, 0x48, 0x49, 0x7, 0x12, 0x2, 0x2, 0x49, 0xd, 0x3, 0x2, 
    0x2, 0x2, 0x4a, 0x4b, 0x7, 0xb, 0x2, 0x2, 0x4b, 0x4c, 0x5, 0x18, 0xd, 
    0x2, 0x4c, 0x4d, 0x7, 0x12, 0x2, 0x2, 0x4d, 0xf, 0x3, 0x2, 0x2, 0x2, 
    0x4e, 0x4f, 0x7, 0xc, 0x2, 0x2, 0x4f, 0x50, 0x7, 0x12, 0x2, 0x2, 0x50, 
    0x11, 0x3, 0x2, 0x2, 0x2, 0x51, 0x53, 0x7, 0x9, 0x2, 0x2, 0x52, 0x54, 
    0x5, 0x1a, 0xe, 0x2, 0x53, 0x52, 0x3, 0x2, 0x2, 0x2, 0x53, 0x54, 0x3, 
    0x2, 0x2, 0x2, 0x54, 0x55, 0x3, 0x2, 0x2, 0x2, 0x55, 0x56, 0x7, 0x12, 
    0x2, 0x2, 0x56, 0x13, 0x3, 0x2, 0x2, 0x2, 0x57, 0x58, 0x7, 0xa, 0x2, 
    0x2, 0x58, 0x59, 0x5, 0x1a, 0xe, 0x2, 0x59, 0x5a, 0x7, 0x12, 0x2, 0x2, 
    0x5a, 0x15, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x62, 0x5, 0x1c, 0xf, 0x2, 0x5c, 
    0x5e, 0x7, 0x3, 0x2, 0x2, 0x5d, 0x5c, 0x3, 0x2, 0x2, 0x2, 0x5d, 0x5e, 
    0x3, 0x2, 0x2, 0x2, 0x5e, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x5f, 0x61, 0x5, 
    0x1c, 0xf, 0x2, 0x60, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x61, 0x64, 0x3, 0x2, 
    0x2, 0x2, 0x62, 0x60, 0x3, 0x2, 0x2, 0x2, 0x62, 0x63, 0x3, 0x2, 0x2, 
    0x2, 0x63, 0x17, 0x3, 0x2, 0x2, 0x2, 0x64, 0x62, 0x3, 0x2, 0x2, 0x2, 
    0x65, 0x6c, 0x5, 0x20, 0x11, 0x2, 0x66, 0x68, 0x7, 0x3, 0x2, 0x2, 0x67, 
    0x66, 0x3, 0x2, 0x2, 0x2, 0x67, 0x68, 0x3, 0x2, 0x2, 0x2, 0x68, 0x69, 
    0x3, 0x2, 0x2, 0x2, 0x69, 0x6b, 0x5, 0x20, 0x11, 0x2, 0x6a, 0x67, 0x3, 
    0x2, 0x2, 0x2, 0x6b, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x6a, 0x3, 0x2, 
    0x2, 0x2, 0x6c, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x19, 0x3, 0x2, 0x2, 
    0x2, 0x6e, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x76, 0x5, 0x1e, 0x10, 0x2, 
    0x70, 0x72, 0x7, 0x3, 0x2, 0x2, 0x71, 0x70, 0x3, 0x2, 0x2, 0x2, 0x71, 
    0x72, 0x3, 0x2, 0x2, 0x2, 0x72, 0x73, 0x3, 0x2, 0x2, 0x2, 0x73, 0x75, 
    0x5, 0x1e, 0x10, 0x2, 0x74, 0x71, 0x3, 0x2, 0x2, 0x2, 0x75, 0x78, 0x3, 
    0x2, 0x2, 0x2, 0x76, 0x74, 0x3, 0x2, 0x2, 0x2, 0x76, 0x77, 0x3, 0x2, 
    0x2, 0x2, 0x77, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x78, 0x76, 0x3, 0x2, 0x2, 
    0x2, 0x79, 0x7a, 0x7, 0x11, 0x2, 0x2, 0x7a, 0x1d, 0x3, 0x2, 0x2, 0x2, 
    0x7b, 0x7c, 0x7, 0x10, 0x2, 0x2, 0x7c, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x7d, 
    0x81, 0x7, 0x10, 0x2, 0x2, 0x7e, 0x80, 0x5, 0x22, 0x12, 0x2, 0x7f, 0x7e, 
    0x3, 0x2, 0x2, 0x2, 0x80, 0x83, 0x3, 0x2, 0x2, 0x2, 0x81, 0x7f, 0x3, 
    0x2, 0x2, 0x2, 0x81, 0x82, 0x3, 0x2, 0x2, 0x2, 0x82, 0x21, 0x3, 0x2, 
    0x2, 0x2, 0x83, 0x81, 0x3, 0x2, 0x2, 0x2, 0x84, 0x85, 0x7, 0x4, 0x2, 
    0x2, 0x85, 0x86, 0x5, 0x24, 0x13, 0x2, 0x86, 0x87, 0x7, 0x5, 0x2, 0x2, 
    0x87, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x88, 0x89, 0x7, 0x6, 0x2, 0x2, 0x89, 
    0x8b, 0x5, 0x28, 0x15, 0x2, 0x8a, 0x84, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x88, 
    0x3, 0x2, 0x2, 0x2, 0x8b, 0x23, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x91, 0x5, 
    0x26, 0x14, 0x2, 0x8d, 0x8e, 0x7, 0x3, 0x2, 0x2, 0x8e, 0x90, 0x5, 0x26, 
    0x14, 0x2, 0x8f, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x90, 0x93, 0x3, 0x2, 0x2, 
    0x2, 0x91, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x91, 0x92, 0x3, 0x2, 0x2, 0x2, 
    0x92, 0x25, 0x3, 0x2, 0x2, 0x2, 0x93, 0x91, 0x3, 0x2, 0x2, 0x2, 0x94, 
    0x95, 0x7, 0x11, 0x2, 0x2, 0x95, 0x27, 0x3, 0x2, 0x2, 0x2, 0x96, 0x97, 
    0x7, 0x10, 0x2, 0x2, 0x97, 0x29, 0x3, 0x2, 0x2, 0x2, 0xf, 0x33, 0x3b, 
    0x42, 0x53, 0x5d, 0x62, 0x67, 0x6c, 0x71, 0x76, 0x81, 0x8a, 0x91, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

CommanderParser::Initializer CommanderParser::_init;
