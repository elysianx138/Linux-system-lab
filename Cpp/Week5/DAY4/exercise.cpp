#include <iostream>
#include <string>
class Flyable {
    std::string fly_speed_;
public:
    Flyable(const std::string& speed) : fly_speed_(speed) {};
    virtual void fly() const {
        std::cout<< fly_speed_ <<std::endl;
    }
};
class Swimmable {
    std::string swim_seed_;
public:
    Swimmable(const std::string& speed) : swim_seed_(speed) {};
    virtual void swim() const {
        std::cout<< swim_seed_ <<std::endl;
    }
};

class Amphibian : public Flyable, public Swimmable {
    std::string name_;
public:
    Amphibian(const std::string& name, const std::string& f, const std::string& s) : name_(name), Flyable(f), Swimmable(s) {};
    void display() const {
        std::cout<<name_;
        fly();
        std::cout<<"以及";
        swim();
    }
};
int main() {
    Amphibian a("哇哇", "正在急速飞行", "然后游泳快溺死了");
    a.display();
}
// class A {
// public:
//     int value_ = 0;
//     void print() const { std::cout << "A\n"; }
// };

// class B : public A {};
// class C : public A {};
// class D : public B, public C {};

// 1. D d; d.value_ = 42; 能编译吗？为什么？
// 不能编译,在编译器,编译器遇到两个value_,不知道更改哪一个,因此报错

// 2. 怎么正确给 D 里的 A 赋值？（写出两种写法）
// (1) d.B::value_, d.C::value_
// (2) class B : virtual public A {}, class C : virtual public A {}, d.value_

// 3. sizeof(D) 大约是多少？（假设 int 4 字节，指针 8 字节）为什么？
//  8吧? D的内存中有两个int value_ 4+4

// 4. d.print() 能编译吗？为什么？
// 不能吧,和第一题一样

// ==========================================================

// 把 B、C 改成虚继承，然后回答： 5. d.value_ = 42; 现在能编译吗？ 
// 可以了,D储存B,Cvbptr和A的数据!;B,Cvbptr偏向位移距离A多少

// 6. 虚继承后 sizeof(D) 变化了吗？为什么？ 
// 有! D内存内有一个int value_, 以及B,C的vbptr;4+8+8 = 20?

// 7. 如果 A 有构造函数 A(int x)，B、C、D 的构造函数应该怎么写？谁负责初始化 A？
// D负责初始化, D() : A(30), B(), C() {}
