#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void swap(char *a, char *b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp;
}
void print_str(char *str, int len)
{
    write (1, str, len);
    write(1, "\n", 1);
}
void sort_str(char *str)
{
    int i = 0;
    int j;
    while (str[i])
    {
        j = i + 1;
        while (str[j])
        {
            if (str[i] > str[j])
                swap(&str[i] , &str[j]);
            j++;
        }
        i++;
    }
}
void perm(char *str, int start, int len)
{
    if (start == len)
        return print_str(str, len);
    int i = start;
    while(i < len)
    {
        sort_str(&str[start]);
        swap(&str[start], &str[i]);
        perm(str, start + 1, len);
        swap(&str[start], &str[i]);
        i++;
    }
}
int main (int argc, char **argv)
{
    if (argc != 2)
        return 0;
    char *str =  strdup(argv[1]);
    sort_str(str);
    perm(str, 0, strlen(str));
    free(str);
    return 0;
}