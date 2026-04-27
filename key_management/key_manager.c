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
        int new_capacity = storage->capacity * 2;
        printf("\n[시스템 로그] 용량 초과! 확장 중: %d -> %d\n",storage->capacity, new_capacity);

        CryptoKey *new_keys = (CryptoKey *)realloc(storage->keys, sizeof(CryptoKey) * new_capacity);

        if (new_keys == NULL) {
            printf("[에러] 메모리 확장 실패!\n");
            return -1;
        }

        storage->keys = new_keys;
        storage->capacity = new_capacity;
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
    for (int i = 0; i < storage->count; i++) {
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

void saveKeyFile(KeyStorage storage) {
    FILE *file = fopen("keys.txt", "w");

    if (file == NULL) {
        printf("[에러] 파일 열기 실패!\n");
        return;
    }

    for (int i = 0; i < storage.count; i++) {
        fprintf(file, "%d,%s,%s\n", storage.keys[i].id, storage.keys[i].label, storage.keys[i].secret_key);
    }

    fclose(file);
    printf("[로그] 키 정보가 keys.txt에 저장되었습니다.\n");
    return;
}