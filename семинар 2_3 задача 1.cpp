#include <iostream>
#include <string>
#include <vector>
#include <memory>

class BankCell {
private:
    bool isOpen = false;
public:
    void open() {
        if (!isOpen) {
            isOpen = true;
            std::cout << "Bank cell is opened" << std::endl;
        }
    }

    void close() {
        if (isOpen) {
            isOpen = false;
            std::cout << "Bank cell is closed" << std::endl;
        }
    }
};

class Human {
private:
    std::string name;
    std::shared_ptr<BankCell> bankCell;
public:
    Human(std::string name, std::shared_ptr<BankCell> bankCell)
        : name(name), bankCell(bankCell) {}

    void openBankCell() {
        bankCell->open();
    }

    void closeBankCell() {
        bankCell->close();
    }

    std::string getName() const {
        return name;
    }
};

int main() {
    std::shared_ptr<BankCell> bankCell = std::make_shared<BankCell>();
    std::vector<std::shared_ptr<Human>> humans;

    std::shared_ptr<Human> john = std::make_shared<Human>("John", bankCell);
    humans.push_back(john);

    std::shared_ptr<Human> alice = std::make_shared<Human>("Alice", bankCell);
    humans.push_back(alice);

    john->openBankCell(); // Bank cell is opened

    for (const auto& human : humans) {
        std::cout << human->getName() << " is a co-owner of the bank cell" << std::endl;
    }

    alice->closeBankCell(); // Bank cell is closed

    return 0;
}