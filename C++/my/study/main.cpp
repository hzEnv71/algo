#include<bits/stdc++.h>
using namespace std;

signed main(){
    cout<<endl<<"============序列式容器=============="<<endl;
    //序列式容器
    //vector
    vector<int> v1(5,1);
    v1.reserve(10);
    v1={1,2,3,4,5};
    cout<<v1[1]<<endl
        <<v1.at(2)<<endl
        <<v1.front()<<endl
        <<v1.back()<<endl
        <<*(v1.data())<<endl
        <<"迭代器"<<endl
        <<*(v1.begin())<<"  "<<*(v1.end()-1)<<endl
        <<*(v1.rbegin())<<"  "<<*(v1.rend()-1)<<endl
        <<"长度"<<endl
        <<v1.size()<<"  "<<v1.empty()<<"  "<<v1.max_size()<<endl
        <<"容量"<<endl
        <<v1.capacity()<<"  "<<endl
        <<endl;
        v1.resize(7); //改变 vector 的长度，多退少补。补充元素可以由参数指定。
        v1.reserve(10);// 使得 vector 预留一定的内存空间，避免不必要的内存拷贝。
        v1.shrink_to_fit();//使得 vector 的容量与长度一致，多退但不会少。
        //增删改查
        v1.push_back(6);
        v1.pop_back();
        v1.insert(v1.begin()+3,6);
        v1.insert(v1.begin(), 2, 7);//在iterator指向位置前插入n个值为elem的元素
        v1.insert(v1.begin(), v1.begin(), v1.end()); //在v的iterator指向位置前，插入v2的[begin, end)区间的
        v1.erase(v1.begin()+1); //移除iterator指向位置上的元素，迭代器此时指向下一个元素，但是迭代器指向位置不变
        v1.erase(v1.begin(), v1.end()-5); //移除[begin, end)区间的数据，迭代器此时指向下一个元素，但是迭代器指向位置不变
        for(auto v=v1.begin();v<v1.end();v++){
            cout<<*v<<"-";
        }
        cout<<endl;
        reverse(v1.begin(),v1.end()); //将vector中的pos1~pos2的元素逆序存储
        for(auto v=v1.begin();v<v1.end();v++){
            cout<<*v<<"+";
        }
    //array
    array<int,3> a1,a2;
    a1.fill(5);
    a1.swap(a2);
    for(auto i =a1.begin(); i != a1.end(); ++i) cout << *i << " ";
    for(int i =0; i != a2.size(); ++i) cout << a2[i] << " ";
    //deque
    deque<int> d1(10, 1);
    // 与 vector 一致，但是没有 reserve() 和 capacity() 函数
    // push_front() 在头部插入一个元素，常数复杂度。
    // pop_front() 删除头部元素，常数复杂度。
    //list
    list<int> l1(10);
    //forword_ 
    forward_list<int> l2(10);

    cout<<endl<<"============关联式容器=============="<<endl;
    //关联式容器
    //set
    set<int> s1;
    s1.insert(6);
    s1.insert(6);
    auto cnt=s1.erase(6);
    s1.emplace(7);
    s1.erase(s1.begin(),s1.begin());
    s1.clear();
    s1.emplace(2);
    // s1.insert(set{2,4,5,1});
    s1.insert(s1.begin(),6);
    s1.insert(s1.begin(),s1.end());
    // for(auto i=s1.begin();i!=s1.end();i++){
    //     cout<<*i<<" ";
    // }
    for(auto i:s1){
        cout<<i<<" * ";
    }
    cout<<endl;
    cout<<*s1.lower_bound(2)<<endl; // 返回大于等于x的最小的数的迭代器
    cout<<*s1.upper_bound(2)<<endl;//  返回大于x的最小的数的迭代器
    cout<<s1.count(2)<<"-"<<(s1.find(6)!=s1.end())<<"-"<<s1.size()<<"-"<<s1.empty()<<endl;
    cout<<endl;
    //map
    map<int,string,greater<int>> m1;
    m1[3]="kas";
    m1.insert({4,"asssdad"});
    m1.insert(make_pair(6,"sdas"));
    m1.emplace(5,"dfs");
    // for (auto i=m1.begin();i!=m1.end();i++){
    //     // cout<<i->first<<"="<<i->second;
    //     cout<<(*i).first<<"="<<(*i).second<<endl;
    // }
    for(auto i:m1){
        cout<<i.first<<"="<<i.second<<endl;
    }
    // for(auto [k,v]:m1){//c++17
    //     cout<<k<<"="<<v<<endl;
    // }
    auto cmp=m1.key_comp();
    auto i=m1.begin();
    auto last=m1.rbegin()->first;
    do
        cout << i->first << " = " << i->second << endl;
    while (cmp(last,(*i++).first));
    cout<<endl;
    cout<<m1.lower_bound(3)->first<<endl; // 返回大于等于x的最小的数的迭代器
    cout<<m1.upper_bound(3)->first<<endl;//  返回大于x的最小的数的迭代器
    cout<<m1.count(3)<<"-"<<(m1.find(5)!=m1.end())<<"-"<<m1.size()<<"-"<<m1.empty()<<endl;
    cout<<endl;
    cout<<endl<<"-----------------自定义比较方式-------------------"<<endl;
    struct cmp {
        bool operator()(int a, int b) { return a > b; }
    };
    cout<<endl<<"============无序关联式容器=============="<<endl;

    unordered_set<int> us1;
    unordered_map<int,string>  um1;
    cout<<endl<<"============容器适配器=============="<<endl;
    //stack 和priority_queue : top()//queue : front()
    stack<int> st1;  // 使用默认底层容器 deque，数据类型为 TypeName
    stack<int,list<int>> st2;  // 使用 Container 作为底层容器
    stack<int> st3(st1);        // 将 s1 复制一份用于构造 s3

    queue<int> q1;  // 使用默认底层容器 deque，数据类型为 TypeName
    queue<int, vector<int>> q2;  // 使用 Container 作为底层容器
    queue<int> q3(q1);  // 将 s1 复制一份用于构造 q3

    priority_queue<int> pq1;             // 数据类型为 TypeName
    priority_queue<int, vector<int>> pq2;  // 使用 Container 作为底层容器
    priority_queue<int,vector<int>,greater<int>> pq3;// 使用 Container 作为底层容器，使用 Compare 作为比较类型

    // 从 C++11 开始，如果使用 lambda 函数自定义 Compare
    // 则需要将其作为构造函数的参数代入，如：
    auto comp = [](const pair<int, int> &l, const pair<int, int> &r) {
        return l.second < r.second;
    };
    priority_queue<pair<int, int>, vector<pair<int, int> >,decltype(comp)> pq4(comp);//decltype 说明符可以推断表达式的类型。

    cout<<endl<<"============STL算法=============="<<endl;
    std::vector<int> nums{3, 4, 2, 8, 15, 267};
 
    auto print = [](const int& n) { std::cout << " " << n; };
    for_each(nums.cbegin(), nums.cend(), print);
}