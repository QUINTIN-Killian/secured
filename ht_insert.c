/*
** EPITECH PROJECT, 2024
** secured
** File description:
** insert a new element
** ht_insert
*/

#include "include/hashtable.h"
#include "include/my.h"

static int is_aldready_present(linked_list_t *node,
    int hashed_value, char *value)
{
    while (node != NULL) {
        if (node->hashed_value == hashed_value) {
            free(node->path);
            node->path = my_strdup(value);
            return 1;
        }
        node = node->next;
    }
    return 0;
}

static void reasign_node(linked_list_t *node, int hashed_value, char *value)
{
    node->hashed_value = hashed_value;
    node->path = my_strdup(value);
}

static linked_list_t *init_node(linked_list_t *node,
    int hashed_value, char *value)
{
    node = malloc(sizeof(linked_list_t));
    node->hashed_value = hashed_value;
    node->path = my_strdup(value);
    return node;
}

static void init_insert_variables(hashtable_t *ht, char *key,
    int *hashed_value, int *ind)
{
    *hashed_value = ht->hash(key, ht->len);
    *ind = *hashed_value % ht->len;
}

int ht_insert(hashtable_t *ht, char *key, char *value)
{
    int hashed_value;
    int ind;
    linked_list_t *node;

    if (key == NULL || my_strlen(key) == 0 || value == NULL ||
    my_strlen(value) == 0 || ht == NULL)
        return 84;
    init_insert_variables(ht, key, &hashed_value, &ind);
    node = ht->linked_list[ind];
    if (is_aldready_present(node, hashed_value, value))
        return 0;
    while (node != NULL && node->hashed_value != -1)
        node = node->next;
    if (node == NULL) {
        node = init_node(node, hashed_value, value);
        node->next = ht->linked_list[ind];
        ht->linked_list[ind] = node;
    } else
        reasign_node(node, hashed_value, value);
    return 0;
}
