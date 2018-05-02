#pragma once
#include "Expr.hpp"
#include "llvm/IR/Function.h"
#include <string>
#include <vector>
#include <memory>

using namespace llvm;
namespace TGC {

	class PrototypeAST {
		friend IRCodegen;
		std::string Name;
		std::vector<std::string> Args;

	public:
		PrototypeAST(const std::string &Name, std::vector<std::string> Args)
			: Name(Name), Args(std::move(Args)) {}

		const std::string &getName() const { return Name; }

		Function* accept(IRCodegen* v);
	};

	class FunctionAST
	{
		friend IRCodegen;
		std::unique_ptr<PrototypeAST> Proto;
		std::unique_ptr<Expr> Body;

	public:
		FunctionAST(std::unique_ptr<PrototypeAST> Proto,
			std::unique_ptr<Expr> Body)
			: Proto(std::move(Proto)), Body(std::move(Body)) {}
		
		Function* accept(IRCodegen* v);
	};

}

