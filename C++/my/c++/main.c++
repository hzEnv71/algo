#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
using ll = long long;
const int N = 1e5 + 10;
// #define START

#ifdef START
struct  person {
    int year;
    int age;
    string name;
};
int** f(int** c) { return c; }
int& add1(int& r) {
    r += 1;
    int res = r;
    return res;
}
int main() {
    IOS;
    cout << "Start" << "\n";
    int arr[3];
    static int arr2[4];
    cout << "arr[0]=" << arr[0] << "\narr2[0]=" << arr2[0] << "\n";
    //字符串长度为8个字节,最后一位是'\0'。
    char s[10] = "yuanrui";
    cout << "s[7] is \0?:" << (s[7] == '\0') << "\n";
    cout << "s.length=" << sizeof(s) / sizeof(s[0]) << "\n";
    //也可以不用定义字符串长度，如：
    char s2[] = "yuanrui";//yuanrui\0
    cout << "s2[7]=" << s2[7] << "\n";
    cout << "s2.length=" << sizeof(s2) / sizeof(s2[0]) << "|" << end(s2) - begin(s2) << "\n";
    int* arr3 = new int[2];//delete []arr1;
    int* arr4 = new int[ 3 ] { 1, 2 };//delete []arr2
    // delete[] arr3,arr3=nullptr;
    // delete []arr4,arr4=nullptr;
    cout << "arr3[0]=" << arr3[0] << "\narr4[1]=" << arr4[1] << "\n";
    int** tmp = new int* [3];//3行2列
    for (int i = 0;i < 3;i++) {
        tmp[i] = new int[ 2 ] {i, i + 1};
    }
    cout << tmp[0][0] << tmp[2][1] << f(tmp)[2][1] << *(*(f(tmp + 2)) + 1) << *(f(tmp)[2] + 1);
    int(*t)[2] = new int[3][2]{ {1,2},{2,3},{3,4} };
    cout << "\n=========\n" << t[0][1] << (*(t + 2))[1] << *(*(t + 2) + 1) << "\n=========\n";
    int a = 12;
    int& b = add1(a);
    int& c = add1(a);

    cout << a << "   " << b << " " << c << endl;//14   -858993460 -858993460
    person p1{ 2003,12,"sdf" };
    person* p2 = &p1;
    cout << p2->name << (*p2).name;
    // int year, month, day;
    // cin >> year, cin.ignore(), cin >> month, cin.ignore(), cin >> day;
    // cout << "year=" << year << ",month=" << month << ",day=" << day;
    cout << hex << 10 << oct << 10 << fixed << 2.0 << "\n";
    setbase(16);
    cout << 10;
    system("pause");
    return 0;
}

#else 
/* class Base
{
public:
    Base(int, double);
    ~Base();
private:
    int aa;
    double dd;
};
Base::Base(int a, double d) :aa(a), dd(d)
{
    cout << "Base Class 构造函数!!!" << endl;
}
Base::~Base()
{
    cout << "Base Class 析构函数!!!" << endl;
}
class Person:public Base
{
public:
    Person(int,double,string);
    ~Person();
private:
    string name;
};
Person::Person(int a,double d,string str):Base(a,d),name(str)
{
    cout << "Person Class 构造函数!!!" << endl;
}
Person::~Person()
{
    cout << "Person Class 析构函数!!!" << endl;
}
int main()
{
    cout << "创建Person对象..." << endl;
    Person *p = new Person(1,2,"yar");
    cout << "删除Person对象...." << endl;
    delete p;
    system("pause");
    return 0;
} */


/* class A {//抽象类：包含纯虚函数的类称为抽象类。由于纯虚函数不能被调用，所以不能利用抽象类创建对象，又称抽象基类。
public:
    void f();
    virtual void show() = 0;//在基类中不执行具体的操作，只为派生类提供统一结构的虚函数，将其声明为虚函数。
};
class B :public A {
public:
    void show() {
        cout << "B_show()";
    }
};
int main() {
    B b;
    b.show();
    system("pause");
    return 0;
}
 */

 /*
 class Vector3 {
 public:
     Vector3();
     Vector3(double x, double y, double z);
 public:
     Vector3 operator+(const Vector3& A)const;
     Vector3 operator++();//++a
     Vector3 operator++(int);//a++
     friend Vector3 operator-(const Vector3& v1, const Vector3& v2);//双目运算符作为友元函数时需要制定两个参数。
     friend Vector3 operator--(Vector3& v);//--a
     friend Vector3 operator--(Vector3& v, int);//a--
     friend ostream& operator<<(ostream& output, const Vector3& v);
     friend istream& operator>>(istream& input, Vector3& v);
     operator double();//类型转换函数只能作为成员函数，不能作为友元函数
     void display()const;
 private:
     double m_x;
     double m_y;
     double m_z;
 };
 Vector3::Vector3() :m_x(0.0), m_y(0.0), m_z(0.0) {}
 Vector3::Vector3(double x, double y, double z) : m_x(x), m_y(y), m_z(z) {}
 //运算符重载
 Vector3 Vector3::operator+(const Vector3& A)const {
     Vector3 B;
     B.m_x = this->m_x + A.m_x;
     B.m_y = this->m_y + A.m_y;
     B.m_z = this->m_z + A.m_z;
     return B;
 }
 Vector3 Vector3::operator++() {
     (this->m_x)++;
     (*this).m_y++;
     this->m_z++;
     return *this;
 }
 Vector3 Vector3::operator++(int) {
     this->m_x++;
     this->m_y++;
     this->m_z++;
     return *this;
 }
 Vector3 operator-(const Vector3& v1, const Vector3& v2) {
     return Vector3(v1.m_x - v2.m_x, v1.m_y - v2.m_y, v1.m_z - v2.m_z);
 }
 Vector3 operator--(Vector3& v) {
     v.m_x--;
     v.m_y--;
     v.m_z--;
     return v;
 }
 Vector3 operator--(Vector3& v, int) {
     v.m_x--;
     v.m_y--;
     v.m_z--;
     return v;
 }
 ostream& operator<<(ostream& output, const Vector3& v) {
     output << "x:" << v.m_x << ",y:" << v.m_y << ",z:" << v.m_z<<"\n";
     return output;
 }

 istream& operator>>(istream& input, Vector3& v) {
     input >> v.m_x >> v.m_y >> v.m_z;
     return input;
 }
 Vector3::operator double() { return this->m_x + this->m_y + this->m_z; }
 void  Vector3::display()const {
     cout << "(" << m_x << "," << m_y << "," << m_z << ")" << endl;
 }
 int main() {
     Vector3 v1(2, 2, 2), v2(2, 3, 4);
     v1 = v1 + v2;
     v1.display();

     ++v1, --v2;
     v1++, v2--;
     v1.display();
     v2.display();
     Vector3 v3 = v1 + v2;
     Vector3 v4 = v1 - v2;
     v3.display();
     v4.display();
     Vector3 v5;
     cin >> v5;
     cout << v3 << v4 << v5;
     double d1 = 3;
     double d2 = v5;
     cout << d1 <<"\n"<< d2;

 }
  */

  /*
  int main() {
      ////文本文件io
      // ifstream in("src.txt", ios::in);
      // if (!in) return 0;
      // ofstream out("tar.txt", ios::out);
      // if (!out) {
      //     in.close();
      //     return 0;
      // }
      // int x, arr[100];
      // for (int i = 0;in >> x;i++) {
      //     arr[i] = x;
      //     out << arr[i];
      // }
      // in.close();
      // out.close();
      ////二进制文件读写
      // ofstream out1("o.bin", ios::out | ios::binary);
      // int x;
      // while (cin >> x) {
      //     out1.write((char*)&x, sizeof(x));
      // }
      // out1.flush();
      // ifstream in1("o.bin", ios::in | ios::binary);
      // if (!in1) return 0;
      // while (in1.read((char*)&x, sizeof(x))) {
      //     cout << x;
      // }
      // in1.close();
      // out1.close();
      ////文件流类的 put 和 get 成员函数
      ifstream in2("a.txt", ios::binary | ios::in);
      if (!in2) return 0;
      ofstream out2("b.txt", ios::binary | ios::out);
      if (!out2) {
          in2.close();
          return 0;
      }
      char c;
      while (in2.get(c)) {//读
          out2.put(c);//写
      }
      in2.seekg(0, ios::beg);
      in2.seekg(1, ios::cur);
      in2.seekg(0, ios::end);
      int in2_length = in2.tellg();
      out2.seekp(0, ios::end);
      int out2_length = out2.tellp();
      cout << "a.txt长度: " << in2_length << ",b.txt长度: " << out2_length<<"\n";
      out2.close();
      in2.close();
      return 0;
  }
   */

   //不同的是typename 还有另外一个作用为：使用嵌套依赖类型(nested depended name)
template<typename T1, typename T2>
class Point {
public:
    Point() {}
    Point(T1 x, T2 y) :x(x), y(y) {}
    void f(T1 x, T2 y) const;//成员函数后加const，声明该函数内部不会改变成员变量的值
public:
    T1 x;
    T2 y;
};
template<typename T1, typename T2>
void  Point<T1, T2>::f(T1 x, T2 y)const {
    cout << "x=" << x << "  y=" << y << "\n";
}
int main() {
    Point<int, int> p1;
    Point<string, int> p2("asd", 23);
    p1.f(23, 12);
    p2.f(p2.x, p2.y);
    return 0;
}



#endif
