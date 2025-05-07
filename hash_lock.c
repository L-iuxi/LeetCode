#include "hash_lock.h"

#include <stdio.h>
#include <stdlib.h>

void hashInit(hash_lock_t* bucket) {
 for(int i = 0;i < 13;i++)
 {
  int n = pthread_mutex_init(&bucket->table[i].mutex, NULL);
        if(n != 0)
        {
          perror("Mutex initialization failed");
          exit(EXIT_FAILURE);
        }
  bucket->table[i].head = NULL;
  

 }
}

int getValue(hash_lock_t* bucket, int key) {
  int a = HASH(key);
  Hlist current = bucket->table[a].head;
  pthread_mutex_lock(&bucket->table[a].mutex);
  if(current == NULL)
  {
    pthread_mutex_unlock(&bucket->table[a].mutex);
    return -1;
  }
  while(current)
  {
    if(current->key == key)
    {
      pthread_mutex_unlock(&bucket->table[a].mutex);
      return current->value;
    }
    current = current->next;
  }
  pthread_mutex_unlock(&bucket->table[a].mutex);
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
  newNode->next = NULL;

  Hlist a = bucket->table[index].head;
  while (a != NULL) {
    if (a->key == key) {
    
      a->value = value;
      free(newNode);  
      pthread_mutex_unlock(&bucket->table[index].mutex);
      return;
    }
    a = a->next;
  }

  
  newNode->next = bucket->table[index].head;
  bucket->table[index].head = newNode; 
  pthread_mutex_unlock(&bucket->table[index].mutex);
}

int setKey(hash_lock_t* bucket, int key, int new_key) {
  int num = HASH(key);
  pthread_mutex_lock(&bucket->table[num].mutex);

  int n = 0;
  if(bucket->table[num].head == NULL)
  {
      pthread_mutex_unlock(&bucket->table[num].mutex);
      return -1;
  }
  else
  {
    
    Hnode* a = bucket->table[num].head;
    Hnode* p = NULL;
    while(a != NULL)
    {
      if(a->key == key)
      {
        if(p == NULL)
        {
            bucket->table[num].head = a->next;
            n = a->value;
            pthread_mutex_unlock(&bucket->table[num].mutex);
            insert(bucket, new_key, n);
            free(a);
        }
        else
        {
            p->next = a->next;
            n = a->value;
            free(a);
            pthread_mutex_unlock(&bucket->table[num].mutex);
            insert(bucket, new_key, n);
        }
        return 0;
      }
      p = a;
      a = a->next;
    }
  }

  pthread_mutex_unlock(&bucket->table[num].mutex);
  return -1;
}