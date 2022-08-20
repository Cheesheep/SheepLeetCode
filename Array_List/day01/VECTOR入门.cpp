#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>

using namespace std;

void Print(vector<int> arr){ //这里的i是指针
    for (vector<int>::iterator i = arr.begin(); i != arr.end(); i++)
    {
        cout << *i << endl;
    }
}

void test01(){
    //基本操作
    vector<int> arr,b;
    arr.push_back(20);
    arr.push_back(44);
    arr.push_back(25);
    arr.push_back(1);

    //赋值操作
    vector<int> a2 = arr;

    vector<int>a3;
    a3.assign(arr.begin(),arr.end());

//容量和大小
    cout << arr.capacity()<<endl;
    arr.resize(6,666);///重新指定大小
    cout << arr.capacity()<<endl;
    cout << arr.size() << endl;
    cout << a2.capacity() << endl;

//插入和删除

    //尾部删除
    arr.pop_back();

    //插入
    arr.insert(arr.begin(),233);
    arr.insert(arr.begin(),2,100);

    //删除
    arr.erase(arr.begin());
    a3.erase(a3.begin(),a3.end());//清空

//存取元素 [] 或者 at（）都可以访问元素
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr.at(i)<<endl;
    }
    a2.front();//第一个元素
    a2.back();
    
//空间交换
    vector<int> a4(500,10);
    a4.resize(5);
    cout << a4.capacity()<<endl;//这个时候容量会很大，浪费空间
    cout << a4.size()<<endl;
    //节省空间
    vector<int>(a4).swap(a4); //利用swap函数与新构造的容器互换数据

//预留空间
    a4.reserve(100);//预留100个数据空间给容器
}

int main(){
    test01();
}