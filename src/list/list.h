/*!
 * \file list.h
 * \author Nicolas Cossio Miravalles nicocossiom@gmail.com
 * \version 0.1
 * \date 14/10/2022
 * \brief This file contains the definitions of a linked_list structure and its functions.
 * \remarks None
 */

// Copyright (c) 2022 Nicolas Cossio Miravalles
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#ifndef LIST_H
#define LIST_H
#include <stdbool.h>

/**
 *
 * @brief  List node structure.
 * @note   This structure is used to create a node.
 * @param  data: Pointer to the data stored in the node.
 * @param  next: Pointer to the next node.
 * @param  prev: Pointer to the previous node.
 *
 */
typedef struct list_node {
    struct list_node *next;
    struct list_node *prev;
    struct linked_list *containing_list;
    void *data;
} list_node;

/**
 * @brief Linked list structure.
 * @note  This structure is used to create a linked list.
 * @param head: Pointer to the first node of the list.
 * @param tail: Pointer to the last node of the list.
 * @param size: Size of the list.
 */
typedef struct linked_list {
    struct list_node *head;
    struct list_node *last;
    int size;
} linked_list;

/**
 * @brief A structure that store the status of an operation.
 * @param success True if the operation was successful, false otherwise.
 * @param error_message A string that contains the error message.
 */
typedef struct op_status {
    bool success;
    char *error_message;
} op_status;

/**
 * @brief Creates a list with no nodes
 * @note  Node creation will be done with the list_add_node functions and its siblings.
 * @param None
 * @retval Pointer to the created list.
 * @return linked_list*
 */
linked_list *list_create();

/**
 * @brief Creates a linked list with the given data.
 * @note  This function creates a linked list with the given data.
 * @param data Pointer to the data to be stored in the list.
 * @param size_of_data Size each pice of the data which will turn into a node to be stored in the list.
 * @return Pointer to the created list.
 */
linked_list *list_create_from_data(void *data, int size_of_data);

/**
 * @brief Destroys the given list with all its nodes.
 * @param l List to be destroyed.
 * @return An operation status structure. Where "op_status.success" is true if the operation was successful, false otherwise.
 */
op_status list_destroy(linked_list *l);

// insertion
/*         insert element           */
/**
 * @brief Inserts a node at the end of the list
 * @note  This function inserts a node at the end of the list.
 * @param l Pointer to the list.
 * @param data Pointer to the data to be stored in the node
 * @return An operation status structure. Where "op_status.success" is true if the operation was successful, false otherwise.
 */
op_status list_append(linked_list *l, void *data);

/**
 * @brief Inserts a node at the start of the list
 * @note  This function inserts a node at the start of the list.
 * @param l Pointer to the list.
 * @param data Pointer to the data to be stored in the node
 * @return An operation status structure. Where "op_status.success" is true if the operation was successful, false otherwise.
 */
op_status list_prepend(linked_list *l, void *data);

/**
 * @brief Replaces the node at a given position in the list with the given data.
 * NOTE: This function will replace the node at the given position. For displacing the node at the given position, use list_insert_at.
 * @note  This function will replace the node at the given position. For displacing the node at the given position, use list_insert_at.
 * @param l Pointer to the list.
 * @param index Integer that represents the position where the node will be inserted in the list
 * @param data Pointer to the data to be stored in the node
 * @return An operation status structure. Where "op_status.success" is true if the operation was successful, false otherwise.
 */
op_status list_replace_at(linked_list *l, int index, void *data);

/**
 * @brief Inserts a node at a given position in the list. NOTE: this function will displace to the right all nodes including the node at the given position. For replacing the node at the given position, use list_insert_at.
 * @note  This function will displace to the right all nodes including the node at the given position. For replacing the node at the given position, use list_insert_at.
 * @param l Pointer to the list.
 * @param index Integer that represents the position where the node will be inserted in the list
 * @param data Pointer to the data to be stored in the node
 * @return An operation status structure. Where "op_status.success" is true if the operation was successful, false otherwise.
 */
op_status list_insert_at(linked_list *l, int index, void *data);

// remove
/*          remove element          */

/**
 * @brief Pops the node at the end of the list from the list.
 * @param l List from which the node will be popped.
 * @return  A pointer to the data stored in the popped node.
 */
void *list_pop_last(linked_list *l);

op_status list_remove_last(linked_list *l);

/**
 * @brief Pops the node at the given position in the list
 * @param l List from which the node will be popped.
 * @param index Integer that represents the position of the node to be popped.
 */
void *list_pop_at(linked_list *l, int index);

/**
 * @brief Removes the node at the given position in the list. NOTE: this will destroy the node.
 * @param l List from where to remove the node
 * @param index Integer that represents the position of the node to be removed.
 * @return An operation status structure. Where "op_status.success" is true if the operation was successful, false otherwise.
 */
op_status list_remove_at(linked_list *l, int index);

/**
 * @brief Pops the head of the list.
 * @param l List to pop the head from.
 * @return A pointer to the data stored in the popped node.
 */
void *list_pop_head(linked_list *l);

/**
 * @brief Pops the tail of the list.
 * @param l List to pop the head from.
 * @return A pointer to the data stored in the popped node.
 */
void *list_pop_tail(linked_list *l);

/**
 * @brief Removes the node at the head of the list. NOTE: this will destroy the node.
 * @param l List from where to remove the head node
 * @return An operation status structure. Where "op_status.success" is true if the operation was successful, false otherwise.
 */
op_status list_remove_head(linked_list *l);

/**
 * @brief Removes the node at the tail of the list. NOTE: this will destroy the node.
 * @param l List from where to remove the tail node
 * @return An operation status structure. Where "op_status.success" is true if the operation was successful, false otherwise.
 */
op_status list_remove_tail(linked_list *l);

void list_add_list(linked_list *list_to_add_to, linked_list *list_to_add_from);

/**
 * @brief Retrieves the node at the given position in the list.
 * @param l List from where to retrieve the node.
 * @param index Integer that represents the position of the node to be retrieved.
 * @return A pointer to the node at the given position in the list.
 */
void *list_get(linked_list *l, int index);

/**
 * @brief Retrieves the index of the given node in the list.
 *
 * @param l List from where to retrieve the index.
 * @param node Node whose index is to be retrieved.
 * @return An integer that represents the index of the given node in the list. -1 if the node is not in the list.
 */
int list_get_index(linked_list *l, list_node *node);

/**
 * @brief Copies the given list returning a duplicate list.
 * NOTE: This is not a shallow copy, meaning new memory will be allocated.
 * @param l List to be copied.
 * @return A pointer to the copied list.
 */
linked_list *list_copy(linked_list *l);

/**
 * @brief Does the union of the given list, comparing the data inside the nodes.
 * NOTE: This is not a shallow copy, meaning new memory will be allocated.
 * @param l1 List to be united
 * @param l2 List to be united
 * @return A pointer to the union of the lists.
 */
linked_list *list_union(linked_list *l1, linked_list *l2);

/**
 * @brief Does the intersection of the given list, comparing the data inside the nodes.
 * NOTE: This is not a shallow copy, meaning new memory will be allocated.
 * @param l1 List to be intersected
 * @param l2 List to be intersected
 * @return A pointer to the intersection of the lists.
 */
linked_list *list_intersection(linked_list *l1, linked_list *l2);

/**
 * @brief Does the difference of the given list, comparing the data inside the nodes.
 * The difference operation consists of retrieving the elements from l1 which are not present in l2
 * NOTE: This is not a shallow copy, meaning new memory will be allocated.
 * @param l1 List to be excepted
 * @param l2 List to be excepted
 * @return A pointer to the difference of the lists.
 */
linked_list *list_difference(linked_list *l1, linked_list *l2);

#endif  // LIST_H
