class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        if(size1 > size2)
            return findMedianSortedArrays(nums2, nums1);
        int low = 0 , high = size1, midX, midY;
        double maxleftX, minRightX, maxleftY, minRightY;
        while(low <= high) {
            midX = low + ((high - low) >> 1);
            midY = ((size1 + size2 + 1) >> 1) - midX;
            maxleftX = (midX == 0) ? INT_MIN : nums1[midX - 1];
            minRightX = (midX == size1) ? INT_MAX : nums1[midX];
            maxleftY = (midY == 0) ? INT_MIN : nums2[midY - 1];
            minRightY = (midY == size2) ? INT_MAX : nums2[midY];
            if( maxleftY <= minRightX && maxleftX<= minRightY){
                if((size1 + size2) % 2 == 0)
                    return (max(maxleftY, maxleftX) + min(minRightX, minRightY)) / 2;
                else
                    return max(maxleftY, maxleftX);
            }
            else if(maxleftX > minRightY)
                    high = midX - 1;
            else
                    low = midX + 1;
        }
        return -1.0;
    }
};