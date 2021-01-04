#include <bits/stdc++.h>
using namespace std;
int maxP(vector<int> &v, int n)
{
    int currMin = 1;
    int currMax = 1;
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        if (v[i] > 0)
        {
            currMax *= v[i];
            currMin = min(1, v[i] * currMin);
        }
        if (v[i] < 0)
        {
            int temp = currMax;
            currMax = max(1, v[i] * currMin);
            currMin = v[i] * temp;
        }
        if (v[i] == 0)
        {
            currMax = 1;
            currMin = 1;
        }
        ans = max(currMax, ans);
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << maxP(v, n);
}