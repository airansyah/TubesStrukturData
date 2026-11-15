#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED
#include <iostream>
using namespace std;

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

//child------------------------------//
struct kepanitiaan{
    string kode;
    string nama_kepanitiaan;
    string jabatan;
};
typedef kepanitiaan infokepanitiaan;
typedef struct elmkepanitiaan *adrkepanitiaan;
struct elmkepanitiaan{
    infokepanitiaan info;
    adrkepanitiaan next;
};
struct Listkepanitiaan {
    adrChild first;
};

//relasi_parent_to_child-----------------//
struct relasi{
    string idkepanitiaan;
    string nim;
    string id_acara;
    int point_keaktifan;
};
typedef relasi inforelasi;
typedef struct elmRelasi *adrrelasi;
struct elmRelasi {
    infoRelasi info;
    adrChild child;
    adrRelasi next;
};
struct ListRelasi {
    adrRelasi first;
};

void createListmahasiswa(listmahasiswa &L);
void createListkepanitiaan(Listkepanitiaan &L);
void createListrelasi(ListRelasi &L);
adrmahasiswa findmahasiswa(listmahasiswa L, string nim);
adrkepanitiaan findkepanitiaan(Listkepanitiaan L, string kode);
bool isrelasi(ListRelasi L, string nim, string kode);
adrmahasiswa allocatemahasiswa(infomahasiswa x);
adrkepanitiaan allocatekepanitiaan(infokepanitiaan x);
adrrelasi allocaterelasi(inforelasi x);

void insertfirstmahasiswa(listmahasiswa &L, adrmahasiswa p);
void insertlastmahasiswa(listmahasiswa &L, adrmahasiswa p);
void insertfirsrelasi(ListRelasi &R, adrrelasi r);
void insertlastrelasi(ListRelasi &R, adrrelasi r);

void deletemahasiswa(listmahasiswa &L, infomahasiswa &p);
void deletekepanitiaan(Listkepanitiaan &L, infokepanitiaan &p);
void deleterelasi(ListRelasi &L, inforelasi &p);


#endif // TUBES_H_INCLUDED
