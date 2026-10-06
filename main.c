#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int moznost;
int pocetPoli = 0;
int **ulozenePole;
int *velikostUlozenychPoli;
int cisloUlozeni = 0;


// Pole funkce

int velikost;
int *pole;

// Pridani hodnot od uživatele do pole jenž si uživatel vytvořil na začátku

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
            if (*misto > *druheMisto && funkce == 0) { // minToMax funkce
                int docasne = *misto;
                *misto = *druheMisto;
                *druheMisto = docasne;
            }
            if (*misto < *druheMisto && funkce == 1) { // maxToMin Funkce
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
           "\n 4 - Basic array math"
           "\n 5 - Load array. WARNING current array will be deleted!"
           "\n 6 - Save array & exit"
           "\n 7 - Exit without saving");
        scanf("%d", &moznostProPole);

        switch (moznostProPole) {
            case 1:
                bubbleSort(pole, velikost, 0);
                sleep(1);
                break;
            case 2:
                bubbleSort(pole, velikost, 1);
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

void nabidkaMapa() {
    int moznostProMapu = 0;
}

// Hlavni nabídka

void nabidka() {
    while (1) {
        printf("\n Vyber si jednu z možností "
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