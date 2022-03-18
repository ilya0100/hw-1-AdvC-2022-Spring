#include "utils.hpp"


bool listcmp(const List &list_l, const List &list_r) {
    if (list_l.size != list_r.size) {
        return false;
    }
    
    Node *node_l = list_l.head;
    Node *node_r = list_r.head;

    while (node_l && node_r) {
        if (strcmp(node_l->computer_info.brand.data, node_r->computer_info.brand.data) != 0) {
            return false;
        }
        if (node_l->computer_info.clock_speed != node_r->computer_info.clock_speed) {
            return false;
        }
        if (node_l->computer_info.cores_count != node_r->computer_info.cores_count) {
            return false;
        }
        if (node_l->computer_info.ram_amount != node_r->computer_info.ram_amount) {
            return false;
        }

        node_l = node_l->next;
        node_r = node_r->next;
    }
    return true;
}
