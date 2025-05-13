#ifndef FUNGSI_H
#define FUNGSI_H

#define MAX 100

typedef struct {
    int id;
    char judul[100];
    char penulis[100];
    char genre[50];
    int stok;
} Buku;

typedef struct NodePeminjaman {
    int idBuku;
    struct NodePeminjaman* next;
} NodePeminjaman;

typedef struct {
    int front, rear;
    int data[MAX];
} Queue;

void initQueue();
int isQueueFull();
int isQueueEmpty();
void enqueue(int idBuku);
int dequeue();
void muatBukuDariFile();

void tambahBuku();
void tampilkanBuku();
void editBuku();
void prosesAntrian();

void cariBuku();
void ajukanPeminjaman();
void lihatPeminjamanSaya();
void lihatRekomendasi();

void registerAdmin();
void registerUser();
int loginAdmin();
int loginUser();

void menuAdmin();
void menuUser();

#endif

