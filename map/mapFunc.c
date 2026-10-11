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
int *savedRows = NULL;
int *savedColumns = NULL;

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

void printMap() {
    printf("\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%c ", mapArray[i][j]);
        }
        printf("\n");
    }
}


void editRow() {
    if (mapArray == NULL) {
        printf("Create a map first!\n");
        return;
    }

    int row;
    char newSymbol;

    printf("Enter row to edit (0-%d):\n: ", rows - 1);
    scanf("%d", &row);

    if (row < 0 || row >= rows) {
        printf("Invalid row!\n");
        return;
    }

    printf("Enter new symbol:\n: ");
    scanf(" %c", &newSymbol);

    for (int i = 0; i < columns; i++) {
        mapArray[row][i] = newSymbol;
    }

    printf("Row edited successfully!\n");
    printMap();
}

void editColumn() {
    if (mapArray == NULL) {
        printf("Create a map first!\n");
        return;
    }

    int column;
    char newSymbol;

    printf("Enter column to edit (0-%d):\n: ", columns - 1);
    scanf("%d", &column);

    if (column < 0 || column >= columns) {
        printf("Invalid column!\n");
        return;
    }

    printf("Enter new symbol:\n: ");
    scanf(" %c", &newSymbol);

    for (int i = 0; i < rows; i++) {
        mapArray[i][column] = newSymbol;
    }

    printf("Column edited successfully!\n");
    printMap();
}

void editByRowAndColumn() {
    if (mapArray == NULL) {
        printf("Create a map first!\n");
        return;
    }

    int row;
    int column;
    char newSymbol;

    printf("Enter row:\n: ");
    scanf("%d", &row);

    printf("Enter column:\n: ");
    scanf("%d", &column);

    if (row < 0 || row >= rows ||
        column < 0 || column >= columns) {
        printf("Invalid row or column!\n");
        return;
    }

    printf("Enter new symbol:\n: ");
    scanf(" %c", &newSymbol);

    mapArray[row][column] = newSymbol;

    printf("Cell edited successfully!\n");
    printMap();
}

void loadMap() {
    if (saveMapNumber == 0) {
        printf("No saved maps!\n");
        return;
    }

    printf("Saved maps: %d\n", saveMapNumber);

    int mapNumber;

    printf("Enter map number (0-%d):\n: ", saveMapNumber - 1);
    scanf("%d", &mapNumber);

    if (mapNumber < 0 || mapNumber >= saveMapNumber) {
        printf("Invalid map number!\n");
        return;
    }

    mapArray = savedMap[mapNumber];

    rows = savedRows[mapNumber];
    columns = savedColumns[mapNumber];

    printf("Map loaded successfully!\n");
    printMap();
}
void saveMap() {
    if (mapArray == NULL) {
        printf("Create a map first!\n");
        return;
    }

    int **copy = malloc(rows * sizeof(int *));

    if (copy == NULL) {
        printf("Map saving failed!\n");
        return;
    }

    for (int i = 0; i < rows; i++) {
        copy[i] = malloc(columns * sizeof(int));

        if (copy[i] == NULL) {
            printf("Map saving failed!\n");

            for (int j = 0; j < i; j++) {
                free(copy[j]);
            }

            free(copy);
            return;
        }

        for (int j = 0; j < columns; j++) {
            copy[i][j] = mapArray[i][j];
        }
    }

    int ***newSavedMap = realloc(
        savedMap,
        (saveMapNumber + 1) * sizeof(int **)
    );

    if (newSavedMap == NULL) {
        printf("Map saving failed!\n");

        for (int i = 0; i < rows; i++) {
            free(copy[i]);
        }

        free(copy);
        return;
    }

    savedMap = newSavedMap;

    int *newSavedRows = realloc(
        savedRows,
        (saveMapNumber + 1) * sizeof(int)
    );

    if (newSavedRows == NULL) {
        printf("Map saving failed!\n");

        for (int i = 0; i < rows; i++) {
            free(copy[i]);
        }

        free(copy);
        return;
    }

    savedRows = newSavedRows;

    int *newSavedColumns = realloc(
        savedColumns,
        (saveMapNumber + 1) * sizeof(int)
    );

    if (newSavedColumns == NULL) {
        printf("Map saving failed!\n");

        for (int i = 0; i < rows; i++) {
            free(copy[i]);
        }

        free(copy);
        return;
    }

    savedColumns = newSavedColumns;

    savedMap[saveMapNumber] = copy;
    savedRows[saveMapNumber] = rows;
    savedColumns[saveMapNumber] = columns;

    printf("Map saved successfully! Map number: %d\n", saveMapNumber);

    saveMapNumber++;
}