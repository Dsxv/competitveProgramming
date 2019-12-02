#include <bits/stdc++.h>
using namespace std ;

#define int long long
int dp[105][10010] ;
    
void print(int k , int n){
	for(int i = 0 ; i <= k ; i++){
		for(int j = 0 ; j <= n ; j++) cout << dp[i][j] <<" ";
		cout << endl ;
	}
	cout << "---------\n";
}

int superEggDrop(int k, int n) {
	for(int i = 1 ;  i <= k ; i++){
		dp[i][1] = 1 ;
	}
	for(int j = 1 ; j <= n ; j++){
		dp[1][j] = j ;
	}
	for(int i = 2 ; i <= k ; i++){
		for(int j = 2 ; j <= n ; j++){
			int lo = 2 , hi = j ;
			while(hi-lo > 1){ //make sure at least 2 elements
				int x = (lo+hi)/2 ;
				int t1 = dp[i-1][x-1] ;
				int t2 = dp[i][j-x] ;
				if(t1 < t2){ //jyada left
					lo = x ;
				} else if(t1 > t2){ //jyada right
					hi = x ;
				} else{
					lo = hi = x ; break; 
				}
			}
			int case1 = max(dp[i-1][lo-1]+1,1+dp[i][j-lo]) ;
			int case2 = max(dp[i-1][hi-1]+1,1+dp[i][j-hi]) ;
			dp[i][j] = min(case1,case2) ;
		}
	}
	// print(k,n) ;
	return dp[k][n] ;
}
int32_t main(){
	int n , k ;
	cin >> k >> n ;
	cout << superEggDrop(k,n) ;
	return 0 ;
}

