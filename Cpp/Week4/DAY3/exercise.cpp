#include <iostream>
#include <string>

class BankAccount {
    std::string owner_;
    double balance_;
    friend class BankManager;
public:
    BankAccount(const std::string& owner, double balance) : owner_(owner), balance_(balance) {
        std::cout<<"账户: "<<owner_<<"创建成功! 卡上余额: "<<balance_<<std::endl;
    }

    friend std::ostream& operator<<(std::ostream& os, const BankAccount& account) {
        os << account.owner_ <<" : "<< account.balance_<<std::endl;
        return os;
    }
};

class BankManager {
public:
    static bool transfer(BankAccount& from, BankAccount& to, double amount) {
        if(amount<0){
            return false;
        }
        if(from.balance_ >= amount){
            from.balance_ -= amount;
            to.balance_ += amount;
            std::cout<<"转账成功! 当前余额: "<<from.balance_<<std::endl;
            return true;
        } else {
            std::cout<<"转账失败! 余额不足!"<<std::endl;
            return false;
        }
    }
};


int main() {
    BankAccount a("Alice", 1000);
    BankAccount b("Bob", 500);
    
    std::cout << a << "\n";  // Alice: 1000
    std::cout << b << "\n";  // Bob: 500
    
    BankManager::transfer(a, b, 300);
    
    std::cout << a << "\n";  // Alice: 700
    std::cout << b << "\n";  // Bob: 800
}