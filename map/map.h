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

// functions

void createMap();
void saveMap(int **mapArray, int saveMapNumber);
#endif //UCENIC_MAP_H
