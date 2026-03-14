//12S25027_Jessica Mariani Situmorang

#include <stdio.h>
#include <string.h>

#define MAX_MENU 30
#define MAX_DETAIL 100

typedef struct {
    char nama[50];
    char kategori[20];
    int harga;
    int stok;
    int terjual;
} Menu;

typedef struct {
    char nama[50];
    int harga;
    int jumlah;
    int subtotal;
} DetailPesanan;

void inisialisasiMenu(Menu menu[], int *jumlahMenu) {
    *jumlahMenu = 23;

    // MAKANAN
    strcpy(menu[0].nama, "Roti Isi Ayam");
    strcpy(menu[0].kategori, "Makanan");
    menu[0].harga = 15000; menu[0].stok = 20; menu[0].terjual = 0;

    strcpy(menu[1].nama, "Risol");
    strcpy(menu[1].kategori, "Makanan");
    menu[1].harga = 10000; menu[1].stok = 20; menu[1].terjual = 0;

    strcpy(menu[2].nama, "PKL");
    strcpy(menu[2].kategori, "Makanan");
    menu[2].harga = 10000; menu[2].stok = 20; menu[2].terjual = 0;

    strcpy(menu[3].nama, "Sosis");
    strcpy(menu[3].kategori, "Makanan");
    menu[3].harga = 15000; menu[3].stok = 20; menu[3].terjual = 0;

    strcpy(menu[4].nama, "Piscok");
    strcpy(menu[4].kategori, "Makanan");
    menu[4].harga = 10000; menu[4].stok = 20; menu[4].terjual = 0;

    strcpy(menu[5].nama, "Nuget");
    strcpy(menu[5].kategori, "Makanan");
    menu[5].harga = 15000; menu[5].stok = 20; menu[5].terjual = 0;

    strcpy(menu[6].nama, "Kentang");
    strcpy(menu[6].kategori, "Makanan");
    menu[6].harga = 15000; menu[6].stok = 20; menu[6].terjual = 0;

    strcpy(menu[7].nama, "Donat");
    strcpy(menu[7].kategori, "Makanan");
    menu[7].harga = 10000; menu[7].stok = 20; menu[7].terjual = 0;

    strcpy(menu[8].nama, "Bakwan");
    strcpy(menu[8].kategori, "Makanan");
    menu[8].harga = 10000; menu[8].stok = 20; menu[8].terjual = 0;

    strcpy(menu[9].nama, "Tahu");
    strcpy(menu[9].kategori, "Makanan");
    menu[9].harga = 10000; menu[9].stok = 20; menu[9].terjual = 0;

    strcpy(menu[10].nama, "Tempe");
    strcpy(menu[10].kategori, "Makanan");
    menu[10].harga = 10000; menu[10].stok = 20; menu[10].terjual = 0;

    strcpy(menu[11].nama, "Gabin");
    strcpy(menu[11].kategori, "Makanan");
    menu[11].harga = 10000; menu[11].stok = 20; menu[11].terjual = 0;

    strcpy(menu[12].nama, "Salad Buah");
    strcpy(menu[12].kategori, "Makanan");
    menu[12].harga = 15000; menu[12].stok = 20; menu[12].terjual = 0;

    strcpy(menu[13].nama, "Sandwich");
    strcpy(menu[13].kategori, "Makanan");
    menu[13].harga = 12000; menu[13].stok = 20; menu[13].terjual = 0;

    // MINUMAN
    strcpy(menu[14].nama, "Chocolatos");
    strcpy(menu[14].kategori, "Minuman");
    menu[14].harga = 8000; menu[14].stok = 25; menu[14].terjual = 0;

    strcpy(menu[15].nama, "Teh Tarik");
    strcpy(menu[15].kategori, "Minuman");
    menu[15].harga = 8000; menu[15].stok = 25; menu[15].terjual = 0;

    strcpy(menu[16].nama, "Lemon Tea");
    strcpy(menu[16].kategori, "Minuman");
    menu[16].harga = 8000; menu[16].stok = 25; menu[16].terjual = 0;

    strcpy(menu[17].nama, "Capucino");
    strcpy(menu[17].kategori, "Minuman");
    menu[17].harga = 8000; menu[17].stok = 25; menu[17].terjual = 0;

    strcpy(menu[18].nama, "Kopi Hitam");
    strcpy(menu[18].kategori, "Minuman");
    menu[18].harga = 5000; menu[18].stok = 25; menu[18].terjual = 0;

    strcpy(menu[19].nama, "Kopi Susu");
    strcpy(menu[19].kategori, "Minuman");
    menu[19].harga = 7000; menu[19].stok = 25; menu[19].terjual = 0;

    strcpy(menu[20].nama, "Teh Manis");
    strcpy(menu[20].kategori, "Minuman");
    menu[20].harga = 5000; menu[20].stok = 25; menu[20].terjual = 0;

    strcpy(menu[21].nama, "Sogem");
    strcpy(menu[21].kategori, "Minuman");
    menu[21].harga = 8000; menu[21].stok = 25; menu[21].terjual = 0;

    strcpy(menu[22].nama, "Matcha");
    strcpy(menu[22].kategori, "Minuman");
    menu[22].harga = 10000; menu[22].stok = 25; menu[22].terjual = 0;
}

void tampilkanMenu(Menu menu[], int jumlahMenu) {
    int i;
    printf("\n========================= DAFTAR MENU =========================\n");
    printf("%-4s %-20s %-12s %-10s %-6s\n", "No", "Nama", "Kategori", "Harga", "Stok");
    printf("---------------------------------------------------------------\n");
    for (i = 0; i < jumlahMenu; i++) {
        printf("%-4d %-20s %-12s Rp%-8d %-6d\n",
               i + 1, menu[i].nama, menu[i].kategori, menu[i].harga, menu[i].stok);
    }
    printf("===============================================================\n");
}

void tampilkanStok(Menu menu[], int jumlahMenu) {
    int i;
    printf("\n========================= SISA STOK ===========================\n");
    printf("%-4s %-20s %-12s %-6s\n", "No", "Nama", "Kategori", "Stok");
    printf("---------------------------------------------------------------\n");
    for (i = 0; i < jumlahMenu; i++) {
        printf("%-4d %-20s %-12s %-6d\n",
               i + 1, menu[i].nama, menu[i].kategori, menu[i].stok);
    }
    printf("===============================================================\n");
}

void cetakStruk(DetailPesanan detail[], int jumlahDetail, int totalBayar) {
    int i;
    printf("\n========================== STRUK ==============================\n");
    printf("%-4s %-20s %-8s %-8s %-10s\n", "No", "Nama", "Harga", "Jumlah", "Subtotal");
    printf("---------------------------------------------------------------\n");
    for (i = 0; i < jumlahDetail; i++) {
        printf("%-4d %-20s %-8d %-8d %-10d\n",
               i + 1,
               detail[i].nama,
               detail[i].harga,
               detail[i].jumlah,
               detail[i].subtotal);
    }
    printf("---------------------------------------------------------------\n");
    printf("TOTAL BAYAR : Rp%d\n", totalBayar);
    printf("===============================================================\n");
}

void prosesPesanan(Menu menu[], int jumlahMenu, int *totalPendapatan) {
    DetailPesanan detail[MAX_DETAIL];
    int jumlahDetail = 0;
    int nomorMenu, jumlah, subtotal, totalBayar = 0;
    char lanjut = 'y';

    while (lanjut == 'y' || lanjut == 'Y') {
        tampilkanMenu(menu, jumlahMenu);

        printf("Masukkan nomor menu (0 untuk selesai): ");
        scanf("%d", &nomorMenu);

        if (nomorMenu == 0) {
            break;
        }

        if (nomorMenu < 1 || nomorMenu > jumlahMenu) {
            printf("Nomor menu tidak valid!\n");
            continue;
        }

        printf("Masukkan jumlah pesanan: ");
        scanf("%d", &jumlah);

        if (jumlah <= 0) {
            printf("Jumlah pesanan harus lebih dari 0!\n");
            continue;
        }

        if (jumlah > menu[nomorMenu - 1].stok) {
            printf("Stok %s tidak cukup. Stok tersedia: %d\n",
                   menu[nomorMenu - 1].nama,
                   menu[nomorMenu - 1].stok);
            continue;
        }

        subtotal = menu[nomorMenu - 1].harga * jumlah;

        strcpy(detail[jumlahDetail].nama, menu[nomorMenu - 1].nama);
        detail[jumlahDetail].harga = menu[nomorMenu - 1].harga;
        detail[jumlahDetail].jumlah = jumlah;
        detail[jumlahDetail].subtotal = subtotal;

        jumlahDetail++;
        totalBayar += subtotal;

        menu[nomorMenu - 1].stok -= jumlah;
        menu[nomorMenu - 1].terjual += jumlah;

        printf("Pesanan berhasil ditambahkan.\n");
        printf("Tambah pesanan lagi? (y/n): ");
        scanf(" %c", &lanjut);
    }

    if (jumlahDetail > 0) {
        *totalPendapatan += totalBayar;
        cetakStruk(detail, jumlahDetail, totalBayar);
    } else {
        printf("Tidak ada transaksi.\n");
    }
}

void tampilkanLaporan(Menu menu[], int jumlahMenu, int totalPendapatan) {
    int i;
    printf("\n==================== LAPORAN PENJUALAN ========================\n");
    printf("%-4s %-20s %-10s %-10s\n", "No", "Nama", "Terjual", "Pendapatan");
    printf("---------------------------------------------------------------\n");
    for (i = 0; i < jumlahMenu; i++) {
        printf("%-4d %-20s %-10d Rp%-8d\n",
               i + 1,
               menu[i].nama,
               menu[i].terjual,
               menu[i].terjual * menu[i].harga);
    }
    printf("---------------------------------------------------------------\n");
    printf("TOTAL PENDAPATAN HARIAN : Rp%d\n", totalPendapatan);
    printf("===============================================================\n");
}

int main() {
    Menu menu[MAX_MENU];
    int jumlahMenu;
    int pilihan;
    int totalPendapatan = 0;

    inisialisasiMenu(menu, &jumlahMenu);

    do {
        printf("\n================ SISTEM KAFETARIA IT DEL ================\n");
        printf("1. Tampilkan Daftar Menu\n");
        printf("2. Proses Pesanan\n");
        printf("3. Tampilkan Sisa Stok\n");
        printf("4. Tampilkan Laporan Penjualan Harian\n");
        printf("5. Keluar\n");
        printf("=========================================================\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                tampilkanMenu(menu, jumlahMenu);
                break;
            case 2:
                prosesPesanan(menu, jumlahMenu, &totalPendapatan);
                break;
            case 3:
                tampilkanStok(menu, jumlahMenu);
                break;
            case 4:
                tampilkanLaporan(menu, jumlahMenu, totalPendapatan);
                break;
            case 5:
                printf("Program selesai. Terima kasih.\n");
                break;
            default:
                printf("Pilihan tidak valid!\n");
        }

    } while (pilihan != 5);

    return 0;
}