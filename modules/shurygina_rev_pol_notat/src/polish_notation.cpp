// Copyright 2022 Shurygina A

#include <string>
#include <stack>
#include "include/polish_notation.h"
#include "include/lexem.h"
#include "include/stack.h"


// check wheather a charackter is number or not

bool PolishNotation::ifNumber(char c) {
    if ((c >= '0') && (c <= '9'))
        return true;
    if ((c != '+') && (c != '-') && (c != '(')
        && (c != ')') && (c != ' ') && (c != '*') && (c != '/'))
        throw std::string("Can't divide by zero");
    return false;
}

// find out the priority of operations

int PolishNotation::priority(Lexem tmp) {
    if (tmp.getS() == " ")
        return -1;
    if (tmp.getS() == "(" || tmp.getS() == ")")
        return 0;
    if (tmp.getS() == "*" || tmp.getS() == "/")
        return 1;
    else
        return 2;
}

// convert mat expresion into lexems array

TQueue<Lexem*>* PolishNotation::separatExpressionOnLexems(std::string _s) {
    std::string str;
    char c;
    TQueue<Lexem*>* q = new TQueue<Lexem*>;
    State st = q0;
    for (size_t i = 0; i < _s.length(); i++) {
        c = _s[i];
        if (st == q0) {
            str = c;
            if (ifNumber(c))
                st = q1;

            if (!ifNumber(c))
                q->push(new Lexem(str, op, -1));
        } else {
            if (st == q1) {
                if (ifNumber(c))
                    str += c;
                if (!ifNumber(c)) {
                    int val_ = atoi(str.c_str());
                    q->push(new Lexem(str, value, val_));
                    st = q0;
                    str = c;
                    q->push(new Lexem(str, op, -1));
                }
            }
        }
    }
    if (ifNumber(c)) {
        str = c;
        int val_ = atoi(str.c_str());
        q->push(new Lexem(str, value, val_));
    }

    return q;
}

// polish notation method

std::string PolishNotation::revPolNot(TQueue<Lexem*>* l) {
    TQueue<Lexem*>* q = new TQueue<Lexem*>;
    TStack<Lexem*>* stack = new TStack<Lexem*>;
    Lexem* tmp;
    State st = q0;
    int count = 0;
    while (!l->isEmpty()) {
        if (st == q0) {
            tmp = l->pop();
            if (tmp->getS() == "(") {
                stack->push(tmp);
            } else if (tmp->getS() == ")") {
                    st = q1;
                } else if (tmp->getType() == value) {
                    int val_ = atoi(tmp->getS().c_str());
                    q->push(new Lexem(tmp->getS(), value, val_));
                } else if (priority(*tmp) >= 1) {
                    if (stack->isEmpty()) {
                        stack->push(tmp);
                    } else {
                        Lexem* ltmp = stack->pop();
                        while (!stack->isEmpty() && priority(*ltmp)
                            <= priority(*tmp) && priority(*ltmp) != 0) {
                            q->push(new Lexem(ltmp->getS(), op, -1));
                            ltmp = stack->pop();
                            count++;
                        }
                        if (stack->isEmpty()) {
                            if (priority(*ltmp) <= priority(*tmp))
                                q->push(new Lexem(ltmp->getS(), op, -1));
                            else
                                stack->push(ltmp);
                        } else {
                            if (count == 0)
                                stack->push(ltmp);
                        }
                        stack->push(tmp);
                        count = 0;
                    }
                }
        }
        if (st == q1) {
            Lexem* sttmp = stack->pop();

            while (!stack->isEmpty() && sttmp->getS() != "(") {
                q->push(new Lexem(sttmp->getS(), op, -1));
                sttmp = stack->pop();
            }
            st = q0;
        }
    }

    while (!stack->isEmpty())
        q->push(new Lexem(stack->pop()->getS(), op, -1));
    std::string s = "";
    while (!q->isEmpty())
        s += q->pop()->getS();
    delete stack;
    delete q;
    return s;
}
