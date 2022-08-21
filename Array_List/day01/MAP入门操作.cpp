#include<iostream>
#include<map>
#include<vector>
#include<random>

using namespace std;

void PrintMap(map<int,int> &m){
    for (map<int,int>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "key = " << (*it).first << "value = "<<(*it).second << endl;
    }
    cout << endl;
    
}
void test01(){
    map<int,int> m; //默认构造,maps是有序的
    
    for (int i = 1; i < 7; i++)
    {
        m.insert(pair<int,int>(i,i * 10)); //插入
    }
    map<int,int>m2(m); 
    m.insert(pair<int,int>(-1,100));
    //PrintMap(m);
    PrintMap(m2);
    
    cout <<"MAP SIZE :"<< m.size() << endl;


//插入和删除
    //插入
    m2.insert(pair<int,int>(11,110));//第一种
    m2.insert(make_pair(12,120));//第二种
    m.insert(map<int,int>::value_type(13,130));//第三种
    PrintMap(m2);
    //删除
    m2.erase(12); //按照key删除，但是无法按照value删除
    m2.erase(m.begin()++);
    PrintMap(m2);

//查找
    if (m2.end() !=  m2.find(11)) //返回的是迭代器
        cout << "Find Success" <<endl;
    else
        cout << "Failed" << endl;
    cout << "Count : "<<m2.count(10) << endl; //返回键的个数，对于map来说只有0和1

//改变排序方式
    

}

int main(){
    test01();
    
}
