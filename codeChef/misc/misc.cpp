#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int N = 2e6 + 5;
vector<int> pw ;
int exr[N] ;
int dp[N] ;

int solve(int i){
	int xr = 0 ;
	while(i){
		int x ;
		for(int j = 0 ; j < pw.size() ; j++) {
			if(pw[j] > i) break ;
			x = j ;
		}
		xr ^= x ;
		i -= pw[x] ;
	}
	return xr ;
}	


int32_t main(){
	pw.resize(0) ;
	int x = 1 ;
	while(x < N) {
		pw.push_back(x) ;
		x *= 3 ;
	}
	for(int i = 1 ; i < N ; i++){
		exr[i] = solve(i) ;
	}
	for(int i = N - 2 ; i >= 1 ; i--){
	   if(exr[i]) dp[i] = dp[i+1] ;
   		else dp[i] = i ;
	}
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		cout << dp[n] << '\n' ;
	}	
	return 0 ;
}

