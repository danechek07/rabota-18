#include <stdio.h>

typedef struct {
    char name[50];
    int year, month, day;
    int shelf_life;
    float price;
    char series[20];
} Product;

int main() {
    system("chcp 1251");
    int current_year = 2025;
    int current_month = 12;
    int current_day = 3;

    Product products[7] = {
        {"Молоко 3.2%",           2025, 11, 29,   6,  89.90,  "MOL001"},
        {"Хлеб нарезной",         2025, 12,  2,   3,  52.00,  "HLEB12"},
        {"Колбаса Докторская",    2025, 11, 25,  14, 489.00,  "KOL889"},
        {"Сыр Российский 50%",    2025, 11, 15,  45, 720.50,  "SYR404"},
        {"Йогурт клубничный",     2025, 12,  1,   7,  48.90,  "YOG777"},
        {"Творог 5%",             2025, 11, 28,  10, 135.00,  "TVO22"},
        {"Масло сливочное 82.5%", 2025, 11, 10,  60, 389.00,  "MAS101"}
    };

    int n = 7;

    printf("Текущая дата: %d-%02d-%02d\n", current_year, current_month, current_day);
    printf("=======================================\n");
    printf("Товары, срок годности которых истекает через 5 дней или раньше:\n\n");

    int found = 0;

    for (int i = 0; i < n; i++) {
        int days_passed = (current_day - products[i].day) +
            (current_month - products[i].month) * 30 +
            (current_year - products[i].year) * 365;

        int days_left = products[i].shelf_life - days_passed;


        if (days_left <= 5 && days_left >= 0) {
            found = 1;
            printf("СРОЧНО! %s\n", products[i].name);
            printf("   Серия: %s\n", products[i].series);
            printf("   Дата производства: %d-%02d-%02d\n",
                products[i].year, products[i].month, products[i].day);
            printf("   Срок годности: %d дней - осталось всего %d дней(дня)!\n",
                products[i].shelf_life, days_left);
            printf("   Цена: %.2f руб.\n", products[i].price);
            printf("----------------------------------------\n");
        }
    }

    if (!found) {
        printf("Ура! Ни один товар не испортится в ближайшие 5 дней!\n");
    }

    return 0;
}