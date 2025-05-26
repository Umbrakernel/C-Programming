// При сбокре не забываем слинковать с pthread
// gcc thread1.c -o thread1 -lpthread
//

#include <stdio.h>
#include <unistd.h> // sleep
#include <pthread.h>

#define NOF_THREADS 4

void message_ded(void *a){
    printf("DEAD %s\n", (char*) a);

}
void *forSleap(void *a) {
    pthread_t tid = pthread_self();
    pthread_cleanup_push(message_ded, a);
    usleep(*(int*)a*1000);
    printf("%d %ld\n", *(int*)a, tid);
    pthread_cleanup_pop(0);
    return NULL;
}

void SleapSort(int *sort){
    pthread_t tids[12];

    for (int i = 0; i < 12; i++) {
        pthread_create(&tids[i], NULL, forSleap, &sort[i]);
    }


    for (int i = 0; i < 12; i++) {
        pthread_join(tids[i], NULL);
  }
}


void *routine(void *a) {
    pthread_t tid = pthread_self();
    pthread_cleanup_push(message_ded, a);
    sleep(2);
    printf("%s %ld\n", (char*)a, tid);
    pthread_cleanup_pop(0);
    return NULL;
}

int main(void) {

    pthread_t tids[NOF_THREADS];

    int sort[12] = {9, 7 ,2, 6, 10, 35, 48, 91, 32, 67, 23, 96};

    char a[4][8] = {"one", "two", "three", "four"};

    // for (int i = 0; i < NOF_THREADS; i++) {
    //     pthread_create(&tids[i], NULL, routine, a[i]);
    // }

    //     sleep(1);

    // for (int i = 0; i < NOF_THREADS; i++) {
    //     pthread_cancel(tids[i]);
    // }
        
    SleapSort(sort);

   printf("hello from main thread %ld\n", pthread_self());

    // for (int i = 0; i < NOF_THREADS; i++) {
    //     pthread_join(tids[i], NULL);
    // }
    // return 0;
}