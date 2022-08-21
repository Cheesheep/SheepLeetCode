#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int right = nums.size() - 1;
        int left = 0;
        while(left <= right){ //注意，等于也是有效状态
            int middle = (right + left) / 2;
            if(nums[middle] > target){
                right = middle-1; //记住这里要减一，而不是等于middle，不然会一直循环下去
            }
            else if (nums[middle] < target){
                left = middle+1;
            }
            else
                return middle;
        }
        return -1;
    }
};

int main(){

}