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

void inputData (){

}

void analisisDesa (int jumlah_desa, Desa desa[]){
    for (int i = 0; i < jumlah_desa; i++){
        printf("\nAnalis desa %s: \n", desa[i].nama);

        int total_kapasitas_sd = desa[i].sd_tersedia * desa[i].kapasitas_sd;
        if (total_kapasitas_sd < desa[i].warga_sd){
            int kekurangan = desa[i].warga_sd - total_kapasitas_sd;
            if (kekurangan < 100){
                printf("- Desa ini membutuhkan tambahan *Kelas* untuk siswa SD (kekurangan untuk %d siswa)\n", kekurangan);
            }
            else {
                printf("- Desa ini membutuhkan tambahan *Sekolah* untuk siswa SD (kekurangan untuk %d siswa)\n", kekurangan);
            }
        }
        else {
            printf("- Kapasitas SD *Mencukupi*.\n");
        }

        int total_kapasitas_smp = desa[i].smp_tersedia * desa[i].kapasitas_smp;
        if (total_kapasitas_smp < desa[i].warga_smp){
            int kekurangan = desa[i].warga_smp - total_kapasitas_smp;
            if (kekurangan < 100){
                printf("- Desa ini membutuhkan tambahan *Kelas* untuk siswa SMP (kekurangan untuk %d siswa)\n", kekurangan);
            }
            else{
                printf("- Desa ini membutuhkan tambahan *Sekolah* untuk siswa SMP (kekurangan untuk %d siswa)\n", kekurangan);
            }
        }
        else{
            printf("- Kapasitas SMP *Mencukupi*.\n");
        }

        int total_kapasitas_sma = desa[i].sma_tersedia * desa[i].kapasitas_sma;
        if (total_kapasitas_sma < desa[i].warga_sma){
            int kekurangan = desa[i].warga_sma - total_kapasitas_sma;
            if (kekurangan < 100){
                printf("- Desa ini membutuhkan tambahan *Kelas* untuk siswa SMA (kekurangan untuk %d siswa)\n", kekurangan);
            }
            else{
                printf("- Desa ini membutuhkan tambahan *Sekolah* untuk siswa SMA (kekurangan untuk %d siswa)\n", kekurangan);
            }
        }
        else{
            printf("- Kapasitas SMA *Mencukupi*.\n");
        }

    }
}

void tampilkanAnalisis (){
    
}

int main (){
    char nama_kota[50];
    int jumlah_desa;
    Desa desa[100]; 
}