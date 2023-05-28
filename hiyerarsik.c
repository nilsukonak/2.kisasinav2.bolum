#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#define MAX_NOKTA 100

// Nokta yap�s�
struct Nokta {
    double x;
    double y;
};

// Noktalar aras� uzakl��� hesaplayan fonksiyon
double hesaplaUzaklik(struct Nokta n1, struct Nokta n2) {
    double uzaklik = sqrt(pow(n2.x - n1.x, 2) + pow(n2.y - n1.y, 2));
    return uzaklik;
}

// En yak�n kom�u k�meleri birle�tiren fonksiyon
void birlestirEnYakinKumeler(struct Nokta noktalar[], int kumeAtamalari[], int noktaSayisi) {
    double minUzaklik = DBL_MAX; // En k���k uzakl�k
    int kume1 = 0, kume2 = 0; // Birle�tirilecek k�melerin indeksleri
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
    
    // Birle�tirme i�lemi
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
    int kumeAtamalari[MAX_NOKTA]; // K�me atamalar�
    int noktaSayisi; // Nokta say�s�
    int kumeSayisi; // K�me say�s�
    
    // Nokta giri�i
    printf("Nokta say�s�n� girin: ");
    scanf("%d", &noktaSayisi);
    
    for (int i = 0; i < noktaSayisi; i++) {
        printf("Nokta %d x koordinat�n� girin: ", i+1);
        scanf("%lf", &noktalar[i].x);
        printf("Nokta %d y koordinat�n� girin: ", i+1);
        scanf("%lf", &noktalar[i].y);
        kumeAtamalari[i] = i; // Her noktay� ayr� bir k�meye at�yoruz
    }
    
    // K�me say�s� giri�i
    printf("K�me say�s�n� girin: ");
    scanf("%d", &kumeSayisi);
    
    // Birle�tirme i�lemi
    while (kumeSayisi > 1) {
        birlestirEnYakinKumeler(noktalar, kumeAtamalari, noktaSayisi);
        kumeSayisi--;
    }
    
    // Sonu�lar� ekrana yazd�rma
    printf("K�meleme Sonu�lar�:\n");
    for (int j = 0; j < noktaSayisi; j++) {
        printf("Nokta %d -> K�me %d\n", j+1, kumeAtamalari[j]+1);
    }
    
    return 0;
}
