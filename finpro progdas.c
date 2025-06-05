#include <stdio.h>
#include <stdlib.h>
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

    int lulusan_d3;
    int lulusan_s1;
    int lulusan_s2;

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

// Fungsi input data desa
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

// Fungsi hitung rasio untuk persentase atau perbandingan
float rasio(float a, float b) {
    return (b == 0) ? 0 : a / b;
}

// Tampilkan kategori desa setelah analisis
void tampilkan(Desa desa[], int index) {
    printf("\n");
    printf("+----------------------------------------------------------+\n");
    printf("|                                                          \n");
    printf("|        HASIL ANALISIS PENDIDIKAN DESA %-30s \n", desa[index].nama);
    printf("|                                                          \n");
    printf("|        Kategori Pendidikan : %-20s           \n", desa[index].kategori);
    printf("|                                                          \n");
    printf("+----------------------------------------------------------+\n");
}

// Analisis kebutuhan infrastruktur sekolah (SD, SMP, SMA)
void analisisDesa(int jumlah_desa, Desa desa[]) {
    for (int i = 0; i < jumlah_desa; i++) {
        printf("+----------------------------------------------------------+\n");
        printf("|                                                          \n");
        printf("|        ANALISIS INFRASTRUKTUR DESA %-30s \n", desa[i].nama);
        printf("|                                                          \n");
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

// Hitung kualitas pengajar berdasarkan lulusan 
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


// Hitung dan tampilkan learning outcome berdasarkan nilai UN SD dan SMP
void hitungLearningOutcome(Desa desa[], int jumlah_desa, float kualitas_sd[]) {
    for (int i = 0; i < jumlah_desa; i++) {
        printf("\n");
        printf("+----------------------------------------------------------+\n");
        printf("|                                                          \n");
        printf("|        LEARNING OUTCOME DESA %-30s \n", desa[i].nama);
        printf("|                                                          \n");
        printf("+----------------------------------------------------------+\n");

        // Total nilai UN SD (max 30)
        int total_un_sd = desa[i].un_sd_bi + desa[i].un_sd_bing + desa[i].un_sd_mtk;
        printf("  Nilai UN SD Total (max 30) : %d\n", total_un_sd);
        if (total_un_sd >= 24)
            printf("  Kualitas SD: Baik\n");
        else if (total_un_sd >= 15)
            printf("  Kualitas SD: Rata-rata\n");
        else
            printf("  Kualitas SD: Kurang\n");

        // Total nilai UN SMP (max 40)
        int total_un_smp = desa[i].un_smp_bi + desa[i].un_smp_bing + desa[i].un_smp_mtk + desa[i].un_smp_ipa_ips;
        printf("  Nilai UN SMP Total (max 40) : %d\n", total_un_smp);
        if (total_un_smp >= 32)
            printf("  Kualitas SMP: Baik\n");
        else if (total_un_smp >= 20)
            printf("  Kualitas SMP: Rata-rata\n");
        else
            printf("  Kualitas SMP: Kurang\n");
    }
}

int main() {
    int jumlah_desa;
    char kota[50];

    printf("+----------------------------------------------------------+\n");
    printf("|                                                          |\n");
    printf("|    SISTEM ANALISIS KUALITAS PENDIDIKAN DESA              |\n");
    printf("|                                                          |\n");
    printf("+----------------------------------------------------------+\n\n");

    // Input nama kota
    printf("+---------------------------------------------------------+\n");
    printf("|  Masukkan Nama Kota    : ");
    scanf(" %[^\n]", kota);
    printf("|  Masukkan Jumlah Desa  : ");
    scanf("%d", &jumlah_desa);
    printf("+---------------------------------------------------------+\n");

    // Array untuk menyimpan data desa
    Desa desa[jumlah_desa];

    // Input data setiap desa
    for (int i = 0; i < jumlah_desa; i++) {
        inputDesa(desa, i);
    }

    printf("\n+----------------------------------------------------------+\n");
    printf("|                                                          \n");
    printf("|        LAPORAN ANALISIS PENDIDIKAN                       \n");
    printf("|              KOTA: %-32s\n", kota);
    printf("|                                                          \n");
    printf("+----------------------------------------------------------+\n");

    // Analisis kebutuhan infrastruktur setiap desa
    analisisDesa(jumlah_desa, desa);

    // Hitung dan tampilkan kualitas pengajar
    float *kualitas_guru = hitungKualitasPengajar(desa, jumlah_desa);

    // Hitung learning outcome berdasarkan nilai UN
    hitungLearningOutcome(desa, jumlah_desa, kualitas_guru);

    // Tentukan kategori pendidikan berdasarkan hasil analisis
    for (int i = 0; i < jumlah_desa; i++) {
        int total_un_sd = desa[i].un_sd_bi + desa[i].un_sd_bing + desa[i].un_sd_mtk;
        int total_un_smp = desa[i].un_smp_bi + desa[i].un_smp_bing + desa[i].un_smp_mtk + desa[i].un_smp_ipa_ips;

        // Penentuan kategori kualitas
        if (total_un_sd >= 24 && total_un_smp >= 32 && kualitas_guru[i] >= 3) {
            strcpy(desa[i].kategori, "Baik");
        } else if (total_un_sd >= 15 && total_un_smp >= 20 && kualitas_guru[i] >= 2) {
            strcpy(desa[i].kategori, "Rata-rata");
        } else {
            strcpy(desa[i].kategori, "Kurang");
        }

        // Tampilkan hasil kategori
        tampilkan(desa, i);
    }

    free(kualitas_guru);
    return 0;
}
