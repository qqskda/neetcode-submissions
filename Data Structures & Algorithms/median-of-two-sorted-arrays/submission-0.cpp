class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // 1. Both vectors are sorted.

        // Q. What is median? The numbers that are in the middle.

        // Regardless, the total dataset is nums1.size() + nums2.size();

        // We simply iterate each vector by compare and order.
        // Takes the median index

        int i = 0;
        int j = 0;

        int total_size = nums1.size() + nums2.size();
        int median_index = total_size / 2;
        // If total size is even => we need to take median_index and median_index-1
        // If total size is odd => just take median_index.

        double prev = 0; // median_index-1 save
        double curr = 0;
        while(i+j <= median_index)
        {
            prev = curr;
            if (i < nums1.size() && j < nums2.size())
            {
                // compare
                int num1 = nums1[i]; int num2 = nums2[j];

                if (num1 > num2)
                {
                    curr = nums2[j];
                    ++j;
                }
                else
                {
                    curr = nums1[i];
                    ++i;
                }
            }
            else if (i < nums1.size())
            {
                // j reached the end
                curr = nums1[i];
                ++i;
            }
            else
            {
                // i reached the end
                curr = nums2[j];
                ++j;
            }
        }

        double ret = (total_size % 2 == 0) ? (prev+curr)/2 : curr;
        return ret;
    }
};
