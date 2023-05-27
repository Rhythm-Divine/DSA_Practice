#include <bits/stdc++.h>
#include <cmath>
typedef long long int lli;
#define plli pair<long long int, long long int>
#define newl "\n"
#define YES cout << "YES" << newl;
#define NO cout << "NO" << newl;
#define debug(v)          \
    for (auto i : v)      \
    {                     \
        cout << i << " "; \
    }                     \
    cout << newl;
#define debugmp(v)                                  \
    for (auto i : v)                                \
    {                                               \
        cout << i.first << " " << i.second << newl; \
    }
#define all(a) a.begin(), a.end()
#define mod 1000000007
#define f(i, c, d) for (lli i = c; i < d; i++)
#define fd(i, c, d) for (lli i = c; i >= d; i--)
using namespace std;
#define N 1000001
// vector<lli> primes;
// void SIEVE(){vector<lli> p(N, 1);for (lli i = 2; i * i <= N; i++){if (p[i] == 1){for (lli j = i * 2; j <= N; j += i)p[j] = 0;}}f(i, 2, N + 1){if (p[i] == 1)primes.push_back(i);}}//
// bool cmp(plli a, plli b){if (a.first > b.first)return true;else if (a.first == b.first){if (a.second > b.second)return true;}return false;}//
// lli power(lli a, lli b){lli res = 1;while (b > 0){if (b % 2 == 1)res = ((res % mod) * (a % mod)) % mod, b--;else{b = b / 2, a = (a % mod) * (a % mod) % mod;}}return res;}//
// bool sortbysec(pair<lli, lli> &a, pair<lli, lli> &b) { return (a.second < b.second); }//
// lli ceill(lli a, lli b){return (a + b - 1) / b;}


void solve()
{
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    lli t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}