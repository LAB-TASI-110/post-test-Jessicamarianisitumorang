#include <stdio.h>
#include <string.h>

void getDataKota(const char kode[], char namaKota[], double *tarif, char kategori[], int *valid);
double hitungBeratUcok(double beratButet);
double hitungTotalBerat(double beratButet, double beratUcok);
double hitungOngkirAwal(double totalBerat, double tarif);
double hitungDiskon(double ongkirAwal, double totalBerat);
double hitungOngkirAkhir(double ongkirAwal, double diskon);
void tampilkanStruk(const char namaKota[], const char kode[], const char kategori[],
                    double tarif, double beratButet, double beratUcok,
                    double totalBerat, double ongkirAwal, double diskon,
                    double ongkirAkhir, int asuransiGratis);

int main() {
    char kode[10];
    char namaKota[50];
    char kategori[30];
    double tarif;
    double beratButet;
    double beratUcok;
    double totalBerat;
    double ongkirAwal;
    double diskon;
    double ongkirAkhir;
    int valid;
    int asuransiGratis;

    printf("=== PROGRAM JASA PENGIRIMAN DEL-EXPRESS ===\n");
    printf("Masukkan kode kota tujuan berulang.\n");
    printf("Ketik END untuk berhenti.\n\n");

    while (1) {
        printf("Masukkan kode kota tujuan (MDN/BLG/JKT/SBY/END): ");
        scanf("%s", kode);

        if (strcmp(kode, "END") == 0) {
            printf("\nProgram selesai. Terima kasih.\n");
            break;
        }

        getDataKota(kode, namaKota, &tarif, kategori, &valid);

        if (!valid) {
            printf("Kode kota tidak valid. Silakan coba lagi.\n\n");
            continue;
        }

        printf("Masukkan berat paket Butet (kg): ");
        scanf("%lf", &beratButet);

        if (beratButet <= 0) {
            printf("Berat paket harus lebih dari 0.\n\n");
            continue;
        }

        beratUcok = hitungBeratUcok(beratButet);
        totalBerat = hitungTotalBerat(beratButet, beratUcok);
        ongkirAwal = hitungOngkirAwal(totalBerat, tarif);
        diskon = hitungDiskon(ongkirAwal, totalBerat);
        ongkirAkhir = hitungOngkirAkhir(ongkirAwal, diskon);

        if (strcmp(kategori, "Luar Pulau") == 0) {
            asuransiGratis = 1;
        } else {
            asuransiGratis = 0;
        }

        tampilkanStruk(namaKota, kode, kategori, tarif, beratButet, beratUcok,
                       totalBerat, ongkirAwal, diskon, ongkirAkhir, asuransiGratis);
    }

    return 0;
}

void getDataKota(const char kode[], char namaKota[], double *tarif, char kategori[], int *valid) {
    *valid = 1;

    if (strcmp(kode, "MDN") == 0) {
        strcpy(namaKota, "Medan");
        *tarif = 8000;
        strcpy(kategori, "Dalam Pulau");
    } else if (strcmp(kode, "BLG") == 0) {
        strcpy(namaKota, "Balige");
        *tarif = 5000;
        strcpy(kategori, "Dalam Pulau");
    } else if (strcmp(kode, "JKT") == 0) {
        strcpy(namaKota, "Jakarta");
        *tarif = 12000;
        strcpy(kategori, "Luar Pulau");
    } else if (strcmp(kode, "SBY") == 0) {
        strcpy(namaKota, "Surabaya");
        *tarif = 13000;
        strcpy(kategori, "Luar Pulau");
    } else {
        *valid = 0;
    }
}

double hitungBeratUcok(double beratButet) {
    return 1.5 * beratButet;
}

double hitungTotalBerat(double beratButet, double beratUcok) {
    return beratButet + beratUcok;
}

double hitungOngkirAwal(double totalBerat, double tarif) {
    return totalBerat * tarif;
}

double hitungDiskon(double ongkirAwal, double totalBerat) {
    if (totalBerat > 10) {
        return 0.10 * ongkirAwal;
    }
    return 0;
}

double hitungOngkirAkhir(double ongkirAwal, double diskon) {
    return ongkirAwal - diskon;
}

void tampilkanStruk(const char namaKota[], const char kode[], const char kategori[],
                    double tarif, double beratButet, double beratUcok,
                    double totalBerat, double ongkirAwal, double diskon,
                    double ongkirAkhir, int asuransiGratis) {
    printf("\n========================================\n");
    printf("         STRUK PEMBAYARAN DEL-EXPRESS   \n");
    printf("========================================\n");
    printf("Kode Tujuan          : %s\n", kode);
    printf("Kota Tujuan          : %s\n", namaKota);
    printf("Kategori Wilayah     : %s\n", kategori);
    printf("Tarif per kg         : Rp %.0f\n", tarif);
    printf("----------------------------------------\n");
    printf("Berat Paket Butet    : %.2f kg\n", beratButet);
    printf("Berat Paket Ucok     : %.2f kg\n", beratUcok);
    printf("Total Berat Kiriman  : %.2f kg\n", totalBerat);
    printf("----------------------------------------\n");
    printf("Ongkir Awal          : Rp %.0f\n", ongkirAwal);
    printf("Diskon               : Rp %.0f\n", diskon);
    printf("Total Ongkir Akhir   : Rp %.0f\n", ongkirAkhir);
    printf("----------------------------------------\n");
    printf("Promo Diperoleh      : ");

    if (diskon > 0 && asuransiGratis) {
        printf("Diskon 10%% + Asuransi Gratis\n");
    } else if (diskon > 0) {
        printf("Diskon 10%%\n");
    } else if (asuransiGratis) {
        printf("Asuransi Gratis\n");
    } else {
        printf("Tidak ada promo\n");
    }

    printf("========================================\n\n");
}