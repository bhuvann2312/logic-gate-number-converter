#include <stdio.h>

void decToBinary(int n) {
    int bits[32], i = 0;
    if (n == 0) {
        printf("Binary: 0\n");
        return;
    }
    while (n > 0) {
        bits[i++] = n % 2;
        n /= 2;
    }
    printf("Binary: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", bits[j]);
    }
    printf("\n");
}

void printTruthTables() {
    printf("\nA  B | AND OR  NAND NOR XOR\n");
    printf("---------------------------\n");
    for (int a = 0; a <= 1; a++) {
        for (int b = 0; b <= 1; b++) {
            int and_g = a & b;
            int or_g  = a | b;
            int nand_g = !(a & b);
            int nor_g  = !(a | b);
            int xor_g  = a ^ b;
            printf("%d  %d |  %d   %d    %d    %d   %d\n", a, b, and_g, or_g, nand_g, nor_g, xor_g);
        }
    }
}

int main() {
    int choice, num;
    while (1) {
        printf("\n--- Digital Logic Helper ---\n");
        printf("1. Convert Decimal to Binary\n");
        printf("2. Print Logic Gate Truth Tables\n");
        printf("3. Exit\n");
        printf("Choice: ");
        if (scanf("%d", &choice) != 1 || choice == 3) break;

        if (choice == 1) {
            printf("Enter a non-negative integer: ");
            scanf("%d", &num);
            if (num >= 0) decToBinary(num);
        } else if (choice == 2) {
            printTruthTables();
        } else {
            printf("Invalid choice.\n");
        }
    }
    return 0;
}
