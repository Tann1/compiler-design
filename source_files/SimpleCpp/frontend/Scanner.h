/**
 * Scanner class for a simple interpreter.
 *
 * (c) 2020 by Ronald Mak
 * Department of Computer Science
 * San Jose State University
 */
#ifndef SCANNER_H_
#define SCANNER_H_

#include "Source.h"
#include "Token.h"

namespace frontend {

using namespace std;

class Scanner
{
private:
    Source *source;

public:
    /**
     * Constructor.
     * @param source the input source.
     */
    Scanner(Source *source) : source(source) {}

    /**
     * Extract the next token from the source.
     * @return the token.
     */
    Token *nextToken()
    {
        char ch = source->currentChar();
        bool needsPair = false;

        // Skip blanks and other whitespace characters.

        //while (isspace(ch)) ch = source->nextChar();
        #if 1
        while (isspace(ch) || ch == '{' || needsPair) {
            if (ch == '{')
                needsPair = true;
            else if (ch == '}')
                needsPair = false;

            ch = source->nextChar();

        }
        #endif

        if (isalpha(ch))      return Token::Word(ch, source);
        else if (isdigit(ch)) return Token::Number(ch, source);
        else if (ch == '\'')  return Token::Character_or_String(ch, source);
        else                  return Token::SpecialSymbol(ch, source);
        
    }
};

}  // namespace frontend

#endif /* SCANNER_H_ */
