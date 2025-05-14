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

int main() {
    initQueue();
    muatBukuDariFile();

    int opsi;
    do {
        printf("\n=== Selamat Datang di LibraryKu ===\n");
        printf("1. Register Admin\n");
        printf("2. Register User\n");
        printf("3. Login Admin\n");
        printf("4. Login User\n");
        printf("5. Keluar\n");

        opsi = inputAngka();  // Menggunakan fungsi validasi input

        switch (opsi) {
            case 1:
                registerAdmin();
                break;
            case 2:
                registerUser();
                break;
            case 3:
                if (loginAdmin())
                    menuAdmin();
                else
                    printf("Password atau username anda salah. Silakan coba lagi!\n");
                break;
            case 4:
                if (loginUser())
                    menuUser();
                else
                    printf("Password atau username anda salah. Silakan coba lagi!\n");
                break;
            case 5:
                printf("Terimakasih sudah menggunakan LibraryKu!\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }

    } while (opsi != 5);

    return 0;
}
