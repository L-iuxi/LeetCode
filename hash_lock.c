#include "hash_lock.h"

#include <stdio.h>
#include <stdlib.h>


// #define HASHNUM 13
// #define HASH(key) key % HASHNUM

// typedef struct HashNode {
// int value;
// int key;
// struct HashNode* next;
// }Hnode,*Hlist;

// struct HashTable {
// pthread_mutex_t mutex;
// Hlist head;
// };

// typedef struct{
// struct HashTable table[HASHNUM];
// }hash_lock_t;





void hashInit(hash_lock_t* bucket) {
 for(int i = 0;i < 13;i++)
 {
  bucket->table[i].head = NULL;
  pthread_mutex_init(bucket->table[i].mutex,NULL);

 }
}

int getValue(hash_lock_t* bucket, int key) {
  int a = HASH(key);
  Hlist current = bucket->table[a].head;
  pthread_mutex_lock(bucket->table[a].mutex);
  if(current)
  {
    if(current->key == key);
    {
      pthread_mutex_unlock(bucket->table[a].mutex);
      return current->value;
    }
    current = current->next;
  }
  pthread_mutex_unlock(bucket->table[a].mutex);
  return -1;
}

void insert(hash_lock_t* bucket, int key, int value) {
  int index = HASH(key); 
  pthread_mutex_lock(&bucket->table[index].mutex); 

  Hlist newNode = (Hlist)malloc(sizeof(Hnode));  
  if (newNode == NULL) {
      perror("Failed to allocate memory");
      pthread_mutex_unlock(&bucket->table[index].mutex);  
      return;
  }
  newNode->key = key;
  newNode->value = value;
  newNode->next = bucket->table[index].head; 
  bucket->table[index].head = newNode;

  pthread_mutex_unlock(&bucket->table[index].mutex);  
}

int setKey(hash_lock_t* bucket, int key, int new_key) {
  int a = HASH(key);
  Hlist current = bucket->table[a].head;
  pthread_mutex_lock(bucket->table[a].mutex);
  if(current)
  {
    if(current->key == key);
    {
      current->key = new_key;
      pthread_mutex_unlock(bucket->table[a].mutex);
      return current->value;
    }
    current = current->next;
  }
  pthread_mutex_unlock(bucket->table[a].mutex);
  return -1;
}