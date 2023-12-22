#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 1000

void divider();
void Add_Product();
void Edit_product(int id);
void Display_product(int id);
void Calculate_Bill(int id, int quantity);
void menu();

int cnt = 0;
int product_id[MAX_ITEMS];
int product_quantity[MAX_ITEMS];
float product_price[MAX_ITEMS];
char product_name[MAX_ITEMS][20];

void divider() {
    printf("**********************\n");
}

void Add_Product() {
    printf("*****ADDING A PRODUCT*****\n\n");

    if (cnt < MAX_ITEMS) {
        printf("Product Id:\n");
        scanf("%d", &product_id[cnt]);
        getchar();

        printf("Product Name:\n");
        scanf("%19s", product_name[cnt]);
        getchar();

        printf("Product Quantity:\n");
        scanf("%d", &product_quantity[cnt]);
        getchar();

        printf("Product price:\n");
        scanf("%f", &product_price[cnt]);
        getchar();

        cnt++;
        printf("Product added successfully!\n");
    } else {
        printf("Inventory full, cannot add more products!\n");
    }

    printf("Press Enter to continue...\n");
    getchar();
}

void Edit_product(int id) {
    if (id > 0 && id <= cnt) {
        int pi, pq;
        char pn[20];
        float pp;
        printf("Product Id:\n");
        scanf("%d", &pi);
        getchar();
        product_id[id - 1] = pi;

        printf("Product Name:\n");
        scanf("%19s", pn);
        getchar();
        strcpy(product_name[id - 1], pn);

        printf("Product Quantity:\n");
        scanf("%d", &pq);
        getchar();
        product_quantity[id - 1] = pq;

        printf("Product price:\n");
        scanf("%f", &pp);
        getchar();
        product_price[id - 1] = pp;
    } else {
        printf("Product is invalid\n");
    }
    printf("Press Enter to continue...\n");
    getchar();
}

void Display_product(int id) {
    if (id > 0 && id <= cnt) {
        id--;
        printf("Product Id: %d\n", product_id[id]);
        printf("Product Name: %s\n", product_name[id]);
        printf("Product Quantity: %d\n", product_quantity[id]);
        printf("Product price: %f\n", product_price[id]);
    } else {
        printf("Product is invalid\n");
    }
    printf("Press Enter to continue...\n");
    getchar();
}

void Calculate_Bill(int id, int quantity) {
    int item_id = id, item_quantity = quantity;
    if (item_id > 0 && item_id <= cnt) {
        if (product_quantity[item_id - 1] >= item_quantity) {
            product_quantity[item_id - 1] -= item_quantity;
            float bill = item_quantity * product_price[item_id - 1] + (item_quantity * product_price[item_id - 1] * 0.06);
            printf("THE BILL = %f\n", bill);
        } else {
            printf("Quantity of Product is invalid\n");
        }
    } else {
        printf("Product is invalid\n");
    }
    printf("Press Enter to continue...\n");
    getchar();
}

void menu() {
    divider();
    printf("\t\tMENU\n");
    divider();
    printf("1. Add product\n");
    printf("2. Edit product\n");
    printf("3. Display product\n");
    printf("4. Calculate Bill\n");
    printf("5. Exit\n");
    divider();
}

int main() {
    int ch, id, item_quantity;
    while (1) {
        menu();
        printf("Enter your choice: \n");
        scanf("%d", &ch);
        getchar();
        switch (ch) {
            case 1:
                Add_Product();
                break;
            case 2:
                printf("Enter Product Id You Want To Edit: \n");
                scanf("%d", &id);
                getchar();
                Edit_product(id);
                break;
            case 3:
                printf("Enter Product Id You Want To Display: \n");
                scanf("%d", &id);
                getchar();
                Display_product(id);
                break;
            case 4:
                printf("Enter Product Id:\n");
                scanf("%d", &id);
                getchar();
                printf("Enter Product Quantity:\n");
                scanf("%d", &item_quantity);
                getchar();
                Calculate_Bill(id, item_quantity);
                break;
            case 5:
                exit(0);
            default:
                printf("*****INVALID PRODUCT*****\n");
        }
    }
    return 0;
}
