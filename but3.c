#include <stdio.h>
#include <stdlib.h>

int isUnique(int *array, int number, int count);
void upload(int **array, int number, int count);
void print(int *array, int count);

int main() {
    int *array = NULL, counter = 0, number = 0;

    for(int i = 0; i < 10; i++) {
        printf("%d-) Enter a number greater than 1: ", i + 1);
        scanf("%d", &number);

        if(number > 1) {
            if(counter == 0) {
                upload(&array, number, counter);
                counter++;
            }   else {
                if(isUnique(array, number, counter)) {
                    upload(&array, number, counter);
                    counter++;
                }
            }
        }
    }
    print(array, counter);
    return 0;
}

int isUnique(int *array, int number, int count) {
    if(count == 0)
        return 1;

    for(int i = 0; i < count; i++) {
        if(array[i] == number)
            return 0;
    }
    return 1;
}

void upload(int **array, int number, int count) {
    if(count == 0) {
        (*array) = (int *) malloc(sizeof(int) * (count + 1));
        (*array)[count] = number;
    }   else {
        (*array) = (int *) realloc((*array), sizeof(int) * (count + 1));
        (*array)[count] = number;
    }
}

void print(int *array, int count) {
    int total = 0;
    for(int i = 0; i < count; i++) {
        total = total + array[i];
    }
    printf("Number of elements: %d\nTotal: %d", count, total);
}
