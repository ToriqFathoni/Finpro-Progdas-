#include <stdio.h>
#include <string.h>
//toriq
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

//toriq & abyan (masukin input dari user)
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
//fernanda (analisis untuk tiap desa)
void analisisDesa (int jumlah_desa, Desa desa[]){
    for (int i = 0; i < jumlah_desa; i++){
        printf("\nAnalis desa %s: \n", desa[i].nama);

        int total_kapasitas_sd = desa[i].sd_tersedia * desa[i].kapasitas_sd;
        if (total_kapasitas_sd < desa[i].warga_sd){
            int kekurangan = desa[i].warga_sd - total_kapasitas_sd;
            if (kekurangan < 100){
                printf("- Desa ini membutuhkan tambahan KELAS untuk siswa SD (kekurangan untuk %d siswa)\n", kekurangan);
            }
            else {
                printf("- Desa ini membutuhkan tambahan SEKOLAH untuk siswa SD (kekurangan untuk %d siswa)\n", kekurangan);
            }
        }
        else {
            printf("- Kapasitas SD MENCUKUPI.\n");
        }

        int total_kapasitas_smp = desa[i].smp_tersedia * desa[i].kapasitas_smp;
        if (total_kapasitas_smp < desa[i].warga_smp){
            int kekurangan = desa[i].warga_smp - total_kapasitas_smp;
            if (kekurangan < 100){
                printf("- Desa ini membutuhkan tambahan KELAS untuk siswa SMP (kekurangan untuk %d siswa)\n", kekurangan);
            }
            else{
                printf("- Desa ini membutuhkan tambahan SEKOLAH untuk siswa SMP (kekurangan untuk %d siswa)\n", kekurangan);
            }
        }
        else{
            printf("- Kapasitas SMP Mencukupi.\n");
        }

        int total_kapasitas_sma = desa[i].sma_tersedia * desa[i].kapasitas_sma;
        if (total_kapasitas_sma < desa[i].warga_sma){
            int kekurangan = desa[i].warga_sma - total_kapasitas_sma;
            if (kekurangan < 100){
                printf("- Desa ini membutuhkan tambahan KELAS untuk siswa SMA (kekurangan untuk %d siswa)\n", kekurangan);
            }
            else{
                printf("- Desa ini membutuhkan tambahan SEKOLAH untuk siswa SMA (kekurangan untuk %d siswa)\n", kekurangan);
            }
        }
        else{
            printf("- Kapasitas SMA Mencukupi.\n");
        }

    }
}
//radya
void tampilkanAnalisis() {
    char nama_kota[50];
    int jumlah_desa;
    Desa desa[100];

    printf("Masukkan Nama Kota: ");
    scanf(" %[^\n]", nama_kota);

    printf("Masukkan Jumlah Desa: ");
    scanf("%d", &jumlah_desa);

    for (int i = 0; i < jumlah_desa; i++) {
        printf("\n--- Input data untuk Desa ke-%d ---\n", i + 1);
        inputDesa(desa, i);
    }

    printf("\n\n=== Analisis Pendidikan untuk Kota %s ===\n", nama_kota);
    analisisDesa(jumlah_desa, desa);
}

//toriq 
int main (){
    char nama_kota[50];
    int jumlah_desa;
    Desa desa[100]; 

    tampilkanAnalisis();

}