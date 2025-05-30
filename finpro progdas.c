#include <stdio.h>
#include <stdlib.h>
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

    int penduduk;
    int lulusan_d3;
    int lulusan_s1;
    int lulusan_s2;

    int sekolah_ada;
    int total_guru;
    int guru_pns;

    // Nilai UN SD 
    int un_sd_bi;  // Bahasa Indonesia
    int un_sd_bing; // Bahasa Inggris
    int un_sd_mtk; // Matematika

    // Nilai UN SMP 
    int un_smp_bi;    // Bahasa Indonesia
    int un_smp_bing;  // Bahasa Inggris
    int un_smp_mtk;   // Matematika
    int un_smp_ipa_ips; // IPA atau IPS

    char kategori[30];
} Desa;

// toriq & abyan Fungsi input data desa
void inputDesa(Desa desa[], int i) {
    printf("\n--- INPUT DATA DESA KE-%d ---\n", i+1);
    printf("Nama Desa           : ");
    scanf(" %[^\n]", desa[i].nama);

    printf("\nData SD:\n");
    printf("  Warga usia SD     : ");
    scanf("%d", &desa[i].warga_sd);
    printf("  SD tersedia       : ");
    scanf("%d", &desa[i].sd_tersedia);
    printf("  Kapasitas/SD      : ");
    scanf("%d", &desa[i].kapasitas_sd);

    printf("\nData SMP:\n");
    printf("  Warga usia SMP    : ");
    scanf("%d", &desa[i].warga_smp);
    printf("  SMP tersedia      : ");
    scanf("%d", &desa[i].smp_tersedia);
    printf("  Kapasitas/SMP     : ");
    scanf("%d", &desa[i].kapasitas_smp);

    printf("\nData SMA:\n");
    printf("  Warga usia SMA    : ");
    scanf("%d", &desa[i].warga_sma);
    printf("  SMA tersedia      : ");
    scanf("%d", &desa[i].sma_tersedia);
    printf("  Kapasitas/SMA     : ");
    scanf("%d", &desa[i].kapasitas_sma);
    
    printf("\n+-- DATA KUALITAS PENGAJAR ---------------------------+\n");
    printf("|  Jumlah Guru PNS     : ");
    scanf("%d", &desa[i].guru_pns);
    printf("|  Jumlah Lulusan D3   : ");
    scanf("%d", &desa[i].lulusan_d3);
    printf("|  Jumlah Lulusan S1   : ");
    scanf("%d", &desa[i].lulusan_s1);
    printf("|  Jumlah Lulusan S2   : ");
    scanf("%d", &desa[i].lulusan_s2);

    // Tambahkan total_guru 
    desa[i].total_guru = desa[i].lulusan_d3 + desa[i].lulusan_s1 + desa[i].lulusan_s2;

    printf("+-----------------------------------------------------+\n");

    // Input nilai UN SD
    printf("\n+-- NILAI UN SD (0-10) -------------------------------+\n");
    do {
        printf("|  Bahasa Indonesia (0-10) : ");
        scanf("%d", &desa[i].un_sd_bi);
    } while (desa[i].un_sd_bi < 0 || desa[i].un_sd_bi > 10);

    do {
        printf("|  Bahasa Inggris (0-10)   : ");
        scanf("%d", &desa[i].un_sd_bing);
    } while (desa[i].un_sd_bing < 0 || desa[i].un_sd_bing > 10);

    do {
        printf("|  Matematika (0-10)       : ");
        scanf("%d", &desa[i].un_sd_mtk);
    } while (desa[i].un_sd_mtk < 0 || desa[i].un_sd_mtk > 10);
    printf("+-----------------------------------------------------+\n");

    // Input nilai UN SMP
    printf("\n+-- NILAI UN SMP (0-10) -------------------------------+\n");
    do {
        printf("|  Bahasa Indonesia (0-10) : ");
        scanf("%d", &desa[i].un_smp_bi);
    } while (desa[i].un_smp_bi < 0 || desa[i].un_smp_bi > 10);

    do {
        printf("|  Bahasa Inggris (0-10)   : ");
        scanf("%d", &desa[i].un_smp_bing);
    } while (desa[i].un_smp_bing < 0 || desa[i].un_smp_bing > 10);

    do {
        printf("|  Matematika (0-10)       : ");
        scanf("%d", &desa[i].un_smp_mtk);
    } while (desa[i].un_smp_mtk < 0 || desa[i].un_smp_mtk > 10);

    do {
        printf("|  IPA / IPS (0-10)        : ");
        scanf("%d", &desa[i].un_smp_ipa_ips);
    } while (desa[i].un_smp_ipa_ips < 0 || desa[i].un_smp_ipa_ips > 10);
    printf("+-----------------------------------------------------+\n");
}
float rasio(float a, float b) {
    return (b == 0) ? 0 : a / b;
}

//fernanda (Menganalisis kualitas guru)
float* hitungKualitasPengajar(Desa desa[], int jumlah_desa) {
    float *kualitas_guru = (float *)malloc(jumlah_desa * sizeof(float));
    if (!kualitas_guru) {
        printf("Gagal mengalokasikan memori untuk kualitas guru.\n");
        return NULL;
    }

    for (int i = 0; i < jumlah_desa; i++) {
        int total_guru = desa[i].total_guru;
        printf("\n");
        printf("+----------------------------------------------------------+\n");
        printf("|                                                          \n");
        printf("|        KUALITAS PENGAJAR DESA %-30s \n", desa[i].nama);
        printf("|                                                          \n");
        printf("+----------------------------------------------------------+\n");
        
        if (total_guru == 0) {
            printf("  Data total guru belum tersedia.\n");
            kualitas_guru[i] = 0;
            continue;
        }
        
        float rasio_pns = rasio(desa[i].guru_pns, total_guru) * 100;
        float rasio_d3 = rasio(desa[i].lulusan_d3, total_guru) * 100;
        float rasio_s1 = rasio(desa[i].lulusan_s1, total_guru) * 100;
        float rasio_s2 = rasio(desa[i].lulusan_s2, total_guru) * 100;

        printf("  Jumlah Total Guru          : %d\n", total_guru);
        printf("  Persentase Guru PNS        : %6.2f%%\n", rasio_pns);
        printf("  Persentase Guru Lulusan D3 : %6.2f%%\n", rasio_d3);
        printf("  Persentase Guru Lulusan S1 : %6.2f%%\n", rasio_s1);
        printf("  Persentase Guru Lulusan S2 : %6.2f%%\n", rasio_s2);

        // Kategori kualitas guru berdasarkan persentase lulusan 
        if (rasio_s2 > rasio_s1 && rasio_s2 > rasio_d3) {
            printf("  Kualitas Guru: Sangat Bagus\n");
            kualitas_guru[i] = 4.0;
        } else if (rasio_s1 > rasio_d3) {
            printf("  Kualitas Guru: Bagus\n");
            kualitas_guru[i] = 3.0;
        } else {
            printf("  Kualitas Guru: Rata-rata\n");
            kualitas_guru[i] = 2.0;
        }
    }
    return kualitas_guru;
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