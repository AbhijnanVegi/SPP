#include <stdbool.h>
typedef struct Timer* Timer;

struct Timer {
    struct timeval t;
    bool running;
};

Timer newTimer(void);
void tick(Timer t);
double tock(Timer t);