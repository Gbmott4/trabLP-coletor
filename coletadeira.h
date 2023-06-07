#ifndef COLETADEIRA_H_INCLUDED
#define COLETADEIRA_H_INCLUDED

#include <stdlib.h>
#pragma once

typedef struct lista {
    void* local;
    int ref;
    struct lista* prox;
} lista;

void* malloc2(size_t size);
void atrib2(void** dest, void* org);




#endif // COLETADEIRA_H_INCLUDED
