#include "lock.h"

#include <stdio.h>

//pthread_mutex_t lock;
// typedef struct {
//   int amount;
//   pthread_mutex_t mutex;
// }lock_t;
void amountInit(lock_t* Account) {
  pthread_mutex_init(&Account->mutex,NULL);
  Account->amount = 0;
  //perror("This function is not implemented");

}

void Income(lock_t* Account, int amount) {
  //perror("This function is not implemented");
  pthread_mutex_lock(&Account->mutex);
  Account->amount += amount;
  pthread_mutex_unlock(&Account->mutex);
}

void Expend(lock_t* Account, int amount) {
  //perror("This function is not implemented");
  pthread_mutex_lock(&Account->mutex);
  Account->amount-= amount;
  pthread_mutex_unlock(&Account->mutex);
}