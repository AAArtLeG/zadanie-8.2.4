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
    if (t == NUMAP_FAIL)
        return -1;

    numap_print(test);
    SEQ* a = (SEQ*)malloc(sizeof(SEQ));
    a->size = 2;
    a->seq = (unsigned int*)malloc(sizeof(int) * a->size);
    a->seq[0] = 4;
    a->seq[1] = 5;
    //a->seq[2] = 4;
    //a->seq[3] = 5;
    //numap_rand_perm_cycle_type(test, a);
    NUMAP* test2 = numap_create_empty();
    test2 = create_prot_perm_cycle_type(a);
    printf("\n\n\n");
    numap_print(test2);
    printf("numap domain: %d\n", test2->size_d);
    printf("numap codomain: %d\n", test2->size_cod);
    numap_perm_conjugation_with_swap(test2, 3, 7);
    printf("\n\n\n");
    numap_print(test2);
    return 0;
}


