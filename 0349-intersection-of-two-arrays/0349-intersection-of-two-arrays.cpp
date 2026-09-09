class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        // Sort nums1
        sort(nums1.begin(), nums1.end());

        // Remove duplicates from nums1
        for (int i = 0; i < nums1.size() - 1; ) {
            if (nums1[i] == nums1[i + 1]) {
                nums1.erase(nums1.begin() + i);
            }
            else {
                i++;
            }
        }

        // Sort nums2
        sort(nums2.begin(), nums2.end());

        // Remove duplicates from nums2
        for (int i = 0; i < nums2.size() - 1; ) {
            if (nums2[i] == nums2[i + 1]) {
                nums2.erase(nums2.begin() + i);
            }
            else {
                i++;
            }
        }

        // Find intersection
        vector<int> result;

        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                if (nums1[i] == nums2[j]) {
                    result.push_back(nums1[i]);
                    break;
                }
            }
        }

        return result;
    }
};
