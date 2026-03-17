#include <stdio.h>
#include <string.h>

int main() {
    int N;
    char kategori[100][50];
    int stok[100];
    char cari[50];
    int total = 0;

    printf("Masukkan jumlah data barang: ");
    scanf("%d", &N);
    getchar(); // membersihkan newline setelah scanf

    // Input data kategori dan stok
    for (int i = 0; i < N; i++) {
        printf("\nData ke-%d\n", i + 1);

        printf("Masukkan nama kategori: ");
        fgets(kategori[i], sizeof(kategori[i]), stdin);
        kategori[i][strcspn(kategori[i], "\n")] = '\0'; // hapus newline

        printf("Masukkan jumlah stok: ");
        scanf("%d", &stok[i]);
        getchar(); // membersihkan newline
    }

    // Input kategori yang dicari
    printf("\nMasukkan kategori yang ingin diketahui stoknya: ");
    fgets(cari, sizeof(cari), stdin);
    cari[strcspn(cari, "\n")] = '\0'; // hapus newline

    // Proses penjumlahan stok sesuai kategori
    for (int i = 0; i < N; i++) {
        if (strcmp(kategori[i], cari) == 0) {
            total += stok[i];
        }
    }

    // Output hasil
    printf("\nKategori : %s\n", cari);
    printf("Total stok: %d\n", total);

    return 0;
}