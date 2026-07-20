void by_ref(int& x){
    x = 100;
}

void by_ptr(int* x){
    *x = 100;
}

int main(){
    int a = 42;
    by_ref(a);
    by_ptr(&a);
    return 0;
}