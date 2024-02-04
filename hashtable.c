/*
** EPITECH PROJECT, 2024
** secured
** File description:
** manage a hashtable
** delete_hashtable
*/

#include "include/my.h"
#include "include/hashtable.h"

hashtable_t *new_hashtable(int (*hash)(char *, int), int len)
{
    hashtable_t *ht;

    if (len <= 0)
        return NULL;
    ht = malloc(sizeof(hashtable_t));
    ht->hash = hash;
    ht->len = len;
    ht->linked_list = malloc(sizeof(linked_list_t *) * len);
    for (int i = 0; i < len; i++)
        ht->linked_list[i] = NULL;
    return ht;
}

static void del_node(linked_list_t *node)
{
    if (node->hashed_value != -1)
        free(node->path);
    free(node);
}

void delete_hashtable(hashtable_t *ht)
{
    linked_list_t *node;
    linked_list_t *tmp;

    if (ht == NULL)
        return;
    for (int i = 0; i < ht->len; i++) {
        node = ht->linked_list[i];
        while (node != NULL) {
            tmp = node;
            node = node->next;
            del_node(tmp);
        }
    }
    free(ht->linked_list);
    free(ht);
}
