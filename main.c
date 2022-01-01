#include <stdio.h>
#include <stdlib.h>

struct Integeren {
    int data;
    int frequency;
};

int getFrequency(struct Integeren *array, int number);
void print(struct Integeren *array);
int wasItHere(struct Integeren *array, int index, int number);
int main() {
    struct Integeren *numbers = (struct Integeren *) malloc(sizeof(struct Integeren) * 10);

    for(int i = 0; i < 10; i++) {
        printf("Enter any number: ");
        scanf("%d", &numbers[i].data);
        numbers[i].frequency = 1;
    }

    for(int i = 0; i < 10; i++) {
        numbers[i].frequency = getFrequency(numbers, numbers[i].data);
    }
    print(numbers);

    return 0;
}

int getFrequency(struct Integeren *array, int number) {
    int counter = 0;
    for(int i = 0; i < 10; i++) {
        if(array[i].data == number)
            counter++;
    }
    return counter;
}

void print(struct Integeren *array) {
    for(int i = 0; i < 10; i++) {
        if(array[i].frequency > 1) {
            if(wasItHere(array, i, array[i].data))
                printf("Frequency of %d: %d\n", array[i].data, array[i].frequency);
        }

    }
}

int wasItHere(struct Integeren *array, int index, int number) {
    for(int i = 0; i < index; i++) {
        if(array[i].data == number)
            return 0;
    }
    return 1;
}
