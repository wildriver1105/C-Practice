#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "key_manager.h"

KeyStorage* init_storage (int initial_capacity) {
    KeyStorage *s = (KeyStorage *)malloc(sizeof(KeyStorage));
    s->count = 0;
    s->capacity = initial_capacity;
    s->keys = (CryptoKey *)malloc(sizeof(CryptoKey) * s->capacity);
    return s;
}

int add_key(KeyStorage *storage, int id, const char *label, const char *secret) {
    // 용량이 꽉 찼을 때
    if (storage->count >= storage->capacity) {
        printf("로그: 용량 부족! 확장이 필요합니다.\n");
        return -1;
    }

    // 새로운 키 데이터 채우기
    CryptoKey *k = &storage->keys[storage->count];
    k->id = id;
    strncpy(k->label, label, 31);
    k->label[31] = '\0';

    k->secret_key = (char *)malloc(strlen(secret) + 1);
    strcpy(k->secret_key, secret);

    storage->count++;
    return 0;
}

void print_all_keys(const KeyStorage *storage) {
    printf("\n-- [Key Storage Report] ---\n");
    for (int i = 0; i< storage->count; i++) {
        printf("[%d] Label: %-15s | Address: %p\n", storage->keys[i].id, storage->keys[i].label, (void *)&storage->keys[i]);
    }
}

void free_storage(KeyStorage *storage) {
    if (!storage) return;
    for (int i = 0; i < storage->count; i++) {
        free(storage->keys[i].secret_key);
    }
    free(storage->keys);
    free(storage);
    printf("\n로그: 모든 메모리가 안전하게 소거되었습니다.\n");
}