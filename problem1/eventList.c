#include "eventList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

EventList *CreateEventList(void)
{
    EventList *event=malloc(sizeof(EventList));
    event->head==NULL;
    event->last==NULL;
    event->isEmpty=0;
    return event;
}

Event *SearchEvent(EventList *this, char *name)
{
    Event *loQueBusca=this->head;  
    if(this->isEmpty==1)  //corregir esto es vacio 1
    {
        /*if(strcmp(loQueBusca->eventName,name)==0) // loquebusca=loquebusca->next (creo)
        {
            return loQueBusca;
        }*/
        while (strcmp(loQueBusca->eventName,name)!=0) //no es necesaria
        {     
            loQueBusca=loQueBusca->next; //no es necesaria
        }
        return loQueBusca;
    }
    else
    return loQueBusca;
    
}

void AddEvent(EventList *this, Event *event)
{
    if(this->isEmpty==0)
    {
        this->head=event;
        //this->last=event;
        //this->head->next=this->last;
        this->isEmpty=1;
    }
    else if(this->isEmpty==1 && this->last==NULL)
    {
        this->last=event;
        this->head->next=event;
        
    }
    else
    {
        this->last->next=event;
        this->last=event;
    }
}

void RemoveEvent(EventList *this, char *name)
{
    Event *antesRemover;
    Event *aRemover;
    antesRemover=this->head;
    if(this->isEmpty==0)
    {
        return ;
    }
    while (strcmp(antesRemover->next->eventName,name)!=0)
    {
        antesRemover=antesRemover->next;
    }  
    aRemover=antesRemover->next;
    //aRemover=SearchEvent(this,name);
    antesRemover->next=aRemover->next;
    DestroyEvent(aRemover);
    //this->last=antesRemover; 

}

void ListEvents(EventList *this)
{
    if(this->isEmpty==0)
    {
        printf("empty\n");
    }
    else
    {
        Event *actual;
        actual=this->head;
        while (actual!=NULL)
        {
            printf("%s\n",actual->eventName);
            actual=actual->next;
        } 
    }
    
}
void DestroyEventList(EventList *this)
{
    Event *antesRemover;
    Event *aRemover;
    while (this->head->next!=NULL)
    {
        antesRemover=this->head;
        while (strcmp(antesRemover->next->eventName,this->last->eventName)==0 )
        {
            antesRemover=antesRemover->next;
        }   
        aRemover=this->last;
        antesRemover->next=aRemover->next;
        DestroyEvent(aRemover);
        this->last=antesRemover;
    }  
    DestroyEvent(this->head); 
    free(this);
}
