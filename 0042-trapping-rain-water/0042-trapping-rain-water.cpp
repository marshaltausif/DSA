class Solution {
public:
    int trap(vector<int>& height) {
        int n =height.size();
   int  leftMax[n];
      int  rightMax[n];

    leftMax[0] = height[0];
    rightMax[n-1] = height[n-1];
    for (int i = 1; i < n; i++) {
        leftMax[i] = max(leftMax[i-1], height[i]);
    }

    for (int i = n-2; i >= 0; i--) {
        rightMax[i] = max(rightMax[i+1], height[i]);
    }

    int water_trapped = 0;

    for (int i = 0; i < n; i++) {
        int curr_water = min(leftMax[i], rightMax[i]) - height[i];
        if (curr_water > 0) {
            water_trapped += curr_water;
        }
    }

        return water_trapped;
    }
};