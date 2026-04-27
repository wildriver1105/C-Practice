#ifndef KEY_MANAGER_H
#define KEY_MANAGER_H

#include <stddef.h>

typedef struct {
    int id;
    char label[32];
    char *secret_key;
} CryptoKey;

typedef struct {
    CryptoKey * keys;
    int count;
    int capacity;
} KeyStorage;

KeyStorage* init_storage(int initial_capacity);
int add_key(KeyStorage *storage, int id, const char *label, const char *secret);
void print_all_keys(const KeyStorage *storage);
void saveKeyFile(KeyStorage storage);
void free_storage(KeyStorage *storage);

#endif