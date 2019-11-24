#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n , k ;
	cin >> n >> k ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	int m1 , m2 ;
	int dp[n] ;
	for(int i = 0 ; i < k && i < n ; i++){
		dp[i] = a[i] ;
	}
	for(int i = k ; i < n ; i+=k){
		m1 = max_element(dp+i-k,dp+i) - dp ;
		int t = dp[m1] ;
		dp[m1] = INT_MIN ;
		m2 = max_element(dp+i-k,dp+i) - dp ;
		dp[m1] = t;
		for(int j = i ; j < n && j < i + k ; j++){
			if(m1 != j-k){
				if(a[j] > 0){
					dp[j] = dp[m1] + a[j] ;
				}else{
					dp[j] = dp[m1] ;
				}
			}else{
				if(a[j] > 0){
					dp[j] = dp[m2] + a[j] ;
				}else{
					dp[j] = dp[m1] ; // if not taking j then take m1
				}
			}
		}
	}
	cout << *max_element(dp,dp+n) ;
	return 0 ;
}

