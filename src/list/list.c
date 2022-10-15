

// Copyright (c) 2022 Nicolas Cossio Miravalles
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#include "list.h"

#include <stdlib.h>

linked_list *list_create() {
    linked_list *list = malloc(sizeof(linked_list));
    list->head = NULL;
    list->last = NULL;
    list->size = 0;
    return list;
}

linked_list *list_create_from_data(void *data, int size_of_data);

op_status list_destroy(linked_list *l) {
    op_status status;
    if (l == NULL) {
        status = (op_status){false, "List is NULL"};
    } else {
        list_node *current = l->head;
        while (current != NULL) {
            list_node *next = current->next;
            free(current);
            current = next;
        }
        free(l);
        status = (op_status){true, NULL};
    }
    return status;
}

op_status list_append(linked_list *l, void *data) {
    op_status status;
    if (l == NULL) {
        status = (op_status){false, "List is NULL"};
    } else {
        list_node *new_node = malloc(sizeof(list_node));
        new_node->data = data;
        new_node->next = NULL;
        if (l->last == NULL) {
            // The list is empty
            new_node->prev = NULL;
            l->head = new_node;
            l->last = new_node;

        } else {
            // The list is not empty
            new_node->prev = l->last;
            l->last = new_node;
        }
        status = (op_status){true, NULL};
    }
    return status;
}

op_status list_prepend(linked_list *l, void *data) {
    op_status status;
    if (l == NULL) {
        status = (op_status){false, "List is NULL"};
    } else if (l->head == NULL) {
        // list is empty
        status = list_append(l, data);
    } else {
        list_node *new_node = malloc(sizeof(list_node));
        new_node->data = data;
        new_node->prev = NULL;
        new_node->next = l->head;
        l->head = new_node;
        status = (op_status){true, NULL};
    }
    return status;
}

op_status list_replace_at(linked_list *l, int index, void *data) {
    op_status status;
    if (l == NULL) {
        status = (op_status){false, "List is NULL"};
    } else if (index < 0 || index >= l->size) {
        status = (op_status){false, "Index out of bounds"};
    } else {
        list_node *current = l->head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        current->data = data;
        status = (op_status){true, NULL};
    }
    return status;
}

op_status list_insert_at(linked_list *l, int index, void *data);

void *list_pop_last(linked_list *l) {
    if (l == NULL) {
        return NULL;
    } else if (l->last == NULL) {
        return NULL;
    }
    list_node *node_to_pop = l->last;
    l->last = node_to_pop->prev;
    node_to_pop->prev->next = NULL;
    void *data_to_return = node_to_pop->data;
    free(node_to_pop);
    return data_to_return;
}

op_status list_remove_last(linked_list *l) {
    op_status status;
    void *data = list_pop_last(l);
    if (data == NULL) {
        status = (op_status){false, "List is empty"};
    } else {
        status = (op_status){true, NULL};
        free(data);
    }
    return status;
}

void *list_pop_at(linked_list *l, int index);

op_status list_remove_at(linked_list *l, int index);

void *list_pop_head(linked_list *l);

void *list_pop_tail(linked_list *l);

op_status list_remove_head(linked_list *l);

op_status list_remove_tail(linked_list *l);

void list_add_list(linked_list *list_to_add_to, linked_list *list_to_add_from);

void *list_get(linked_list *l, int index);

int list_get_index(linked_list *l, list_node *node);

linked_list *list_copy(linked_list *l);

linked_list *list_union(linked_list *l1, linked_list *l2);

linked_list *list_intersection(linked_list *l1, linked_list *l2);

linked_list *list_difference(linked_list *l1, linked_list *l2);
