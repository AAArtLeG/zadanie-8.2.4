#include "numap.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

NUMAP* numap_create_empty()
{
    NUMAP* a = (NUMAP*)malloc(sizeof(NUMAP));
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

NUMAP* numap_id(NUMAP* to_redef, unsigned int size)
{
    to_redef->size_d = size;
    to_redef->size_cod = size;
    to_redef->map = (int*)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++)
    {
        to_redef->map[i] = i;
    }
    return(to_redef);
}

NUMAP* create_zob(NUMAP* f, unsigned int size)
{
    f->size_d = size;
    f->size_cod = 3 * size;
    for (int i = 0; i < f->size_d; i++)
    {
        f->map[i] = 2 * i + 1;
    }
    return(f);
}

void numap_print(NUMAP* f)
{
    for (int i = 0; i < f->size_d; i++)
    {
        printf("%d ", f->map[i]);
    }
    printf("\n");
}

bool search(int* a, int x, int size)
{
    int f = 0;
    int l = size - 1;
    while (f <= l) {
        int mid = l + (f - l) / 2;
        if (x == a[mid])
            return true;
        if (x > a[mid])
            f = mid + 1;
        if (x < a[mid])
            l = mid - 1;
    }
    return false;
}

int* push_back(int* arr, unsigned int* size_arr, int* add, unsigned int* size_add)
{
    if (*size_arr == 0)
    {
        arr = (int*)malloc((*size_add) * sizeof(int));
        for (int i = 0; i < (*size_add); i++) {
            arr[i] = add[i];
        }
        *size_arr = *size_add;
        return arr;
    }
    int* temp = (int*)malloc((*size_arr) * sizeof(int));
    for (int i = 0; i < (*size_add); i++) {
        temp[i] = arr[i];
    }
    *size_arr = *size_arr + *size_add;
    if (temp == NULL) {
        return NULL;
    }
    free(arr);
    arr = (int*)malloc((*size_arr) * sizeof(int));
    if (arr == NULL) {
        free(temp);
        return NULL;
    }
    for (int i = 0; i < (*size_arr - *size_add); i++)
    {
        arr[i] = temp[i];
    }
    for (int i = (*size_arr - *size_add); i < *size_arr; i++)
    {
        arr[i] = add[i - (*size_arr - *size_add)];
    }
    free(temp);
    return(arr);
}

char numap_rand_perm_cycle_type(NUMAP* to_redef, SEQ* cycle_type)
{
    numap_print(to_redef);
    unsigned int size = 0;
    int* cycle = NULL;
    for (int i = 0; i < cycle_type->size; i++) {
        int temp = cycle_type->seq[i];
        int* a = (int*)malloc(sizeof(int) * temp);
        unsigned int size_new = 0;
        printf("\n\n\n a");
        for (int j = 0; j < temp; j++) {
            int x = rand() % (to_redef->size_d);
            printf("%d ", x);
            if (j == 0) {
                a[0] = x;
                size_new++;
                continue;
            }
            while (true) {
                if (search(a, x, size_new))
                    x = rand() % (to_redef->size_d);
                else
                    break;

            }
            a[j] = x;
            size_new++;
            //numap_print(to_redef);
        }
        printf("\n");
        int* b = (int*)malloc(sizeof(int) * temp);
        for (int j = 0; j < temp; j++) {
            if ((j + 1) != size_new) {
                b[j] = to_redef->map[a[j + 1]];
            }
            else {
                b[j] = to_redef->map[a[0]];
            }
        }
        printf("\n b");
        for (int j = 0; j < temp; j++) {
            printf("%d ", b[j]);
        }
        printf("\n");
        /*for (int j = 0; j < temp; j++) {
            to_redef->map[a[j]] = b[j];
        }*/
        cycle = push_back(cycle, &size, b, &size_new);
        printf("\n cycle ");
        for (int i = 0; i < size; i++) {
            printf("%d ", cycle[i]);
        }
        printf("\n\n\n");
        //numap_print(to_redef);
        free(a);
        free(b);
    }
    /*NUMAP* a = numap_create_empty();
    to_redef->map = cycle;
    to_redef->size_d = size;
    printf("\n map");*/
    //numap_print(to_redef);
    to_redef->map = cycle;
    to_redef->size_d = size;
    return 0; 
}