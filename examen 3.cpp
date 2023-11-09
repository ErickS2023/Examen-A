/*
// da el valor aproximado de mis 3 ultimos digitos 622
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define MAX_WORD_LENGTH 50

int main(){
    char line[5172]; 
    char* word;
    int count = 0;
    bool condition = false;
    
    FILE* file = fopen("emails.csv", "r");

    if(file == NULL){
        perror("Error en la apertura del archivo");
        return 1;
    }

    
    for (int i = 0; i < 50; ++i) {
        fgets(line, sizeof(line), file);

        
        if (i > 0) {
            word = strtok(line, ",");
            while (word != NULL) {
                count++;
                word = strtok(NULL, ",");
            }
        }
    }

    printf("%d", count);
    fclose(file);
    printf("\n\nTodo esta en viento en popa...\n\n\n\n");

    return 0;
}
|*/


#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 50

int main() {
    char line[5172];
    char *word;
    bool isHeader = true;

    FILE *file = fopen("emails.csv", "r");

    if (file == NULL) {
        perror("Error en la apertura del archivo");
        return 1;
    }

    int start_row = 622; // Últimos tres dígitos del ID (180622)
    int current_row = 0;

    while (fgets(line, sizeof(line), file) != NULL) {
        current_row++;

        if (current_row >= start_row && current_row < start_row + 50) {
            if (isHeader) {
                isHeader = false;
            } else {
                word = strtok(line, ",");
                while (word != NULL) {
                    printf("%s, 1\n", word);
                    word = strtok(NULL, ",");
                }
            }
        }
    }

    fclose(file);

    printf("\n\nTodo está en viento en popa...\n\n\n\n");

    return 0;
}


/*
// un aproximado de los diferentes emails
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 50

int main() {
    char line[5172];
    char *word;
    bool isHeader = true;
    int emailCount = 0;

    FILE *file = fopen("emails.csv", "r");

    if (file == NULL) {
        perror("Error en la apertura del archivo");
        return 1;
    }

    int start_row = 622; // Últimos tres dígitos del ID (180622)
    int current_row = 0;

    while (fgets(line, sizeof(line), file) != NULL) {
        current_row++;

        if (current_row >= start_row && current_row < start_row + 50) {
            if (isHeader) {
                isHeader = false;
            } else {
                emailCount++;
                printf("Email %d:\n", emailCount);
                word = strtok(line, ",");
                while (word != NULL) {
                    printf("%s, 1\n", word);
                    word = strtok(NULL, ",");
                }
                printf("\n");
            }
        }
    }

    fclose(file);

    printf("\n\nTodo está en viento en popa...\n\n\n\n");

    return 0;
}
|*/


















































