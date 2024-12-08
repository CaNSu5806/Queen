#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

void level1(char words1[5][20], int *attempts, int *counter){

    int i, j, num, len, random, used[5]={0};
    char temp,userword[20],originalWord[20];
    srand(time(0));

    for(i = 0; i < 5 && *attempts > 0 ; i++){
        do {
                random = rand() % 5;
        } while (used[random] == 1);

            used[random] = 1;

        strcpy(originalWord, words1[random]);
        
        len = strlen(words1[random]);

        for(j = 0; j < len; j++){
            int randIndex = rand() % len;
            temp = words1[random][j];
            words1[random][j] = words1[random][randIndex];
            words1[random][randIndex] = temp;
        }
        printf("The word is= %s\n",words1[random]);

        while ((*attempts) > 0){
            printf("Your guess: ");
            scanf("%s", userword);

            for (j = 0; j < strlen(userword); j++) {
                userword[j] = tolower(userword[j]);
            }

            if (strcmp(userword, originalWord) == 0){
                printf("Well Down!\n");
                (*counter)++;
                break;
            }else {
                (*attempts)--;
                if (*attempts > 0) {
                    printf("Incorrect! Try again. Attempts left: %d\n", *attempts);
                } else {
                    printf("Sorry, the word was %s.\n", originalWord);
                    
                }
            }
        }
    }
}