#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;
using namespace std;
#define ll long long
#define hii cout << "hii" << endl
#define int ll
#define endl '\n'
#define all(s) s.begin(), s.end()
 
template <class T> ostream& operator << (ostream &os, const vector<T> &v) { for (T i : v) os << i << ' '; return os; }
template <class T> ostream& operator << (ostream &os, const set<T> &v) { for (T i : v) os << i << ' '; return os; }
template <class T, class S> ostream& operator << (ostream &os, const pair<T, S> &v) { os << v.first << ' ' << v.second; return os; }
template <class T, class S> ostream& operator << (ostream &os, const unordered_map<T, S> &v) { for (auto i : v) os << '(' << i.first << "=>" << i.second << ')' << ' '; return os; } 
 
 
#ifndef ONLINE_JUDGE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <class Arg1> void __f(const char* name, Arg1&& arg1) { cerr << name << " : " << arg1 << endl; }
    template <class Arg1, class... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args) {
        const char* sep = strchr(names + 1, ',');
        cerr.write(names, sep - names) << " : " << arg1 << "  ";
        __f(sep + 1, args...);
    }
#else
#define trace(...) 0
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define _CRT_SECURE_NO_WARNINGS
#endif // ifndef ONLINE_JUDGE
 
 
const int N = 1e6 + 5;
const int MAXN = 3e5 + 5;
const int M = 3e5;
const int mod = 1e9 + 7;
const int MOD = 1e9 + 7;
const int INF = 1e15;
const int LG = 21;
 
int arr[N];
int brr[N];
int n, k;
string input;

int pref[N];

int get(int l, int r)
{
	if(r < l)
	{
		return 0;
	}
	if(l <= 0)
	{
		return pref[r];
	}
	else
	{
		return pref[r] - pref[l - 1];
	}
}

int DP[N][2];

int f(int idx, bool start)
{
	if(idx >= n)
	{
		return 0;
	}
	int & ret = DP[idx][start];
	if(~ret)
	{
		return ret;
	}
	if(start)
	{
		if(input[idx] == '0')
		{
			int ans1 = 1 + get(idx + 1, min(idx + k - 1, n - 1)) + f(idx + k, 1);
			int ans2 = get(idx, n - 1);
			return ret = min(ans1, ans2);
		}
		else
		{
			int ans1 = get(idx + 1, min(idx + k - 1, n - 1)) + f(idx + k, 1);
			int ans2 = get(idx, n - 1);
			return ret = min(ans1, ans2);
		}
	}
	else
	{
		if(input[idx] == '0')
		{
			int ans1 = 1 + get(idx + 1, min(idx + k - 1, n - 1)) + f(idx + k, 1);
			int ans2 = f(idx + 1, 0);
			return ret = min(ans1, ans2);
		}
		else
		{
			int ans1 = 1 + f(idx + 1, 0);
			int ans2 = get(idx + 1, min(idx + k - 1, n - 1)) + f(idx + k, 1);
			if(idx == 0)
			{
				trace(ans1, ans2);
			}
			if(idx == 1)
			{
				trace(idx, ans1, ans2);
			}
			return ret = min(ans1, ans2);
		}
	}
}

void solve() 
{
	//cin >> n >> k ;
	k = 1 ;
	cin >> input;
	 n = input.size() ;
	for(int i = 0; i < n; i++)
	{
		pref[i] = (input[i] == '1');
		if(i)
		{
			pref[i] += pref[i - 1];
		}
		DP[i][0] = -1;
		DP[i][1] = -1;
	}
	cout << f(0, 0) << endl;
}
 
 
int32_t main() 
{	
    ios_base:: sync_with_stdio(false);
	cin.tie(NULL);
	int t = 1;
	cin >> t;
	while(t--)solve();
	return 0;
}
