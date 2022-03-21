#include "subject.h"

static void _destroy(Subject* this){
    if(this != NULL){
        free(this);
        this = NULL;
    }
}

static int _register(Subject* this, int type, Observer* viewer){
    int i = 0;
    for(; i < max_viewers; i++){
        if(this -> viewers[i] == NULL){
            this -> viewers[i] = viewer;

            return OK;
        }
    }
    printf("[INF] [SUbJECT] No se puede registrar.\n");
    return KO;
}

static int _unregister(Suject* this, Observer* viewer){
    int i = 0;
    for(; i < max_viewers; i++){
        void* pViewer = this -> viewers[i];
        if(viewer == pViewer){
            pViewer = NULL;
            return OK;
        }
    }
    return KO;
}

static void _notify(Subject* this){
    int i = 0;
    for(; i < max_viewers; i++){
        if(this -> viewers[i] !=NULL){
            this -> viewers[i] -> notify(this -> viewers[i], this -> type, this -> imple);
        }
    }
}

Subject * subjectNew(void* imple, int type){
    Subject * this = (Subject *) malloc(sizeof(*this));
    this -> destroy = _destroy;
    this -> imple = imple;
    this -> type = type;
    this -> register = _register;
    this -> unregister = _unregister;
    this -> notify = _notify;

    return this;
}