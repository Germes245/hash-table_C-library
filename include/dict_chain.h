typedef struct{
    int key;
    int value;
} dict_couple;

typedef struct{
    dict_couple *array;
    size_t length;
} dict_chain;

dict_chain dict_chain_init();
void dict_chain_put(dict_chain *chain, int key, int value);
char *dict_chain_get(dict_chain chain, int key);
unsigned char dict_chain_delete(dict_chain *chain, int key);
void dict_chain_free(dict_chain *chain);