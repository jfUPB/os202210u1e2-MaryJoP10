#ifndef ELEFANTE_H
	#define ELEFANTE_H
 	#include <stdio.h>
	#include <stdlib.h>
	#include "../../observer/observer.h"
	#include "hierba.h"

	typedef struct __elefante
	{
		char* name;
		void (*exist)(struct __elefante*);
		void (*destroy)(struct __elefante*);
		void (*eat)(struct __elefante*, Hierba*);

		Observer* observer;
	} Elefante;
	Elefante* Elefante_create(char *);
#endif