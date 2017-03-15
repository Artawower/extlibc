#include <stdlib.h>
#include <stdio.h>
#include "../include/list.h"

int main()
{
    list my_list;
    list_init(&my_list);

    uint32_t *a = (uint32_t *)malloc(sizeof(uint32_t));
    *a = 123;

    if (list_push(&my_list, a) != RESULT_OK)
        printf("Error!\n");
    else
        printf( "%u\n", *(uint32_t *)(list_get(&my_list, 0)->data) );

    return 0;
}
