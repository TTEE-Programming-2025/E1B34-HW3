#include <stdio.h>

#define PASSWORD 2025 // �A�O�ܴa

// �ܴa�z�麯��
int checkPassword() {
    int input;
    int attempts = 0;

    while (attempts < 3) {
        // �@ʾ��ʾ����
        printf("===== Welcome to the Booking System =====\n");
        for (int i = 0; i < 20; i++) {
            printf("||        This is a test screen        ||\n");
        }
        printf("=========================================\n");

        // ��ʾʹ����ݔ���ܴa
        printf("Please enter the 4-digit password: ");
        scanf("%d", &input);

        if (input == PASSWORD) {
            printf("\nCorrect password! Access granted.\n");
            return 1; // �ܴa���_
        } else {
            printf("Incorrect password. Please try again.\n\n");
            attempts++;
        }
    }

    // �����e�`��Y����ʽ
    printf("Too many incorrect attempts. Exiting program.\n");
    return 0;
}

int main() {
    if (!checkPassword()) {
        return 0; // �ܴa�e�`���Y����ʽ
    }

    // δ���ܕ����@�e�^�m����
    printf("Password correct. Program continues...\n");

    return 0;
}

