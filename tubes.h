#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

//child------------------------------//
struct kepanitiaan{
    string kode;
    string nama_kepanitiaan;
    string kategori;
};
typedef kepanitiaan infokepanitiaan;
typedef struct elmkepanitiaan *adrkepanitiaan;
struct elmkepanitiaan{
    infokepanitiaan info;
    adrkepanitiaan next;
};
struct Listkepanitiaan {
    adrkepanitiaan first;
};

//relasi_parent_to_child-----------------//
struct Relasi{
    string idkepanitiaan;
    string nim;
    string id_acara;
    string divisi;
    string jabatan;
    int point_keaktifan;
};
typedef Relasi infoRelasi;
typedef struct elmRelasi *adrrelasi;
struct elmRelasi {
    infoRelasi info;
    adrkepanitiaan kepanitiaan;
    adrrelasi next;
};
struct ListRelasi {
    adrrelasi first;
};

//parent--------------------------------//
struct mahasiswa {
    string nim;
    string nama;
    string prodi;
    int angkatan;
};
typedef mahasiswa infomahasiswa;
typedef struct elmmahasiswa *adrmahasiswa;
struct elmmahasiswa{
    infomahasiswa info;
    ListRelasi relasi;
    adrmahasiswa next;
};
struct listmahasiswa{
    adrmahasiswa first;
};

void createListmahasiswa(listmahasiswa &L);
void createListkepanitiaan(Listkepanitiaan &L);
 void createListrelasi(ListRelasi &L);
adrmahasiswa findmahasiswa(listmahasiswa L, string nim);
adrkepanitiaan findkepanitiaan(Listkepanitiaan L, string kode);
bool isrelasi(listmahasiswa L, string kepanitiaan, string nim);
adrmahasiswa allocatemahasiswa(infomahasiswa x);
adrkepanitiaan allocatekepanitiaan(infokepanitiaan x);
adrrelasi allocaterelasi(infoRelasi x);
int countrelasi(ListRelasi L);
void deallocaterelasi(adrrelasi &p);

void insertfirstmahasiswa(listmahasiswa &L, adrmahasiswa p);
void insertfirstkepanitiaan(Listkepanitiaan &L, adrkepanitiaan p);
void insertlastrelasi(ListRelasi &R, adrrelasi r);

void tambahrelasi(listmahasiswa &L, Listkepanitiaan &K, string nim, string kode,
                  string id_acara, string divisi, string jabatan, int point_keaktifan);

void deleteallrelasi(ListRelasi &L);
void hapusrelasikode(ListRelasi &R, string kode);
void deleterelasi(listmahasiswa &L, string nim, string kode);
void deletemahasiswa(listmahasiswa &L, string nim);
void deletekepanitiaan(Listkepanitiaan &k, listmahasiswa &L, string kode);

#endif // TUBES_H_INCLUDED
