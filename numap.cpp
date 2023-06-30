#include "numap.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

NUMAP* numap_create_empty()
{
    NUMAP* a = (NUMAP*)malloc(sizeof(NUMAP));
    if (a == NULL) {
        return NULL;
    }
    a->map = NULL;
    a->size_cod = 0;
    a->size_d = 0;
    a->is_perm = 0;
    return(a);
}

void numap_destroy(NUMAP* to_destroy)
{
    free(to_destroy->map);
    free(to_destroy);
}

char numap_id(NUMAP* to_redef, unsigned int size)
{
    free(to_redef->map);
    to_redef->size_d = size;
    to_redef->size_cod = size;
    to_redef->map = (int*)malloc(sizeof(int) * size);
    if (to_redef->map == NULL)
        return NUMAP_FAIL;
    for (int i = 0; i < size; i++)
        to_redef->map[i] = i;
    return NUMAP_SUCCESS;
}

NUMAP* create_zob(NUMAP* f, unsigned int size)
{
    free(f->map);
    f->size_d = size;
    f->size_cod = 3 * size;
    f->map = (int*)malloc(sizeof(int) * size);
    if (f->map == NULL)
        return NULL;
    for (int i = 0; i < f->size_d; i++)
    {
        f->map[i] = rand() % (3 * size);
    }
    return(f);
}

void numap_print(NUMAP* f)
{
    for (int i = 0; i < f->size_d; i++)
        printf("%d ", f->map[i]);
    printf("\n");
}

int* push_back(int* arr, unsigned int* size_arr, int* add, unsigned int* size_add)
{
    if (*size_arr == 0)
    {
        arr = (int*)malloc((*size_add) * sizeof(int));
        if (arr == NULL)
            return NULL;
        for (int i = 0; i < (*size_add); i++)
            arr[i] = add[i];
        *size_arr = *size_add;
        return arr;
    }
    int* temp = (int*)malloc((*size_arr) * sizeof(int));
    if (temp == NULL)
        return NULL;

    for (int i = 0; i < (*size_arr); i++)
        temp[i] = arr[i];

    *size_arr = *size_arr + *size_add;
    free(arr);
    arr = (int*)malloc((*size_arr) * sizeof(int));
    if (arr == NULL) {
        free(temp);
        return NULL;
    }
    for (int i = 0; i < (*size_arr - *size_add); i++)
        arr[i] = temp[i];

    for (int i = (*size_arr - *size_add); i < *size_arr; i++)
        arr[i] = add[i - (*size_arr - *size_add)];
 
    free(temp);
    return(arr);
}

bool search(int* a, int size, int x)
{
    for (int i = 0; i < size; i++) {
        if (a[i] == x)
            return true;
    }
    return false;
}

char numap_rand_perm_cycle_type(NUMAP* to_redef, SEQ* cycle_type)
{
    unsigned int size = 0;
    int* cycle = NULL;
    for (int i = 0; i < cycle_type->size; i++) {
        int temp = cycle_type->seq[i];
        int* a = (int*)malloc(sizeof(int) * temp);
        if (a == NULL) {
            to_redef->size_d = 0;
            to_redef->map = NULL;
            return NUMAP_FAIL;
        }
        unsigned int size_new = 0;
        for (int j = 0; j < temp; j++) {
            a[j] = size + j;
            size_new++;
        }
        int* b = (int*)malloc(sizeof(int) * temp);
        if (b == NULL) {
            free(a);
            to_redef->size_d = 0;
            to_redef->map = NULL;
            return NUMAP_FAIL;
        }
        int x = rand() % temp;
        //printf("\n%d\n", x);
        for (int j = 0; j < temp; j++) {
            if ((j + x) >= temp)
                b[j] = a[j + x - temp];
            else 
                b[j] = a[j + x];
        }
        cycle = push_back(cycle, &size, b, &size_new);
        if (cycle == NULL) {
            free(a);
            free(b);
            to_redef->size_d = 0;
            to_redef->map = NULL;
            return NUMAP_FAIL;
        }
        free(a);
        free(b);
    }
    to_redef->map = cycle;
    to_redef->size_d = size;
    to_redef->size_cod = size;
    return NUMAP_SUCCESS;
}