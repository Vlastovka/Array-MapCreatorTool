#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "array/array.h"
#include "map/map.h"

// Moznosti pro pole

void nabidkaPole() {
    int moznostProPole = 0;

    printf("Jak chceš veliké pole: ");
    scanf("%d", &velikost);

    if (velikost <= 0) {
        printf("Zadej velikost pole větší než 0!");
        return;
    }
    pole = malloc(velikost*sizeof(int));
    if (pole == NULL) {
        printf("Pole se nepodařilo vytvořit");
        return;
    }
    nactiPole(pole, velikost);
    while (moznost == 1) {
        printf(""
           "\n -------------------"
           "\n |      ARRAY      |"
           "\n -------------------"
           "\n 1 - Print array"
           "\n 2 - Sort array"
           "\n 3 - Add value to array"
           "\n 4 - Find in array by index"
           "\n 5 - Basic array math"
           "\n 6 - Load array. WARNING current array will be deleted!"
           "\n 7 - Save array & exit"
           "\n 8 - Exit without saving"
           "\n : ");
        scanf("%d", &moznostProPole);
        switch (moznostProPole) {
            case 1: // Print array select
                vypisPole(pole, velikost);
                sleep(1);
                break;
            case 2: // Sort select
                int moznost;
                printf("\n 1 - Sort array from smallest to biggest"
                       "\n 2 - Sort array from biggest to smallest"
                       "\n :");
                scanf("%d", &moznost);
                switch (moznost) {
                    case 1:
                        bubbleSort(pole, velikost, moznost);
                        break;
                    case 2:
                        bubbleSort(pole, velikost, moznost);
                        break;
                    default:
                        printf("Please enter valid choice next time!");
                        return;
                }
                sleep(1);
                break;
            case 3: // Add value to array select
                pridejHodnotu(&pole, &velikost);
                sleep(1);
                break;
            case 4: // Find in array by index select
                konkretniHodnota(pole, velikost);
                sleep(1);
                break;
            case 5: // Basic math array
                int volba;
                printf("\n 1 - Total array value"
                       "\n 2 - Count two value in array"
                       "\n 3 - Substract two value in array"
                       "\n 4 - Diviosn two value in array"
                       "\n 5 - Multiply two value in array"
                       "\n :");
                scanf("%d", &volba);
                switch (volba) {
                    case 1:
                        arrayBasicMath(pole, velikost, volba);
                        break;
                    case 2:
                        arrayBasicMath(pole, velikost, volba);
                        break;
                    case 3:
                        arrayBasicMath(pole, velikost, volba);
                        break;
                    case 4:
                        arrayBasicMath(pole, velikost, volba);
                        break;
                    case 5: arrayBasicMath(pole, velikost, volba);
                        break;
                    default:
                        printf("Please enter valid choice next time!");
                        break;
                }
                sleep(1);
                break;
            case 6:
                nacistZUlozenychPoli();
                sleep(1);
                break;
            case 7:
                ulozitPole(pole, velikost, cisloUlozeni);
                sleep(1);
                return;
            case 8:
                sleep(1);
                return;
            default:
                printf("\n Neplatný výběr");
                break;
        }
    }
}

void map() {
    int volba;
    while (moznost == 2) {
        printf("\n ------------------");
        printf("\n |       MAP      |");
        printf("\n ------------------");
        printf("\n 1 - Create map & print");
        printf("\n 2 - Print map");
        printf("\n 3 - Edit row");
        printf("\n 4 - Edit column");
        printf("\n 5 - Edit by row & column");
        printf("\n 6 - Save map & exit");
        printf("\n 7 - Load saved map");
        printf("\n 8 - Exit without saving");
        printf("\n : ");
        scanf("%d", &volba);
        switch (volba) {
            case 1:
                createMap();
                break;
            case 2:
                printMap();
                break;
            case 3:
                editRow();
                break;
            case 4:
                editColumn();
                break;
            case 5:
                editByRowAndColumn();
                break;
            case 6:
                saveMap();
                return;
            case 7:
                loadMap();
                break;
            case 8:
                return;
            default:
                printf("Please enter valid choice next time!");
                break;
        }
    }
}

// Hlavni nabídka

void nabidka() {
    while (1) {
        printf("\n Chose option "
            "\n 1 - Number array"
            "\n 2 - Map"
            "\n 3 - End"
            "\n :");
        scanf("%d", &moznost);
        switch (moznost) {
            case 1: {
                nabidkaPole();
                break;
            }
            case 2: {
                map();
                break;
                }
            case 3: {
                return;
                }
            }
        }
    }

int main() {
    nabidka();
}