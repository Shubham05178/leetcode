class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        if(size1 > size2)
          return  findMedianSortedArrays(nums2, nums1);
        int low = 0, high = size1, mid1, mid2, leftmax1,leftmax2, rightmin1, rightmin2;
        while(low <= high) {
            mid1 = low + ((high - low) >> 1);
            mid2 = ((size1 + size2 + 1) >> 1) - mid1;
            leftmax1 = (mid1 == 0 ) ? INT_MIN : nums1[mid1 - 1];
            leftmax2 = (mid2 == 0 ) ? INT_MIN : nums2[mid2 - 1];
            rightmin1 = (mid1 == size1) ? INT_MAX : nums1[mid1];
            rightmin2 = (mid2 == size2) ? INT_MAX : nums2[mid2];
            if(leftmax1 <= rightmin2 && leftmax2 <= rightmin1){
                if((size1 + size2) % 2 == 0) 
                    return (max(leftmax1, leftmax2) + min(rightmin1, rightmin2))/2.0;
                return max(leftmax1, leftmax2);
            }
            else if( leftmax1 > rightmin2)
                high = mid1 -1;
            else 
                low = mid1 + 1;
        }
        return 0.0;
    }
};