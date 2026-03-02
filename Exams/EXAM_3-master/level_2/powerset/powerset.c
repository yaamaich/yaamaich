#include <stdio.h>
#include <stdlib.h>


int        calcule(int *nums, int n)
{
    int    sum = 0;
    for (int i = 0; i < n; i++)
        sum += nums[i];
    return sum;
}

void display(int *nums, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf ("%d", nums[i]);
        if (i < len - 1)
            printf (" ");
    }
    printf ("\n");
}

void    SumSubset(int *nums, int n, int target, int *subset, int sub_size, int level)
{
    if (n == level)
    {
        if (calcule(subset, sub_size) == target)
            display(subset, sub_size);
        return ;
    }

    subset[sub_size] = nums[level];
    SumSubset(nums, n, target, subset, sub_size + 1, level + 1);
    SumSubset(nums, n, target, subset, sub_size, level + 1);
}

int main(int ac, char **av)
{
    if (ac < 3)    
        return 1;

    int target = atoi(av[1]);
    int size = ac - 2;

        int *nums = (int *)malloc(sizeof(int) * size);
        for (int i = 0; i < size; i++)
            nums[i] = atoi(av[i + 2]);
        
        int *subset = (int *)malloc(sizeof(int) * size);

    SumSubset(nums, size, target, subset, 0, 0);

    return 0;
}