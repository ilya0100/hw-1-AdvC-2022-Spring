#include "list_t.h"


int read_comuter_info(ComputerInfo *comp_info, FILE *stream) {
    if (!comp_info || !stream) {
        return -1;
    }

    if (read_string(&comp_info->brand, ' ', stream)) {
        return -1;
    }

    if (fscanf(stream, "%d %f %d", &comp_info->cores_count, &comp_info->clock_speed,
        &comp_info->ram_amount) != 3) {
        return -1;
    }

    return 0;
}

int push_back(List *list, const ComputerInfo *comp_info) {
    if (!list || !comp_info) {
        return -1;
    }

    Node *new_node = malloc(sizeof(Node));
    if (!new_node) {
        return -1;
    }

    new_node->computer_info = *comp_info;
    new_node->next = NULL;

    if (list->size == 0) {
        list->head = list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }
    ++list->size;

    return 0;
}

int insert_element(Node *node, const ComputerInfo *comp_info) {
    if (!node || !comp_info) {
        return -1;
    }

    Node *new_node = malloc(sizeof(Node));
    if (!new_node) {
        return -1;
    }

    new_node->computer_info = *comp_info;
    new_node->next = node->next;
    node->next = new_node;

    return 0;
}

Node *find_element(const List *list, const String str) {
    if (!str.data) {
        return NULL;
    }

    Node *node = list->head;
    while (node) {
        if (strcmp(str.data, node->computer_info.brand.data) == 0) {
            return node;
        } else {
            node = node->next;
        }
    }
    return node;
}

void clear_list(List *list) {
    Node *node = list->head;

    while (node) {
        Node *temp = node;
        node = node->next;
        free_string(&(temp->computer_info.brand));
        free(temp);
    }

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}
