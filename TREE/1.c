#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Abstract Product Structure
typedef struct Product
{
    char name[50];
    double price;
    double (*calculateDiscount)(struct Product *);
    void (*displayDetails)(struct Product *);
} Product;

// Electronics Structure inheriting from Product
typedef struct
{
    Product base; // Base Product structure
} Electronics;

double electronicsDiscount(Product *p)
{
    return p->price * 0.9; // 10% discount
}

void displayElectronicsDetails(Product *p)
{
    printf("Electronics: %s, Price: $%.2f, Discounted Price: $%.2f\n", p->name, p->price, p->calculateDiscount(p));
}

Product *createElectronics(const char *name, double price)
{
    Electronics *e = (Electronics *)malloc(sizeof(Electronics));
    strcpy(e->base.name, name);
    e->base.price = price;
    e->base.calculateDiscount = electronicsDiscount;
    e->base.displayDetails = displayElectronicsDetails;
    return (Product *)e;
}

// Clothing Structure inheriting from Product
typedef struct
{
    Product base;
} Clothing;

double clothingDiscount(Product *p)
{
    return p->price * 0.8; // 20% discount
}

void displayClothingDetails(Product *p)
{
    printf("Clothing: %s, Price: $%.2f, Discounted Price: $%.2f\n", p->name, p->price, p->calculateDiscount(p));
}

Product *createClothing(const char *name, double price)
{
    Clothing *c = (Clothing *)malloc(sizeof(Clothing));
    strcpy(c->base.name, name);
    c->base.price = price;
    c->base.calculateDiscount = clothingDiscount;
    c->base.displayDetails = displayClothingDetails;
    return (Product *)c;
}

// User Structure
typedef struct User
{
    char name[50];
    char email[50];
    void (*login)(struct User *);
} User;

// Customer Structure inheriting from User
typedef struct
{
    User base;
} Customer;

void customerLogin(User *u)
{
    printf("Customer %s logged in with email: %s\n", u->name, u->email);
}

User *createCustomer(const char *name, const char *email)
{
    Customer *c = (Customer *)malloc(sizeof(Customer));
    strcpy(c->base.name, name);
    strcpy(c->base.email, email);
    c->base.login = customerLogin;
    return (User *)c;
}

// Admin Structure inheriting from User
typedef struct
{
    User base;
} Admin;

void adminLogin(User *u)
{
    printf("Admin %s logged in with email: %s\n", u->name, u->email);
}

User *createAdmin(const char *name, const char *email)
{
    Admin *a = (Admin *)malloc(sizeof(Admin));
    strcpy(a->base.name, name);
    strcpy(a->base.email, email);
    a->base.login = adminLogin;
    return (User *)a;
}

int main()
{
    // Creating Products
    Product *p1 = createElectronics("Laptop", 1000);
    Product *p2 = createClothing("T-Shirt", 50);

    // Display product details
    p1->displayDetails(p1);
    p2->displayDetails(p2);

    // Creating Users
    User *customer = createCustomer("John Doe", "john@example.com");
    User *admin = createAdmin("Admin User", "admin@example.com");

    // Users logging in
    customer->login(customer);
    admin->login(admin);

    // Cleaning up
    free(p1);
    free(p2);
    free(customer);
    free(admin);

    return 0;
}