class Solution {
public:
      double largestTriangleArea(vector<vector<int>>& p) {
        double res = 0;
        for (auto &a : p)
            for (auto &b : p)
                for (auto &c : p)
            res = max(res, 0.5 * abs(a[0] * b[1] + b[0] * c[1] + c[0] * a[1] - b[0] * a[1] - c[0] * b[1] - a[0] * c[1]));
        return res;
    }
};