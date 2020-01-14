#include <bits/stdc++.h>
using namespace std ;

#define int long long

int solve(vector<int>& v){
	sort(v.begin(),v.end()) ;
	int n = v.size() ;
	vector<int> dp(n) ;
	for(int i = 0 ; i < n ; i++){
		dp[i] = 1 ;
		for(int j = i-1 ; j >= 0 ; j--){
			if(v[i] % v[j] == 0){
				dp[i] = max(dp[i],dp[j]+1) ;
			}
		}
	}
	return *max_element(dp.begin(),dp.end()) ;
}

int32_t main(){
	int n ;
	cin >> n ;
	vector<int> v(n) ;
	for(int i = 0 ; i < n ; i++) cin >> v[i] ;
	cout << solve(v) ;
	return 0 ;
}

