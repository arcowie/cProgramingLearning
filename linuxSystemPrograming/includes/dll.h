#ifndef dll_h
#define dll_h

typedef struct dllNode{
    void *data;
    struct dllNode *right;
    struct dllNode *left;
} dllNodeT;

typedef struct dll{
    dllNodeT *head;
    int (*keyMatch)(void *, void *);
    int sizeOfData;
} dllT;

dllT * getNewDll(int sizeOfData);

/*Adds a node to a Doubly Linked List*/
int addDataDll(dllT *dll, void *appData);

/*Adds the key match funciton pointer to double link list*/
void regKeyMatch(dllT *dll, int (*keyMatch)(void *, void *));

/*Generic key search function*/
void * searchByKey(dllT *dll, void *key);

/*Removes a piece of data from the DLL.
Returns 0 for success and -1 for failure*/
int removeDataFromDll(dllT *dll, void *data);

/*Check if DLL is empty.  Returns 0 if empty
and -1 if not empty.*/
int isDllEmpty(dllT *dll);

/*Removes all nodes from a DLL but does not 
free appln data*/
void drainDll(dllT *dll);


#endif