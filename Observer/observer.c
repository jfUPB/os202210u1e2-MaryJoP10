#include "observer.h"

static void _destroy(Observer* this){
    if(this != NULL){
        free(this);
        this = NULL;
    }
}

static void _notify(Observer *this, int type, void *subject){
    this -> notifyImple(this ->imple, type, subject);
}

Observer * observerNew(void* imple, int type){
    Observer * this = (Observer *) malloc(sizeof(*this));
    this -> destroy = _destroy;
    this -> notify = _notify;
    this -> imple = imple;
    this -> type = type;
    
    return this;
}