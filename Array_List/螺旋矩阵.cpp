#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<int> line(n,0);
        vector<vector<int>> Matrix(n,line);
        int count = 1,row,col;
        row = 0;col = 0;
        while(count != n*n){
            while(col < n - 1 && !Matrix[row][col+1]){ //向右
                Matrix[row][col++] = count++;
            }
            while(row < n - 1 && !Matrix[row+1][col]){ //向下
                Matrix[row++][col] = count++;
            }
            while(col > 0 && !Matrix[row][col-1]){ //向左
                Matrix[row][col--] = count++;
            }
            while(row > 0 && !Matrix[row - 1][col]){ //向上
                Matrix[row--][col] = count++;
            }
        }
        Matrix[row][col] = count;
        return Matrix;
    }
};


int main(){
    Solution S;
    int n = 4;
    vector<vector<int>> M = S.generateMatrix(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << M[i][j] << ' ';
        }
        cout << endl;
        
    }
    
}