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

void inputDesa (){
    
}

Desa inputData(Desa desa) {
    printf("Masukkan jumlah warga usia SD	: ");
    scanf("%d", &desa.warga_sd);
    
    printf("Masukkan jumlah SD tersedia	: ");
    scanf("%d", &desa.sd_tersedia);
    
    printf("Masukkan total kapasitas SD	: ");
    scanf("%d", &desa.kapasitas_sd);
    
    printf("\nMasukkan jumlah warga usia SMP	: ");
    scanf("%d", &desa.warga_smp);
    
    printf("Masukkan jumlah SMP tersedia	: ");
    scanf("%d", &desa.smp_tersedia);
    
    printf("Masukkan total kapasitas SMP	: ");
    scanf("%d", &desa.kapasitas_smp);
    
    printf("\nMasukkan jumlah warga usia SMA	: ");
    scanf("%d", &desa.warga_sma);
    
    printf("Masukkan jumlah SMA tersedia	: ");
    scanf("%d", &desa.sma_tersedia);
    
    printf("Masukkan total kapasitas SMA	: ");
    scanf("%d", &desa.kapasitas_sma);

    return desa;
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
