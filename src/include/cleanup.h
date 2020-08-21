#ifndef CLEANUP_H
#define CLEANUP_H
#include "lexer.h"
#include "parser.h"
#include "runtime.h"


void ys_cleanup(
    ys_lexer_T* ys_lexer,
    ys_parser_T* parser,
    runtime_T* runtime,
    AST_T* node
);
#endif
