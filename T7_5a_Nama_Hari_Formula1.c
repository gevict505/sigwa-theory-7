#include <stdio.h>

int kabisat(int tahun);
int hari_dalam_bulan(int bulan, int tahun);

int main() {
    /* kolom 0 = tahun biasa, kolom 1 = tahun kabisat */
    int kode_bulan[12][2] = {
        {1, 0}, {4, 3}, {4, 4}, {0, 0}, {2, 2}, {5, 5},
        {0, 0}, {3, 3}, {6, 6}, {1, 1}, {4, 4}, {6, 6}
    };
    char *nama_hari[7] = {"Sabtu", "Minggu", "Senin", "Selasa",
                          "Rabu", "Kamis", "Jumat"};
    int tanggal, bulan, tahun, yy, k, kode;
    char ulang;

    do {
        printf("Masukkan tanggal (dd-mm-yy) : ");
        scanf("%d-%d-%d", &tanggal, &bulan, &tahun);

        if (tahun >= 1900 && tahun <= 1999)
            yy = tahun - 1900;
        else
            yy = tahun;

        if (yy < 0 || yy > 99 || bulan < 1 || bulan > 12 ||
            tanggal < 1 || tanggal > hari_dalam_bulan(bulan, 1900 + yy)) {
            printf("Tanggal tidak valid atau di luar tahun 1900-1999!\n");
        } else {
            k = kabisat(1900 + yy);
            kode = (tanggal + kode_bulan[bulan - 1][k] + yy + yy / 4) % 7;
            printf("Tanggal tersebut adalah hari %s.\n", nama_hari[kode]);
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
