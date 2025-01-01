#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Product Class
class Product {
public:
    int productID;
    string productName;
    double price;
    int quantity;

    // Constructor
    Product(int id, const string& name, double p, int qty)
        : productID(id), productName(name), price(p), quantity(qty) {}

    // Method to display product details
    void displayDetails() const {
        cout << "Product ID: " << productID << ", Name: " << productName
             << ", Price: " << price << ", Quantity: " << quantity << endl;
    }

    // Method to check availability
    bool checkAvailability() const {
        return quantity > 0;
    }
};

// Order Class
class Order {
public:
    int orderID;
    string orderDate;
    double totalAmount;
    string status;
    vector<Product> products;

    // Constructor
    Order(int id, const string& date) : orderID(id), orderDate(date), totalAmount(0), status("Pending") {}

    // Method to add products to the order
    void addProducts(const Product& product) {
        products.push_back(product);
        totalAmount += product.price;
    }

    // Method to calculate total amount
    double calculateTotal() const {
        return totalAmount;
    }

    // Method to update order status
    void updateStatus(const string& newStatus) {
        status = newStatus;
    }

    // Method to display order details
    void displayOrder() const {
        cout << "Order ID: " << orderID << ", Date: " << orderDate << ", Total Amount: " << totalAmount << ", Status: " << status << endl;
        for (const auto& product : products) {
            product.displayDetails();
        }
    }
};

// ShoppingCart Class
class ShoppingCart {
public:
    int cartID;
    vector<Product> products;
    double totalPrice;

    // Constructor
    ShoppingCart(int id) : cartID(id), totalPrice(0) {}

    // Method to add product to cart
    void addProducts(const Product& product) {
        products.push_back(product);
        totalPrice += product.price;
    }

    // Method to remove product from cart
    void removeProducts(int productID) {
        for (auto it = products.begin(); it != products.end(); ++it) {
            if (it->productID == productID) {
                totalPrice -= it->price;
                products.erase(it);
                break;
            }
        }
    }

    // Method to view cart details
    void viewCartDetails() const {
        cout << "Shopping Cart ID: " << cartID << ", Total Price: " << totalPrice << endl;
        for (const auto& product : products) {
            product.displayDetails();
        }
    }
};

// Payment Class
class Payment {
public:
    int paymentID;
    int orderID;
    string paymentMethod;
    string paymentStatus;

    // Constructor
    Payment(int id, int order, const string& method) : paymentID(id), orderID(order), paymentMethod(method), paymentStatus("Pending") {}

    // Method to process payment
    void processPayment() {
        paymentStatus = "Completed";
    }

    // Method to update payment status
    void updateStatus(const string& newStatus) {
        paymentStatus = newStatus;
    }

    // Method to display payment details
    void displayPayment() const {
        cout << "Payment ID: " << paymentID << ", Order ID: " << orderID << ", Method: " << paymentMethod << ", Status: " << paymentStatus << endl;
    }
};

// ShippingInfo Class
class ShippingInfo {
public:
    int shippingID;
    int orderID;
    string address;
    string estimatedDelivery;
    string shippingStatus;

    // Constructor
    ShippingInfo(int id, int order, const string& addr, const string& delivery)
        : shippingID(id), orderID(order), address(addr), estimatedDelivery(delivery), shippingStatus("Pending") {}

    // Method to update shipping status
    void updateStatus(const string& newStatus) {
        shippingStatus = newStatus;
    }

    // Method to display shipping details
    void displayShipping() const {
        cout << "Shipping ID: " << shippingID << ", Order ID: " << orderID << ", Address: " << address
             << ", Estimated Delivery: " << estimatedDelivery << ", Shipping Status: " << shippingStatus << endl;
    }
};

// Customer Class
class Customer {
public:
    int custID;
    string custName;
    string email;
    string address;
    string phone;
    ShoppingCart cart;
    vector<Order> orders;

    // Constructor
    Customer(int id, const string& name, const string& email, const string& addr, const string& phone, int cartID)
        : custID(id), custName(name), email(email), address(addr), phone(phone), cart(cartID) {}

    // Method to add an order
    void addOrder(const Order& order) {
        orders.push_back(order);
    }

    // Method to view orders
    void viewOrder() const {
        cout << "Customer: " << custName << "'s Orders:" << endl;
        for (const auto& order : orders) {
            order.displayOrder();
        }
    }

    // Method to view product list in cart
    void viewProductList() const {
        cart.viewCartDetails();
    }
};

// Main function to demonstrate the functionality
int main() {
    // Creating products
    Product product1(1, "Laptop", 1000.00, 10);
    Product product2(2, "Smartphone", 600.00, 20);
    Product product3(3, "Headphones", 100.00, 50);

    // Creating customer
    Customer customer1(101, "Alice", "alice@example.com", "123 Main St", "123-456-7890", 201);

    // Adding products to the shopping cart
    customer1.cart.addProducts(product1);
    customer1.cart.addProducts(product2);

    // Viewing the cart
    customer1.viewProductList();

    // Creating an order
    Order order1(301, "2024-11-19");
    order1.addProducts(product1);
    order1.addProducts(product2);

    // Adding order to customer
    customer1.addOrder(order1);

    // Processing payment
    Payment payment1(401, 301, "Credit Card");
    payment1.processPayment();

    // Creating shipping info
    ShippingInfo shipping1(501, 301, "123 Main St", "2024-11-25");

    // Viewing order, payment, and shipping details
    customer1.viewOrder();
    payment1.displayPayment();
    shipping1.displayShipping();

    return 0;
}
