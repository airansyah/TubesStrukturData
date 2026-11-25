# Kepanitiaan Acara Kampus (MLL-01 + BST)

Tugas Besar Struktur Data, Topik 9: program terminal C++ untuk mengelola data mahasiswa,
kepanitiaan acara kampus, dan keikutsertaan mahasiswa di dalamnya.

## Kelompok WhenYahIMO (IF-49-09)

| Nama | NIM |
| --- | --- |
| Airansyah Muhafiz Halizamni | 103012500332 |
| Muhammad Wildan Al Fattah | 103012500157 |

## Struktur Data

- **Multi Linked List (MLL-01)**: mahasiswa sebagai parent, kepanitiaan sebagai child,
  dan list relasi di dalam tiap mahasiswa (id acara, divisi, jabatan, poin keaktifan).
- **Binary Search Tree**: daftar mahasiswa yang pernah menjadi panitia, dengan kunci NIM.

## Progres

- [x] Create, alokasi, dan insert mahasiswa, kepanitiaan, relasi
- [x] Cari mahasiswa/kepanitiaan dan cek relasi
- [x] Hapus mahasiswa, kepanitiaan, dan relasi tertentu
- [x] Batas maksimal 3 kepanitiaan per mahasiswa
- [ ] Tampil semua parent beserta child dan sebaliknya
- [ ] Hitung jumlah parent dari child tertentu
- [ ] BST: insert, cari, hapus, traversal, min, max, tinggi, jumlah node
- [ ] Tambah poin keaktifan, 5 mahasiswa teraktif, kepanitiaan terbanyak per kategori

## Struktur File

| File | Isi |
| --- | --- |
| `tubes.h` | Definisi tipe dan prototype subprogram |
| `tubes.cpp` | Implementasi subprogram ADT |
| `main.cpp` | Menu interaktif di terminal |

## Cara Menjalankan

```bash
g++ main.cpp tubes.cpp -o tubes
./tubes
```

Di Windows (PowerShell), jalankan dengan `.\tubes.exe`.
