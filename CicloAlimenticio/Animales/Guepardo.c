#include "guepardo.h"

static void _destroy(Guepardo* this)
{
	this->observer->destroy(this->observer);

	if (this != NULL){
		free(this);
		this = NULL;
	}
}
static void _attack(Guepardo* this, Elefante* elefante)
{
	elefante->register(elefante, this->observer);
	printf("%s *Atacado* %s\n", this->name, elefante->name);
}

static void _notify(Guepardo* this, int numero, void* subject) {
	_handleElefanteEvent(this, (Elefante*) subject);
}

Guepardo* Guepardo_create(char* guepardoName)
{
	Guepardo* this = (Guepardo*) malloc(sizeof(*this));

	this->name = guepardoName;
	this->attack = _attack;
	this->destroy = _destroy;
	this->observer = observerNew(this, (void (*)(void*, int, void*))_notify);
	return this;
}