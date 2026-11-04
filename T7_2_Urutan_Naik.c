#include <stdio.h>

#define MAKS 100

int main() {
    int data[MAKS];
    int n, i, j, tmp;
    char ulang;

    do {
        do {
            printf("Masukkan jumlah data (5-%d) = ", MAKS);
            scanf("%d", &n);
        } while (n < 5 || n > MAKS);

        for (i = 0; i < n; i++) {
            printf("Data ke-%d = ", i + 1);
            scanf("%d", &data[i]);
        }

        for (i = 0; i < n - 1; i++) {
            for (j = 0; j < n - 1 - i; j++) {
                if (data[j] > data[j + 1]) {
                    tmp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = tmp;
                }
            }
        }

        printf("\nJumlah data : %d\n", n);
        printf("Data terurut naik :");
        for (i = 0; i < n; i++)
            printf(" %d", data[i]);
        printf("\n");

        printf("Coba lagi? (y/n) ");
        scanf(" %c", &ulang);
        printf("\n");
    } while (ulang == 'y' || ulang == 'Y');
    return 0;
}
