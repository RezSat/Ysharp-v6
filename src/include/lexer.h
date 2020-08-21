#ifndef LEXER_H
#define LEXER_H
#include "token.h"
#include <stdlib.h>


typedef struct YS_LEXER_STRUCT
{
    char* contents;
    size_t contents_length;

    char current_char;
    unsigned int char_index;
    unsigned int line_n;
} ys_lexer_T;

ys_lexer_T* init_ys_lexer(char* contents);

void ys_lexer_free(ys_lexer_T* ys_lexer);

token_T* ys_lexer_get_next_token(ys_lexer_T* ys_lexer);

token_T* ys_lexer_advance_with_token(ys_lexer_T* ys_lexer, int type);

void ys_lexer_advance(ys_lexer_T* ys_lexer);

void ys_lexer_expect_char(ys_lexer_T* ys_lexer, char c);

void ys_lexer_skip_whitespace(ys_lexer_T* ys_lexer);

void ys_lexer_skip_inline_comment(ys_lexer_T* ys_lexer);

void ys_lexer_skip_block_comment(ys_lexer_T* ys_lexer);

token_T* ys_lexer_collect_string(ys_lexer_T* ys_lexer);

token_T* ys_lexer_collect_char(ys_lexer_T* ys_lexer);

token_T* ys_lexer_collect_number(ys_lexer_T* ys_lexer);

token_T* ys_lexer_collect_id(ys_lexer_T* ys_lexer);

char* ys_lexer_current_charstr(ys_lexer_T* ys_lexer);
#endif
