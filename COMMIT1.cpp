#include <stdio.h>

#define PASSWORD 2025 // 預設密碼

// 密碼檢查函數
int checkPassword() {
    int input;
    int attempts = 0;

    while (attempts < 3) {
        // 顯示提示畫面
        printf("===== Welcome to the Booking System =====\n");
        for (int i = 0; i < 20; i++) {
            printf("||        This is a test screen        ||\n");
        }
        printf("=========================================\n");

        // 提示使用者輸入密碼
        printf("Please enter the 4-digit password: ");
        scanf("%d", &input);

        if (input == PASSWORD) {
            printf("\nCorrect password! Access granted.\n");
            return 1; // 密碼正確
        } else {
            printf("Incorrect password. Please try again.\n\n");
            attempts++;
        }
    }

    // 三次錯誤後結束程式
    printf("Too many incorrect attempts. Exiting program.\n");
    return 0;
}

int main() {
    if (!checkPassword()) {
        return 0; // 密碼錯誤，結束程式
    }

    // 未來功能會在這裡繼續加入
    printf("Password correct. Program continues...\n");

    return 0;
}

