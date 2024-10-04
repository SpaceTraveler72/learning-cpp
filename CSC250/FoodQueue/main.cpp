// Using a queue to take orders for a resteraunt
// Sawyer Theis
// 2/12/24
// CSC 250
// Project 3

// My compiler doesn't compile unless I include the cpp file
// I know it's not supposed to do this but alternative is inconvienent
#include "OrderQueue.cpp"
#include <iostream>
#include <iomanip>
using namespace std;

struct Order {
    string name;  // may include spaces
    int burgers;
    int cheeseburgers;
    int fries;

};

enum MenuOption {ADDORDER, REMOVEORDER, PRINTQUEUE, PRINTREVERSE};

// Makes a menu that contionlously loops taking user input until the user exits
void menu(OrderQueue<Order>&);
// Adds a new order to the passed in order queue based on user input
void addOrder(OrderQueue<Order>&);
// Removes the oldest order and prints out their order and the cost
void removeOrder(OrderQueue<Order>&);
// prints all the pending orders from oldest order to newest
void printQueue(const OrderQueue<Order>);
// prints all the pending orders from newest order to oldest using the recusive function of similar name
void printReverse(const OrderQueue<Order>);
// recusivly prints the whole queue passed in from newest order to oldest
void printReverseRecursion(OrderQueue<Order>&);


int main() {
    OrderQueue<Order> orders(5);

    menu(orders);
}

// Makes a menu that contionlously loops taking user input until the user exits
void menu(OrderQueue<Order>& orders) {
    while (true) {
        cout << "Enter 0 to add a new order" << endl;
        cout << "Enter 1 to remove an order" << endl;
        cout << "Enter 2 to print the queue" << endl;
        cout << "Enter 3 to print the queue in reverse" << endl;
        cout << "Enter any other number to exit" << endl;

        int input;
        cin >> input;

        // Calls a method based on the users input
        switch ((MenuOption)input) {
        case ADDORDER:
            addOrder(orders);
            break;
        case REMOVEORDER:
            removeOrder(orders);
            break;
        case PRINTQUEUE:
            printQueue(orders);
            break;
        case PRINTREVERSE:
            printReverse(orders);
            break;
        default:
            return;
        }
    }
}

// Adds a new order to the passed in order queue based on user input
void addOrder(OrderQueue<Order>& orders) {
    if (orders.isFull()) {
        cout << "Queue is Full!";
        return;
    }
    Order newOrder;

    cout << "Enter name: ";
    getline(cin >> ws, newOrder.name);
    cout << "Enter number of burgers: ";
    cin >> newOrder.burgers;
    cout << "Enter number of cheseburgers: ";
    cin >> newOrder.cheeseburgers;
    cout << "Enter number of fries: ";
    cin >> newOrder.fries;

    orders.enqueue(newOrder);
}

// Removes the oldest order and prints out their order and the cost
void removeOrder(OrderQueue<Order>& orders) {
    if (orders.isEmpty()) {
        cout << "Queue is Empty!";
        return;
    }
    Order served;

    orders.dequeue(served);

    cout << "Name of Customer: " << served.name << "  Burgers: " << served.burgers << 
        "  Cheeseburgers: " << served.cheeseburgers << "  Fries: " << served.fries << endl;

    // calculates cost of the order and prints them out
    double subtotal = 0;
    subtotal+=served.burgers * 7;
    subtotal+=served.cheeseburgers * 8;
    subtotal+=served.fries * 2.5;

    cout << "Subtotal: " << fixed << setprecision(2) << subtotal << endl;
    cout << "With Tax: " << subtotal * 1.07 << endl;
    
    cout << "Discount: ";
    if (subtotal >= 25) cout << "Yes";
    else cout << "No";
    cout << endl;
    double discout = (subtotal >= 25) ? .9 : 1;

    cout << "Total Price: " << fixed << setprecision(2) << subtotal * 1.07 * discout << endl;
}

// prints all the pending orders from oldest order to newest
void printQueue(const OrderQueue<Order> orders) {
    OrderQueue<Order> temp(orders);

    // prints headers
    cout << left <<setw(20) << "Name"
        << setw(15) << "Burgers" << setw(15) << "Cheeseburgers" << setw(15) << "Fries" << endl;

    // prints orders
    while (!temp.isEmpty()) {
        Order order;
        temp.dequeue(order);
        cout << left << setw(20) << order.name << right
            << setw(15) << order.burgers << setw(15) << order.cheeseburgers << setw(15) << order.fries << endl;
    }
}

// prints all the pending orders from newest order to oldest using the recusive function of similar name
void printReverse(const OrderQueue<Order> orders) {
    OrderQueue<Order> temp(orders);

    // prints headers
    cout << left << setw(20) << "Name"
        << setw(15) << "Burgers" << setw(15) << "Cheeseburgers" << setw(15) << "Fries" << endl;

    printReverseRecursion(temp);
}

// recusivly prints the whole queue passed in from newest order to oldest
void printReverseRecursion(OrderQueue<Order>& orders) {
    if (orders.isEmpty()) return;

    Order order;
    orders.dequeue(order);

    printReverseRecursion(orders);

    cout << left << setw(20) << order.name << right
        << setw(15) << order.burgers << setw(15) << order.cheeseburgers << setw(15) << order.fries << endl;
}
