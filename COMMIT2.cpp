#include <stdio.h>
#include <stdlib.h>

#define PASSWORD 2025

// 密碼檢查函數
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

// 顯示主選單
void showMenu() {
    printf("----------[Booking System]----------\n");
    printf("|  a. Available seats              |\n");
    printf("|  b. Arrange for you              |\n");
    printf("|  c. Choose by yourself           |\n");
    printf("|  d. Exit                         |\n");
    printf("------------------------------------\n");
}

// 確認是否要繼續
void askContinue() {
    char choice;
    while (1) {
        printf("Continue? (y/n): ");
        scanf(" %c", &choice); // 注意前面有空格，避免讀取換行符

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

    char option;

    while (1) {
        system("cls"); // 清屏，適用於 Windows，Linux 可用 \"clear\"
        showMenu();

        printf("Enter your choice: ");
        scanf(" %c", &option);

        switch (option) {
            case 'a':
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

