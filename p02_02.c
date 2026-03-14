//12S25027_Jessica Mariani Situmorang   

#include <stdio.h>

int main() {
    int N, i;
    int kode[100], stok[100];
    int kodeCari;
    int totalStok = 0;

    printf("Kode Kategori Barang:\n");
    printf("1 = Dasi SD\n");
    printf("2 = Gula\n");
    printf("3 = Rok Pramuka\n");
    printf("4 = Minyak\n\n");

    printf("Masukkan jumlah data barang: ");
    scanf("%d", &N);

    for (i = 0; i < N; i++) {
        printf("\nData barang ke-%d\n", i + 1);
        printf("Masukkan kode kategori: ");
        scanf("%d", &kode[i]);
        printf("Masukkan jumlah stok: ");
        scanf("%d", &stok[i]);
    }

    printf("\nMasukkan kode kategori yang ingin diketahui total stoknya: ");
    scanf("%d", &kodeCari);

    for (i = 0; i < N; i++) {
        if (kode[i] == kodeCari) {
            totalStok += stok[i];
        }
    }

    printf("\nTotal stok kategori ");
    if (kodeCari == 1) {
        printf("Dasi SD");
    } else if (kodeCari == 2) {
        printf("Gula");
    } else if (kodeCari == 3) {
        printf("Rok Pramuka");
    } else if (kodeCari == 4) {
        printf("Minyak");
    } else {
        printf("Tidak dikenal");
    }

    printf(" = %d\n", totalStok);

    return 0;
}