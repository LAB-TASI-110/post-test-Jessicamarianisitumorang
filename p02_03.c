#include <stdio.h>
#include <string.h>

#define MAX_BAHAN 20
#define MAX_MENU 20
#define MAX_RESEP 10
#define MAX_PESANAN 20

typedef struct {
    char nama[50];
    int stok;
    char satuan[20];
} Bahan;

typedef struct {
    int indexBahan;
    int jumlah;
} ResepItem;

typedef struct {
    char nama[50];
    int harga;
    int jumlahResep;
    ResepItem resep[MAX_RESEP];
} MenuItem;

typedef struct {
    int indexMenu;
    int qty;
    int subtotal;
} PesananItem;

Bahan daftarBahan[MAX_BAHAN];
MenuItem daftarMenu[MAX_MENU];
int jumlahBahan = 0;
int jumlahMenu = 0;

void tambahBahanAwal(const char *nama, int stok, const char *satuan) {
    strcpy(daftarBahan[jumlahBahan].nama, nama);
    daftarBahan[jumlahBahan].stok = stok;
    strcpy(daftarBahan[jumlahBahan].satuan, satuan);
    jumlahBahan++;
}

void tambahMenuAwal(const char *nama, int harga) {
    strcpy(daftarMenu[jumlahMenu].nama, nama);
    daftarMenu[jumlahMenu].harga = harga;
    daftarMenu[jumlahMenu].jumlahResep = 0;
    jumlahMenu++;
}

void tambahResep(int indexMenu, int indexBahan, int jumlah) {
    int r = daftarMenu[indexMenu].jumlahResep;
    daftarMenu[indexMenu].resep[r].indexBahan = indexBahan;
    daftarMenu[indexMenu].resep[r].jumlah = jumlah;
    daftarMenu[indexMenu].jumlahResep++;
}

void inisialisasiData() {
    // Data bahan
    tambahBahanAwal("Nasi", 50, "porsi");
    tambahBahanAwal("Ayam", 30, "potong");
    tambahBahanAwal("Mie", 40, "bungkus");
    tambahBahanAwal("Telur", 50, "butir");
    tambahBahanAwal("Teh", 100, "gelas");
    tambahBahanAwal("Kopi", 80, "gelas");
    tambahBahanAwal("Gula", 100, "sendok");
    tambahBahanAwal("Air Mineral", 100, "botol");
    tambahBahanAwal("Es Batu", 100, "kubus");

    // Data menu
    tambahMenuAwal("Nasi Goreng", 15000);
    tambahMenuAwal("Mie Goreng", 14000);
    tambahMenuAwal("Ayam Goreng", 18000);
    tambahMenuAwal("Es Teh", 5000);
    tambahMenuAwal("Kopi Hitam", 7000);
    tambahMenuAwal("Air Mineral", 4000);

    // Resep menu
    // Nasi Goreng
    tambahResep(0, 0, 1); // Nasi
    tambahResep(0, 3, 1); // Telur
    tambahResep(0, 6, 1); // Gula (simbolik bahan tambahan)

    // Mie Goreng
    tambahResep(1, 2, 1); // Mie
    tambahResep(1, 3, 1); // Telur

    // Ayam Goreng
    tambahResep(2, 1, 1); // Ayam
    tambahResep(2, 0, 1); // Nasi

    // Es Teh
    tambahResep(3, 4, 1); // Teh
    tambahResep(3, 6, 1); // Gula
    tambahResep(3, 8, 2); // Es Batu

    // Kopi Hitam
    tambahResep(4, 5, 1); // Kopi
    tambahResep(4, 6, 1); // Gula

    // Air Mineral
    tambahResep(5, 7, 1); // Air Mineral
}

void tampilkanDaftarMenu() {
    int i;
    printf("\n========== DAFTAR MENU ==========\n");
    printf("%-5s %-20s %-10s\n", "No", "Nama Menu", "Harga");
    for (i = 0; i < jumlahMenu; i++) {
        printf("%-5d %-20s Rp%-10d\n", i + 1, daftarMenu[i].nama, daftarMenu[i].harga);
    }
    printf("=================================\n");
}

void tampilkanStokBahan() {
    int i;
    printf("\n========== STOK BAHAN ==========\n");
    printf("%-5s %-20s %-10s %-10s\n", "No", "Nama Bahan", "Stok", "Satuan");
    for (i = 0; i < jumlahBahan; i++) {
        printf("%-5d %-20s %-10d %-10s\n",
               i + 1,
               daftarBahan[i].nama,
               daftarBahan[i].stok,
               daftarBahan[i].satuan);
    }
    printf("================================\n");
}

int cekStokCukup(int indexMenu, int qty) {
    int i;
    for (i = 0; i < daftarMenu[indexMenu].jumlahResep; i++) {
        int idxBahan = daftarMenu[indexMenu].resep[i].indexBahan;
        int kebutuhan = daftarMenu[indexMenu].resep[i].jumlah * qty;
        if (daftarBahan[idxBahan].stok < kebutuhan) {
            return 0;
        }
    }
    return 1;
}

void kurangiStok(int indexMenu, int qty) {
    int i;
    for (i = 0; i < daftarMenu[indexMenu].jumlahResep; i++) {
        int idxBahan = daftarMenu[indexMenu].resep[i].indexBahan;
        int kebutuhan = daftarMenu[indexMenu].resep[i].jumlah * qty;
        daftarBahan[idxBahan].stok -= kebutuhan;
    }
}

void cetakStruk(PesananItem pesanan[], int jumlahPesanan, int total, int bayar, int kembalian) {
    int i;
    printf("\n=========== STRUK PEMBAYARAN ===========\n");
    printf("Kafetaria IT Del\n");
    printf("----------------------------------------\n");
    printf("%-20s %-5s %-10s\n", "Menu", "Qty", "Subtotal");

    for (i = 0; i < jumlahPesanan; i++) {
        printf("%-20s %-5d Rp%-10d\n",
               daftarMenu[pesanan[i].indexMenu].nama,
               pesanan[i].qty,
               pesanan[i].subtotal);
    }

    printf("----------------------------------------\n");
    printf("Total Bayar   : Rp%d\n", total);
    printf("Uang Bayar    : Rp%d\n", bayar);
    printf("Kembalian     : Rp%d\n", kembalian);
    printf("========================================\n");
    printf("Terima kasih telah berbelanja!\n");
}

void prosesPesanan() {
    PesananItem pesanan[MAX_PESANAN];
    int jumlahPesanan = 0;
    int pilihan, qty;
    int total = 0;
    int bayar, kembalian;
    int i;

    while (1) {
        tampilkanDaftarMenu();
        printf("Pilih nomor menu (0 untuk selesai): ");
        scanf("%d", &pilihan);

        if (pilihan == 0) {
            break;
        }

        if (pilihan < 1 || pilihan > jumlahMenu) {
            printf("Pilihan menu tidak valid!\n");
            continue;
        }

        printf("Masukkan jumlah pesanan: ");
        scanf("%d", &qty);

        if (qty <= 0) {
            printf("Jumlah pesanan harus lebih dari 0!\n");
            continue;
        }

        if (!cekStokCukup(pilihan - 1, qty)) {
            printf("Stok bahan untuk menu '%s' tidak mencukupi!\n", daftarMenu[pilihan - 1].nama);
            continue;
        }

        pesanan[jumlahPesanan].indexMenu = pilihan - 1;
        pesanan[jumlahPesanan].qty = qty;
        pesanan[jumlahPesanan].subtotal = daftarMenu[pilihan - 1].harga * qty;

        total += pesanan[jumlahPesanan].subtotal;
        jumlahPesanan++;

        printf("Pesanan '%s' sebanyak %d berhasil ditambahkan.\n",
               daftarMenu[pilihan - 1].nama, qty);

        if (jumlahPesanan >= MAX_PESANAN) {
            printf("Batas maksimal item pesanan tercapai.\n");
            break;
        }
    }

    if (jumlahPesanan == 0) {
        printf("Belum ada pesanan yang diproses.\n");
        return;
    }

    // Kurangi stok setelah semua pesanan dikonfirmasi
    for (i = 0; i < jumlahPesanan; i++) {
        kurangiStok(pesanan[i].indexMenu, pesanan[i].qty);
    }

    printf("\nTotal pembayaran: Rp%d\n", total);

    do {
        printf("Masukkan jumlah uang bayar: Rp");
        scanf("%d", &bayar);

        if (bayar < total) {
            printf("Uang pembayaran kurang!\n");
        }
    } while (bayar < total);

    kembalian = bayar - total;

    cetakStruk(pesanan, jumlahPesanan, total, bayar, kembalian);
}

void tambahStokBahan() {
    int pilihan, tambahan;

    tampilkanStokBahan();
    printf("Pilih nomor bahan yang ingin ditambah stoknya: ");
    scanf("%d", &pilihan);

    if (pilihan < 1 || pilihan > jumlahBahan) {
        printf("Pilihan bahan tidak valid!\n");
        return;
    }

    printf("Masukkan jumlah tambahan stok: ");
    scanf("%d", &tambahan);

    if (tambahan <= 0) {
        printf("Jumlah tambahan harus lebih dari 0!\n");
        return;
    }

    daftarBahan[pilihan - 1].stok += tambahan;
    printf("Stok bahan '%s' berhasil ditambah.\n", daftarBahan[pilihan - 1].nama);
}

int main() {
    int menuUtama;
    inisialisasiData();

    do {
        printf("\n=====================================\n");
        printf(" SISTEM OPERASIONAL KAFETARIA IT DEL \n");
        printf("=====================================\n");
        printf("1. Lihat daftar menu\n");
        printf("2. Lihat stok bahan\n");
        printf("3. Proses pesanan pelanggan\n");
        printf("4. Tambah stok bahan\n");
        printf("0. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &menuUtama);

        switch (menuUtama) {
            case 1:
                tampilkanDaftarMenu();
                break;
            case 2:
                tampilkanStokBahan();
                break;
            case 3:
                prosesPesanan();
                break;
            case 4:
                tambahStokBahan();
                break;
            case 0:
                printf("Program selesai. Terima kasih.\n");
                break;
            default:
                printf("Pilihan tidak valid!\n");
        }
    } while (menuUtama != 0);

    return 0;
}