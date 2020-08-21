#include "include/AST.h"
#include "include/dynamic_list.h"
#include "include/runtime.h"


AST_T* getpi(runtime_T* runtime, AST_T* self, dynamic_list_T* args)
{
    AST_T* float_ast = init_ast(AST_FLOAT);
    float_ast->float_value = 3.14;

    return float_ast;
}