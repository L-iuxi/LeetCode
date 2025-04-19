#include "list_lock.h"

#include <stdio.h>
#include <stdlib.h>

// 初始化链表
void listInit(list_lock_t* list) {
    list->head = NULL;
    pthread_mutex_init(&list->mutex, NULL);
    pthread_cond_init(&list->cond, NULL);
}

void producer(list_lock_t* list, DataType value) {
    LNode* newNode = (LNode*)malloc(sizeof(LNode));  
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    newNode->value = value;
    newNode->next = NULL;

    pthread_mutex_lock(&list->mutex);  
    newNode->next = list->head;        
    list->head = newNode;
    pthread_cond_signal(&list->cond);  
    pthread_mutex_unlock(&list->mutex);  
}
// 消费者从链表中取出数据
void consumer(list_lock_t* list) {
    pthread_mutex_lock(&list->mutex);  

    
    while (list->head == NULL) {
        pthread_cond_wait(&list->cond, &list->mutex);  
    }

    
    LNode* temp = list->head;
    list->head = list->head->next;
    free(temp);  

    pthread_mutex_unlock(&list->mutex);  
}

// 获取链表中的元素个数
int getListSize(list_lock_t* list) {
    int size = 0;
    pthread_mutex_lock(&list->mutex);  

    LNode* current = list->head;
    while (current != NULL) {
        size++;
        current = current->next;
    }

    pthread_mutex_unlock(&list->mutex);  
    return size;
}
