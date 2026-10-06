//
// Created by vlastovka on 06.10.2026.
//

#ifndef UCENIC_ARRAY_H
#define UCENIC_ARRAY_H

// Global

int velikost;
int *pole;
int moznost;
int pocetPoli = 0;
int **ulozenePole;
int *velikostUlozenychPoli;
int cisloUlozeni = 0;

// functions

void nactiPole(int *pole, int velikost); // Array creation
void bubbleSort(int *pole, int velikost, int funkce); // Sorting function
void konkretniHodnota(int *pole, int velikost); // Finding by index in array
void vypisPole(int *pole, int velikost); // Print current array
void pridejHodnotu(int **pole, int *velikost); // adding more values to array

// Saving & loading array

void ulozitPole(int *pole,int velikost,int cisloUlozeni);
void nacistZUlozenychPoli();

// Array math

void totalValue(int *pole, int velikost);
void countTwoValues(int *pole, int velikost);
void substractTwoValues(int *pole, int velikost);
void divisionTwoValues(int *pole, int velikost);
void multiplyTwoValues(int *pole, int velikost);

#endif //UCENIC_ARRAY_H