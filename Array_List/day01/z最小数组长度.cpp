#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result = INT32_MAX; //保证是最小值
        int sumLen = 0;
        int sum;
        for(int i = 0 ; i < nums.size();i++){
            sum = 0;
            for(int j = i;j < nums.size();j++){
                sum += nums[j];
                if(sum >= target){
                    sumLen = j - i + 1;
                    if(result > sumLen)
                        result = sumLen;
                    break;
                }
            }
        }
        if(result == INT32_MAX)
            return 0;
        else
            return result;
    }
    int minSubArrayLen02(int target, vector<int>& nums) {
        int result = INT32_MAX; //保证是最小值
        int sumLen = 0;
        int sum = 0;
        for(int i = 0,j = 0 ; i < nums.size();i++){
            sum += nums[i];
            while(sum >= target){//当大于等于目标值时开始缩短窗口
                sum -= nums[j];//缩短窗口
                sumLen = i - j + 1; //计算长度          
                result = result < sumLen ? result : sumLen;//取最小长度
                j++;
            }
        }
        if(result == INT32_MAX)
            return 0;
        else
            return result;

};

int main(){
    Solution S;
    vector<int> arr = {1,2,3,4,5};
    int target = 11;
    cout << S.minSubArrayLen(target,arr) <<endl;
}