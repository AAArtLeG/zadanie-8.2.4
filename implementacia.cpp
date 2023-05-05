#include <stdio.h>
#include<stdlib.h>
#include <windows.h>
#include<time.h>

typedef struct {
    unsigned int size_d;
    unsigned int size_cod;
    char is_perm;
    int* map;
}NUMAP;

typedef struct {
    unsigned int size;
    unsigned int* seq;
}SEQ;

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

char numap_id(NUMAP* to_redef, unsigned int size)
{
    to_redef->size_d = size;
    to_redef->size_cod = size;
    to_redef->map = (int*)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++)
    {
        to_redef->map[i] = i;
    }
    return('S');
}

void numap_print(NUMAP* f)
{
    for (int i = 0; i < f->size_d; f++)
    {
        printf("%d %f\n", i, f->map[i]);
    }
}



int main()
{
    
}


