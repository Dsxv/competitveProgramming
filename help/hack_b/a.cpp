#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int N = 1e3 + 5 ;
int dp[N][N] ;
map<string , int> mp ; 
const int mod = 1e9 + 7 ;
int n ;
int solve(string& s , int i , int x){
	if(i >= n) return 0 ;
	if(x == 1){
		return mp.count(s.substr(i)) ;
	}
	if(~dp[i][x]) return dp[i][x] ;
	int ans = 0 ;
	for(int j = i ; j < n ; j++){
		if(mp.count(s.substr(i , j - i + 1)))
			ans = (ans + solve(s , j + 1 , x - 1)) % mod ;
	}
	return dp[i][x] = ans ;
}

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int t ;
	cin >> t ;
	while(t--){
		memset(dp , - 1 , sizeof(dp)) ;
		mp.clear() ;
		string s ;
		cin >> s ;
		n = s.size() ;
		int m ;
		cin >> m ;
		for(int i = 0 ; i < m ; i++){
			string temp ; cin >> temp ;
			mp[temp]++ ;
		}
		int ans = 0 ;
		for(int i = 1 ; i <= n ; i++){
			ans = ans + solve(s , 0 , i) % mod ;
		}
		cout << ans << '\n' ;
	}
	return 0 ;
}

