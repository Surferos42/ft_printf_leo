#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "process.h"

#define MAX_LEN 50

void processSentences(void) {
    char lol[MAX_LEN];
    int emptyCount = 0;
    int sentenceCount = 0;

    while (1) {
        printf("Wpisz swoje zdanie: ");
        fgets(lol, MAX_LEN, stdin);

        if (lol[strlen(lol) - 1] != '\n') {
            printf("Za długie zdanie :( Jeszcze raz\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            continue;
        }

        lol[strlen(lol) - 1] = '\0';

        int onlyspaces = 1;
        for (int i = 0; lol[i]; i++) {
            if (!isspace(lol[i])) {
                onlyspaces = 0;
                break;
            }
        }

        if (strlen(lol) == 0 || onlyspaces) {
            emptyCount++;
            printf("Nieznany znak :( %d/5\n", emptyCount);
            if (emptyCount >= 5) {
                printf("Nic nie wpisałeś, koniec programu :(\n");
                break;
            }
            continue;
        }

        emptyCount = 0;

        int result = 0;
        for (int i = 0; lol[i]; i++) {
            if (!isspace(lol[i])) {
                result++;
            }
        }

        if (result == 1)
            printf("Twoje zdanie %s, ma %d znak.\n", lol, result);
        else if (result >= 2 && result <= 4)
            printf("Twoje zdanie %s, ma %d znaki.\n", lol, result);
        else
            printf("Twoje zdanie %s, ma %d znaków.\n", lol, result);

        sentenceCount++;
        if (sentenceCount >= 5) {
            printf("Wpisano 5 zdań. Koniec programu :)\n");
            break;
        }
    }
}

