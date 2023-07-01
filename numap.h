#pragma once
#define NUMAP_SUCCESS 0
#define NUMAP_FAIL  1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



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

NUMAP* numap_create_empty();

void numap_destroy(NUMAP* to_destroy);

char numap_id(NUMAP* to_redef, unsigned int size);

NUMAP* create_zob(NUMAP* f, unsigned int size);

void numap_print(NUMAP* f);

bool search(int* a, int x, int size);

int* push_back(int* arr, unsigned int* size_arr, int* add, unsigned int* size_add);

NUMAP* create_prot_perm_cycle_type(SEQ* cycle_type);

char numap_perm_conjugation_with_swap(NUMAP* perm, unsigned int a, unsigned int b);

NUMAP* numap_rand_perm_cycle_type(NUMAP* to_redef, SEQ* cycle_type);