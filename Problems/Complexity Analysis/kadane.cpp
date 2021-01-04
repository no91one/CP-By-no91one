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
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << kadane(v, n);
}