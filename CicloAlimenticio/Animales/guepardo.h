#ifndef GUEPARDO_H
	#define GUEPARDO_H
 	#include <stdio.h>
	#include <stdlib.h>
	#include "../../observer/observer.h"
	#include "elefante.h"

	typedef struct __guepardo
	{
		char* name;
		void (*eat)(struct __guepardo*);
		void (*destroy)(struct __guepardo*);
		void (*attack)(struct __guepardo*, Elefante*);

		Observer* observer;
	} Guepardo;

	Guepardo* Guepardo_create(char *);
#endif