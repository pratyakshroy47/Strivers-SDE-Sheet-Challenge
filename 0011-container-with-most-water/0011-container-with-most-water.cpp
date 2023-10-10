class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1, maxiWater = 0;
        while(left < right) {
            maxiWater = max(maxiWater, min(height[left], height[right]) * (right - left));
            if(height[left] < height[right]) {
                left += 1;
            }
            else {
                right -= 1;
            }
        }

        return maxiWater;
    }
};