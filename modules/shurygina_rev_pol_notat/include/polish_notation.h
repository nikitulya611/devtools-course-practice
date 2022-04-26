// Copyright 2022 Shurygina A

#ifndef  MODULES_SHURYGINA_REV_POL_NOTAT_INCLUDE_POLISH_NOTATION_H_
#define  MODULES_SHURYGINA_REV_POL_NOTAT_INCLUDE_POLISH_NOTATION_H_

#include <string>
#include "include/lexem.h"
#include "include/stack.h"

class PolishNotation {
 public:
    bool ifNumber(char c);
    int priority(Lexem tmp);
    TQueue<Lexem*>* separatExpressionOnLexems(std::string _s);
    std::string revPolNot(TQueue<Lexem*>* q);
};
#endif  //  MODULES_SHURYGINA_REV_POL_NOTAT_INCLUDE_POLISH_NOTATION_H_

