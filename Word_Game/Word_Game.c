#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include "level1.h"
#include "level2.h"
#include "level3.h"

void level1(char words1[5][20], int *attempts, int *counter);
void level2(char words2[5][20], int *attempts, int *counter);
void level3(char words3[5][20], int *attempts, int *counter);

int main()
{
    char words1[5][20] = {"narrow", "souvenir", "explosion", "accept", "withdraw"};
    char words2[5][20] = {"pleasant", "destination", "accommodation", "ashtray", "italian"};
    char words3[5][20] = {"acquisition", "compensation", "initiative", "vegetation", "residue"};
    int attempts = 5, counter = 0;

    printf("Welcome to Words-Game!\n");
    printf("A word game consisting of 3 levels and the words become more difficult in each level.\n");
    printf("You have a total of 5 lives. Good Luck!\n\n");
    level1(words1, &attempts, &counter); 
    if (attempts > 0){
        printf("\nCongratulations, you passed the first level\n");
        printf("Next Level Questions:\n\n");
        level2(words2, &attempts, &counter);
    }else {
        printf("\nSorry, you ran out of attempts! Your score is: %d/150\n\n", counter * 10);
        return 1;
    }

    if (attempts > 0){
        printf("\nCongratulations, you passed the second level\n");
        printf("The last past questions:\n\n");
        level3(words3, &attempts, &counter);
    }else {
        printf("\nSorry, you ran out of attempts! Your score is: %d/150\n\n", counter * 10);
        return 1;
    } 
    
    if (attempts > 0){
        printf("\nCongratulations, You passed all the levels. Your score is %d/150\n\n", counter * 10);
    }else {
        printf("\nSorry, you ran out of attempts! Your score is: %d/150\n\n", counter * 10);
    }
    return 0;
}
