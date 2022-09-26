#include "event.h"
#include <string.h>
#include <stdlib.h>

Event *CreateEvent(char *name)
{
    Event *evento=malloc(sizeof(Event));
    name[15]=0;
    strncpy(evento->eventName,name,strlen(name) +1);
    evento->next=NULL;
    return evento;
}

void DestroyEvent(Event *this)
{
    free(this);
}
