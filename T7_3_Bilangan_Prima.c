#include <stdio.h>
#define MAX 46349

int main() {
    static int P[MAX + 1];
    long long i, j;
    int n, banyak, kolom;
    char ulang;

    do {
        do {
            printf("Masukkan n (2-%d) = ", MAX);
            scanf("%d", &n);
        } while (n < 2 || n > MAX);

        for (i = 0; i <= n; i++)
            P[i] = 0;

        for (i = 2; i <= n; i++) {
            if (P[i] == 0) {
                for (j = i * i; j <= n; j += i)
                    P[j] = 1;
            }
        }

        printf("Bilangan prima dari 1 sampai %d:\n", n);
        banyak = 0;
        kolom = 0;
        for (i = 2; i <= n; i++) {
            if (P[i] == 0) {
                printf("%7lld", i);
                banyak++;
                kolom++;
                if (kolom == 10) {
                    printf("\n");
                    kolom = 0;
                }
            }
        }
        if (kolom != 0)
            printf("\n");
        printf("Banyak bilangan prima = %d\n", banyak);

        printf("Coba lagi? (y/n) ");
        scanf(" %c", &ulang);
        printf("\n");
    } while (ulang == 'y' || ulang == 'Y');
    return 0;
}
