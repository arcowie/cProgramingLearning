#include "dll.h"
#include <memory.h>
#include <stdlib.h>

dllT * getNewDll(){
    dllT *temp = malloc(sizeof(dllT));
    temp->head = NULL;
    return temp;
}

int addDataDll(dllT *dll, void *appData){
    dllNodeT *newNode = malloc(sizeof(dllNodeT));

    newNode->data=appData;

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