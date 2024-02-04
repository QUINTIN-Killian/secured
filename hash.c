/*
** EPITECH PROJECT, 2024
** secured
** File description:
** hash
** hash
*/

#include "include/my.h"

int calc(char *nbr, int len)
{
    int ans = 0;
    int ind_end = my_strlen(nbr) - 1;

    for (int i = 0; i < my_strlen(nbr); i++) {
        ans += my_compute_power_rec(nbr[i] - 48, nbr[ind_end] - 48) +
        my_compute_power_rec(nbr[i] - 48, 9);
        ind_end--;
    }
    ans = ans / len;
    if (ans < 0)
        ans *= -1;
    free(nbr);
    return ans;
}

int hash(char *key, int len)
{
    char *ans = malloc(sizeof(char));
    char *str1;
    char *str2;

    ans[0] = '\0';
    for (int i = 0; i < my_strlen(key); i++) {
        str1 = my_strdup(ans);
        str2 = convert_int_to_str(key[i]);
        free(ans);
        ans = concat_2_str(str1, str2);
        free(str1);
        free(str2);
    }
    return calc(ans, len);
}
