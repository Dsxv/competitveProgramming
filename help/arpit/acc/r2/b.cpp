#include <bits/stdc++.h>
using namespace std ;

#define int long long

int maxProfit(int* prices , int n) {
	if(n == 0) return -1 ;
	if(n < 2) return 0 ;
	long long pre[n] , suf[n] ;
	long long ans = 0 , mx = 0 , mn = 0;
	for(int i = n - 1 ; i >= 0 ; i--){
		ans = max(ans , mx - prices[i]) ;
		suf[i] = ans ;
		mx = max(mx , prices[i]) ;
	}
	ans = 0 ;
	mn = INT_MAX ;
	for(int i = 0 ; i < n ; i++){
		ans = max(ans , prices[i] - mn) ;
		pre[i] = ans ;
		mn = min(mn , (long long)prices[i]) ;
	}
	for(int i = 0 ; i < n ; i++){
		ans = max(suf[i] + pre[i] , ans) ;
	}
	return ans ;
}

int32_t main(){
	int n ;
	cin >> n ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	cout << maxProfit(a , n) << endl ;
	return 0 ;
}

