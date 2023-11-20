#include<iostream>
// #include<time.h>
// #pragma G++ optimize(2)
// #pragma GCC optimize(2)
// #pragma GCC optimize("O2")
// #pragma G++ optimize("O2")
using namespace std;
__attribute__((noinline))
long long test(long long n) {
    long long fact = 1, num = n + 1;
    for (int i = 1;i < num;i++) {
        fact *= i;
    }
    
    return fact;
}
int main() {
    time_t s, e;
    time(&s);
    cout << test(1000000000);
    time(&e);
    cout << fixed << double(e - s);
    return 0;
}