#include "eventList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

EventList *CreateEventList(void)
{
    EventList *event=malloc(sizeof(EventList));
    event->head==NULL;
    event->last==NULL;
    event->isEmpty=1;
    return event;
}

Event *SearchEvent(EventList *this, char *name)
{
    Event *loQueBusca=NULL;  
    if(this->isEmpty==0)
    {
        loQueBusca=this->head;
        if(strcmp(loQueBusca->eventName,name)==1)
        {
            return loQueBusca;
        }
        while (strcmp(loQueBusca->next->eventName,name)==0)
        {     
            loQueBusca=loQueBusca->next;
        }
        return loQueBusca;
    }
    else
    return loQueBusca;
    
}

void AddEvent(EventList *this, Event *event)
{
    if(this->isEmpty==1)
    {
        this->head=event;
        this->last=event;
        //this->head->next=this->last;
        this->isEmpty=0;
        return 0;
    }
    else if(this->isEmpty==0)
    {
        this->last=event;
        this->head->next=event;
        return 0;
    }
    else
    {
        this->last->next=event;
        this->last=event;
        return 0;
    }
}

void RemoveEvent(EventList *this, char *name)
{
    Event *antesRemover;
    Event *aRemover;
    antesRemover=this->head;
    if(antesRemover->next==NULL)
    {
        antesRemover==NULL;
        return 0;
    }
    while (antesRemover->next->eventName!=name)
    {
        antesRemover=antesRemover->next;
    }   
    aRemover=SearchEvent(this,name);
    antesRemover->next=aRemover->next;
    DestroyEvent(aRemover);
    this->last=antesRemover;
}

void ListEvents(EventList *this)
{
    if(this->isEmpty==1)
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