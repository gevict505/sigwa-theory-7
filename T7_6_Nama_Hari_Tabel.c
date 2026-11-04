#include <stdio.h>

int kabisat(int tahun);
int hari_dalam_bulan(int bulan, int tahun);

int main() {
    /* baris = (tahun - 1900) % 28, kolom = bulan Jan sampai Des */
    int kode[28][12] = {
        {0, 3, 4, 0, 2, 5, 0, 3, 6, 1, 4, 6},
        {2, 5, 5, 1, 3, 6, 1, 4, 0, 2, 5, 0},
        {3, 6, 6, 2, 4, 0, 2, 5, 1, 3, 6, 1},
        {4, 0, 0, 3, 5, 1, 3, 6, 2, 4, 0, 2},
        {5, 1, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4},
        {0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5},
        {1, 4, 4, 0, 2, 5, 0, 3, 6, 1, 4, 6},
        {2, 5, 5, 1, 3, 6, 1, 4, 0, 2, 5, 0},
        {3, 6, 0, 3, 5, 1, 3, 6, 2, 4, 0, 2},
        {5, 1, 1, 4, 6, 2, 4, 0, 3, 5, 1, 3},
        {6, 2, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4},
        {0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5},
        {1, 4, 5, 1, 3, 6, 1, 4, 0, 2, 5, 0},
        {3, 6, 6, 2, 4, 0, 2, 5, 1, 3, 6, 1},
        {4, 0, 0, 3, 5, 1, 3, 6, 2, 4, 0, 2},
        {5, 1, 1, 4, 6, 2, 4, 0, 3, 5, 1, 3},
        {6, 2, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5},
        {1, 4, 4, 0, 2, 5, 0, 3, 6, 1, 4, 6},
        {2, 5, 5, 1, 3, 6, 1, 4, 0, 2, 5, 0},
        {3, 6, 6, 2, 4, 0, 2, 5, 1, 3, 6, 1},
        {4, 0, 1, 4, 6, 2, 4, 0, 3, 5, 1, 3},
        {6, 2, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4},
        {0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5},
        {1, 4, 4, 0, 2, 5, 0, 3, 6, 1, 4, 6},
        {2, 5, 6, 2, 4, 0, 2, 5, 1, 3, 6, 1},
        {4, 0, 0, 3, 5, 1, 3, 6, 2, 4, 0, 2},
        {5, 1, 1, 4, 6, 2, 4, 0, 3, 5, 1, 3},
        {6, 2, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4}
    };
    char *nama_hari[7] = {"Sabtu", "Minggu", "Senin", "Selasa",
                          "Rabu", "Kamis", "Jumat"};
    int tanggal, bulan, tahun, baris, k, neptu;
    char ulang;

    do {
        printf("Masukkan tanggal (dd-mm-yyyy) : ");
        scanf("%d-%d-%d", &tanggal, &bulan, &tahun);

        if (tahun < 1901 || tahun > 2099 || bulan < 1 || bulan > 12 ||
            tanggal < 1 || tanggal > hari_dalam_bulan(bulan, tahun)) {
            printf("Tanggal tidak valid atau di luar tahun 1901-2099!\n");
        } else {
            baris = (tahun - 1900) % 28;
            k = kode[baris][bulan - 1];
            neptu = tanggal + k;
            printf("Tanggal + kode : %d + %d = %d\n", tanggal, k, neptu);
            printf("Tanggal tersebut adalah hari %s.\n", nama_hari[neptu % 7]);
        }

        printf("Coba lagi? (y/n) ");
        scanf(" %c", &ulang);
        printf("\n");
    } while (ulang == 'y' || ulang == 'Y');
    return 0;
}

int kabisat(int tahun) {
    if ((tahun % 400 == 0) || (tahun % 4 == 0 && tahun % 100 != 0))
        return 1;
    return 0;
}

int hari_dalam_bulan(int bulan, int tahun) {
    int hari[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (bulan == 2 && kabisat(tahun))
        return 29;
    return hari[bulan - 1];
}
