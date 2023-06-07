#include<stdlib.h>

typedef struct lista {
    void* local;
    int ref;
    struct lista* prox;
} lista;

lista* l = NULL;

void* malloc2(size_t size) {
  void* ptr = malloc(size);

    if (ptr != NULL) {
      lista* newlista = malloc(sizeof(lista));
      newlista->local = ptr;
      newlista->ref = 1;
      newlista->prox = l;
      l = newlista;
    }

  return ptr;
}

void atrib2(void** dest, void* org) {
  if (*dest != NULL) {
    lista* curr = l;
    while (curr != NULL) {
      if (curr->local == *dest) {
        curr->ref--;
        if (curr->ref == 0) {
          free(curr->local);
          lista* temp = curr;
          if (curr == l) {
            l = curr->prox;
          }else{
            lista* prev = l;
            while (prev->prox != curr) {
              prev = prev->prox;
            }
            prev->prox = curr->prox;
          }
          free(temp);
        }
        break;
      }
    curr = curr->prox;
    }
  }
  *dest = org;
  if (org != NULL) {
    lista* curr = l;
    while (curr != NULL) {
      if (curr->local == org) {
        curr->ref++;
        break;
      }
      curr = curr->prox;
    }
  }
}

