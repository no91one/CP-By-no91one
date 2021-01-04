#include <bits/stdc++.h>
using namespace std;
int kadane(vector<int> &v, int n)
{
    int curr = 0;
    int ans = INT_MIN;
    for (int i = 0; i < n; ++i)
    {
        curr = max(v[i], curr + v[i]);
        ans = max(ans, curr);
    }
    return ans;
}
int kCon(vector<int> &v, int n, int k)
{
    int ans = 0;
    int kSum = kadane(v, n);
    if (k == 1)
    {
        ans = kSum;
    }
    else
    {
        int currPre = 0, currSuff = 0, maxPre = INT_MIN, maxSuff = INT_MIN;

        for (int i = 0; i < n; ++i)
        {
            currPre += v[i];
            maxPre = max(maxPre, currPre);
        }
        int tSum = currPre;
        for (int i = n - 1; i >= 0; --i)
        {
            currSuff += v[i];
            maxSuff = max(maxSuff, currSuff);
        }

        if (tSum < 0)
        {
            ans = maxSuff + maxPre;
        }
        else
        {
            ans = (maxSuff + maxPre + (k - 2) * tSum);
        }
    }
    return ans;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        cout << kCon(v, n, k) << endl;
    }
}