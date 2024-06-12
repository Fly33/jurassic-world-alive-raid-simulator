#ifndef __EXPRESSION__H__
#define __EXPRESSION__H__

#include <string>
#include <memory>
#include "dino.h"
#include "pack.h"

class Expression
{
public:
    Expression()
    {}
    virtual ~Expression() {}
    virtual bool IsMalformed() const { return false; }
    virtual int Calc(const Dino team[], int team_size) const = 0;
    virtual std::unique_ptr<Expression> Copy() const = 0;
    virtual std::string ToString() const = 0;
};

class MalformedExpression : public Expression
{
    std::string message;
public:
    MalformedExpression(const std::string &_message)
        : message(_message)
    {}
    virtual ~MalformedExpression()
    {}
    virtual bool IsMalformed() const override { return true; }
    virtual int Calc(const Dino team[], int team_size) const override;
    virtual std::unique_ptr<Expression> Copy() const override;
    virtual std::string ToString() const override;
};

class Binary : public Expression
{
    std::unique_ptr<Expression> op1, op2;
    int operation;
public:
    Binary(std::unique_ptr<Expression> &&_op1, std::unique_ptr<Expression> &&_op2, int _operation)
        : op1(std::move(_op1))
        , op2(std::move(_op2))
        , operation(_operation)
    {}
    virtual int Calc(const Dino team[], int team_size) const override;
    virtual std::unique_ptr<Expression> Copy() const override;
    virtual std::string ToString() const override;
};

class Unary : public Expression
{
    std::unique_ptr<Expression> op;
    int operation;
public:
    Unary(std::unique_ptr<Expression> &&_op, int _operation)
        : op(std::move(_op))
        , operation(_operation)
    {}
    virtual int Calc(const Dino team[], int team_size) const override;
    virtual std::unique_ptr<Expression> Copy() const override;
    virtual std::string ToString() const override;
};

class Const : public Expression
{
    int value;
public:
    Const(int _value)
        : value(_value)
    {}
    virtual int Calc(const Dino team[], int team_size) const override;
    virtual std::unique_ptr<Expression> Copy() const override;
    virtual std::string ToString() const override;
};

class Property : public Expression
{
    std::string name;
    int index;
public:
    Property(const std::string &_name, int _index)
        : name(_name)
        , index(_index)
    {}
    virtual int Calc(const Dino team[], int team_size) const override;
    virtual std::unique_ptr<Expression> Copy() const override;
    virtual std::string ToString() const override;
};

inline void SkipWhite(const char *&line)
{
    while (isspace(*line))
        ++line;
}

std::unique_ptr<Expression> ParseExpression(const char *line);

#include "unpack.h"

#endif // __EXPRESSION__H__
