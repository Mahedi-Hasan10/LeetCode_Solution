/*
     Author : Mahedi-Hasan10
     Date : 19-05-2023
     Topic: https://leetcode.com/problems/perfect-squares/
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

vector<int> dp(N);

int PerfectSquare(int n)
{
    if (n <= 0)
        return 0;
    int ans = INT_MAX;
    if (dp[n] != -1)
        return dp[n];

    for (int i = 1; i * i <= n; i++)
    {
        int sqnum = i * i;
        int count = 1 + PerfectSquare(n - sqnum);
        ans = min(ans, count);
    }
    return dp[n] = ans;
}
int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        dp[i] = -1;
    }
    cout << PerfectSquare(n) << endl;
    return 0;
}
