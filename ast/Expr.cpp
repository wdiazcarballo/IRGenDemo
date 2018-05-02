#include "Expr.hpp"
#include "ASTStmtReader.hpp"
#include "../llvmIRGen/IRCodegen.hh"
#include <iostream>

namespace TGC {
	Expr::~Expr()
	{
	}
	Value* Expr::accept(IRCodegen* v)
	{
		return v->genIR(this);
	}

	BinaryOperator::~BinaryOperator()
	{
		std::cout << "BinaryOp Destructor\n";
		delete(lhs);
		delete(rhs);
		lhs = rhs = nullptr;
	}

	BinaryOperator::BinaryOperator(Expr* l, Expr* r, Opcode o)
		:lhs(l), rhs(r), opc(o)
	{

	}
	void BinaryOperator::accept(ASTStmtReader* v)
	{
		v->visit(this);
	}

	Value* BinaryOperator::accept(IRCodegen* v)
	{
		return v->genIR(this);
	}
	IntegerLiteral::IntegerLiteral(int value): val(value) 
	{
		setType(INT);
	}
	IntegerLiteral::~IntegerLiteral()
	{
	}

	void IntegerLiteral::accept(ASTStmtReader* v)
	{
		v->visit(this);
	}

	Value* IntegerLiteral::accept(IRCodegen* v)
	{
		return v->genIR(this);
	}
}