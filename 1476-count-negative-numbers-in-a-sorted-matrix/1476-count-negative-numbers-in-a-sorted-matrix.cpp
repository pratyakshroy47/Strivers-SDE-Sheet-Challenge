class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int low = 0, high = 0, count = 0, sum = 0;
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        int i = 0, j = n-1; //start from top right
        while(i<m && j>=0){
            if(grid[i][j]<0){    //if grid[i][j] -ve then all the below also -ve as it is sorted
                ans += m-i;
                j--; //go to previous column then
            }
            else{ 
                // and if positive go downwards
                i++;
            }
        }
        return ans;
    }
};