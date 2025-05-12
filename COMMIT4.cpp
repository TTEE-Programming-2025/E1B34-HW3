#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define ROWS 9
#define COLS 9
#define PASSWORD 2025

char seats[ROWS][COLS]; // 座位陣列

// ---------- 第1階段：密碼驗證 ----------
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

// ---------- 第3階段：座位初始化與顯示 ----------
void initSeats() {
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            seats[i][j] = '-';

    int count = 0;
    while (count < 10) {
        int r = rand() % ROWS;
        int c = rand() % COLS;
        if (seats[r][c] == '-') {
            seats[r][c] = '*';
            count++;
        }
    }
}

void displaySeats() {
    printf("\\123456789\n");
    for (int i = ROWS - 1; i >= 0; i--) {
        printf("%d", i + 1);
        for (int j = 0; j < COLS; j++) {
            printf("%c", seats[i][j]);
        }
        printf("\n");
    }
}

// ---------- 第4階段：自動安排座位 ----------
void arrangeSeats() {
    int num;
    printf("How many seats do you need? (1-4): ");
    scanf("%d", &num);

    if (num < 1 || num > 4) {
        printf("Invalid number of seats.\n");
        return;
    }

    int found = 0;

    for (int i = 0; i < ROWS && !found; i++) {
        for (int j = 0; j <= COLS - num; j++) {
            int canArrange = 1;
            for (int k = 0; k < num; k++) {
                if (seats[i][j + k] != '-') {
                    canArrange = 0;
                    break;
                }
            }
            if (canArrange) {
                for (int k = 0; k < num; k++) {
                    seats[i][j + k] = '@'; // 暫時標示建議座位
                }
                found = 1;
                break;
            }
        }
    }

    if (!found) {
        printf("No suitable seats found.\n");
        return;
    }

    displaySeats();

    char response;
    printf("Are you satisfied with the arrangement? (y/n): ");
    scanf(" %c", &response);

    if (response == 'y' || response == 'Y') {
        for (int i = 0; i < ROWS; i++)
            for (int j = 0; j < COLS; j++)
                if (seats[i][j] == '@')
                    seats[i][j] = '*'; // 確認選位
    } else {
        for (int i = 0; i < ROWS; i++)
            for (int j = 0; j < COLS; j++)
                if (seats[i][j] == '@')
                    seats[i][j] = '-'; // 清除建議
    }
}

// ---------- 主選單與選項處理 ----------
void showMenu() {
    printf("----------[Booking System]----------\n");
    printf("|  a. Available seats              |\n");
    printf("|  b. Arrange for you              |\n");
    printf("|  c. Choose by yourself           |\n");
    printf("|  d. Exit                         |\n");
    printf("------------------------------------\n");
}

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

// ---------- 主程式 ----------
int main() {
    if (!checkPassword()) return 0;

    initSeats();

    char option;
    while (1) {
        system("cls"); // Windows 下清除螢幕，Linux/macOS 可改為 system("clear")
        showMenu();

        printf("Enter your choice: ");
        scanf(" %c", &option);

        switch (option) {
            case 'a':
                system("cls");
                displaySeats();
                printf("Press Enter to return to menu...\n");
                getchar(); getchar();
                break;

            case 'b':
                system("cls");
                arrangeSeats();
                printf("Press Enter to return to menu...\n");
                getchar(); getchar();
                break;

            case 'c':
                printf("Manual selection not implemented yet.\n");
                break;

            case 'd':
                askContinue();
                break;

            default:
                printf("Invalid option. Try again.\n");
                break;
        }
    }

    return 0;
}

