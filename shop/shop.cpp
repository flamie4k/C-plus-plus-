#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Product {
private:
    const static int G_MAX = 10;
    const static int F_MAX = 7;

    int selector_switch_mark;
    int item_int;
    int total_price;  // Added total_price variable
    string groceries[G_MAX] = {
        "Chicken", "Rice", "Milk", "Curd", "Ice-Cream", "Sugar", "Pepper", "Spinach", "Salt", "Olive Oil"
    };
    string flour[F_MAX] = {
        "Rice Flour", "Chickpea Flour", "White Flour", "Cake Flour", "Rye Flour", "Semolina Flour", "Wheat Flour"
    };
    int g_price[G_MAX] = { 420, 180, 110, 130, 380, 95, 190, 110, 50, 400 };
    int f_price[F_MAX] = { 200, 240, 190, 300, 320, 550, 160 };

public:
    Product() : total_price(0) {}  // Initialize total_price to 0

    void menu() {
        cout << "\nOur list is as follows: \n" << endl;
        cout << "Groceries: \n";
        for (int i = 0; i < G_MAX; i++) {
            cout << i + 1 << "\t" << groceries[i] << " = Rs." << g_price[i] << endl;
        }
        cout << "\nFlours: \n";
        for (int i = 0; i < F_MAX; i++) {
            cout << i + 1 << "\t" << flour[i] << " = Rs." << f_price[i] << endl;
        }
    }

    void selector() {
        cout << "\nPress [1] and [2] for Grocery menu and Flour menu, respectively:  \n";
        cin >> selector_switch_mark;
        if (selector_switch_mark == 1) {
            displayMenu(groceries, G_MAX);
        } else if (selector_switch_mark == 2) {
            displayMenu(flour, F_MAX);
        } else {
            error();
        }
    }

    void displayMenu(const string* items, int maxItems) {
        cout << "Press the corresponding number to select the item:\n";
        for (int i = 0; i < maxItems; i++) {
            cout << i + 1 << "\t" << items[i] << " \n";
        }
        cout << "Enter the number here: ";
        cin >> item_int;
        item_count();
    }

    void error() {
        cout << "\nInvalid option or no item found!!!\n";
    }

    void item_count() {
        if ((selector_switch_mark == 1 && item_int >= 1 && item_int <= G_MAX) || (selector_switch_mark == 2 && item_int >= 1 && item_int <= F_MAX)) {
            pick_item(item_int);
        } else {
            error();
        }
    }

    void pick_item(int item) {
        while (item != 0) {
            if (item < 1 || (selector_switch_mark == 1 && item > G_MAX) || (selector_switch_mark == 2 && item > F_MAX)) {
                cout << "Invalid item number. Please select a valid item or enter 0 to finish shopping." << endl;
                continue;
            }

            item--;  // Adjust the index to match the array
            int quantity = 0;

            cout << "\nPicked " << (selector_switch_mark == 1 ? groceries[item] : flour[item]) << endl;
            cout << "Enter the amount of " << (selector_switch_mark == 1 ? groceries[item] : flour[item]) << " that you want to purchase: ";
            cin >> quantity;

            if (quantity < 0) {
                cout << "Invalid quantity. Please enter a positive quantity." << endl;
                continue;
            }

            int item_price = (selector_switch_mark == 1) ? g_price[item] : f_price[item];
            int item_total_price = item_price * quantity;
            total_price += item_total_price;

            cout << "You've purchased " << quantity << " " << (selector_switch_mark == 1 ? groceries[item] : flour[item]) << endl;
            cout << "Total cost for this item is Rs." << item_total_price << endl;
            cout << "Overall Total Bill so far: Rs." << total_price << endl;

            cout << "Enter the number of the item you want to purchase (or 0 to finish shopping): ";
            cin >> item;
        }

        cout << "Overall Total Bill is Rs." << total_price << endl;
    }

    int getTotalPrice() {
        return total_price;
    }
};

class product_in_file : public Product {
public:
    void updateCreditTab(const string& customerName, int total_price) {
        ofstream vipFile("VIP.txt", ios::app);
        if (vipFile.is_open()) {
            vipFile << customerName << " " << total_price << endl;
            vipFile.close();
            cout << "VIP credit tab updated successfully." << endl;
        } else {
            cout << "Failed to update VIP's credit tab." << endl;
        }
    }

    void updateRegularPayments(const string& customerName, int total_price) {
        ofstream regularPaymentsFile("RegularPayments.txt", ios::app);
        if (regularPaymentsFile.is_open()) {
            regularPaymentsFile << customerName << " " << total_price << endl;
            regularPaymentsFile.close();
            cout << "Regular customer payment updated successfully." << endl;
        } else {
            cout << "Failed to update regular customer's payment." << endl;
        }
    }
};

int main() {
    system("cls");
    Product p;
    p.menu();
    p.selector();

    vector<string> vipCustomers = {"Pratik Adhikari", "Lutput Adhikari", "Sailesh Kafle", "Joanna Dannis", "Michiking Sumire"};

    string customerName;
    cout << "Enter customer name: ";
    cin.ignore(); // Clear the newline character left in the input buffer
    getline(cin, customerName);

    product_in_file fileHandler;
    if (find(vipCustomers.begin(), vipCustomers.end(), customerName) != vipCustomers.end()) {
        fileHandler.updateCreditTab(customerName, p.getTotalPrice());
    } else {
        // For non-VIP customers, handle their payment
        fileHandler.updateRegularPayments(customerName, p.getTotalPrice());
    }

    return 0;
}
