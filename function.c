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

