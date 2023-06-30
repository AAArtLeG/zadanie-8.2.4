#include "numap.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));
    NUMAP* test = numap_create_empty();
    unsigned int size = 20;
    char t = numap_id(test, size);
    if (t == NUMAP_FAIL) {
        return -1;
    }
    numap_print(test);
    SEQ* a = (SEQ*)malloc(sizeof(SEQ));
    a->size = 2;
    a->seq = (unsigned int*)malloc(sizeof(int) * a->size);
    a->seq[0] = 7;
    a->seq[1] = 11;
    numap_rand_perm_cycle_type(test, a);
    printf("\n\n\n");
    numap_print(test);
    printf("numap domain: %d\n", test->size_d);
    printf("numap codomain: %d\n", test->size_cod);
    return 0;
}


