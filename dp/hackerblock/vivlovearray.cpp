#include<bits/stdc++.h>
using namespace std ;

int solve(int* a , int n , int i , int j , long long s){
	if(s%2) return 0 ;
	s /= 2 ;
	if(i == j){
		return 0;
	}
	long long sum = 0 ;
	for(int k = i ; k < j ; k++){
		sum += a[k] ;
		if(sum == s){
			return max(solve(a,n,i,k,s) , solve(a,n,k+1,j,s)) + 1 ;
		}
	}
	return 0 ;
}

int32_t main() {
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		int a[n] ;
		for(int i = 0 ; i < n ; i++) cin >> a[i] ;
		cout << solve(a,n,0,n-1,accumulate(a,a+n,0LL)) << '\n';
	}
	return 0;
}
