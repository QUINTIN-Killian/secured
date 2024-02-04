/*
** EPITECH PROJECT, 2024
** secured
** File description:
** main file where everything starts
** main
*/

#include "../include/my.h"
#include "../include/hashtable.h"

int main(void)
{
    hashtable_t *ht = new_hashtable(&hash, 5);
    char *tmp;

    if (ht == NULL)
        printf("NULL\n");
    printf("%d\n", ht_insert(ht, "Aillian", "test1"));
    printf("%d\n", ht_insert(ht, "Billian", "test2"));
    ht_dump(ht);
    delete_hashtable(ht);
    return 0;
}
