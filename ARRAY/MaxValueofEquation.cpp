#include <bits/stdc++.h>
using namespace std;
int findMaxValueOfEquation(vector<vector<int>> &points, int k)
{
    priority_queue<pair<int, int>> p;
    // 1st value is xi-yi and 2nd is xi
    int ans = INT_MIN;
    for (int i = 0; i < points.size(); i++)
    {
        // if xi-xj>k
        while (!p.empty() && (points[i][0] - p.top().second) > k)
            p.pop();
        if (!p.empty())
        {
            ans = max(ans, points[i][0] + points[i][1] + p.top().first);
        }
        p.push({points[i][1] - points[i][0], points[i][0]});
    }
    return ans;
}

int main()
{
    vector<vector<int>> points = {{1, 3}, {2, 0}, {5, 10}, {6, -10}};
    int k = 1;
    int result = findMaxValueOfEquation(points, k);
    cout << result;
    return 0;
}