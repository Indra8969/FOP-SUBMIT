#include <stdio.h>

struct Time {
    int h; 
    int m; 
    int s; 
};

void addSeconds(struct Time *time, int secondsToAdd) {
    time->s += secondsToAdd;

    time->m += time->s / 60;
    time->s = time->s % 60;

    time->h += time->m / 60;
    time->m = time->m % 60;
    time->h = time->h % 24;
}

int main() {
    struct Time currentTime;
    int secondsToAdd;

    printf("Enter current time (hh mm ss): ");
    scanf("%d %d %d", &currentTime.h, &currentTime.m, &currentTime.s);

    printf("Enter seconds to add: ");
    scanf("%d", &secondsToAdd);

    addSeconds(&currentTime, secondsToAdd);

    printf("New time: %02d:%02d:%02d\n", currentTime.h, currentTime.m, currentTime.s);

    return 0;
}\
//output 
//Enter current time (hh mm ss): 21 05 23
//Enter seconds to add: 23
//New time: 21:05:46

