#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 9
#define COLS 9
#define PASSWORD 2025

char seats[ROWS][COLS]; // ��λ���

// �ܴa�z�麯��
int checkPassword() {
    int input, attempts = 0;
    while (attempts < 3) {
        printf("===== Welcome to the Booking System =====\n");
        for (int i = 0; i < 20; i++) {
            printf("||        This is a test screen        ||\n");
        }
        printf("=========================================\n");

        printf("Please enter the 4-digit password: ");
        scanf("%d", &input);

        if (input == PASSWORD) {
            printf("\nCorrect password! Access granted.\n");
            return 1;
        } else {
            printf("Incorrect password. Please try again.\n\n");
            attempts++;
        }
    }

    printf("Too many incorrect attempts. Exiting program.\n");
    return 0;
}

// ��ʼ����λ���K�S�C�a�� 10 �����Aӆ��λ
void initSeats() {
    srand(time(NULL)); // �a���S�C�N��
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            seats[i][j] = '-'; // �A�O���λ

    int count = 0;
    while (count < 10) {
        int r = rand() % ROWS;
        int c = rand() % COLS;
        if (seats[r][c] == '-') {
            seats[r][c] = '*'; // �S�C��ӛ�����Aӆ
            count++;
        }
    }
}

// �@ʾ��λ��
void displaySeats() {
    printf("\\123456789\n"); // ��һ����λ��̖
    for (int i = ROWS - 1; i >= 0; i--) {
        printf("%d", i + 1); // �о�̖
        for (int j = 0; j < COLS; j++) {
            printf("%c", seats[i][j]);
        }
        printf("\n");
    }
}

// �@ʾ���x��
void showMenu() {
    printf("----------[Booking System]----------\n");
    printf("|  a. Available seats              |\n");
    printf("|  b. Arrange for you              |\n");
    printf("|  c. Choose by yourself           |\n");
    printf("|  d. Exit                         |\n");
    printf("------------------------------------\n");
}

// �_�J�Ƿ�Ҫ�^�m
void askContinue() {
    char choice;
    while (1) {
        printf("Continue? (y/n): ");
        scanf(" %c", &choice);

        if (choice == 'y' || choice == 'Y') return;
        else if (choice == 'n' || choice == 'N') {
            printf("Exiting program. Goodbye!\n");
            exit(0);
        } else {
            printf("Invalid input. Please enter 'y' or 'n'.\n");
        }
    }
}

int main() {
    if (!checkPassword()) return 0;

    initSeats(); // ��ʼ����λ
    char option;

    while (1) {
        system("cls");
        showMenu();

        printf("Enter your choice: ");
        scanf(" %c", &option);

        switch (option) {
            case 'a':
                system("cls");
                displaySeats();
                printf("Press Enter to return to menu...\n");
                getchar(); getchar(); // ��ͣ
                break;
            case 'b':
            case 'c':
                printf("Feature not implemented yet.\n");
                break;
            case 'd':
                askContinue();
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }

    return 0;
}

