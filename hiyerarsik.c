#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#define MAX_NOKTA 100

// Nokta yapýsý
struct Nokta {
    double x;
    double y;
};

// Noktalar arasý uzaklýðý hesaplayan fonksiyon
double hesaplaUzaklik(struct Nokta n1, struct Nokta n2) {
    double uzaklik = sqrt(pow(n2.x - n1.x, 2) + pow(n2.y - n1.y, 2));
    return uzaklik;
}

// En yakýn komþu kümeleri birleþtiren fonksiyon
void birlestirEnYakinKumeler(struct Nokta noktalar[], int kumeAtamalari[], int noktaSayisi) {
    double minUzaklik = DBL_MAX; // En küçük uzaklýk
    int kume1 = 0, kume2 = 0; // Birleþtirilecek kümelerin indeksleri
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
    
    // Birleþtirme iþlemi
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
    int kumeAtamalari[MAX_NOKTA]; // Küme atamalarý
    int noktaSayisi; // Nokta sayýsý
    int kumeSayisi; // Küme sayýsý
    
    // Nokta giriþi
    printf("Nokta sayýsýný girin: ");
    scanf("%d", &noktaSayisi);
    
    for (int i = 0; i < noktaSayisi; i++) {
        printf("Nokta %d x koordinatýný girin: ", i+1);
        scanf("%lf", &noktalar[i].x);
        printf("Nokta %d y koordinatýný girin: ", i+1);
        scanf("%lf", &noktalar[i].y);
        kumeAtamalari[i] = i; // Her noktayý ayrý bir kümeye atýyoruz
    }
    
    // Küme sayýsý giriþi
    printf("Küme sayýsýný girin: ");
    scanf("%d", &kumeSayisi);
    
    // Birleþtirme iþlemi
    while (kumeSayisi > 1) {
        birlestirEnYakinKumeler(noktalar, kumeAtamalari, noktaSayisi);
        kumeSayisi--;
    }
    
    // Sonuçlarý ekrana yazdýrma
    printf("Kümeleme Sonuçlarý:\n");
    for (int j = 0; j < noktaSayisi; j++) {
        printf("Nokta %d -> Küme %d\n", j+1, kumeAtamalari[j]+1);
    }
    
    return 0;
}
