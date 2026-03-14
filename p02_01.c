//12S25027_Jessica Mariani Situmorang

#include <stdio.h>
#include <string.h>

#define JUMLAH_KOTA 4

/* Data kota berdasarkan gambar soal */
const char kodeKota[JUMLAH_KOTA][4] = {"MDN", "BLG", "JKT", "SBY"};
const char namaKota[JUMLAH_KOTA][20] = {"Medan", "Balige", "Jakarta", "Surabaya"};
const int tarifKota[JUMLAH_KOTA] = {8000, 5000, 12000, 13000};
const char kategoriKota[JUMLAH_KOTA][15] = {
    "Dalam Pulau",
    "Dalam Pulau",
    "Luar Pulau",
    "Luar Pulau"
};

/* Mencari indeks kota berdasarkan kode */
int cariIndexKota(const char kode[]) {
    int i;
    for (i = 0; i < JUMLAH_KOTA; i++) {
        if (strcmp(kode, kodeKota[i]) == 0) {
            return i;
        }
    }
    return -1;
}

/* Menghitung berat paket Ucok */
float hitungBeratUcok(int beratButet) {
    return 1.5f * beratButet;   /* 3/2 x berat Butet */
}

/* Menghitung total ongkir sebelum diskon */
float hitungOngkirAwal(float totalBerat, int tarifPerKg) {
    return totalBerat * tarifPerKg;
}

/* Menentukan promo dan besar diskon */
void tentukanPromo(
    const char kategori[],
    float totalBerat,
    float ongkirAwal,
    float *diskon,
    int *dapatAsuransi,
    char infoPromo[]
) {
    int adaPromo = 0;

    *diskon = 0.0f;
    *dapatAsuransi = 0;
    strcpy(infoPromo, "");

    if (totalBerat > 10.0f) {
        *diskon = 0.10f * ongkirAwal;
        strcat(infoPromo, "Diskon ongkir 10%");
        adaPromo = 1;
    }

    if (strcmp(kategori, "Luar Pulau") == 0) {
        *dapatAsuransi = 1;
        if (adaPromo) {
            strcat(infoPromo, " + ");
        }
        strcat(infoPromo, "Asuransi gratis");
        adaPromo = 1;
    }

    if (!adaPromo) {
        strcpy(infoPromo, "Tidak ada promo");
    }
}

/* Mencetak struk */
void cetakStruk(
    const char kode[],
    const char nama[],
    const char kategori[],
    int beratButet,
    float beratUcok,
    float totalBerat,
    int tarifPerKg,
    float ongkirAwal,
    float diskon,
    float ongkirAkhir,
    const char infoPromo[]
) {
    printf("\n========================================\n");
    printf("      STRUK PEMBAYARAN DEL-EXPRESS      \n");
    printf("========================================\n");
    printf("Kode Kota        : %s\n", kode);
    printf("Kota Tujuan      : %s\n", nama);
    printf("Kategori Kota    : %s\n", kategori);
    printf("----------------------------------------\n");
    printf("Berat Butet      : %d.0 kg\n", beratButet);
    printf("Berat Ucok       : %.1f kg\n", beratUcok);
    printf("Total Berat      : %.1f kg\n", totalBerat);
    printf("----------------------------------------\n");
    printf("Tarif / Kg       : Rp %d\n", tarifPerKg);
    printf("Ongkir Awal      : Rp %.0f\n", ongkirAwal);
    printf("Diskon           : Rp %.0f\n", diskon);
    printf("Total Bayar      : Rp %.0f\n", ongkirAkhir);
    printf("Promo            : %s\n", infoPromo);
    printf("========================================\n");
}

/* Program utama */
int main() {
    char kode[10];
    int beratButet;
    int index;

    while (1) {
        printf("Masukkan kode kota (MDN/BLG/JKT/SBY) atau END untuk selesai: ");
        scanf("%s", kode);

        if (strcmp(kode, "END") == 0) {
            printf("\nProgram selesai.\n");
            break;
        }

        index = cariIndexKota(kode);

        if (index == -1) {
            printf("Kode kota tidak valid!\n\n");
            continue;
        }

        printf("Masukkan berat paket Butet (kg): ");
        scanf("%d", &beratButet);

        /* Proses perhitungan */
        {
            float beratUcok = hitungBeratUcok(beratButet);
            float totalBerat = beratButet + beratUcok;
            float ongkirAwal = hitungOngkirAwal(totalBerat, tarifKota[index]);
            float diskon;
            int dapatAsuransi;
            char infoPromo[100];
            float ongkirAkhir;

            tentukanPromo(
                kategoriKota[index],
                totalBerat,
                ongkirAwal,
                &diskon,
                &dapatAsuransi,
                infoPromo
            );

            ongkirAkhir = ongkirAwal - diskon;

            cetakStruk(
                kodeKota[index],
                namaKota[index],
                kategoriKota[index],
                beratButet,
                beratUcok,
                totalBerat,
                tarifKota[index],
                ongkirAwal,
                diskon,
                ongkirAkhir,
                infoPromo
            );
        }
    }

    return 0;
}