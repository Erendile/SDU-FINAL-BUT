#include <stdio.h>

int main() {
    int array[10], period = 0;
    for(int i = 0; i < 10; i++) {
        printf("Number of day %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    printf("Number of period: ");
    scanf("%d", &period);

    for(int i = 0; (i + period) <= 10; i++) {
        int total = 0;
        for(int j = i; j < (i + period); j++) {
            total = total + array[j];
        }
        float average = (float) total / period;
        printf("Result of period %d: %f\n", (i + 1), average);
    }
    return 0;
}
