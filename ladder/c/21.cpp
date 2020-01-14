#include <bits/stdc++.h>
using namespace std ;

#define int long long

int check(int n , int k , int d){
	int ans = 0 ;
	int x = 1 ;
	for(int i = 0 ; i < d ; i++){
		x *= k ;
		if(x >= n) return 1 ;
	}
	return x >= n ;
}
int32_t main(){
	int n , k , d ;
	cin >> n >> k >> d ;
	if(!check(n,k,d)){
		cout << -1 ;
		return 0 ;
	}
	int ans[d][n] ;
	for(int i = 0 ; i < d ; i++) ans[i][0] = 0 ;
	for(int j = 1 ; j < n ; j++){
		for(int i = 0 ; i < d ; i++) ans[i][j] = ans[i][j-1] ;
		int c = 1 ;
		for(int i = 0 ; i  < d ; i++){
			ans[i][j] += c ;
			c = ans[i][j]/k ;
			ans[i][j] %= k;
		}
	}
	for(int i = 0 ; i < d ; i++){
		for(int j = 0 ; j < n ; j++){
			cout << ans[i][j] + 1 << ' ' ;
		} cout << endl ;
	}

	return 0 ;
}

