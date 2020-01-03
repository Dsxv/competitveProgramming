#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n , m;
	double x ;
	cin >> n >> m ;
	int a[n] ;
	for(int i = 0 ;  i < n ; i++){
		cin >> a[i] >> x;
	}
	int dp[n] = {0};
	for(int i = 0; i < n ; i++){
		for(int j = i ; j >= 0 ; j--){
			if(a[i] >= a[j])
				dp[i] = max(dp[j],dp[i]);
		}
		dp[i]++ ;
	}
	cout << n - *max_element(dp,dp+n) ;
	return 0 ;
}

