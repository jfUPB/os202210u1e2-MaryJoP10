#ifndef OSUBJET_H
    #define SUBJECT_H
    #include "observer.h"
    
    typedef struct __subject{
        int type;
        void(*destroy)(struct __subject *);
        void* imple;
        Observer * viewers[max_viewers];
        int (*register)(struct __subject*, Observer*);
        int (*unregister)(struct __subject*, Observer*);
        void (*notify)(struct __subject*);
    }
    Subject;

    //Constructor
    Subject * subjectNew (void*, int)