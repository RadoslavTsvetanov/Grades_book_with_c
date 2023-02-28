#include <stdio.h>
#include <stdlib.h>
#define SUCCESS 0
#define TOO_SHORT 1
#define FAILED_MALLOC 2
int main(void)
{
    int size;

    while (1)
    {
        printf("number of grades:");
        scanf("%d", &size);
        if (size > 0)
        {
            break;
        }
    }
    double *ptr = malloc(size * (sizeof(double)));
    if (ptr == NULL)
    {
        printf("Error: malloc failed");
        free(ptr);
        exit(FAILED_MALLOC);
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            scanf("%lf", ptr + i);
        }
        int choice = 0;
        printf("average - 1,add - 2,remove - 3,exit - 4:\n");
        while (1)
        {
            printf("choice:");
            scanf("%d", &choice);
            if (choice == 1)
            {
                double avg = 0;
                for (int i = 0; i < size; i++)
                {
                    avg += ptr[i];
                }
                printf("avg:%lf ", (avg / size));
            }
            else if (choice == 2)
            {

                size += 1;
                ptr = realloc(ptr, (size) * sizeof(double));
                printf("new grade:");
                scanf("%lf", ptr + size - 1);
            }
            else if (choice == 3)
            {
                if (size > 1)
                {
                    size -= 1;
                    ptr = realloc(ptr, (size) * sizeof(double));
                }
                else
                {
                    printf("can not remove grade if the number is below 2");
                }
            }
            else
            {
                free(ptr);
                exit(SUCCESS);
            }
        }
    }
}