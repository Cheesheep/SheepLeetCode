#include<iostream>
#include<vector>

using namespace std;

class Solution { //方法1.使用库函数
public:
    int removeElement(vector<int>& nums, int val) {
        int length = nums.size();
        for(auto it = nums.begin();it != nums.end();){
            if(*it == val){
                nums.erase(it);
                length--;
            }else
                it++;    
        }
        return length;
    }
    //方法2 ：快慢指针
    int removeElement02(vector<int>& nums, int val) {
        int length = nums.size();
        int slow = 0;
        for(int fast = 0;fast < nums.size();fast++){
            if(nums[fast] != val)//当快指针不等于val时
            {
                nums[slow] = nums[fast];//慢指针先赋值
                slow++;//然后再往后移一位，快指针也会移动，在for循环里面移动
            }
        }
        return length;
    }
};

