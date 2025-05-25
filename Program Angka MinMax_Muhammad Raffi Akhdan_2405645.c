#include <stdio.h>
#include <stdlib.h>

void urutanAngka(float arr[], int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1]) {
                float temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
}

float cariMedian(float arr[], int n) {
    urutanAngka(arr, n);  // Panggil fungsi urutanAngka, bukan bubbleSort
    if (n % 2 == 0)
        return (arr[n/2 - 1] + arr[n/2]) / 2;
    else
        return arr[n/2];
}

float cariModus(float arr[], int n) {
    int maxCount = 0;
    float modus = arr[0];

    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (arr[j] == arr[i])
                count++;
        }

        if (count > maxCount) {
            maxCount = count;
            modus = arr[i];
        }
    }

    // Jika semua angka hanya muncul satu kali, tidak ada modus
    if (maxCount == 1)
        return -1; // penanda tidak ada modus
    else
        return modus;
}

int main() {
    int n;
    float total = 0, min, max;

    printf("Masukkan jumlah angka: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Jumlah angka harus lebih dari 0.\n");
        return 1;
    }

    float angka[n];

    for (int i = 0; i < n; i++) {
        printf("Masukkan angka ke-%d: ", i + 1);
        scanf("%f", &angka[i]);
        total += angka[i];

        if (i == 0) {
            max = min = angka[i];
        } else {
            if (angka[i] > max) max = angka[i];
            if (angka[i] < min) min = angka[i];
        }
    }

    float mean = total / n;
    float median = cariMedian(angka, n);
    float modus = cariModus(angka, n);

    printf("\n=== Hasil Perhitungan ===\n");
    printf("Nilai Tertinggi : %.2f\n", max);
    printf("Nilai Terendah  : %.2f\n", min);
    printf("Mean (Rata-rata): %.2f\n", mean);
    printf("Median          : %.2f\n", median);
    if (modus == -1)
        printf("Modus           : Tidak ada (semua nilai unik)\n");
    else
        printf("Modus           : %.2f\n", modus);

    return 0;
}

