#pragma once
#include "Stmt.hpp"
/*!
*  \addtogroup TGC
*  @{
*/


/*! TGC namespace */
namespace TGC {
	/*! \class Expr
	 A test class */
	class Expr :
		public Stmt
	{
	public:
		Expr() = default;
		virtual ~Expr();
		/** An enum type.
		*  Opcode
		*/
		enum Opcode { ADD, SUB, MUL, DIV };
		/** An enum type.
		*  RType
		*/
		enum RType { VOID, INT, FLOAT };

		void setType(RType t) { etype = t; }
		virtual void accept(ASTStmtReader* v)=0;
		Value* accept(IRCodegen* v);
	protected:
		RType etype = INT;
		int val = 0;
	};
	/*! \class BinaryOperator
	stores an expression written by using a binary operator */
	class BinaryOperator: 
		public Expr
	{
	public:
		BinaryOperator()=default;
		BinaryOperator(Expr* l, Expr* r, Opcode o);
		~BinaryOperator();

		Expr* left() { return lhs; };
		Expr* right() { return rhs; };
		Opcode getOpcode() { return opc; };

		void accept(ASTStmtReader* v);
		Value* accept(IRCodegen* v);
	private:
		Expr* lhs = nullptr;
		Expr* rhs = nullptr;
		Opcode opc;

	};
	/*! A test class */
	class IntegerLiteral:public Expr
	{
	public:
		IntegerLiteral() = default;

		IntegerLiteral(int value);

		~IntegerLiteral();

		void accept(ASTStmtReader* v);
		Value* accept(IRCodegen* v);
		int getVal() {
			return val;
		};
	private:
		int val = 0;
	};

}

/** @}*/