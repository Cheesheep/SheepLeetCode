#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int length = nums.size();
        vector<int>::iterator head = nums.begin();
        for(int i = 0;i < nums.size();i++){
            if(nums[i] == val){
                nums.erase(head);
                length--;
            }else
                head++;    
        }
        return length;
    }
};

