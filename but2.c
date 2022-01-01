#include <stdio.h>
#define SIZE 20

int isEqual(char letter1, char letter2);
int isUnique(char common[], char letter, int count);
void print(char common[], int count);

int main() {
    char text1[SIZE], text2[SIZE], common[SIZE];
    int counter = 0;
    printf("Enter 2 texts:\n");
    scanf("%s", text1);
    scanf("%s", text2);

    for(int i = 0; text1[i] != '\0'; i++) {
        for(int j = 0; text2[j]; j++) {
            if(isEqual(text1[i], text2[j])) {
                if(isUnique(common, text1[i], counter))
                    common[counter++] = text1[i];
            }
        }
    }
    print(common, counter);
    return 0;
}

int isEqual(char letter1, char letter2) {
    if(letter1 == letter2 || (letter1 + 32) == letter2 || letter1 == (letter2 + 32))
        return 1;
    return 0;
}

int isUnique(char common[], char letter, int count) {
    if(count == 0)
        return 1;
    for(int i = 0; i < count; i++) {
        if(isEqual(common[i], letter))
            return 0;
    }
    return 1;
}

void print(char common[], int count) {
    printf("Common letters: ");
    for(int i = 0; i < count; i++) {
        printf("%c ", common[i]);
    }
    printf("\nThere are %d common letters", count);
}
