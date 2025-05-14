#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fungsi.h"

Buku daftarBuku[MAX];
int jumlahBuku = 0;
Queue antrian;
NodePeminjaman* daftarPeminjaman = NULL;

void initQueue() {
    antrian.front = antrian.rear = -1;
}

int isQueueFull() {
    return antrian.rear == MAX - 1;
}

int isQueueEmpty() {
    return antrian.front == -1;
}

void enqueue(int idBuku) {
    if (isQueueFull()) return;
    if (isQueueEmpty()) antrian.front = 0;
    antrian.data[++antrian.rear] = idBuku;
}

int dequeue() {
    if (isQueueEmpty()) return -1;
    int data = antrian.data[antrian.front];
    if (antrian.front == antrian.rear) antrian.front = antrian.rear = -1;
    else antrian.front++;
    return data;
}

void simpanBukuKeFile() {
    FILE* file = fopen("buku.txt", "w");
    for (int i = 0; i < jumlahBuku; i++) {
        fprintf(file, "%d;%s;%s;%s;%d\n", daftarBuku[i].id, daftarBuku[i].judul, daftarBuku[i].penulis, daftarBuku[i].genre, daftarBuku[i].stok);
    }
    fclose(file);
}

void muatBukuDariFile() {
    FILE* file = fopen("buku.txt", "r");
    if (!file) return;

    while (fscanf(file, "%d;%[^;];%[^;];%[^;];%d\n", &daftarBuku[jumlahBuku].id, daftarBuku[jumlahBuku].judul,
                  daftarBuku[jumlahBuku].penulis, daftarBuku[jumlahBuku].genre, &daftarBuku[jumlahBuku].stok) != EOF) {
        jumlahBuku++;
    }
    fclose(file);
}

int idBukuSudahAda(int id) {
    for (int i = 0; i < jumlahBuku; i++) {
        if (daftarBuku[i].id == id) return 1;
    }
    return 0;
}

void tambahBuku() {
    Buku b;
    printf("ID Buku: "); scanf("%d", &b.id);
    if (idBukuSudahAda(b.id)) {
        printf("ID buku sudah digunakan!\n");
        return;
    }
    getchar();
    printf("Judul: "); fgets(b.judul, 100, stdin);
    printf("Penulis: "); fgets(b.penulis, 100, stdin);
    printf("Genre: "); fgets(b.genre, 50, stdin);
    printf("Stok: "); scanf("%d", &b.stok);

    b.judul[strcspn(b.judul, "\n")] = 0;
    b.penulis[strcspn(b.penulis, "\n")] = 0;
    b.genre[strcspn(b.genre, "\n")] = 0;

    daftarBuku[jumlahBuku++] = b;
    simpanBukuKeFile();
    printf("Buku berhasil ditambahkan.\n");
}

void tampilkanBuku() {
    if (jumlahBuku == 0) {
        printf("Belum ada buku yang tersedia.\n");
        return;
    }

    for (int i = 0; i < jumlahBuku; i++) {
        printf("[%d] %s oleh %s | Genre: %s | Stok: %d\n",
               daftarBuku[i].id, daftarBuku[i].judul,
               daftarBuku[i].penulis, daftarBuku[i].genre, daftarBuku[i].stok);
    }
}

void editBuku() {
    int id, found = 0;
    printf("Masukkan ID buku yang ingin diedit: ");
    scanf("%d", &id);
    for (int i = 0; i < jumlahBuku; i++) {
        if (daftarBuku[i].id == id) {
            getchar();
            printf("Judul Baru: "); fgets(daftarBuku[i].judul, 100, stdin);
            printf("Penulis Baru: "); fgets(daftarBuku[i].penulis, 100, stdin);
            printf("Genre Baru: "); fgets(daftarBuku[i].genre, 50, stdin);
            printf("Stok Baru: "); scanf("%d", &daftarBuku[i].stok);

            daftarBuku[i].judul[strcspn(daftarBuku[i].judul, "\n")] = 0;
            daftarBuku[i].penulis[strcspn(daftarBuku[i].penulis, "\n")] = 0;
            daftarBuku[i].genre[strcspn(daftarBuku[i].genre, "\n")] = 0;

            found = 1;
            simpanBukuKeFile();
            printf("Buku berhasil diedit.\n");
            break;
        }
    }
    if (!found) printf("Buku tidak ditemukan.\n");
}


