#pragma once
/*!
*  \addtogroup TGC
*  @{
*/
#include "llvm/IR/Value.h"

using namespace llvm;

/*! TGC namespace */
namespace TGC {

	class ASTStmtReader;
	class IRCodegen;

	/*! A test class */
	class Stmt
	{
		friend class ASTStmtReader;
	public:
		Stmt() = default;
		virtual ~Stmt();

		virtual void accept(ASTStmtReader *v) = 0;
		virtual Value* accept(IRCodegen* v) = 0;
	};
}// End namespace TGC
 /** @}*/