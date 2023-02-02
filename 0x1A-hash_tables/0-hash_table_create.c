#include <stdlib.h>
#include <string.h>

typedef struct node {
  char *key;
  int value;
  struct node *next;
} node_t;

typedef struct hash_table {
  unsigned long int size;
  node_t **array;
} hash_table_t;

hash_table_t *hash_table_create(unsigned long int size) {
  hash_table_t *hash_table = malloc(sizeof(hash_table_t));
  if (!hash_table) return NULL;

  hash_table->size = size;
  hash_table->array = calloc(size, sizeof(node_t*));
  if (!hash_table->array) {
    free(hash_table);
    return NULL;
  }

  return hash_table;
}
