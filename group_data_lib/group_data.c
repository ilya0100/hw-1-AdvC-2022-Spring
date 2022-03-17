#include "group_data.h"


int add_data(List *list, FILE *stream) {
    if (!list || !stream) {
        return -1;
    }

    ComputerInfo info = {0};

    if (read_comuter_info(&info, stream)) {
        free_string(&info.brand);
        return -1;
    }

    Node *temp = find_element(list, info.brand);

    if (temp && temp != list->tail) {
        if (insert_element(temp, &info)) {
            free_string(&info.brand);
            return -1;
        }
        ++list->size;
    } else {
        if (push_back(list, &info)) {
            free_string(&info.brand);
            return -1;
        }
    }
    return 0;
}

void print_grouped_data(const List *list) {
    if (!list) {
        return;
    }
    Node *node = list->head;

    printf("%25s%15s%15s%15s\n", "Brand", "Cores count", "Clock speed", "RAM");
    while (node) {
        printf("%25s%15d%11.1f GHz%13d G\n",
            node->computer_info.brand.data, node->computer_info.cores_count, node->computer_info.clock_speed,
            node->computer_info.ram_amount);
        node = node->next;
    }
    printf("\n");
}

int group_data(List *list, FILE *stream) {
    int n;
    if (fscanf(stream, "%d", &n) != 1) {
        return -1;
    }

    for (int i = 0; i < n; ++i) {
        if (add_data(list, stream)) {
            clear_list(list);
            return -1;
        }
    }
    print_grouped_data(list);
    return 0;
}
