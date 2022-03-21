#include <stdio.h>
#include "Animales/elefante.h"
#include "Animales/hierba.h"
#include "Animales/guepardo.h"

int main(int argc, char const *argv[]){
  Hierba* cesped = Hierba_create("Cesped");
  Elefante* dumbo = Elefante_create("Dumbo");
  Guepardo* guepardex = Guepardo_create("Guepardex");

  cesped -> exist(cesped);
  dumbo -> eat(dumbo, cesped);
  guepardex -> attack(guepardex, dumbo);

  cesped -> destroy(cesped);
  dumbo -> destroy(dumbo);
  guepardex -> destroy(guepardex);

  return 0;

}