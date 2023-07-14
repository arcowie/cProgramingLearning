#include "dll.h"
#include <memory.h>
#include <stdlib.h>

int freeNodeMem(dllNodeT *node){
    free(node->data);
    free(node);
    return 0;
}

int removeDataFromDll(dllT *dll, void *appData){
    if(dll->head == NULL) return -1;

    else{
        int endOfList = 0;
        dllNodeT *currentNode = dll->head, *previousNode = NULL;
        while(endOfList == 0){
            if(memcmp(appData, currentNode->data, dll->sizeOfData)){
                /*If head node is the one removed*/
                if(currentNode->left==NULL){
                    dll->head=currentNode->right;
                    freeNodeMem(currentNode);
                    return 0;
                }
                /*If node removed in the middle of the list*/
                else if(currentNode->right != NULL){
                    previousNode = currentNode->left;
                    previousNode->right = currentNode->right;
                    freeNodeMem(currentNode);
                    return 0;
                }
                /*If node removed is the tail node*/
                else{
                    previousNode = currentNode->left;
                    previousNode->right = NULL;
                    freeNodeMem(currentNode);
                    return 0;
                }

            }
            /*If note at the end of list*/
            if(currentNode->right != NULL){
                currentNode = currentNode->right;
            }
            /*If at end of list*/
            else if(currentNode->right == NULL){
                endOfList = 1;
            }
        }
        return -1;

    }
}

int isDllEmpty(dllT *dll){
    if(dll->head == NULL) return 0;
    else return -1;
}