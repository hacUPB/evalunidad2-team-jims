#include "event.h"
#include <string.h>
#include <stdlib.h>

Event *CreateEvent(char *name)
{
    char nombre=name;
    Event *evento=malloc(sizeof(Event));
    evento->eventName[0]=nombre;
    evento->next=NULL;
}

void DestroyEvent(Event *this)
{
    free(this);
}
