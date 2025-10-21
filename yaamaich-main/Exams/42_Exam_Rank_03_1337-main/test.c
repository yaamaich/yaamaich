#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    char *ptr = malloc(12 * sizeof(char));
    if (!ptr) return 1;

    scanf("name : %11s", ptr);
    printf("You entered: %s\n", ptr);
    return 0;
}