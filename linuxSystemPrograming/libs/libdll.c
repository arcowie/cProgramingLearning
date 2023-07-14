#include "dll.h"
#include <memory.h>
#include <stdlib.h>

dllT * getNewDll(int sizeOfData){
    dllT *temp = malloc(sizeof(dllT));
    temp->head = NULL;
    temp->sizeOfData=sizeOfData;
    return temp;
}

void regKeyMatch(dllT *dll, int (*keyMatch)(void *, void *)){
    dll->keyMatch = keyMatch;
}

void * searchByKey(dllT *dll, void *key){
    if(dll->head==NULL) {
        return NULL;
    }
    dllNodeT *currentNode = dll->head;
    
    while(currentNode!=NULL){
        if(dll->keyMatch(currentNode->data, key)==0){
            return (void *)currentNode->data;
        }
        else{
            currentNode=currentNode->right;
        }
    }
    return NULL;
    
}

int addDataDll(dllT *dll, void *appData){
    dllNodeT *newNode = malloc(sizeof(dllNodeT));
    newNode->data=malloc(dll->sizeOfData);
    memcpy(newNode->data, appData, dll->sizeOfData);

    /*Only true if an empty list*/
    if(!dll->head){
        dll->head=newNode;
        newNode->left=NULL;
        newNode->right=NULL;
    }

    else{
        dllNodeT *oldHeadNode = dll->head;
        dll->head = newNode;
        newNode->right = oldHeadNode;
        oldHeadNode->left = newNode; 
    }
    return 0;
}