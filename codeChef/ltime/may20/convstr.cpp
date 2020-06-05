#include <bits/stdc++.h>
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
const int N = 2e5 + 5;
const int MAXN = 1e4 + 5;
const int M = 3e5;
const int mod = 1e9 + 7;
const int MOD = 1e9 + 7;
const int INF = 1e15;
const int LG = 21;
int arr[N];
void solve()
{
		int n ;
		cin >> n ;
		int a[n] , b[n] ;
		for(int i = 0 ; i < n ; i++) {
			char ch ;
			cin >> ch ;
			a[i] = ch - 'a' ;
		}
		for(int i = 0 ; i < n ; i++){
			char ch ;
			cin >> ch ;
			b[i] = ch - 'a' ;
		}
		bool check = true ;
		vector<vector<int>> v ;
		for(int ch = 25 ; ch >= 0 ; ch--){
			int id = -1 ;
			vector<int> temp ;
			for(int j = 0 ; j < n ; j++){
				if(ch == a[j]){
					id = j ;
				}
				if(b[j] == ch && a[j] < ch) {
					check = false ;
				}
				if(b[j] == ch && a[j] > ch) temp.push_back(j) ;
			}
			if(temp.size()){
				if(~id){
					temp.push_back(id) ;
				} else {
					check = false ;
					break ;
				}
			}
			if(!check) break ;
			if(temp.size()) v.push_back(temp) ;
		}
		if(check){
			cout << v.size() << '\n' ;
			for(auto i : v){
				cout << i.size() << " " ;
				for(auto j : i) cout << j << " " ;
				cout << '\n' ;
			} 
		} else {
				cout << -1 << '\n' ;
		}
}

int32_t main() 
{	
    ios_base:: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//#ifndef ONLINE_JUDGE
		//freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	//#endif
	int t ;
	cin >> t;
	while(t--)solve();
	return 0;
}
