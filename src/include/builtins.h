#ifndef BUILTINS_H
#define BUILTINS_H
#include "AST.h"
#include "runtime.h"

void init_builtins(runtime_T* runtime);

AST_T* ys_builtin_function_write(runtime_T* runtime, AST_T* self, dynamic_list_T* args);

AST_T* ys_builtin_function_stdoutbuffer(runtime_T* runtime, AST_T* self, dynamic_list_T* args);

AST_T* ys_builtin_function_writex(runtime_T* runtime, AST_T* self, dynamic_list_T* args);

AST_T* ys_builtin_function_include(runtime_T* runtime, AST_T* self, dynamic_list_T* args);

AST_T* ys_builtin_function_fopen(runtime_T* runtime, AST_T* self, dynamic_list_T* args);

AST_T* ys_builtin_function_fclose(runtime_T* runtime, AST_T* self, dynamic_list_T* args);

AST_T* ys_builtin_function_fputs(runtime_T* runtime, AST_T* self, dynamic_list_T* args);

AST_T* ys_builtin_function_input(runtime_T* runtime, AST_T* self, dynamic_list_T* args);

AST_T* ys_builtin_function_char_to_bin(runtime_T* runtime, AST_T* self, dynamic_list_T* args);

AST_T* ys_builtin_function_char_to_oct(runtime_T* runtime, AST_T* self, dynamic_list_T* args);

AST_T* ys_builtin_function_char_to_dec(runtime_T* runtime, AST_T* self, dynamic_list_T* args);

AST_T* ys_builtin_function_char_to_hex(runtime_T* runtime, AST_T* self, dynamic_list_T* args);

AST_T* ys_builtin_function_time(runtime_T* runtime, AST_T* self, dynamic_list_T* args);

AST_T* ys_builtin_function_cload(runtime_T* runtime, AST_T* self, dynamic_list_T* args);

AST_T* ys_builtin_function_free(runtime_T* runtime, AST_T* self, dynamic_list_T* args);

AST_T* ys_builtin_function_visit(runtime_T* runtime, AST_T* self, dynamic_list_T* args);

AST_T* ys_builtin_function_strrev(runtime_T* runtime, AST_T* self, dynamic_list_T* args);

AST_T* ys_builtin_function_ssh(runtime_T* runtime, AST_T* self, dynamic_list_T* args);

AST_T* INITIALIZED_NOOP;
#endif
