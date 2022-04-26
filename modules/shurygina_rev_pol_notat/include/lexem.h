// Copyright 2022 Shurygina A

#ifndef  MODULES_SHURYGINA_REV_POL_NOTAT_INCLUDE_LEXEM_H_
#define  MODULES_SHURYGINA_REV_POL_NOTAT_INCLUDE_LEXEM_H_

#include <string>

enum Type {
    op, value
};
enum State {
    q0, q1
};

class Lexem {
    std::string s;
    Type t;
    int val;
 public:
    Lexem() {}
    Lexem(std::string _s, Type _t, int _val) {
        s = _s;
        t = _t;
        val = _val;
    }
    Type getType() { return t; }
    int getVal() { return val; }
    std::string getS() { return s; }
};

#endif  //  MODULES_SHURYGINA_REV_POL_NOTAT_INCLUDE_LEXEM_H_


