#include<iostream>
#pragma GCC optimize (3) // O(3)
using namespace std;
__attribute__((noinline))
long long test(long long n) {
    register long long fact = 1, num = n + 1;
    for (register int i = 1;i < num;i+=4) {
        fact *= i;
        fact *= i + 1;
        fact *= i + 2;
        fact *= i + 3;
    }
    
    return fact;
}
int main() {
    cout<<test(1000000000);
    return 0;
}