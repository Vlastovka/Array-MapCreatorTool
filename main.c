#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int moznost;
int ulozenePole = {};

// Pole funkce

int velikost;
int *pole;

void nactiPole(int *pole, int velikost) {
    for (int i = 0; i < velikost; i++) {
        printf("Přidej hodnotu do pole: ");
        scanf("%d", &pole[i]);
    }
}

void minToMax(int *pole, int velikost) {
    for (int i = 0; i < velikost - 1; i++) {
        for (int j = 0; j < velikost - 1 - i; j++) {
            int *misto = &pole[j];
            int *druheMisto = &pole[j + 1];
            if (*misto > *druheMisto) {
                int docasne = *misto;
                *misto = *druheMisto;
                *druheMisto = docasne;
            }
        }
    }
}

void maxToMin(int *pole, int velikost) {
    for (int i = 0; i < velikost - 1; i++) {
        for (int j = 0; j < velikost - 1 - i; j++) {
            int *misto = &pole[j];
            int *druheMisto = &pole[j + 1];
            if (*misto < *druheMisto) {
                int docasne = *misto;
                *misto = *druheMisto;
                *druheMisto = docasne;
            }
        }
    }
}

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

void vypisPole(int *pole, int velikost) {
    for (int i = 0; i < velikost; i++) {
        printf("%d\n", pole[i]);
    }
}

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

// Mapa tvorba

void tvorbaMapy(int velikost) {
    for (int i = 0; i < velikost; i++) {
        for (int j = 0; j < velikost; j++) {
            printf(". ");
        }
        printf("\n");
    }
}

// Moznosti pro pole

void nabidkaPole() {
    free(pole);
    int moznostProPole = 0;
    while (moznost == 1) {
        switch (moznostProPole) {
            case 0: {
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

                printf("\n 1 - minToMax "
           "\n 2 - maxToMin "
           "\n 3 - Hledani pomoci indexu "
           "\n 4 - Vypis pole "
           "\n 5 - Pridej hodnotu do pole"
           "\n 6 - Vratit se a uložit pole"
           "\n 7 - Vratit se bez uložení pole"
           "\n : ");
                scanf("%d", &moznostProPole);
                break;
            }
            case 1:
                minToMax(pole, velikost);
                sleep(1);
                break;
            case 2:
                maxToMin(pole, velikost);
                sleep(1);
                break;
            case 3:
                konkretniHodnota(pole, velikost);
                sleep(1);
                break;
            case 4:
                vypisPole(pole, velikost);
                sleep(1);
                break;
            case 5:
                pridejHodnotu(&pole, &velikost);
                sleep(1);
                break;
            case 6:
                int cisloPole = 0;
                if (cisloPole <= 0) {
                    printf("Nelze uložit do zaporného pole");
                }

                return;
            case 7:
                return;
            default:
                printf("\n Neplatný výběr");
                break;
        }
    }
}

void nabidkaMapa() {
    int moznostProMapu = 0;
}

// Hlavni nabídka

void nabidka() {
    while (1) {
        printf("Vyber si jednu z možností "
            "\n 1 - Číselné Pole"
            "\n 2 - Mapa"
            "\n 3 - Konec"
            "\n :");
        scanf("%d", &moznost);
        switch (moznost) {
            case 1: {
                nabidkaPole();
                break;
            }
            case 2: {
                nabidkaMapa();
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