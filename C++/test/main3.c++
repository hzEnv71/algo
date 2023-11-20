#include<iostream>
using namespace std;
__attribute__((noinline))
long long test(long long n) {
    register long  long fact0 = 1,fact1 = 1,fact2 = 1,fact3 = 1, num = n + 1;
    for (register int  i = 1;i < num;i+=4) {
        fact0 *= i;
        fact1 *= i + 1;
        fact2 *= i + 2;
        fact3 *= i + 3;
    }
    
    return fact0*fact1*fact2*fact3;
}
int main() {
    cout<<test(1000000000);
    return 0;
}