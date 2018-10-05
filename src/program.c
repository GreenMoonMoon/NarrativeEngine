#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void testMalloc(int);
void generateState();
void testVarArg(int* arr, int count, ...);

int main()
{
    printf("Narrative Engine\n");
    return 0;
}

void testVarArg(int * arr, int count, ...)
{
    va_list args;
    int arrayOfInt[count]; // Static data

    va_start(args, count);
    int i;
    for(i=0;i<count;i++){
        arrayOfInt[i] = va_arg(args, int);
    }
    va_end(args);

    arr = arrayOfInt; // cannot return an array this way
}

void testMalloc(int size)
{
    int *darray = (int *)malloc(size * sizeof(int));
    if (darray == NULL)
    {
        /*Always check for allocation failure, since allocation is not garenteed*/
        printf("malloc failed");
        exit(1);
    }
    size_t darray_size = size * sizeof(int);
    int array[10];
    printf("size of 10 int array: %d\n", (int)sizeof(array));
    printf("supposed size of %d int array: %d\n", (int)size, darray_size);
    printf("size of darray: %d\n", (int)sizeof(darray));
    printf("size of int: %d\n", (int)sizeof(int));

    int i;
    for (i = 0; i < size; i++)
    {
        darray[i] = i;
    }
    printf("%d\n", darray[10]);
    darray = realloc(darray, 11);
    printf("%d\n", darray[10]);
    free(darray);
}