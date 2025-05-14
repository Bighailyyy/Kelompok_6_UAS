#include <stdio.h>
#include "fungsi.h"

int inputAngka() {
    int angka;
    while (1) {
        printf("Pilih: ");
        if (scanf("%d", &angka) == 1)
            return angka;
        else {
            printf("Input tidak valid. Harap masukkan angka.\n");
            while (getchar() != '\n'); // flush stdin
        }
    }
}
