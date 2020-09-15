#include <bits/stdc++.h>
using namespace std ;
const int N = 1 << 22 ;
int cnt[N] ;
int dp[2][N] ;

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int n; 
	cin >> n ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++) {
		cin >> a[i] ;
		cnt[a[i]] = i+1 ;
	}
	for(int i = 0 ; i < N ; i++){
		dp[1][i] = cnt[i] ;
	}
	for(int i = 0 ; i < 22 ; i++){
		int cur = i%2 ;
		int prev = (i+1)%2 ;
		for(int mask = 0 ; mask < N ; mask++){
			dp[cur][mask] = dp[prev][mask] ;
		}
		for(int mask = 0 ; mask < N ; mask++){
			if(mask&(1<<i)){
				if(!dp[cur][mask]) dp[cur][mask] = dp[prev][mask^(1<<i)] ;
			}
		}
	}
	for(int i = 0 ; i < n ; i++){
		int comp = ((1 << 22) - 1) ^ a[i] ; 
		if(dp[1][comp]){
			cout << a[dp[1][comp] - 1] << " " ;
		} else {
			cout << -1 << " " ;
		}
	}
	return 0 ;
}

