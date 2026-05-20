#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Global variables for results
double mean, median, std_dev;
int *data, size;

// Comparison function for qsort (needed for median)
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void *calc_mean(void *param) {
    double sum = 0;
    for (int i = 0; i < size; i++) sum += data[i];
    mean = sum / size;
    pthread_exit(0);
}

void *calc_median(void *param) {
    int *temp = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) temp[i] = data[i];
    qsort(temp, size, sizeof(int), compare);
    
    if (size % 2 == 0) median = (temp[size/2 - 1] + temp[size/2]) / 2.0;
    else median = temp[size/2];
    
    free(temp);
    pthread_exit(0);
}

void *calc_std_dev(void *param) {
    double sum = 0, variance = 0;
    for (int i = 0; i < size; i++) sum += data[i];
    double avg = sum / size;
    for (int i = 0; i < size; i++) variance += pow(data[i] - avg, 2);
    std_dev = sqrt(variance / size);
    pthread_exit(0);
}

int main(int argc, char *argv[]) {
    if (argc < 2) return 1;
    size = argc - 1;
    data = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) data[i] = atoi(argv[i+1]);

    pthread_t tid1, tid2, tid3;
    pthread_create(&tid1, NULL, calc_mean, NULL);
    pthread_create(&tid2, NULL, calc_median, NULL);
    pthread_create(&tid3, NULL, calc_std_dev, NULL);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    pthread_join(tid3, NULL);

    printf("Mean: %.2f\nMedian: %.2f\nStd Dev: %.2f\n", mean, median, std_dev);
    free(data);
    return 0;
}