//
// Created by vlastovka on 06.10.2026.
//

// Pole funkce

// Pridani hodnot od uživatele do pole jenž si uživatel vytvořil na začátku

#include <stdio.h>
#include <stdlib.h>

#include "array.h"

int velikost;
int *pole;
int moznost;
int pocetPoli = 0;
int **ulozenePole;
int *velikostUlozenychPoli;
int cisloUlozeni = 0;

void nactiPole(int *pole, int velikost) {
    for (int i = 0; i < velikost; i++) {
        printf("Přidej hodnotu do pole: ");
        scanf("%d", &pole[i]);
    }
}

// bubble sort pro seřazení pole od nejmenšího po největší/nějvětšího po nejmenšího

void bubbleSort(int *pole, int velikost, int funkce) {
    for (int i = 0; i < velikost - 1; i++) {
        for (int j = 0; j < velikost - 1 - i; j++) {
            int *misto = &pole[j];
            int *druheMisto = &pole[j + 1];
            if (*misto > *druheMisto && funkce == 1) { // minToMax funkce
                int docasne = *misto;
                *misto = *druheMisto;
                *druheMisto = docasne;
            }
            if (*misto < *druheMisto && funkce == 2) { // maxToMin Funkce
                int docasne = *misto;
                *misto = *druheMisto;
                *druheMisto = docasne;
            }
        }
    }
}

// Konkretni hodnota v poli pomoci indexu

void konkretniHodnota(int *pole, int velikost) {
    int cislo;
    printf("Zadej index: ");
    scanf("%d", &cislo);
    if (cislo >= 0 && cislo < velikost) {
        printf("Hodnota na indexu v poli je: %d\n", pole[cislo]);
    } else {
        printf("Neplatný index \n");
    }
}

// Funkce pro vypsání pole

void vypisPole(int *pole, int velikost) {
    for (int i = 0; i < velikost; i++) {
        printf("%d\n", pole[i]);
    }
}

// Pridani dalších hodnot do existujícího pole

void pridejHodnotu(int **pole, int *velikost) {
    int zadanaVelikost;
    printf("Zadej o kolik chceš zvětšit hodnotu: ");
    scanf("%d", &zadanaVelikost);
    *pole = realloc(*pole, (zadanaVelikost + *velikost)*sizeof(int));

    if (*pole == NULL) {
        printf("Nepodařilo se přidat hodnotu \n");
        return;
    }

    for (int i = 0; i < zadanaVelikost; i++) {
        printf("Přidej hodnot do pole \n");
        scanf("%d", &(*pole)[i + *velikost]);
    }
    *velikost += zadanaVelikost;
}

// Ukládání pole

void ulozitPole(int *pole,int velikost,int cisloUlozeni) {
    ulozenePole = realloc(ulozenePole, (pocetPoli + 1) * sizeof(*ulozenePole));

    if (ulozenePole == NULL) {
        printf("Nepovedlo se uložit pole!");
    }

    velikostUlozenychPoli = realloc(velikostUlozenychPoli, (pocetPoli + 1) * sizeof(int));

    if (velikostUlozenychPoli == NULL) {
        printf("Nepovedlo se uložit pole!");
    }

    ulozenePole[pocetPoli] = malloc(velikost * sizeof(int));

    if (ulozenePole[pocetPoli] == NULL) {
        printf("Nepovedl ose uložit pole!");
    }

    for (int i = 0; i < velikost; ++i) {
        ulozenePole[pocetPoli][i] = pole[i];
    }

    velikostUlozenychPoli[pocetPoli] = velikost;

    printf("Pole ulozeno pod číslem: %d\n", cisloUlozeni);
    pocetPoli++;

    // debug

    for (int i = 0; i < pocetPoli; ++i) {
        printf("%d", velikostUlozenychPoli[i]);
    }
}

// Nacist z ulozenych polí

void nacistZUlozenychPoli() {
    int cisloPole = 0;
    printf("\n Zadej číslo pole které chceš načíst: ");
    scanf("%d", &cisloPole);
    if (cisloPole < 0) {
        printf("\n Číslo nesmí být nula nebo záporné");
    }
    printf("\n Vypisuji ulozene pole: \n");
    for (int i = 0; i < velikostUlozenychPoli[cisloPole]; i++) {
        printf("%d\n", ulozenePole[cisloPole][i]);
    }
    for (int i = 0; i < velikostUlozenychPoli[cisloPole]; ++i) {
        pole[i] = ulozenePole[cisloPole][i];
    }
}

// Basic math functions

void arrayBasicMath(int *pole, int velikost, int volba) {
    int userNum1 = 0;
    int userNum2 = 1;
    int finalValue = 0;
    switch (volba) {
        case 1:
            for (int i = 0; i < velikost; i++) {
                finalValue += pole[i];
            }
            printf("\n Total array value = %d\n", finalValue);
            break;
        case 2:
            printf("\n Enter first index "
                   "\n :");
            scanf("%d", &userNum1);
            printf("\n Enter second index "
                   "\n :");
            scanf("%d", &userNum2);
            if ((userNum1 == userNum2) || (userNum1 > velikost) || (userNum2 > velikost) || (userNum1 < 0) || (userNum2 < 0)) {
                printf("\n Enter valid index!");
                break;
            }
            finalValue = pole[userNum1] + pole[userNum2];
            printf("\n%d ", pole[userNum1]);
            printf(" + ");
            printf("%d",pole[userNum2]);
            printf(" = %d", finalValue);
            break;
        case 3:
            printf("\n Enter first index "
                   "\n :");
            scanf("%d", &userNum1);
            printf("\n Enter second index "
                   "\n :");
            scanf("%d", &userNum2);
            if ((userNum1 == userNum2) || (userNum1 > velikost) || (userNum2 > velikost) || (userNum1 < 0) || (userNum2 < 0)) {
                printf("\n Enter valid index!");
                break;
            }
            finalValue = pole[userNum1] - pole[userNum2];
            printf("\n%d ", pole[userNum1]);
            printf(" - ");
            printf("%d",pole[userNum2]);
            printf(" = %d", finalValue);
            break;
        case 4:
            printf("\n Enter first index "
       "\n :");
            scanf("%d", &userNum1);
            printf("\n Enter second index "
                   "\n :");
            scanf("%d", &userNum2);
            if ((userNum1 == userNum2) || (userNum1 >= velikost) || (userNum2 >= velikost) || (userNum1 < 0) || (pole[userNum2] <= 0)) {
                printf("\n Enter valid index or divison cant be done with number 0!");
                break;
            }
            float finalValueDivison = (float)pole[userNum1] / (float)pole[userNum2];
            printf("\n%d ", pole[userNum1]);
            printf(" / ");
            printf("%d",pole[userNum2]);
            printf(" = %f", finalValueDivison);
            break;
        case 5:
            printf("\n Enter first index "
       "\n :");
            scanf("%d", &userNum1);
            printf("\n Enter second index "
                   "\n :");
            scanf("%d", &userNum2);
            if ((userNum1 == userNum2) || (userNum1 > velikost) || (userNum2 > velikost) || (userNum1 < 0) || (userNum2 < 0)) {
                printf("Enter valid index!");
                break;
            }
            finalValue = pole[userNum1] * pole[userNum2];
            printf("\n%d", pole[userNum1]);
            printf(" * ");
            printf("%d",pole[userNum2]);
            printf(" = %d", finalValue);
            break;
    }
}