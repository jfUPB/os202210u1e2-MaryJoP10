#include "hierba.h"

static void _exist(Hierba* this){
  printf("%s\n", this -> name);
  printf("%s\n", "*estiste*");

    this -> event = EXIST;
    this -> subject -> notifyObservers(this -> subject);   
}

static void _destroy(Hierba* this){
  this -> subject -> destroy(this -> subject);
  if(this != NULL){
    free(this);
    this = NULL;
  }
}

static HierbaEvent _getEvent(Hierba* this){
  return this -> event;
}

static int _register(Hierba* this, Observer* observer){
  return this -> subject -> register(this -> subject, observer);  
}

static unregister(Hierba* this, Observer* observer){
  return this -> subject -> unregister(this -> subject, observer);
}

Hierba* Hierba_create(char* name){
  Hierba* this = (Hierba *) malloc(sizeof(*this));
  this -> name = name;
  this -> destroy = _destroy
  this -> getEvent = _getEvent;
  this -> exist = _exist;
  this -> subject = SubjectNew(this, 1);
  this -> register = _register;
  this -> unregister = _unregister;

  return this;
}