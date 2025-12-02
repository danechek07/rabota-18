#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50];
    int year, month, day;
    int shelf_life;
    float price;
    char series[20];
} Product;

int main() {
    system("chcp 1251");

    int current_year = 2025, current_month = 12, current_day = 3;
    Product products[7];
    int n = 7;

    printf("=== Ввод данных о товарах ===\n");
    printf("Сегодня: %d-%02d-%02d\n\n", current_year, current_month, current_day);

    for (int i = 0; i < n; i++) {
        printf("--- Товар %d из %d ---\n", i + 1, n);

        printf("Введите название: ");
        scanf(" %49[^\n]", products[i].name);//Читает строку с пробелами (например, "Молоко 3.2%")

        printf("Дата производства (гггг мм дд): ");
        scanf("%d %d %d", &products[i].year, &products[i].month, &products[i].day);

        printf("Срок годности (в днях): ");
        scanf("%d", &products[i].shelf_life);

        printf("Цена (руб): ");
        scanf("%f", &products[i].price);

        printf("Серия (например, ABC123): ");
        scanf("%19s", products[i].series);

        printf("\n");
    }

    printf("\n=======================================\n");
    printf("Текущая дата: %d-%02d-%02d\n", current_year, current_month, current_day);
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
            printf("   Произведено: %d-%02d-%02d\n",
                   products[i].year, products[i].month, products[i].day);
            printf("   Срок годности: %d дней → осталось %d дн.\n",
                   products[i].shelf_life, days_left);
            printf("   Цена: %.2f руб.\n", products[i].price);
            printf("----------------------------------------\n");
        }
    }

    if (found == 0) {
        printf("Ура! Все товары свежие! Ничего не испортится в ближайшие 5 дней.\n");
    }

    return 0;
}
