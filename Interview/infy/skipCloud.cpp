#include <bits/stdc++.h>
using namespace std ;

#define int long long

int minJump(int * a , int n){
	vector<int> dp(n , INT_MAX) ;
	if(a[0] == 0) dp[0] = 0 ;
	if(n == 1) return dp[0] ;
	if(a[1] == 0) dp[1] = 0 ;  
	for(int i = 2 ; i < n ; i++){
		int minBack = INT_MAX ;
		if(a[i]) continue ;
		if(a[i-1] == 0){
			minBack = min(minBack , dp[i-1]) ;
		}
		if(a[i-2] == 0){
			minBack = min(minBack , dp[i-2]) ;
		}
		dp[i] = min(minBack + 1 , dp[i]) ;
	}
	for(int i = 0 ; i < n ; i++) cout << dp[i] << " " ;
	cout << endl ;
	return dp[n-1] ;
}


int32_t main(){
	int n; 
	cin >> n; 
	int a[n] ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	int jump =  minJump(a , n) ;
	if(jump == INT_MAX){
		cout << "Not Possible\n" ;
	} else {
		cout << jump ;
	}
	return 0 ;
}

