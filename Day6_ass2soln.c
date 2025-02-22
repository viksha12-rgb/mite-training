#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
    char name[50];
    int price;
} Product;

// Function to compare products for sorting (Ascending order of price)
int compare(const void *a, const void *b) {
    return ((Product *)a)->price - ((Product *)b)->price;
}

// Linear search function to find product by name (fix for binary search issue)
int search_product(Product products[], int n, char *name) {
    for (int i = 0; i < n; i++) {
        if (strcmp(products[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to display products
void display_products(Product products[], int n) {
    printf("\nProduct List:\n");
    for (int i = 0; i < n; i++) {
        printf("Name: %s, Price: %d\n", products[i].name, products[i].price);
    }
}

int main() {
    int n;
    printf("Enter number of products: ");
    scanf("%d", &n);

    if (n > MAX_PRODUCTS || n <= 0) {
        printf("Invalid number of products!\n");
        return 1;
    }

    Product products[MAX_PRODUCTS];
    for (int i = 0; i < n; i++) {
        printf("Enter Name and Price for product %d: ", i + 1);
        scanf("%s %d", products[i].name, &products[i].price);
    }

    // Sorting products by price (Ascending)
    qsort(products, n, sizeof(Product), compare);
   
    printf("\nSorted Product List (by Price):\n");
    display_products(products, n);
   
    // Display cheapest and most expensive products
    printf("\nCheapest Product: %s (Price: %d)\n", products[0].name, products[0].price);
    printf("Most Expensive Product: %s (Price: %d)\n", products[n-1].name, products[n-1].price);
   
    // Search for a product by name
    char search_name[50];
    printf("\nEnter Product Name to search: ");
    scanf("%s", search_name);
   
    int index = search_product(products, n, search_name);
    if (index != -1) {
        printf("Product Found: %s, Price: %d\n", products[index].name, products[index].price);
    } else {
        printf("Product '%s' not found.\n", search_name);
    }
   
    return 0;
}
