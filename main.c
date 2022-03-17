#include "group_data.h"


int main() {
    List list = {0};

    group_data(&list, stdin);

    clear_list(&list);
    return 0;
}
