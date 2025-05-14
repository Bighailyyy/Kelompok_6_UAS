#include <stdio.h>
#include "fungsi.h"

int main() {
    initQueue();
    muatBukuDariFile();

    int opsi;
    do {
        printf("\n=== MENU UTAMA ===\n");
        printf("1. Register Admin\n");
        printf("2. Register User\n");
        printf("3. Login Admin\n");
        printf("4. Login User\n");
        printf("5. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &opsi);

        switch (opsi) {
            case 1: registerAdmin(); break;
            case 2: registerUser(); break;
            case 3:
                if (loginAdmin()) menuAdmin();
                else printf("Login admin gagal. Coba lagi.\n");
