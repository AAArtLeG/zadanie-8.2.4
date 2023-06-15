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
        printf("%d %d\n", i, f->map[i]);
    }
}

char numap_rand_perm_cycle_type(NUMAP* to_redef, SEQ* cycle_type)
{
    for (int i = 0; i < cycle_type->size; i++) {
        int temp = cycle_type->seq[i];
        for (int j = 0; j < temp; j++) {
            int a = rand() % to_redef->size_d;
            int b = rand() % to_redef->size_d;
            while (b == a) {
                b = rand() % to_redef->size_d;
            }
            int t = to_redef->map[a];
            to_redef->map[a] = to_redef->map[b];
            to_redef->map[b] = t;
            numap_print(to_redef);
        }
    }
    return 0;
}




int main()
{
    srand(time(0));
    NUMAP* test = numap_create_empty();
    unsigned int size = 5;
    test = numap_id(test, size);
    //numap_print(test);
    test = create_zob(test, size);
    numap_print(test);
    numap_destroy(test);
    SEQ* a = (SEQ*)malloc(sizeof(SEQ));
    a->size = 1;
    a->seq = (unsigned int*)malloc(sizeof(int) * a->size);
    a->seq[0] = 1;
    printf("%d\n", a->seq[0]);
    numap_rand_perm_cycle_type(test, a);
    numap_print(test);
}


