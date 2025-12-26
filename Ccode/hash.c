//
// Created by 58413 on 2025/12/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 哈希节点
typedef struct {
    int key;
    int value;
} HashEntry;

// 哈希表
#define TABLE_SIZE 100
typedef struct {
    HashEntry* entries[TABLE_SIZE];
} HashTable;

// 哈希函数
int hash(int key) {
    return abs(key) % TABLE_SIZE;
}

// 初始化
void initHashTable(HashTable* table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        table->entries[i] = NULL;
    }
}

// 插入
void put(HashTable* table, int key, int value) {
    int index = hash(key);
    HashEntry* entry = (HashEntry*)malloc(sizeof(HashEntry));
    entry->key = key;
    entry->value = value;

    if (table->entries[index] != NULL) {
        free(table->entries[index]);
    }

    table->entries[index] = entry;
}

// 查找
int get(HashTable* table, int key) {
    int index = hash(key);
    HashEntry* entry = table->entries[index];
    if (entry != NULL && entry->key == key) {
        return entry->value;
    }
    return -1;
}

// 删除
void removeEntry(HashTable* table, int key) {
    int index = hash(key);
    HashEntry* entry = table->entries[index];
    if (entry != NULL && entry->key == key) {
        free(entry);
        table->entries[index] = NULL;
    }
}

// 主函数测试
int main() {
    HashTable table;
    initHashTable(&table);

    put(&table, 10, 100);
    put(&table, 20, 200);
    put(&table, 110, 300);  // 与 10 冲突（10 % 100 = 10，110 % 100 = 10）

    printf("Key 10 -> Value %d\n", get(&table, 10));   // 100
    printf("Key 20 -> Value %d\n", get(&table, 20));   // 200
    printf("Key 110 -> Value %d\n", get(&table, 110)); // 300（被覆盖）

    removeEntry(&table, 20);
    printf("Key 20 -> Value %d\n", get(&table, 20));   // -1（已删除）

    return 0;
}
