#include "FunctionAST.hpp"
#include "../llvmIRGen/IRCodegen.hh"

namespace TGC {

	Function* PrototypeAST::accept(IRCodegen* v)
	{
		return v->genIR(this);
	}

	Function* FunctionAST::accept(IRCodegen* v)
	{
		return v->genIR(this);
	}
}