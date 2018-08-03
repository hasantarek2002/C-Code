#include <time.h>
#include <stdio.h>      /* printf */
#include <math.h>       /* sqrt */
#include <stdlib.h>



int main()
{

    int i;
    double sum;
    clockid_t clk_id;
    clk_id=CLOCK_REALTIME
    struct timespec endTime, start;
    clock_gettime(clk_id, &start);
    for(i=0; i<1024; i++){
        sum += i;
    }
    clock_gettime(clk_id, &endTime);
    double seconds = (double)((endTime.tv_sec+endTime.tv_nsec*1e-9) - (double)(start.tv_sec+start.tv_nsec*1e-9));
    printf("wall time %fs\n", seconds);





/*
    struct timespec ts;
    printf("time returns %d seconds\n", time(NULL));
    clock_gettime(CLOCK_REALTIME, &ts);
    printf("clock_gettime returns:\n");
    printf("%d seconds and %ld nanoseconds\n", ts.tv_sec, ts.tv_nsec);
*/
    return 0;
}
