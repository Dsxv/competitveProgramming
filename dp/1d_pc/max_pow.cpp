#include <bits/stdc++.h>
using namespace std ;

#define int long long


int solve(int* a , int n){
	int f = 1 , b = 1 ;
	int ans = INT_MIN ;
	for(int i = 0 ; i < n ; i++){
		f *= a[i] ;
		b *= a[n-i-1] ;
		ans = max({f,b,ans}) ;
		if(f == 0) f = 1 ;
		if(b == 0) b = 1 ;
	}
	return ans ;
}

int32_t main(){
	int n ;
	cin >> n; 
	int a[n] ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	cout << solve(a,n) ;
	return 0 ;
}

