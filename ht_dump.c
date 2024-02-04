/*
** EPITECH PROJECT, 2024
** B-CPE-110-LYN-1-1-secured-elie.chardin
** File description:
** display the hashtable
** ht_dump
*/

#include "include/hashtable.h"
#include "include/my.h"

static void print_nodes(linked_list_t *node)
{
    while (node != NULL) {
        if (node->hashed_value != -1) {
            my_putstr("> ");
            my_put_nbr(node->hashed_value);
            my_putstr(" - ");
            my_putstr(node->path);
            my_putchar('\n');
        }
        node = node->next;
    }
}

void ht_dump(hashtable_t *ht)
{
    linked_list_t *node;

    if (ht == NULL)
        return;
    for (int i = 0; i < ht->len; i++) {
        my_putstr("[");
        my_put_nbr(i);
        my_putstr("]:\n");
        node = ht->linked_list[i];
        print_nodes(node);
    }
}
