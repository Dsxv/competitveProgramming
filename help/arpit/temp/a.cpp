#include <bits/stdc++.h>
using namespace std ;

#define int long long

int solve(int* a , int n){
	int l = 0 , mx = 0 ;
	int tsum = 0 , csum = 0 ;
	for(int i = 0 ; i < n ; i++){
		csum += a[i] ;
		if(a[i] % 2){
			l = i + 1 ;
			csum = 0 ;
		}
		if((i - l + 1) == mx){
			tsum += csum ;
		}
		if((i - l + 1) > mx){
			mx = i - l + 1 ;
			tsum = csum ;
		}
	}
	return mx ? tsum : -1 ;
}

int32_t main(){
	int n ;
	cin >> n ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;

	cout << solve(a,n) ;

	return 0 ;
}

