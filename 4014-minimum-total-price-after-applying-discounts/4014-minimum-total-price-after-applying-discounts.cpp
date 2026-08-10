class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.rbegin(), prices.rend());
        sort(discounts.rbegin(), discounts.rend());

        int n = prices.size();
        int m = discounts.size();

        double fsum = 0;

        for(int i = 0; i < n; i++) {
            if(i < m) {
                fsum += prices[i] * (100.0 - discounts[i]) / 100.0;
            }
            else {
                fsum += prices[i];
            }
        }

        return fsum;
    }
};