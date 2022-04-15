#ifndef BENCH_UTILS_H
#define BENCH_UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <stdbool.h>

#include <stdbool.h>
#include <sys/time.h>


struct Timer {
    struct timeval t;
    bool running;
};

typedef struct Timer* Timer;

Timer newTimer(void);
void tick(Timer t);
double tock(Timer t);

Timer newTimer(void) {
    Timer t = (Timer)malloc(sizeof(struct Timer));
    t->running = false;
    return t;
}

void tick(Timer t) {
    t->running = true;
    gettimeofday(&t->t, NULL);
}

double tock(Timer t) {
    if (!t->running) {
        fprintf(stderr, "Timer not running!\n");
        return 0;
    }
    struct timeval now;
    gettimeofday(&now, NULL);
    return (double)(now.tv_sec - t->t.tv_sec) + ((double)(now.tv_usec - t->t.tv_usec) / 1000000.0f);
}

#endif


