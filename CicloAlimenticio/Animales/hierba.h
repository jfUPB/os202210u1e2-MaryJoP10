#ifndef HIERBA_H
  #define HIERBA_H
  #include <stdio.h>
  #include <stdlib.h>
  #include "../../observer/observer.h"
  #include "../../observer/subject.h"

  typedef enum __hierba_event{
    EXIST
  } HierbaEvent;

  typedef struct __hierba{
    char* name; 
    void (*destroy)(struct __hierba*);
    HierbaEvent event;
    HierbaEvent (*getEvent)(struct __hierba*);

    void (*exist)(struct __hierba*);

    Subject * sibject;
    int (*register)(struct __hierba*, Observer*);
    int (*unregister)(struct __hierba*, Observer*);
  } Hierba;

  Hierba* Hierba_create(char *);

#endif