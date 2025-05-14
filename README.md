# **Kelompok_6_UAS** <br>
Kelompok 6 <br>
Putroe Fatimah Az-Zahra 2408107010002 <br>
Dedek Saleha 2408107010023 <br>
Fayla Syifa Rustam 2408107010029 <br>
Habib Nuran Mulkan 2408107010109 <br>

LibraryKu - Mini Perpustakaan Console Based
LibraryKu adalah sebuah program perpustakaan berbasis terminal (console-based) yang ditulis dalam bahasa C. Program ini menyediakan fitur manajemen buku dan peminjaman buku dengan dua peran pengguna utama: Admin dan User. Program menggunakan penyimpanan file .txt untuk menyimpan data secara permanen.

**Fitur Utama**
1. Register & Login
   Admin dan User dapat mendaftar (register) terlebih dahulu.
   Sistem akan menolak username yang sudah terpakai.
   Login menggunakan validasi username dan password, termasuk jika mengandung spasi.
   
2. Admin
   Tambah Buku
   Tampilkan Daftar Buku
   Edit Buku
   Proses Antrian
   Keluar
   
4. User
   Lihat Daftar Buku
   Cari Buku
   Ajukan Peminjaman Buku
   Lihat Peminjaman Saya
   Lihat Rekomendasi Buku
   Kembalikan Buku
   Keluar
   
5. Struktur File<br>
   main.c – Alur utama program dan menu awal.
   fungsi.c – Berisi semua fungsi untuk login, register, manajemen buku, antrian, pencarian, dll.
   fungsi.h – Header file untuk mendeklarasikan fungsi-fungsi.
   admin.txt – Menyimpan data akun admin.
   user.txt – Menyimpan data akun user.
   buku.txt – Menyimpan data buku secara permanen.

6. Cara Menjalankan
    Kompilasi program:
    gcc main.c fungsi.c -o libraryku
    Jalankan program:
   ./libraryku




