#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 2e3 ;

pair<int,int> dp[N][N] ;

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){

		int n ;
		cin >> n ; n-- ;
		int a[n+1] ;
		for(int i = 0 ; i <= n ; i++) cin >> a[i] ;
		for(int i = n ; i >= 0 ; i--){
			for(int j = i ; j < n ; j++){
				if(i == j){ 
					dp[i][j] = {0,i} ;
					continue ;
				}
				int min_val = INT_MAX , ind = i;
				for(int k = i ; k < j ; k++){
					int cost = dp[i][k].first + dp[k+1][j].first 
								+ a[i]*a[k+1]*a[j+1] ;
					if(cost < min_val){
						min_val = cost ;
						ind = k ;
					}
				}
				dp[i][j] = {min_val,ind} ;
			}
		}
		cout << dp[0][n-1].first << "\n" ;
	}
	return 0 ;
}

