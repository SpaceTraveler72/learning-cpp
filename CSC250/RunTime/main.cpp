#include <iostream>
#include <time.h>
#include <iomanip>
using namespace std;

int function1(int N) {
    int count = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            count = count + 1;

    return count;

}

int function2(int N) {
    int count = 0;
    for (int i = 0; i < N; i++)
        count = count + 1;

    return count;
}

int function3(int N) {
    int count = 0;
    for (int i = 0; i < N; i++)
        for (int j = i; j < N; j++)
            count = count + 1;

    return count;
}

int function4(int N) {
    int limit = N;
    int count = 0;
    while (limit > 1) {
        for (int j = 1; j < limit; j++) {
            count = count + 1;
        }
        limit = limit / 2;
    }
    return count;
}

int main() {
    double times = 0;
    double count = 0;
    double runs = 10;


    for (int i = 0; i < runs; i++) {
        clock_t timeStart = clock();
        count+=function3(50);
        times+= (double)(clock() - timeStart)/CLOCKS_PER_SEC;
    }
    double avg = times/runs;
    printf("Avg. Time Taken: %.4f\n", avg);
    double countAvg = count / runs;
    printf("Avg. Count: %.4f", countAvg);
}