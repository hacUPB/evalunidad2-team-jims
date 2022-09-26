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
    Event *loQueBusca;
    loQueBusca=this->head;
    if(strcmp(loQueBusca->eventName,name)==0)
    {
        return loQueBusca;
    }
    while (loQueBusca->next->eventName!=name)
    {     
        loQueBusca=loQueBusca->next;
    }
    return loQueBusca;
}

void AddEvent(EventList *this, Event *event)
{
    if(this->head==NULL)
    {
        this->head=event;
        this->head->next=this->last;
        this->isEmpty=0;
        return 0;
    }
    else if(this->head!=NULL && this->last==NULL )
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
    if(this->head=NULL)
    {
        printf("empty\n");
    }
    else
    {
        Event *actual;
        actual=this->head;
        while (actual!=NULL)
        {
            printf("%p - %s\n",actual,actual->eventName);
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
