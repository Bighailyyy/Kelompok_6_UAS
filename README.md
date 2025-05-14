PROJEK UAS PRAKTIKUM STRUKTUR DATA DAN ALGORITMA<br>

Kelompok 6 <br>
Putroe Fatimah Az-Zahra 2408107010002 <br>
Dedek Saleha 2408107010023 <br>
Fayla Syifa Rustam 2408107010029 <br>
Habib Nuran Mulkan 2408107010109 <br>

LibraryKu - Mini Perpustakaan Console Based<br>
LibraryKu adalah sebuah program perpustakaan berbasis terminal (console-based) yang ditulis dalam bahasa C. Program ini menyediakan fitur manajemen buku dan peminjaman buku dengan dua peran pengguna utama: Admin dan User. Program menggunakan penyimpanan file .txt untuk menyimpan data secara permanen.

Fitur Utama<br>
1. Register & Login<br>
   Admin dan User dapat mendaftar (register) terlebih dahulu.<br>
   Sistem akan menolak username yang sudah terpakai.<br>
   Login menggunakan validasi username dan password, termasuk jika mengandung spasi.<br>
   
2. Admin<br>
   Tambah Buku<br>
   Tampilkan Daftar Buku<br>
   Edit Buku<br>
   Proses Antrian<br>
   Hapus Buku<br>
   Keluar<br>
   
4. User<br>
   Lihat Daftar Buku<br>
   Cari Buku<br>
   Ajukan Peminjaman Buku<br>
   Lihat Peminjaman Saya<br>
   Lihat Rekomendasi Buku<br>
   Kembalikan Buku<br>
   Keluar<br>
   
5. Struktur File<br>
   main.c – Alur utama program dan menu awal.<br>
   fungsi.c – Berisi semua fungsi untuk login, register, manajemen buku, antrian, pencarian, dll.<br>
   fungsi.h – Header file untuk mendeklarasikan fungsi-fungsi.<br>
   admin.txt – Menyimpan data akun admin.<br>
   user.txt – Menyimpan data akun user.<br>
   buku.txt – Menyimpan data buku secara permanen.<br>

6. Cara Menjalankan<br>
    Kompilasi program:<br>
    gcc main.c fungsi.c -o libraryku<br>
    Jalankan program:<br>
   ./libraryku<br>




