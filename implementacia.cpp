#include "numap.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));
    NUMAP* test = numap_create_empty();
    unsigned int size = 10;
    test = numap_id(test, size);
    //numap_print(test);
    test = create_zob(test, size);
    numap_print(test);
    //numap_destroy(test);
    SEQ* a = (SEQ*)malloc(sizeof(SEQ));
    a->size = 2;
    a->seq = (unsigned int*)malloc(sizeof(int) * a->size);
    a->seq[0] = 4;
    a->seq[1] = 5;
    //printf("%d\n", a->seq[0]);
    //printf("size = %d\n", test->size_d);
    numap_rand_perm_cycle_type(test, a);
    printf("\n\n\n");
    numap_print(test);
}


