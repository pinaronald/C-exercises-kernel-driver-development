#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/types.h>

void burnStackSpace(int *depth)
{
    char foo[8192];
    (*depth)--;

    if (*depth > 0) {
        burnStackSpace(depth);
    }
    else {
        sprintf(foo, "Hit final depth!\n" ); 
        /* Actually use foo to make sure complier keeps it*/        
        puts(foo);
        sleep(30);

    }
}

extern "C" void *useStackSpace(void *arg)
{
    int stackSpace = *(int *)arg;
    int depth = (stackSpace/8192) * 2;
    burnStackSpace(&depth);
    return NULL;
}

int main(int argc, char *argv[], char *envp[])
{
    int sRC = 0;
    pthread_t newThread;
    int stackSpace = 1008*1024;
    pthread_attr_t attr;

    pthread_attr_init(&attr);
    pthread_attr_setstacksize(&attr, 1024*1024);
    sRC = pthread_create(&newThread, &attr, useStackSpace, (void *)&stackSpace);
    pthread_join(newThread, NULL);
}
