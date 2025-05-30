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

// Fungsi hitung rasio untuk persentase atau perbandingan
float rasio(float a, float b) {
    return (b == 0) ? 0 : a / b;
} 

// Tampilkan kategori desa setelah analisis
void tampilkan(Desa desa[], int index) {
    printf("\n");
    printf("+----------------------------------------------------------+\n");
    printf("|                                                          |\n");
    printf("|        HASIL ANALISIS PENDIDIKAN DESA %-30s |\n", desa[index].nama);
    printf("|                                                          |\n");
    printf("|        Kategori Pendidikan : %-20s           |\n", desa[index].kategori);
    printf("|                                                          |\n");
    printf("+----------------------------------------------------------+\n");
}

// Analisis kebutuhan infrastruktur sekolah (SD, SMP, SMA)
void analisisDesa(int jumlah_desa, Desa desa[]) {
    for (int i = 0; i < jumlah_desa; i++) {
        printf("+----------------------------------------------------------+\n");
        printf("|                                                          |\n");
        printf("|        ANALISIS INFRASTRUKTUR DESA %-30s |\n", desa[i].nama);
        printf("|                                                          |\n");
        printf("+----------------------------------------------------------+\n");
        
        int total_kapasitas_sd = desa[i].sd_tersedia * desa[i].kapasitas_sd;
        if (total_kapasitas_sd < desa[i].warga_sd) {
            int kekurangan = desa[i].warga_sd - total_kapasitas_sd;
            if (kekurangan < 100)
                printf("  Tambahan KELAS SD dibutuhkan (%d siswa)\n", kekurangan);
            else
                printf("  Tambahan SEKOLAH SD dibutuhkan (%d siswa)\n", kekurangan);
        } else {
            printf("  Kapasitas SD mencukupi\n");
        }

        int total_kapasitas_smp = desa[i].smp_tersedia * desa[i].kapasitas_smp;
        if (total_kapasitas_smp < desa[i].warga_smp) {
            int kekurangan = desa[i].warga_smp - total_kapasitas_smp;
            if (kekurangan < 100)
                printf("  Tambahan KELAS SMP dibutuhkan (%d siswa)\n", kekurangan);
            else
                printf("  Tambahan SEKOLAH SMP dibutuhkan (%d siswa)\n", kekurangan);
        } else {
            printf("  Kapasitas SMP mencukupi\n");
        }

        int total_kapasitas_sma = desa[i].sma_tersedia * desa[i].kapasitas_sma;
        if (total_kapasitas_sma < desa[i].warga_sma) {
            int kekurangan = desa[i].warga_sma - total_kapasitas_sma;
            if (kekurangan < 100)
                printf("  Tambahan KELAS SMA dibutuhkan (%d siswa)\n", kekurangan);
            else
                printf("  Tambahan SEKOLAH SMA dibutuhkan (%d siswa)\n", kekurangan);
        } else {
            printf("  Kapasitas SMA mencukupi\n");
        }
    }
}


int main (){
    char nama_kota[50];
    int jumlah_desa;
    Desa desa[100]; 

    tampilkan();

}