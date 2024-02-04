/*
** EPITECH PROJECT, 2024
** secured
** File description:
** search an element
** ht_search
*/

#include "include/hashtable.h"
#include "include/my.h"

static char *is_src_key(linked_list_t *node, int src_key)
{
    while (node != NULL) {
        if (node->hashed_value == src_key)
            return node->path;
        node = node->next;
    }
    return NULL;
}

char *ht_search(hashtable_t *ht, char *key)
{
    linked_list_t *node;
    int src_key;
    char *ans;

    if (key == NULL || my_strlen(key) == 0 || ht == NULL)
        return NULL;
    src_key = ht->hash(key, ht->len);
    for (int i = 0; i < ht->len; i++) {
        node = ht->linked_list[i];
        ans = is_src_key(node, src_key);
        if (ans != NULL)
            return ans;
    }
    return NULL;
}
