#include <iostream>
class A {
public:
    int value_;
};

class B : public A {};
class C : public A {};
class D : public B, public C {};

class E : virtual public A {};
class F : virtual public A {};
class G : public E, public F {};

int main() {
    D d;
    // d.value_ = 42;
    d.B::value_ = 1;
    d.C::value_ = 2;
    // ===============================

    G g;
    g.value_ = 3;
    std::cout<<"d.B::value_ : "<<d.B::value_<<std::endl;
    std::cout<<"d.C::value_ : "<<d.C::value_<<std::endl;
    std::cout<<"g.value_ : "<<g.value_<<std::endl;
}