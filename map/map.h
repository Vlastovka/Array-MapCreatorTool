//
// Created by vlastovka on 09.10.2026.
//

#ifndef UCENIC_MAP_H
#define UCENIC_MAP_H

// declarations

extern int columns;
extern int rows;
extern int **mapArray;
extern int ***savedMap;
extern int saveMapNumber;
extern char symbol;
extern int *savedRows;
extern int *savedColumns;
// functions

void createMap();
void printMap();

void editRow();
void editColumn();
void editByRowAndColumn();
void loadMap();
void saveMap();

#endif // UCENIC_MAP_H
