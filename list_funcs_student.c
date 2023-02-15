#include <stdlib.h>
#include "linked_list.h"

int list_find_student(list_t *list, int value) {
    int i = 0;
    node_t *current = list->head;
    while (current != NULL){
        if(current->value == value){
          return i;
        }
        i++;
        current = current->next;
    }
    return -1;
}
