#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void Print(vector<int> arr){ //这里的i是指针
    for (vector<int>::iterator i = arr.begin(); i != arr.end(); i++)
    {
        cout << *i << ' ';
    }
    cout << endl;
}
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int len = nums.size();
        vector<int> _nums(nums);
        //使用双指针，因为数组本身是有序的
        //但是可以保证最大值肯定在两边，因此不需要排序
        for(int right = len - 1,left = 0,i=len - 1;left <= right;){
            if(abs(nums[left]) < abs(nums[right])){
                _nums[i--] = nums[right] * nums[right];
                right--;
            }
            else{
                _nums[i--] = nums[left] * nums[left];
                left++;
            }
        }
        return _nums;
    }
    vector<int> sortedSquares02(vector<int>& nums) {
        //暴力解
        int len = nums.size();
        for (int i = 0; i < len; i++)
        {
            /* code */
            nums[i] *= nums[i];
        }
        sort(nums.begin(),nums.end());        
        return nums;
    }
};

int main(){
    vector<int> nums = {-8,-4,-2,1,3,7};
    Solution S;
    nums = S.sortedSquares(nums);
    Print(nums);
}