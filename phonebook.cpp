#include <iostream>
#include <map>
#include <string>

class PhoneBook {
private:
    std::map<std::string, std::string> contacts;

public:
    void addContact(const std::string& name, const std::string& phoneNumber) {
        contacts[name] = phoneNumber;
        std::cout << "Contact added: " << name << " - " << phoneNumber << std::endl;
    }

    void searchContact(const std::string& name) {
        if (contacts.find(name) != contacts.end()) {
            std::cout << "Contact found: " << name << " - " << contacts[name] << std::endl;
        } else {
            std::cout << "Contact not found for name: " << name << std::endl;
        }
    }

    void displayAllContacts() {
        if (contacts.empty()) {
            std::cout << "Phone book is empty." << std::endl;
            return;
        }

        std::cout << "Phone Book Contacts:" << std::endl;
        for (const auto& entry : contacts) {
            std::cout << entry.first << " - " << entry.second << std::endl;
        }
    }
};

int main() {
    PhoneBook phoneBook;
    int choice;

    do {
        std::cout << "\nPhone Book Management System\n";
        std::cout << "1. Add Contact\n";
        std::cout << "2. Search Contact\n";
        std::cout << "3. Display All Contacts\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string name, phoneNumber;
                std::cout << "Enter name: ";
                std::cin >> name;
                std::cout << "Enter phone number: ";
                std::cin >> phoneNumber;
                phoneBook.addContact(name, phoneNumber);
                break;
            }
            case 2: {
                std::string name;
                std::cout << "Enter name to search: ";
                std::cin >> name;
                phoneBook.searchContact(name);
                break;
            }
            case 3:
                phoneBook.displayAllContacts();
                break;
            case 4:
                std::cout << "Exiting the program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please enter a valid option.\n";
                break;
        }
    } while (choice != 4);

    return 0;
}
