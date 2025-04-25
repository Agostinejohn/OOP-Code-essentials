#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <algorithm>

// --- Program 1: Add Two Numbers ---
void addTwoNumbers() {
    int num1, num2;
    std::cout << "Enter two numbers: ";
    std::cin >> num1 >> num2;
    std::cout << "Sum: " << num1 + num2 << std::endl;
}

// --- Program 2: String Reversal ---
void reverseString() {
    std::string str;
    std::cout << "Enter a string: ";
    std::cin >> str;
    std::reverse(str.begin(), str.end());
    std::cout << "Reversed string: " << str << std::endl;
}

// --- Program 3: Calculator ---
void calculator() {
    double num1, num2;
    char op;
    std::cout << "Enter first number: ";
    std::cin >> num1;
    std::cout << "Enter operator (+, -, *, /, %): ";
    std::cin >> op;
    std::cout << "Enter second number: ";
    std::cin >> num2;

    switch(op) {
        case '+': std::cout << "Result: " << num1 + num2 << std::endl; break;
        case '-': std::cout << "Result: " << num1 - num2 << std::endl; break;
        case '*': std::cout << "Result: " << num1 * num2 << std::endl; break;
        case '/': std::cout << "Result: " << num1 / num2 << std::endl; break;
        case '%': std::cout << "Result: " << (int)num1 % (int)num2 << std::endl; break;
        default: std::cout << "Invalid operator!" << std::endl;
    }
}

// --- Program 4: Fibonacci Series ---
void fibonacciSeries() {
    int terms;
    std::cout << "Enter number of terms: ";
    std::cin >> terms;
    int first = 0, second = 1;
    std::cout << "Fibonacci Series: ";
    for (int i = 1; i <= terms; ++i) {
        std::cout << first << " ";
        int next = first + second;
        first = second;
        second = next;
    }
    std::cout << std::endl;
}

// --- Program 5: Guessing Game ---
void guessingGame() {
    std::srand(std::time(0));
    int number = std::rand() % 100 + 1;
    int guess;
    std::cout << "Guess the number (1-100): ";
    do {
        std::cin >> guess;
        if (guess > number) {
            std::cout << "Lower! Try again: ";
        } else if (guess < number) {
            std::cout << "Higher! Try again: ";
        } else {
            std::cout << "Correct! The number was " << number << std::endl;
        }
    } while (guess != number);
}

// --- Program 6: File Copy ---
void fileCopy() {
    std::string sourceFile, destinationFile;
    std::cout << "Enter source file name: ";
    std::cin >> sourceFile;
    std::cout << "Enter destination file name: ";
    std::cin >> destinationFile;

    std::ifstream source(sourceFile, std::ios::binary);
    std::ofstream destination(destinationFile, std::ios::binary);
    
    if (source && destination) {
        destination << source.rdbuf();
        std::cout << "File copied successfully!" << std::endl;
    } else {
        std::cout << "Error opening file(s)." << std::endl;
    }
}

// --- Program 7: Palindrome Checker ---
void palindromeChecker() {
    std::string str;
    std::cout << "Enter a word or phrase: ";
    std::cin >> str;
    
    std::string reversed = str;
    std::reverse(reversed.begin(), reversed.end());
    
    if (str == reversed) {
        std::cout << str << " is a palindrome." << std::endl;
    } else {
        std::cout << str << " is not a palindrome." << std::endl;
    }
}

// --- Program 8: Grade Calculator ---
void gradeCalculator() {
    int subjects;
    std::cout << "Enter number of subjects: ";
    std::cin >> subjects;
    double total = 0, grade;
    for (int i = 0; i < subjects; ++i) {
        std::cout << "Enter grade for subject " << i + 1 << ": ";
        std::cin >> grade;
        total += grade;
    }
    std::cout << "Average grade: " << total / subjects << std::endl;
}

// --- Program 9: Array Sorting ---
void arraySorting() {
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;
    int arr[n];
    std::cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    int choice;
    std::cout << "Choose sorting order (1 for Ascending, 2 for Descending): ";
    std::cin >> choice;
    
    if (choice == 1) {
        std::sort(arr, arr + n);
        std::cout << "Sorted Array in Ascending Order: ";
    } else if (choice == 2) {
        std::sort(arr, arr + n, std::greater<int>());
        std::cout << "Sorted Array in Descending Order: ";
    } else {
        std::cout << "Invalid choice!" << std::endl;
        return;
    }
    
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// --- Program 10: Rock-Paper-Scissors ---
void rockPaperScissors() {
    std::srand(std::time(0));
    std::string userChoice, computerChoice;
    std::cout << "Enter rock, paper, or scissors: ";
    std::cin >> userChoice;

    std::string choices[] = {"rock", "paper", "scissors"};
    computerChoice = choices[std::rand() % 3];

    std::cout << "Computer chose: " << computerChoice << std::endl;

    if (userChoice == computerChoice) {
        std::cout << "It's a tie!" << std::endl;
    } else if ((userChoice == "rock" && computerChoice == "scissors") ||
               (userChoice == "paper" && computerChoice == "rock") ||
               (userChoice == "scissors" && computerChoice == "paper")) {
        std::cout << "You win!" << std::endl;
    } else {
        std::cout << "Computer wins!" << std::endl;
    }
}

// --- Program 11: Inventory Management System ---
void inventoryManagementSystem() {
    struct Item {
        int id;
        std::string name;
        int quantity;
    };

    std::vector<Item> inventory;
    int choice;
    
    do {
        std::cout << "1. Add Item\n2. Display Items\n3. Search by ID\n4. Search by Name\n5. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                Item newItem;
                std::cout << "Enter Item ID: ";
                std::cin >> newItem.id;
                std::cout << "Enter Item Name: ";
                std::cin >> newItem.name;
                std::cout << "Enter Quantity: ";
                std::cin >> newItem.quantity;
                inventory.push_back(newItem);
                std::cout << "Item added successfully!\n";
                break;
            }
            case 2:
                for (const auto& item : inventory) {
                    std::cout << "ID: " << item.id << ", Name: " << item.name << ", Quantity: " << item.quantity << std::endl;
                }
                break;
            case 3: {
                int id;
                std::cout << "Enter Item ID to search: ";
                std::cin >> id;
                bool found = false;
                for (const auto& item : inventory) {
                    if (item.id == id) {
                        std::cout << "Found - ID: " << item.id << ", Name: " << item.name << ", Quantity: " << item.quantity << std::endl;
                        found = true;
                        break;
                    }
                }
                if (!found) std::cout << "Item not found.\n";
                break;
            }
            case 4: {
                std::string name;
                std::cout << "Enter Item Name to search: ";
                std::cin >> name;
                bool found = false;
                for (const auto& item : inventory) {
                    if (item.name == name) {
                        std::cout << "Found - ID: " << item.id << ", Name: " << item.name << ", Quantity: " << item.quantity << std::endl;
                        found = true;
                        break;
                    }
                }
                if (!found) std::cout << "Item not found.\n";
                break;
            }
            case 5:
                std::cout << "Exiting inventory system...\n";
                break;
            default:
                std::cout << "Invalid choice!\n";
        }
    } while (choice != 5);
}

int main() {
    int choice;
    
    do {
        std::cout << "\nChoose a program to run:\n";
        std::cout << "1. Add Two Numbers\n";
        std::cout << "2. Reverse String\n";
        std::cout << "3. Calculator\n";
        std::cout << "4. Fibonacci Series\n";
        std::cout << "5. Guessing Game\n";
        std::cout << "6. File Copy\n";
        std::cout << "7. Palindrome Checker\n";
        std::cout << "8. Grade Calculator\n";
        std::cout << "9. Array Sorting\n";
        std::cout << "10. Rock-Paper-Scissors\n";
        std::cout << "11. Inventory Management System\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: addTwoNumbers(); break;
            case 2: reverseString(); break;
            case 3: calculator(); break;
            case 4: fibonacciSeries(); break;
            case 5: guessingGame(); break;
            case 6: fileCopy(); break;
            case 7: palindromeChecker(); break;
            case 8: gradeCalculator(); break;
            case 9: arraySorting(); break;
            case 10: rockPaperScissors(); break;
            case 11: inventoryManagementSystem(); break;
            case 0: std::cout << "Goodbye!\n"; break;
            default: std::cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
