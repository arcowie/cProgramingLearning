typedef struct dllNode{
    void *data;
    struct dllNode *right;
    struct dllNode *left;
} dllNodeT;

typedef struct dll{
    dllNodeT *head;
} dllT;

dllT * getNewDll();

int addDataDll(dllT *dll, void *appData);