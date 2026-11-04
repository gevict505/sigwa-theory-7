#include <stdio.h>

#define N 8

int main() {
    int data[N] = {7, 8, 4, 2, 9, 3, 1, 6};
    int urut[N];
    int i, j, tmp, terbesar, idx_terbesar, jumlah, ada_genap;
    float rata2, tengah;
    char pilih;

    printf("Pakai data pada soal? (y/n) ");
    scanf(" %c", &pilih);
    if (pilih != 'y' && pilih != 'Y') {
        for (i = 0; i < N; i++) {
            printf("Data index %d = ", i + 1);
            scanf("%d", &data[i]);
        }
    }

    printf("\nindex :");
    for (i = 0; i < N; i++)
        printf("%3d", i + 1);
    printf("\ndata  :");
    for (i = 0; i < N; i++)
        printf("%3d", data[i]);
    printf("\n");

    printf("\nAngka genap :");
    ada_genap = 0;
    for (i = 0; i < N; i++) {
        if (data[i] % 2 == 0) {
            printf(" %d", data[i]);
            ada_genap = 1;
        }
    }
    if (!ada_genap)
        printf(" tidak ada");
    printf("\n");

    terbesar = data[0];
    idx_terbesar = 1;
    for (i = 1; i < N; i++) {
        if (data[i] > terbesar) {
            terbesar = data[i];
            idx_terbesar = i + 1;
        }
    }
    printf("Angka terbesar : %d (index %d)\n", terbesar, idx_terbesar);

    for (i = 0; i < N; i++)
        urut[i] = data[i];
    for (i = 0; i < N - 1; i++) {
        for (j = 0; j < N - 1 - i; j++) {
            if (urut[j] > urut[j + 1]) {
                tmp = urut[j];
                urut[j] = urut[j + 1];
                urut[j + 1] = tmp;
            }
        }
    }
    printf("Urut dari kecil :");
    for (i = 0; i < N; i++)
        printf(" %d", urut[i]);
    printf("\n");

    jumlah = 0;
    for (i = 0; i < N; i++)
        jumlah += data[i];
    rata2 = (float)jumlah / N;
    printf("Rata-rata : %.2f\n", rata2);

    if (N % 2 == 1)
        tengah = urut[N / 2];
    else
        tengah = (urut[N / 2 - 1] + urut[N / 2]) / 2.0;
    printf("Nilai tengah : %.2f\n", tengah);
    return 0;
}
