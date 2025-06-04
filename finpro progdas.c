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

//abyan 
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
        
//fernanda (analisis untuk tiap desa)
void analisisDesa (int jumlah_desa, Desa desa[]){
    for (int i = 0; i < jumlah_desa; i++){
        printf("\nAnalis desa %s: \n", desa[i].nama);

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

    tampilkan();

}
