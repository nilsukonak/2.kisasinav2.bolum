#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#define MAX_NOKTA 100

// Nokta yapısı
struct Nokta {
    double x;
    double y;
};

// Noktalar arası uzaklığı hesaplayan fonksiyon
double hesaplaUzaklik(struct Nokta n1, struct Nokta n2) {
    double uzaklik = sqrt(pow(n2.x - n1.x, 2) + pow(n2.y - n1.y, 2));
    return uzaklik;
}

// En yakın komşu kümeleri birleştiren fonksiyon
void birlestirEnYakinKumeler(struct Nokta noktalar[], int kumeAtamalari[], int noktaSayisi) {
    double minUzaklik = DBL_MAX; // En küçük uzaklık
    int kume1 = 0, kume2 = 0; // Birleştirilecek kümelerin indeksleri
    int i, j;
    for (i = 0; i < noktaSayisi; i++) {
        for (j = i + 1; j < noktaSayisi; j++) {
            if (kumeAtamalari[i] != kumeAtamalari[j]) {
                double uzaklik = hesaplaUzaklik(noktalar[i], noktalar[j]);
                if (uzaklik < minUzaklik) {
                    minUzaklik = uzaklik;
                    kume1 = i;
                    kume2 = j;
                }
            }
        }
    }
    
    // Birleştirme işlemi
    int yeniKume = kumeAtamalari[kume1];
    int eskiKume = kumeAtamalari[kume2];
    for (i = 0; i < noktaSayisi; i++) {
        if (kumeAtamalari[i] == eskiKume) {
            kumeAtamalari[i] = yeniKume;
        }
    }
}

int main() {
    struct Nokta noktalar[MAX_NOKTA]; // Nokta dizisi
    int kumeAtamalari[MAX_NOKTA]; // Küme atamaları
    int noktaSayisi; // Nokta sayısı
    int kumeSayisi; // Küme sayısı
    
    // Nokta girişi
    printf("Nokta sayısını girin: ");
    scanf("%d", &noktaSayisi);
    
    for (int i = 0; i < noktaSayisi; i++) {
        printf("Nokta %d x koordinatını girin: ", i+1);
        scanf("%lf", &noktalar[i].x);
        printf("Nokta %d y koordinatını girin: ", i+1);
        scanf("%lf", &noktalar[i].y);
        kumeAtamalari[i] = i; // Her noktayı ayrı bir kümeye atıyoruz
    }
    
    // Küme sayısı girişi
    printf("Küme sayısını girin: ");
    scanf("%d", &kumeSayisi);
    
    // Birleştirme işlemi
    while (kumeSayisi > 1) {
        birlestirEnYakinKumeler(noktalar, kumeAtamalari, noktaSayisi);
        kumeSayisi--;
    }
    
    // Sonuçları ekrana yazdırma
    printf("Kümeleme Sonuçları:\n");
    for (int j = 0; j < noktaSayisi; j++) {
        printf("Nokta %d -> Küme %d\n", j+1, kumeAtamalari[j]+1);
    }
    
    return 0;
}
