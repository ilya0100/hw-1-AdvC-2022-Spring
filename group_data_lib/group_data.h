#ifndef GROUP_DATA_LIB_GROUP_DATA_H_
#define GROUP_DATA_LIB_GROUP_DATA_H_

#include "list_t.h"


int add_data(List *list, FILE *stream);
void print_grouped_data(const List *list);
int group_data(List *list, FILE *stream);

#endif  // GROUP_DATA_LIB_GROUP_DATA_H_
