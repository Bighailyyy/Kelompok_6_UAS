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

