/*
** EPITECH PROJECT, 2022
** my_strcmp
** File description:
** Behavior of the strcmp function
*/

int my_strcmp(char const *s1, char const *s2)
{
        int i = 1;
        while ((s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0'))
                i = i + 1;
        return (s1[i] - s2[i]);
}
