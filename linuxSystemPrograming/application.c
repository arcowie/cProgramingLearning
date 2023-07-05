#include "dll.h"
#include <stdio.h>

typedef struct person{
    char name[20];
    int age;
    int weight;
} person;

int printPerson(person *p){
    printf("\nName: %s", p->name);
    printf("\nAge: %d", p->age);
    printf("\nWeight: %d\n\n", p->weight);
    return 0;
}

int main(int argc, char **argv){
    dllT *list = getNewDll();
    person one = {"Al", 45, 205};
    person two = {"Sammi", 24, 144}; 
    person three = {"Ebony", 12, 105 };
    dllNodeT *head;

    addDataDll(list, &one);
    addDataDll(list, &two);
    addDataDll(list, &three);
    if(!list->head){
        return 1;
    }
    else{
        head = list->head;
    }

    while(head){
        if(head->right){
            printPerson(head->data);
            head=head->right;
            //printf("\nIn if\n");
        }
        else{
            printf("\n\nEnd of List\n");
            head=head->right;
        }
    }
    return 0;


}