class Solution {
public:
    void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
        // Create a temporary array to store the merged values
        int nums3[n + m];

        // Initialize variables for iterating through nums1, nums2, and nums3
        int left = 0;   // Index for nums2
        int right = 0;  // Index for nums1
        int index = 0;  // Index for nums3

        // Merge the two arrays by comparing elements
        while (left < n && right < m) {
            if (nums1[left] <= nums2[right]) {
                nums3[index] = nums1[left];
                left++;
                index++;
            } else {
                nums3[index] = nums2[right];
                index++;
                right++;
            }
        }

        // Add remaining elements from nums1 (if any) to nums3
        while (left < n) {
            nums3[index++] = nums1[left++];
        }

        // Add remaining elements from nums2 (if any) to nums3
        while (right < m) {
            nums3[index++] = nums2[right++];
        }

        // Copy the merged values from nums3 back to nums1 and nums2
        for (int i = 0; i < n + m; i++) {
            
                nums1[i] = nums3[i];
            
        }
    }
};