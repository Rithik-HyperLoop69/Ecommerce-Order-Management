#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct {
    int id, qty;
    float price;
    char name[50], product[50], status[20];
} Order;

Order o[MAX];
int n = 0;

/* ---------- INPUT VALIDATION ---------- */

/* Integer input */
int getInt() {
    int x;
    while (scanf("%d", &x) != 1) {
        printf("Invalid number. Try again: ");
        while (getchar() != '\n');
    }
    return x;
}

/* Float input */
float getFloat() {
    float x;
    while (scanf("%f", &x) != 1) {
        printf("Invalid number. Try again: ");
        while (getchar() != '\n');
    }
    return x;
}

/* Validate name (only letters + space) */
int isValidName(char str[]) {
    for (int i = 0; str[i]; i++) {
        if (!isalpha(str[i]) && str[i] != ' ')
            return 0;
    }
    return 1;
}
int isValidProductName(char str[]) {
    int hasLetter = 0;
    for (int i = 0; str[i]; i++) {
        if (isalpha(str[i])) hasLetter = 1;
        else if (!isdigit(str[i]) && str[i] != ' ' && str[i] != '-' && str[i] != '#')
            return 0;
    }
    return hasLetter;
}
/* Validate status */
int isValidStatus(char str[]) {
    return strcmp(str, "Pending") == 0 ||
           strcmp(str, "Shipped") == 0 ||
           strcmp(str, "Delivered") == 0 ||
           strcmp(str, "Cancelled") == 0;
}

/* ---------- FIND ---------- */

int find(int id) {
    for (int i = 0; i < n; i++)
        if (o[i].id == id) return i;
    return -1;
}

/* ---------- MENU ---------- */

void menu(void) {
    printf("\n|=================================================|\n");
    printf("        E-Commerce Order Management System\n");
    printf("|=================================================|\n");
    printf(" 1. Add Order\n");
    printf(" 2. Display All Orders\n");
    printf(" 3. Search Order\n");
    printf(" 4. Update Order\n");
    printf(" 5. Save Orders\n");
    printf(" 6. Load Orders\n");
    printf(" 7. Exit\n");
    printf("|-------------------------------------------------|\n");
    printf("Choose an option\n");
    printf("=>");
}

/* ---------- ADD ---------- */

void add() {
    if (n >= MAX) return;

    printf("Enter Order ID: ");
    o[n].id = getInt();

    if (find(o[n].id) != -1) {
        printf("ID already exists!\n");
        return;
    }

    /* Name validation */
    while (1) {
        printf("Enter Customer Name: ");
        scanf(" %[^\n]", o[n].name);

        if (isValidName(o[n].name)) break;
        printf("Invalid name. Use only letters.\n");
    }
    while (1) {
    printf("Enter Product Name: ");
    scanf(" %[^\n]", o[n].product);
    if (isValidProductName(o[n].product)) break;
    printf("Invalid product name. Must contain at least one letter.\n");
}

    printf("Enter Quantity: ");
    o[n].qty = getInt();

    printf("Enter Price: ");
    o[n].price = getFloat();

    /* Status validation */
    while (1) {
        printf("Enter Status (Pending/Shipped/Delivered/Cancelled): ");
        scanf(" %[^\n]", o[n].status);

        if (isValidStatus(o[n].status)) break;
        printf("Invalid status. Use: Pending, Shipped, Delivered, Cancelled\n");
    }

    n++;
    printf("Order added successfully.\n");
}

/* ---------- DISPLAY ---------- */

void display() {
    if (n == 0) {
        printf("No orders available.\n");
        return;
    }

    printf("\n%-5s %-15s %-15s %-5s %-10s %-12s\n",
           "ID", "Name", "Product", "Qty", "Price", "Status");
    printf("---------------------------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        printf("%-5d %-15s %-15s %-5d %-10.2f %-12s\n",
               o[i].id,
               o[i].name,
               o[i].product,
               o[i].qty,
               o[i].price,
               o[i].status);
    }
}

/* ---------- SEARCH ---------- */

void search() {
    int id;
    printf("Enter ID: ");
    id = getInt();

    int i = find(id);
    if (i == -1) {
        printf("Order not found.\n");
        return;
    }

    printf("\n%-5s %-15s %-15s %-5s %-10s %-12s\n",
           "ID", "Name", "Product", "Qty", "Price", "Status");
    printf("---------------------------------------------------------------------\n");

    printf("%-5d %-15s %-15s %-5d %-10.2f %-12s\n",
           o[i].id, o[i].name, o[i].product,
           o[i].qty, o[i].price, o[i].status);
}

/* ---------- UPDATE ---------- */

void update() {
    int id;
    printf("Enter ID to update: ");
    id = getInt();

    int i = find(id);
    if (i == -1) {
        printf("Order not found.\n");
        return;
    }

    while (1) {
        printf("New Name: ");
        scanf(" %[^\n]", o[i].name);
        if (isValidName(o[i].name)) break;
        printf("Invalid name.\n");
    }

    while (1) {
    printf("New Product: ");
    scanf(" %[^\n]", o[i].product);
    if (isValidProductName(o[i].product)) break;
    printf("Invalid product name. Must contain at least one letter.\n");
}

    printf("New Qty: ");
    o[i].qty = getInt();

    printf("New Price: ");
    o[i].price = getFloat();

    while (1) {
        printf("New Status (Pending/Shipped/Delivered/Cancelled): ");
        scanf(" %[^\n]", o[i].status);

        if (isValidStatus(o[i].status)) break;
        printf("Invalid status.\n");
    }

    printf("Order updated.\n");
}

/* ---------- SAVE ---------- */

void save() {
    FILE *f = fopen("orders.txt", "w");
    if (!f) {
        printf("Error saving file.\n");
        return;
    }

    for (int i = 0; i < n; i++)
        fprintf(f, "%d|%s|%s|%d|%f|%s\n",
                o[i].id, o[i].name, o[i].product,
                o[i].qty, o[i].price, o[i].status);

    fclose(f);
    printf("Orders saved.\n");
}

/* ---------- LOAD ---------- */

void load() {
    FILE *f = fopen("orders.txt", "r");

    if (!f) {
        f = fopen("orders.txt", "w");
        if (f) fclose(f);
        printf("File created: orders.txt\n");
        return;
    }

    n = 0;
    while (fscanf(f, "%d|%49[^|]|%49[^|]|%d|%f|%19[^\n]\n",
                  &o[n].id, o[n].name, o[n].product,
                  &o[n].qty, &o[n].price, o[n].status) == 6) {
        n++;
    }

    fclose(f);
    printf("Orders loaded.\n");
}
/* ---------- MAIN ---------- */

int main() {
    int ch;
    load();

    while (1) {
        menu();
        ch = getInt();

        switch (ch) {
            case 1: add(); break;
            case 2: display(); break;
            case 3: search(); break;
            case 4: update(); break;
            case 5: save(); break;
            case 6: load(); break;
            case 7:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}