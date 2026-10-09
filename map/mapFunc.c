//
// Created by vlastovka on 09.10.2026.
//

#include <stdio.h>
#include <stdlib.h>

#include "map.h"

int columns;
int rows;
int **mapArray;
int ***savedMap;
int saveMapNumber;
char symbol = 'B';

void createMap() {
    printf("Enter how many columns in map:\n: ");
    scanf("%d", &columns);
    printf("Enter how many rows in map:\n: ");
    scanf("%d", &rows);
    mapArray = malloc(rows * sizeof(int *));
    if (mapArray == NULL) {
        printf("Map creation failed!\n");
        return;
    }
    for (int i = 0; i < rows; i++) {
        mapArray[i] = malloc(columns * sizeof(int));

        if (mapArray[i] == NULL) {
            printf("Map creation failed when trying to create columns!\n");
            return;
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            mapArray[i][j] = symbol;
        }
    }
    printf("\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%c ", mapArray[i][j]);
        }
        printf("\n");
    }
}