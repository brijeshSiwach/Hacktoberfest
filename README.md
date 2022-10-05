#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> u(n + 2, vector<int>(n + 2));
        for (int b = 2; b <= n; ++b) {
            int k0 = b - 1;
            deque<pair<int, int>> v;
            for (int a = b - 1; a; --a) {
                while (u[a][k0 - 1] > u[k0 + 1][b]) {
                    if (!v.empty() && v.front().second == k0) v.pop_front();
                    --k0;
                }
                int vn = a + u[a + 1][b];
                while (!v.empty() && vn < v.back().first) v.pop_back();
                v.emplace_back(vn, a);
                int u1 = u[a][k0] + k0 + 1;
                int u2 = v.front().first;
                u[a][b] = u1 < u2 ? u1 : u2;
            }
        }
        return u[1][n];
    }
};
