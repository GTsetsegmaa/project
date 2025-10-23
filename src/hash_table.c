#include <stdlib.h>
#include <string.h>

#include "hash_table.h"

static ht_item* ht_new_item(const char* key, const char* value) {
    ht_item* item_ptr = malloc(sizeof(ht_item));
    item_ptr->key = strdup(key);
    item_ptr->value = strdup(value);
    return item_ptr;
}

ht_hash_table* ht_new() {
    ht_hash_table* ht_ptr = malloc(sizeof(ht_hash_table));
    ht_ptr->size = 53;
    ht_ptr->count = 0;
    ht_ptr->items = calloc((size_t)ht_ptr->size, sizeof(ht_item*));
    return ht_ptr;
}

static void ht_free_item(ht_item* item_ptr) {
    free(item_ptr->key);
    free(item_ptr->value);
    free(item_ptr);
}

void delete_hash_table(ht_hash_table* ht_ptr) {
    for (int i = 0; i < ht_ptr->size; i++) {
        ht_item* item = ht_ptr -> items[i];
        if (item != NULL){
            ht_free_item(item);
        }
    }
    free(ht_ptr->items);
    free(ht_ptr);
}