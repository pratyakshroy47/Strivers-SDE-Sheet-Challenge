// formula to find how many hourglasses can be form in 2D matrix: 
// (r-2)(c-2)

class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int Max = 0;
        int sum = 0;

        for(int i=0; i<=m-3; i++){
            for(int j=0; j<=n-3; j++){
                sum=0;
                for(int c=j; c<j+3; c++){    //for adding 3 values from column to make hourglass
                    sum += grid[i][c];       //add 1st row to make hourglass
                    sum += grid[i+2][c];     //add 3rd row to make hourglass
                }
                sum += grid[i+1][j+1];       //add middle of 3x3 grid to make hourglass
                Max = max(Max, sum);         //find maximum value
            }
        }
        return Max;
        
    }
};