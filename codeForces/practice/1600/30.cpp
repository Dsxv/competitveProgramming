#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 1e6 + 10 ;

int32_t main(){
	int n; 
	cin >> n ;
	pair<int,int> p[n] ;
	for(int i = 0 ; i < n ; i++){
		cin >> p[i].first >> p[i].second ;
		p[i].first++ ;
	}
	sort(p,p+n) ;
	int cnt[N] = {};
	for(int i = 1 , j = 0 ; j < n && i < N ; i++){
		cnt[i] = cnt[i-1] ;
		if(i == p[j].first){
			cnt[i]++ ;
			j++ ;
		}
	}
	int dp[N] = {}; // no. of lamps destroyed
	int ans = INT_MAX ;
	for(int i = 1 , j = 0 ; j < n && i < N ; i++){
		if(i == p[j].first){
			int left = max(0LL , i - p[j].second - 1) ;
			dp[i] = dp[left] + (cnt[i-1] - cnt[left]) ;
			ans = min(ans, n - cnt[i] + dp[i]) ;
			j++ ;
		} else {
			dp[i] = dp[i-1] ;
		}
	}
	cout << ans ; 
	return 0 ;
}

