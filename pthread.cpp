#include <iostream>
#include <pthread.h>
#include <unistd.h>
using namespace std;
void* func(void* arg)
{
    cout << "start" << endl;
    sleep(2);
    cout << "end" << endl;
   return NULL;
}
int main()
{
    pthread_t thread;
    int t = pthread_create(&thread,NULL,func,NULL);
    if(t != 0)
    {
        cerr << "default" << endl;
        exit(1);
    };
    pthread_join(thread,NULL);
    {
        cout << "over" << endl;
    }
    exit(0);
}