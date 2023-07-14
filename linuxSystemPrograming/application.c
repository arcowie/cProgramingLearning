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

int keyAgeMatch(void *app, void *key){
    int appAge = ((person*)app)->age;
    int key = *(int*)key;
    if(appAge == key) return 0;
    else return 1;
}

int main(int argc, char **argv){
    dllT *list = getNewDll(sizeof(person));
    person one = {"Al", 45, 205}, two = {"Sammi", 24, 144}, three = {"Ebony", 12, 105 }, *result;
    int searchKey=45;
    dllNodeT *head;

    addDataDll(list, &one);
    addDataDll(list, &two);
    addDataDll(list, &three);
    regKeyMatch(list, keyAgeMatch);
    
    
    result=searchByKey(list, &searchKey);
    if(result==NULL){
        printf("\nResult not found, exiting\n");
        return 1;
    }
   
    
    printPerson((person *)result);

    
    

}