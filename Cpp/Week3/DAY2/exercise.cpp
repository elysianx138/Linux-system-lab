#include <iostream>
#include <string>

class BankAccount{
private:
    std::string owner_;
    double balance_;
    const int account_id_;
    static int total_account_;

public:
    BankAccount(const std::string& owner, double balance, const int account_id) : owner_(owner), balance_(balance), account_id_(account_id){
        total_account_++;
        std::cout<<"用户#"<<account_id_<<" "<<owner<<": 余额 "<<balance<<std::endl;
    }
    
    BankAccount(const std::string& owner, const int id) : BankAccount(owner, 0, id){

    }
    BankAccount(const BankAccount& other) : BankAccount(other.owner_, other.balance_, other.account_id_+1){
        
    }

    ~BankAccount(){
        total_account_--;
    }

    static void get_total_account(){
        std::cout<<total_account_<<std::endl;
    }

    void deposit(double amount){
        balance_ += amount;
        std::cout<<"存款成功 -> 余额 "<<balance_<<std::endl;
    }

    bool withdraw(double amount){
        if(amount>balance_){
            return false;
        }else{
            balance_ -= amount;
            return true;
        }
    }

    void display() const {
        std::cout<<"账户#"<<account_id_<<" "<<owner_<<": 余额 "<<balance_<<std::endl;
    }

};

int BankAccount::total_account_ = 0;

void func(BankAccount& banckaccount){
    banckaccount.display();
    banckaccount.deposit(1000);
    bool flg = banckaccount.withdraw(100);
    std::cout<<"flg = "<<flg<<std::endl;
    flg = banckaccount.withdraw(2000);
    std::cout<<"flg = "<<flg<<std::endl;
    banckaccount.display();
}

int main(){
    BankAccount* bankaccount = new BankAccount[2]{{"张三", 1000, 1001}, {"李四", 1002}};
    BankAccount bankaccount_3 = bankaccount[1];
    std::cout<<"================"<<std::endl;

    func(bankaccount[0]);
    std::cout<<"================"<<std::endl;
    func(bankaccount[1]);
    std::cout<<"================"<<std::endl;
    func(bankaccount_3);

    BankAccount::get_total_account();

    delete[] bankaccount;

}

