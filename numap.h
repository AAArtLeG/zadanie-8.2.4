#pragma once
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

NUMAP* numap_id(NUMAP* to_redef, unsigned int size);

NUMAP* create_zob(NUMAP* f, unsigned int size);

void numap_print(NUMAP* f);

bool search(int* a, int x, int size);

int* push_back(int* arr, unsigned int* size_arr, int* add, unsigned int* size_add);

char numap_rand_perm_cycle_type(NUMAP* to_redef, SEQ* cycle_type);