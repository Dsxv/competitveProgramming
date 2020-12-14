#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int N = 1e5 + 10 ;
int dp[N][8] ;
const int inf = 1e15 ;
vector<vector<pair<int,int>>> a ; 

int solve(int n , int i = 0 , int j = 0){
	if(i == n){
		return 0 ;
	}
	if(~dp[i][j]) return dp[i][j] ;
	int ans = -inf ;
	for(auto x : a[i]){
		if(x.second == j) continue ;
		ans = max(ans , solve(n , i + 1 , x.second) + x.first) ;
	}
	return dp[i][j] = ans ;
}

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		memset(dp , -1 , sizeof(dp)) ;
		int n , m ;
		cin >> n >> m ;
		a.clear() ;
		a.resize(n) ;
		for(int i = 0 ; i < m ; i++){
			int x , y , z ;
			cin >> x >> y >> z ;
			a[x-1].push_back({z , y}) ;
		}
		if(solve(n) < 0){
			cout << -1 << '\n' ;
		} else {
			cout << solve(n) << '\n' ;
		}
	}
	return 0 ;
}

