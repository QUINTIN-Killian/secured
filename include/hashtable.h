/*
** EPITECH PROJECT, 2023
** B-CPE-110 : Secured
** File description:
** header file for the secured project
** hashtable.h
*/

#ifndef HASHTABLE_H
    #define HASHTABLE_H

typedef struct linked_list_s {
    int hashed_value;
    char *path;
    struct linked_list_s *next;
} linked_list_t;

typedef struct hashtable_s {
    int (*hash)(char *, int);
    int len;
    linked_list_t **linked_list;
} hashtable_t;

// Hash function
int hash(char *key, int len);

// Create & destro table
hashtable_t *new_hashtable(int (*hash)(char *, int), int len);
void delete_hashtable(hashtable_t *ht);

// Handle table
int ht_insert(hashtable_t *ht, char *key, char *value);
int ht_delete(hashtable_t *ht, char *key);
char *ht_search(hashtable_t *ht, char *key);
void ht_dump(hashtable_t *ht);

#endif /* HASHTABLE_H */
