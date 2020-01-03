#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 505 ;
int g[N][N] ;

int32_t main(){
	int n ;
	cin >> n ;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			cin >> g[i][j] ;
		}
	}
	int x[n] ;
	for(int i = 0 ; i < n ; i++){
		cin >> x[i] ;
		x[i]-- ;
	}
	reverse(x,x+n) ;
	int dp[N][N] = {} ;
	vector<int> ans(n) ;
	int pr[n] = {0} ;
	for(int k = 0 ; k < n ; k++){
		for(int i = 0 ; i < n ; i++) {
			if(pr[i]) {
				dp[x[k]][i] = g[x[k]][i] ;
				dp[i][x[k]] = g[i][x[k]] ;
			}
		}
		// min dis of x[k] from all prev present elements
		for(int i = 0 ; i < k ; i++){ 
			for(int j = 0 ; j < k ; j++){
				dp[x[k]][j] = min(dp[x[k]][x[i]] + dp[x[i]][j] , dp[x[k]][j]) ;            			dp[j][x[k]] = min(dp[j][x[i]] + dp[x[i]][x[k]] , dp[j][x[k]]) ;
			}
		}	
		pr[x[k]] = 1 ;
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < n ; j++){
				if(dp[i][x[k]] + dp[x[k]][j] < dp[i][j]){
					dp[i][j] = dp[i][x[k]] + dp[x[k]][j] ;
				}
			}
		}
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < n ; j++)
				ans[k] += dp[i][j] ;
		}
	}
	reverse(ans.begin(), ans.end()) ;
	for(auto i : ans) cout << i << ' ' ;
	return 0 ;
}

