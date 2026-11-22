#include <iostream>
#include "tubes.h"
#include <string>
using namespace std;

void createListmahasiswa(listmahasiswa &L){
  L.first = nullptr;
}
void createListkepanitiaan(Listkepanitiaan &L){
  L.first = nullptr;
}
void createListrelasi(ListRelasi &L){
  L.first = nullptr;
}
adrmahasiswa findmahasiswa(listmahasiswa L, string nim){
  adrmahasiswa p = L.first;
  while(p != nullptr && p -> info.nim != nim){
    p = p -> next;
  }
  return p;
}
adrkepanitiaan findkepanitiaan(Listkepanitiaan L, string kode){
  adrkepanitiaan p = L.first;
  while(p != nullptr && (p -> info.kode != kode)){
    p = p -> next;
  }
  return p;
}
bool isrelasi(listmahasiswa L,string kepanitiaan, string nim){
  adrmahasiswa p = findmahasiswa(L, nim);
  adrrelasi r = nullptr;
  if (p != nullptr){
    r = p -> relasi.first;
    while( r != nullptr && r -> info.idkepanitiaan != kepanitiaan){
      r = r -> next;
    }
  }
  return r != nullptr;
}
adrmahasiswa allocatemahasiswa(infomahasiswa x){
  adrmahasiswa p = new elmmahasiswa;
  p -> next = nullptr;
  p -> relasi.first = nullptr; 
  p ->info.nim = x.nim;
  p ->info.nama = x.nama;
  p ->info.prodi = x.prodi;
  p ->info.angkatan = x.angkatan;
  return p;
}
adrkepanitiaan allocatekepanitiaan(infokepanitiaan x){
  adrkepanitiaan p = new elmkepanitiaan;
  p -> next = nullptr;
  p ->info.kode = x.kode;
  p ->info.nama_kepanitiaan = x.nama_kepanitiaan;
  p ->info.kategori = x.kategori;
  return p;
}
adrrelasi allocaterelasi(infoRelasi x){
  adrrelasi p = new elmRelasi;
  p -> next = nullptr;
  p -> kepanitiaan = nullptr;
  p ->info.idkepanitiaan = x.idkepanitiaan;
  p ->info.nim = x.nim;
  p ->info.id_acara = x.id_acara;
  p ->info.divisi = x.divisi;
  p ->info.jabatan = x.jabatan;
  p ->info.point_keaktifan = x.point_keaktifan;
  return p;
}

int countrelasi(ListRelasi L){
  adrrelasi p = L.first;
  int count = 0;
  while(p != nullptr){
    count++;
    p = p -> next;
  }
  return count;
}

void deallocaterelasi(adrrelasi &p){
  p = nullptr;
}

void tambahrelasi(listmahasiswa &L, Listkepanitiaan &K, string nim, string kode, string id_acara, string divisi, string jabatan, int point_keaktifan){
  adrmahasiswa p = findmahasiswa(L, nim);
  adrkepanitiaan k = findkepanitiaan(K, kode);
  if (p == nullptr || k == nullptr){
    cout << "Data mahasiswa atau kepanitiaan tidak ditemukan" << endl;
  } else if (isrelasi(L, kode, nim)){
    cout << "Mahasisswa sudah terdaftar di kepanitiaan ini" << endl;
  } else if(countrelasi(p -> relasi) >= 3){
    cout << "Mahasiswa sudah terdaftar di 3 kepanitiaan" << endl;
  } else if (p != nullptr && k != nullptr){
    infoRelasi x;
    x.idkepanitiaan = kode;
    x.nim = nim;
    x.id_acara = id_acara;
    x.divisi = divisi;
    x.jabatan = jabatan;
    x.point_keaktifan = point_keaktifan;
    adrrelasi r = allocaterelasi(x);
    r -> kepanitiaan = k;
    insertlastrelasi(p -> relasi, r);
  }
}

void insertfirstmahasiswa(listmahasiswa &L, adrmahasiswa p){
  if (L.first == nullptr){
    L.first = p;
  } else {
    p -> next = L.first;
    L.first = p;
  }
}
void insertfirstkepanitiaan(Listkepanitiaan &L, adrkepanitiaan p){
  if(L.first == nullptr){
    L.first = p;
  } else {
    p -> next = L.first;
    L.first = p;
  }
}
void insertlastrelasi(ListRelasi &R, adrrelasi r){
  if(R.first == nullptr){
    R.first = r;
  }else {
    adrrelasi p = R.first;
    while(p -> next != nullptr){
      p = p -> next;
    }
    p -> next = r;
  }
}

void deletemahasiswa(listmahasiswa &L, string nim){
  adrmahasiswa q = findmahasiswa(L, nim);
  if ( q!= nullptr){
    if (q == L.first && q -> next == nullptr){
      L.first = nullptr;
    }else if (q == L.first && q -> next != nullptr){
      L.first = q -> next;
      q  -> next = nullptr;
    } else {
      adrmahasiswa r = L.first;
      while (r != nullptr && r -> next != q){
        r = r -> next;
      }
      r  -> next = q -> next;
      q -> next = nullptr;
    }
    adrrelasi temp = q -> relasi.first;
    while(temp != nullptr){
      adrrelasi r = temp;
      temp = temp -> next;
      deallocaterelasi(r);
    }
    q -> relasi.first = nullptr;
  }
}
void deletekepanitiaan(Listkepanitiaan &k, listmahasiswa &L, string kode){
  adrkepanitiaan r = findkepanitiaan(k, kode);
  if (r != nullptr){
    adrmahasiswa m = L.first;
    while(m!= nullptr){
      hapusrelasikode(m -> relasi, kode);
      m = m -> next;
    }
    if (r == k.first){
      k.first = r -> next;
    } else {
      adrkepanitiaan p = k.first;
      while (p != nullptr && p -> next != r){
        p = p -> next;
      }
      p -> next = r -> next;
    }
  }
}
void deleteallrelasi(ListRelasi &L){
  adrrelasi p = L.first;
  while(p != nullptr){
    adrrelasi temp = p;
    p = p -> next;
    deallocaterelasi(temp);
  }
  L.first = nullptr; 
}
void hapusrelasikode(ListRelasi &R, string kode){
  if (R.first != nullptr){
    if (R.first -> info.idkepanitiaan == kode){      // kasus: relasi pertama
      adrrelasi r = R.first;
      R.first = r -> next;
      deallocaterelasi(r);
    } else {
      adrrelasi prec = R.first;
      while (prec -> next != nullptr && prec -> next -> info.idkepanitiaan != kode){
        prec = prec -> next;
      }
      if (prec -> next != nullptr){                  // ketemu
        adrrelasi r = prec -> next;
        prec -> next = r -> next;
        deallocaterelasi(r);
      }
    }
  }
} 
void deleterelasi(listmahasiswa &L, string nim, string kode){
  adrmahasiswa m = findmahasiswa(L, nim);
  if (m != nullptr){
    hapusrelasikode(m -> relasi, kode);
  }
}