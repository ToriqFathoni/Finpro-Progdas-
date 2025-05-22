#include <stdio.h>
#include <string.h>

typedef struct {
    char nama[50];
    int warga_sd;
    int sd_tersedia;
    int kapasitas_sd;

    int warga_smp;
    int smp_tersedia;
    int kapasitas_smp;

    int warga_sma;
    int sma_tersedia;
    int kapasitas_sma;
} Desa;

void inputDesa(Desa desa[], int i) {
    printf("Masukkan Nama Desa: ");
    scanf(" %[^\n]", desa[i].nama);
    
    printf("Masukkan Jumlah Warga usia SD        : ");
    scanf("%d", &desa[i].warga_sd);
    printf("Masukkan Jumlah SD yang tersedia     : ");
    scanf("%d", &desa[i].sd_tersedia);
    printf("Masukkan Rata-rata Kapasitas tiap SD : ");
    scanf("%d", &desa[i].kapasitas_sd);

    printf("Masukkan Jumlah Warga usia SMP       : ");
    scanf("%d", &desa[i].warga_smp);
    printf("Masukkan Jumlah SMP yang tersedia    : ");
    scanf("%d", &desa[i].smp_tersedia);
    printf("Masukkan Rata-rata Kapasitas tiap SMP: ");
    scanf("%d", &desa[i].kapasitas_smp);

    printf("Masukkan Jumlah Warga usia SMA       : ");
    scanf("%d", &desa[i].warga_sma);
    printf("Masukkan Jumlah SMA yang tersedia    : ");
    scanf("%d", &desa[i].sma_tersedia);
    printf("Masukkan Rata-rata Kapasitas tiap SMA: ");
    scanf("%d", &desa[i].kapasitas_sma);
}

void inputData (){
    //buat yang bikin bagian ini tolong nanti parameter buat looping nya pake i ya biar sesuai
}

void analisisDesa (){
    
}

void tampilkanAnalisis (){
    
}

int main (){
    char nama_kota[50];
    int jumlah_desa;
    Desa desa[100]; 
}
