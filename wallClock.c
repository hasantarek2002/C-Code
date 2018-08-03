#include <time.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int i;
    double sum;

    clockid_t clk_id;
    clk_id=CLOCK_REALTIME;
    struct timespec finish, start;
    clock_gettime(clk_id, &start);
    for(i=0; i<1024; i++){
        sum += i;
    }
    clock_gettime(clk_id, &finish);
    double seconds = (double)((finish.tv_sec+finish.tv_nsec*1e-9) - (double)(start.tv_sec+start.tv_nsec*1e-9));
    printf("wall time %fs\n", seconds);


    return 0;
}
