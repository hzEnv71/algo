#include <iostream>
#define IOS ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
using ll = long long;
const int N = 5e5 + 10;

template<typename T1,typename T2,typename T>
T sum(T1 num1,T2 num2){
	return num1 + num2;
}
int main(){
	cout<<sum<int,float,double>(1,3.0);//输出
	return 0;
}