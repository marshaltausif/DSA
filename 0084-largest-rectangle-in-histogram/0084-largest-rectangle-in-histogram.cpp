class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();

        vector<int> nsl(n);
        vector<int> nsr(n);

        stack<int> s;
        stack<int> r;

        // NSL
        nsl[0] = -1;
        s.push(0);

        for (int i = 1; i < n; i++) {

            int curr = heights[i];

            while (!s.empty() && curr <= heights[s.top()]) {
                s.pop();
            }

            if (s.empty()) {
                nsl[i] = -1;
            }
            else {
                nsl[i] = s.top();
            }

            s.push(i);
        }

        // NSR
        nsr[n - 1] = n;
        r.push(n - 1);

        for (int i = n - 2; i >= 0; i--) {

            int curr = heights[i];

            while (!r.empty() && curr <= heights[r.top()]) {
                r.pop();
            }

            if (r.empty()) {
                nsr[i] = n;
            }
            else {
                nsr[i] = r.top();
            }

            r.push(i);
        }

        // Area
        int maxA = 0;

        for (int i = 0; i < n; i++) {

            int h = heights[i];

            int w = nsr[i] - nsl[i] - 1;

            int area = h * w;

            maxA = max(maxA, area);
        }

        return maxA;
    }
};