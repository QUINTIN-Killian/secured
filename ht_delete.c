/*
** EPITECH PROJECT, 2024
** B-CPE-110-LYN-1-1-secured-elie.chardin
** File description:
** delete an element
** ht_delete
*/

#include "include/hashtable.h"
#include "include/my.h"

static int explore_linked_list(linked_list_t *node, int rm_key)
{
    while (node != NULL) {
        if (node->hashed_value == rm_key) {
            node->hashed_value = -1;
            free(node->path);
            return 1;
        }
        node = node->next;
    }
    return 0;
}

int ht_delete(hashtable_t *ht, char *key)
{
    linked_list_t *node;
    int rm_key;

    if (key == NULL || my_strlen(key) == 0 || ht == NULL)
        return 84;
    rm_key = ht->hash(key, ht->len);
    for (int i = 0; i < ht->len; i++) {
        node = ht->linked_list[i];
        if (explore_linked_list(node, rm_key))
            return 0;
    }
    return 84;
}
