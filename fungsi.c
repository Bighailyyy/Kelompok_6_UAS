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

void hapusBuku() {
    int id, found = 0;
    printf("Masukkan ID buku yang ingin dihapus: ");
    scanf("%d", &id);

    for (int i = 0; i < jumlahBuku; i++) {
        if (daftarBuku[i].id == id) {
            for (int j = i; j < jumlahBuku - 1; j++) {
                daftarBuku[j] = daftarBuku[j + 1];
            }
            jumlahBuku--;
            simpanBukuKeFile();
            printf("Buku berhasil dihapus dari katalog.\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Buku dengan ID %d tidak ditemukan.\n", id);
    }
}

void prosesAntrian() {
    int id = dequeue();
    if (id == -1) {
        printf("Tidak ada antrian.\n");
        return;
    }
    for (int i = 0; i < jumlahBuku; i++) {
        if (daftarBuku[i].id == id && daftarBuku[i].stok > 0) {
            daftarBuku[i].stok--;
            simpanBukuKeFile();
            printf("Peminjaman buku '%s' diproses.\n", daftarBuku[i].judul);
            return;
        }
    }
    printf("Buku tidak ditemukan atau stok habis.\n");
}

void cariBuku() {
    char keyword[100];
    while (getchar() != '\n'); 
    printf("Masukkan judul buku: "); 
    fgets(keyword, 100, stdin);
    keyword[strcspn(keyword, "\n")] = 0;

    int ditemukan = 0;
    for (int i = 0; i < jumlahBuku; i++) {
        if (strstr(daftarBuku[i].judul, keyword)) {
            printf("[%d] %s oleh %s | Genre: %s | Stok: %d\n",
                   daftarBuku[i].id, daftarBuku[i].judul, daftarBuku[i].penulis,
                   daftarBuku[i].genre, daftarBuku[i].stok);
            ditemukan = 1;
        }
    }
    if (!ditemukan) {
        printf("Buku dengan judul '%s' tidak ditemukan.\n", keyword);
    }
}

void ajukanPeminjaman() {
    if (jumlahBuku == 0) {
        printf("Belum ada buku dalam katalog. Tidak bisa meminjam.\n");
        return;
    }

    int id;
    printf("Masukkan ID buku yang ingin dipinjam: ");
    scanf("%d", &id);
}

void lihatPeminjamanSaya() {
    NodePeminjaman* temp = daftarPeminjaman;
    int ada = 0;

    if (!temp) {
        printf("Belum ada buku yang dipinjam.\n");
        return;
    }

    while (temp) {
        for (int i = 0; i < jumlahBuku; i++) {
            if (daftarBuku[i].id == temp->idBuku) {
                printf("%s\n", daftarBuku[i].judul);
                ada = 1;
                break;
            }
        }
        temp = temp->next;
    }

    if (!ada) {
        printf("Belum ada buku yang dipinjam atau semua buku sudah dihapus dari katalog.\n");
    }
}

void lihatRekomendasi() {
    if (jumlahBuku == 0) {
        printf("Belum ada buku yang direkomendasikan.\n");
        return;
    }

    for (int i = 0; i < jumlahBuku - 1; i++) {
        for (int j = i + 1; j < jumlahBuku; j++) {
            if (daftarBuku[j].stok > daftarBuku[i].stok) {
                Buku temp = daftarBuku[i];
                daftarBuku[i] = daftarBuku[j];
                daftarBuku[j] = temp;
            }
        }
    }
    printf("Rekomendasi buku berdasarkan stok tertinggi:\n");
    tampilkanBuku();
}

void kembalikanBuku() {
    if (!daftarPeminjaman) {
        printf("Tidak ada buku yang sedang dipinjam.\n");
        return;
    }

    int id;
    printf("Masukkan ID buku yang ingin dikembalikan: ");
    scanf("%d", &id);

    NodePeminjaman *prev = NULL, *curr = daftarPeminjaman;
    while (curr != NULL) {
        if (curr->idBuku == id) {
            for (int i = 0; i < jumlahBuku; i++) {
                if (daftarBuku[i].id == id) {
                    daftarBuku[i].stok++;
                    simpanBukuKeFile();
                    printf("Buku '%s' berhasil dikembalikan.\n", daftarBuku[i].judul);
                    break;
                }
            }

            // Hapus node dari daftarPeminjaman
            if (prev == NULL) {
                daftarPeminjaman = curr->next;
            } else {
                prev->next = curr->next;
            }
            free(curr);
            return;
        }

        prev = curr;
        curr = curr->next;
    }

    printf("ID buku tidak ditemukan dalam daftar peminjaman Anda.\n");
}

int usernameSudahAda(const char* file, const char* username) {
    FILE* f = fopen(file, "r");
    if (!f) return 0;
    char user[100], pass[100];
    while (fscanf(f, "%[^;];%[^\n]\n", user, pass) != EOF) {
        if (strcmp(user, username) == 0) {
            fclose(f);
            return 1;
        }
    }
    fclose(f);
    return 0;
}

void registerAdmin() {
    FILE* f = fopen("admin.txt", "a");
    if (!f) {
        printf("Gagal membuka file admin.\n");
        return;
    }

    char username[100], password[100];
    getchar();
    printf("Masukkan username admin: "); fgets(username, sizeof(username), stdin);
    printf("Masukkan password admin: "); fgets(password, sizeof(password), stdin);
    username[strcspn(username, "\n")] = 0;
    password[strcspn(password, "\n")] = 0;

    if (usernameSudahAda("admin.txt", username) || usernameSudahAda("user.txt", username)) {
        printf("Username sudah digunakan.\n");
        fclose(f);
        return;
    }

    fprintf(f, "%s;%s\n", username, password);
    fclose(f);
    printf("Register admin berhasil.\n");
}
void registerUser() {
    FILE* f = fopen("user.txt", "a");
    if (!f) {
        printf("Gagal membuka file user.\n");
        return;
    }

    char username[100], password[100];
    getchar();
    printf("Masukkan username user: "); fgets(username, sizeof(username), stdin);
    printf("Masukkan password user: "); fgets(password, sizeof(password), stdin);
    username[strcspn(username, "\n")] = 0;
    password[strcspn(password, "\n")] = 0;

    if (usernameSudahAda("user.txt", username) || usernameSudahAda("admin.txt", username)) {
        printf("Username sudah digunakan.\n");
        fclose(f);
        return;
    }

    fprintf(f, "%s;%s\n", username, password);
    fclose(f);
    printf("Register user berhasil.\n");
}
int loginCocok(const char* file, char* username, char* password) {
    FILE* f = fopen(file, "r");
    if (!f) return 0;
    char user[100], pass[100];
    while (fscanf(f, "%[^;];%[^\n]\n", user, pass) != EOF) {
        if (strcmp(user, username) == 0 && strcmp(pass, password) == 0) {
            fclose(f);
            return 1;
        }
    }
    fclose(f);
    return 0;
}

int loginAdmin() {
    char username[100], password[100];
    getchar();
    printf("Masukkan username admin: "); fgets(username, sizeof(username), stdin);
    printf("Masukkan password admin: "); fgets(password, sizeof(password), stdin);
    username[strcspn(username, "\n")] = 0;
    password[strcspn(password, "\n")] = 0;
    if (loginCocok("admin.txt", username, password)) return 1;
    return 0;
}
int loginUser() {
    char username[100], password[100];
    getchar();
    printf("Masukkan username user: "); fgets(username, sizeof(username), stdin);
    printf("Masukkan password user: "); fgets(password, sizeof(password), stdin);
    username[strcspn(username, "\n")] = 0;
    password[strcspn(password, "\n")] = 0;
    if (loginCocok("user.txt", username, password)) return 1;
    return 0;
}

void menuAdmin() {
    int pilihan;
    char newline;
    do {
        printf("\n=== ADMIN MENU ===\n");
        printf("1. Tambah Buku\n");
        printf("2. Tampilkan Buku\n");
        printf("3. Edit Buku\n");
        printf("4. Proses Antrian\n");
        printf("5. Hapus Buku dari Katalog\n");
        printf("6. Kembali ke Menu Login\n");
        printf("7. Keluar dari Program\n");

        printf("Pilih: ");
        if (scanf("%d%c", &pilihan, &newline) != 2 || newline != '\n') {
            printf("Input tidak valid! Harus berupa angka.\n");
            while (getchar() != '\n');
            pilihan = -1;
            continue;
        }

        switch (pilihan) {
            case 1: tambahBuku(); break;
            case 2: tampilkanBuku(); break;
            case 3: editBuku(); break;
            case 4: prosesAntrian(); break;
            case 5: hapusBuku(); break;
            case 6: printf("Kembali ke menu login...\n"); break;
            case 7:
                printf("Terimakasih sudah menggunakan LibraryKu!\n");
                exit(0);
            default: printf("Pilihan tidak valid.\n");
        }
    } while (pilihan != 6);
}

