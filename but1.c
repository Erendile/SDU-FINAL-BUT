#include <stdio.h>
#define SIZE 20

struct Student {
    char name[SIZE];
    char surname[SIZE];
    int number;
    int midterm;
};
int main() {
    struct Student students[20];
    float total = 0, average = 0;

    for(int i = 0; i < 20; i++) {
        printf("%d-) Name: ", i + 1);
        scanf("%s", students[i].name);
        printf("%d-) Surname: ", i + 1);
        scanf("%s", students[i].surname);
        printf("%d-) Number: ", i + 1);
        scanf("%d", &students[i].number);
        printf("%d-) Midterm: ", i + 1);
        scanf("%d", &students[i].midterm);
    }

    for(int i = 0; i < 20; i++) {
        total = total + students[i].midterm;
    }

    average = total / 20;

    for(int i = 0; i < 20; i++) {
        if(students[i].midterm < average)
            printf("%d\n", students[i].number);
    }

    return 0;
}
