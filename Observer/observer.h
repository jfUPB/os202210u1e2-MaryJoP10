#ifndef OBSERVER_H
        #define OBSERVER_H
        #include "fixing.h"

        typedef struct __observer{
            void (*destroy)(struct __observer *);
            void* imple;
            void (*notify)(struct __observer*, int, void *);
            void (*notifyImple)(void*, int, void*);
            int type;
        }
        Observer;

        //Constructor
        Observer * observerNew(void *, void (*)(void *, int, void *));
#endif