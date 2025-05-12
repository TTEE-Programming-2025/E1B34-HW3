#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 9
#define COLS 9
#define PASSWORD 2025

char seats[ROWS][COLS]; // 座位陣列

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

// 初始化座位表，並隨機產生 10 個已預訂座位
void initSeats() {
    srand(time(NULL)); // 產生隨機種子
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            seats[i][j] = '-'; // 預設為空位

    int count = 0;
    while (count < 10) {
        int r = rand() % ROWS;
        int c = rand() % COLS;
        if (seats[r][c] == '-') {
            seats[r][c] = '*'; // 隨機標記為已預訂
            count++;
        }
    }
}

// 顯示座位表
void displaySeats() {
    printf("\\123456789\n"); // 第一行座位標號
    for (int i = ROWS - 1; i >= 0; i--) {
        printf("%d", i + 1); // 列編號
        for (int j = 0; j < COLS; j++) {
            printf("%c", seats[i][j]);
        }
        printf("\n");
    }
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

    initSeats(); // 初始化座位
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
                getchar(); getchar(); // 暫停
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

