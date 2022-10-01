#include "eventList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

EventList *CreateEventList(void)
{
    EventList *event=malloc(sizeof(EventList));
    event->head=NULL;
    event->last=NULL;
    event->isEmpty=1;
    return event;
}

Event *SearchEvent(EventList *this, char *name)
{
    Event *loQueBusca=this->head;  
    if(this->isEmpty==0)  
    {
        while(loQueBusca!=NULL)
        {
            if(strcmp(loQueBusca->eventName,name)==0)
            {
                return loQueBusca;
            }
            loQueBusca = loQueBusca->next;
        }
    }
    return NULL;
    
}

void AddEvent(EventList *this, Event *event)
{
   
   Event *eso=SearchEvent(this,event->eventName);
    if(eso!=NULL)
    {
        
    }
    else if(this->isEmpty==1)
    {
        this->head=event;
        //this->last=event;
        //this->head->next=this->last;
        this->isEmpty=0;
    }
    else if(this->isEmpty==0 && this->last==NULL)
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
    /*Caso remove inicio fila
    if (this->isEmpty == 0)
    {
        return -1;
    }
    Event *antesRemover;
    Event *aRemover;
    antesRemover=this->head;
    this->head = this->head->next;
    if (this->isEmpty == 1)
    {
        this->last = NULL;
    }
    free (antesRemover->eventName);
    free (antesRemover);
    this->isEmpty--;
    return 0;x*/
    
    Event *antesRemover;
    Event *aRemover;
    antesRemover=this->head;
    if(this->isEmpty==1)
    {
        this->head=NULL;
        this->last=NULL;
    }
    else if(strcmp(antesRemover->eventName,name)==0)
    {
        aRemover=this->head;
        this->head=aRemover->next;
        if(this->head==NULL)
        {
            this->last=NULL;
            this->isEmpty=1;

        }
        DestroyEvent(aRemover);
        /*if(this->head==NULL && this->last==NULL)
        {
            this->isEmpty=0;
        }*/
    }
    else
    {
        while (strcmp(antesRemover->next->eventName,name)!=0)
        {
            antesRemover=antesRemover->next;
        }   
        aRemover=antesRemover->next;
        if(aRemover==this->head)
        {
            this->head=aRemover->next;
        }
        if(aRemover==this->last)
        {
            this->last=antesRemover;
        }
        antesRemover->next=aRemover->next;
        DestroyEvent(aRemover);
        if(this->head==NULL && this->last==NULL)
        {
            this->isEmpty=1;
        }
    }
    
}

void ListEvents(EventList *this)
{
    if(this->head==NULL)
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
    Event *siguienteRemover;
    Event *aRemover;
    aRemover=this->head;
    while (aRemover!=NULL)
    {
        siguienteRemover=aRemover->next;
        DestroyEvent(aRemover);
        aRemover=siguienteRemover;
    }
    free(this);
}

