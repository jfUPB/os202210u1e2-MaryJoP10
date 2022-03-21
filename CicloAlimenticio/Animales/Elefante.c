#include "elefante.h"
static void _destroy(Elefante* this){
  this -> observer -> destroy(this -> observer);
  if(this != NULL){
    free(this);
    this = NULL;
  }
}

static void _eat(Elefante* this, Hierba* hierba){
  hierba -> register(hierba, this -> observer);
  printf("%s *Comida* %s\n", this -> name, hierba -> name);
}

static void _notify(Elefante* this, int numero, void* subject){
  _handleHierbaEvent(this, (Hierba*) subject);
}

Elefante* Elefante_create(char* elefanteName){
  Elefante* this = (Elefante*) malloc(sizeof(*this));
  this -> name = elefanteName;
  this -> eat = _eat;
  this -> destroy = _destroy;
  this -> observer = observerNew(this, (void (*)(void*, int, void*))_notify);
  return this;
}