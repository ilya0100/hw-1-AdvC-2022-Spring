#ifndef GROUP_DATA_LIB_STRING_T_H_
#define GROUP_DATA_LIB_STRING_T_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MIN_SIZE 30


typedef struct {
    char *data;
    size_t size;
    size_t capacity;
} String;

void free_string(String *string);
int resize_string(String *string);
int add_char(String *string, const char c);
int read_string(String *string, const char delim, FILE *stream);


#endif  // GROUP_DATA_LIB_STRING_T_H_
