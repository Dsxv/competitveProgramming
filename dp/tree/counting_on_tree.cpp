#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int mod = 1e9 + 7 ;
vector<vector<int>> g ;
vector<int> a ;
vector<vector<int>> dp ;

void solve(int start , int k , int parent = -1){
	vector<int> temp(k+1) , memo(k+1) ;
	memo[a[start]]++ ;
	for(auto i : g[start]){
		if(i == parent) continue ;
		solve(i , k , start) ;
		for(int j = 0 ; j <= k ; j++){
			for(int l = 0 ; l <= k ; l++){
				if((j+l) > k) continue ;
				temp[j+l] = (temp[j+l] + memo[j]*dp[i][l]) % mod ;
			}
		}
		for(int i = 0 ; i <= k ; i++){
			memo[i] = temp[i] ;
			temp[i] = 0 ;
		}
	}
	dp[start] = memo ;
	dp[start][0] = (dp[start][0] + (k != 0))  % mod ;
}

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int t ;
	cin >> t ;
	while(t--){
		int n , k; 
		cin >> n >> k;
		g.clear() ; a.clear() ;
		g.resize(n) ; a.resize(n) ;
		dp = vector<vector<int>> (n , vector<int>(k+1)) ;
		for(int i = 0 ; i < n ; i++){
			cin >> a[i] ;
		}
		for(int i = 0 ; i < n - 1 ; i++){
			int f , s ;
			cin >> f >> s ;
			f-- , s-- ;
			g[f].push_back(s) ;
			g[s].push_back(f) ;
		}
		solve(0,k) ;
		int ans = 0 ;
		for(int i = 0 ; i < n ; i++) ans = (ans + dp[i][k]) % mod ;
		cout << ans << '\n' ;
	}
	return 0 ;
}

