#include <stdio.h>

#define MAKS 19

int main() {
    int ajaib[MAKS][MAKS];
    int ordo, baris, kolom, angka, i, j;
    int baris_lama, kolom_lama;
    int konstanta, jumlah, ok;
    char ulang;

    do {
        do {
            printf("Masukkan ordo (ganjil, 3-%d) = ", MAKS);
            scanf("%d", &ordo);
            if (ordo < 3 || ordo > MAKS || ordo % 2 == 0)
                printf("Ordo harus ganjil dan antara 3 sampai %d!\n", MAKS);
        } while (ordo < 3 || ordo > MAKS || ordo % 2 == 0);

        for (i = 0; i < ordo; i++)
            for (j = 0; j < ordo; j++)
                ajaib[i][j] = 0;

        baris = 0;
        kolom = ordo / 2;
        for (angka = 1; angka <= ordo * ordo; angka++) {
            ajaib[baris][kolom] = angka;
            baris_lama = baris;
            kolom_lama = kolom;

            baris--;
            kolom++;
            if (baris < 0)
                baris = ordo - 1;
            if (kolom == ordo)
                kolom = 0;

            if (ajaib[baris][kolom] != 0) {
                baris = baris_lama + 1;
                kolom = kolom_lama;
            }
        }

        printf("\n");
        for (i = 0; i < ordo; i++) {
            for (j = 0; j < ordo; j++)
                printf("%4d", ajaib[i][j]);
            printf("\n");
        }

        konstanta = ordo * (ordo * ordo + 1) / 2;
        ok = 1;
        for (i = 0; i < ordo; i++) {
            jumlah = 0;
            for (j = 0; j < ordo; j++)
                jumlah += ajaib[i][j];
            if (jumlah != konstanta)
                ok = 0;
            jumlah = 0;
            for (j = 0; j < ordo; j++)
                jumlah += ajaib[j][i];
            if (jumlah != konstanta)
                ok = 0;
        }
        jumlah = 0;
        for (i = 0; i < ordo; i++)
            jumlah += ajaib[i][i];
        if (jumlah != konstanta)
            ok = 0;
        jumlah = 0;
        for (i = 0; i < ordo; i++)
            jumlah += ajaib[i][ordo - 1 - i];
        if (jumlah != konstanta)
            ok = 0;

        printf("\nJumlah tiap baris, kolom, dan diagonal = %d\n", konstanta);
        if (ok)
            printf("Semua jumlah sama, bujursangkar ini ajaib\n");
        else
            printf("Ada jumlah yang berbeda\n");

        printf("Coba lagi? (y/n) ");
        scanf(" %c", &ulang);
        printf("\n");
    } while (ulang == 'y' || ulang == 'Y');
    return 0;
}
