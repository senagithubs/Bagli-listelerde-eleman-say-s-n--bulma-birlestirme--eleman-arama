
//SORU1:

#include <stdio.h>
#include <stdlib.h>


struct Dugum {
    int veri;
    struct Dugum* ileri;
};

//  eleman sayısını hesaplama
int elemanSayisi(struct Dugum* baslangic) {
    int sayac = 0; 
    struct Dugum* suanki = baslangic; 

        while (suanki != NULL) {
        sayac++; 
        suanki = suanki->ileri;     }

    return sayac; // eleman sayısını döndürecek
}

// örnek  bağıl listem:

struct Dugum* olusturListe() {
    struct Dugum* baslangic = NULL;
    struct Dugum* ikinci = NULL;
    struct Dugum* ucuncu = NULL;

    
    baslangic = (struct Dugum*)malloc(sizeof(struct Dugum));
    ikinci = (struct Dugum*)malloc(sizeof(struct Dugum));
    ucuncu = (struct Dugum*)malloc(sizeof(struct Dugum));

    baslangic->veri = 1; 
    baslangic->ileri = ikinci; 
    ikinci->veri = 2; 
    ikinci->ileri = ucuncu; 
    ucuncu->veri = 3; 
    ucuncu->ileri = NULL;

    return baslangic; 
}

int main() {
    struct Dugum* baslangic = olusturListe(); 
    
    printf("bağlı listedeki eleman adedi: %d", elemanSayisi(baslangic));

    return 0;
}




//SORU2:


#include <stdio.h>
#include <stdlib.h>

struct Dugum {
    int veri;
    struct Dugum* ileri;
};


struct Dugum* yeniDugum(int veri) {
    struct Dugum* yeni = (struct Dugum*)malloc(sizeof(struct Dugum));
    yeni->veri = veri;
    yeni->ileri = NULL;
    return yeni;
}

//  baştan sona fonksiyon
void bastanYazdir(struct Dugum* baslangic) {
    struct Dugum* suanki = baslangic;
    while (suanki != NULL) {
        printf("%d ", suanki->veri);
        suanki = suanki->ileri;
    }
}

// sondan başa  (recursive) fonksiyon
void sondanYazdir(struct Dugum* baslangic) {
    if (baslangic == NULL)
        return;
    sondanYazdir(baslangic->ileri);
    printf("%d ", baslangic->veri);
}

//  birleştirme 
struct Dugum* birlestir(struct Dugum* ilk, struct Dugum* ikinci) {
    struct Dugum* birlesmis = NULL;
    struct Dugum* temp;

    
    birlesmis = yeniDugum(ilk->veri);
    temp = birlesmis;
    ilk = ilk->ileri;

    while (ilk != NULL) {
        temp->ileri = yeniDugum(ilk->veri);
        temp = temp->ileri;
        ilk = ilk->ileri;
    }

        temp->ileri = NULL;
    while (ikinci != NULL) {
        struct Dugum* yeni = yeniDugum(ikinci->veri);
        yeni->ileri = birlesmis;
        birlesmis = yeni;
        ikinci = ikinci->ileri;
    }

    return birlesmis;
}

int main() {

    // baştan sona
    struct Dugum* basaListe = yeniDugum(0); // Başlangıç düğümü
    struct Dugum* suanki = basaListe;
    char numara[] = "032190049";
    for (int i = 0; i < 9; i++) {
        suanki->ileri = yeniDugum(numara[i] - '0');
        suanki = suanki->ileri;
    }

    //  sondan başa
    struct Dugum* sondanListe = NULL; 
    for (int i = 8; i >= 0; i--) {
        struct Dugum* yeni = yeniDugum(numara[i] - '0');
        yeni->ileri = sondanListe;
        sondanListe = yeni;
    }

    printf("Baştan sona liste: ");
    bastanYazdir(basaListe->ileri);
    printf("\n");

    printf("Sondan başa liste: ");
    sondanYazdir(sondanListe);
    printf("\n");

    // birleştirme 
    struct Dugum* birlesmisListe = birlestir(basaListe->ileri, sondanListe);
    printf("Birleştirilmiş liste: ");
    bastanYazdir(birlesmisListe);
    

   
   

    return 0;
}







//SORU3:

#include <stdio.h>
#include <stdlib.h>

struct Dugum {
    int veri;
    struct Dugum* ileri;
};

struct Dugum* yeniDugum(int veri) {
    struct Dugum* yeni = (struct Dugum*)malloc(sizeof(struct Dugum));
    yeni->veri = veri;
    yeni->ileri = NULL;
    return yeni;
}

// arama :
int ara(struct Dugum* baslangic, int aranan, int* indeks) {
    struct Dugum* suanki = baslangic;
    int index = 0;
    while (suanki != NULL) {
        if (suanki->veri == aranan) {
            *indeks = index;
            return 1; // girilen eleman var
        }
        suanki = suanki->ileri;
        index++;
    }
    return 0; // girilen eleman yok
}

int main() {
    
    struct Dugum* basaListe = yeniDugum(0); 
    struct Dugum* suanki = basaListe;
    char numara[] = "032190049";
    for (int i = 0; i < 9; i++) {
        suanki->ileri = yeniDugum(numara[i] - '0');
        suanki = suanki->ileri;
    }

    //  eleman alma
    int aranan;
    printf("Aranacak elemani giriniz: ");
    scanf("%d", &aranan);

    //  elemanı arama
    int indeks;
    if (ara(basaListe->ileri, aranan, &indeks)) {
        printf("%d bulundu, [%d] index\n", aranan, indeks);
    } else {
        printf("%d bulunamadi.\n", aranan);
    }

    return 0;
}




















