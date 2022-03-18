#ifndef GROUP_DATA_LIB_LIST_T_H_
#define GROUP_DATA_LIB_LIST_T_H_

#include "string_t.h"


typedef struct {
    String brand;
    int cores_count;
    float clock_speed;
    int ram_amount;
} ComputerInfo;

typedef struct Node {
    ComputerInfo computer_info;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    Node *tail;
    size_t size;
} List;


int read_comuter_info(ComputerInfo *comp_info, FILE *stream);

int push_back(List *list, const ComputerInfo *comp_info);
int insert_element(Node *node, const ComputerInfo *comp_info);

Node *find_element(const List *list, const String str);

void clear_list(List *list);

#endif  // GROUP_DATA_LIB_LIST_T_H_
