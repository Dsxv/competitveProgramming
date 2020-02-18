#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(int* a , int* b , int n){
	int max_val = -1 , id = -1 ;
	int check = 0 ;
	for(int i = 0 ; i < n ; i++){
		int sx = 0 ;
		if(i < n-1) sx = b[i+1] ;
		int ans = a[i] , tval = (check|sx) ;
		for(int j = 0 ; j < 32 ; j++){
			int y = (1LL<<j) ;
			if(!(ans & y)) continue ;
			if(tval&y) {
				ans -= y ;
			}
		}
		if(ans > max_val){
			max_val = ans ;
			id = i;
		}
		check |= a[i] ;
	}
	swap(a[0],a[id]) ;
	for(int i = 0 ; i < n ; i++) cout << a[i] << " ";
	return ;
}

int32_t main(){
	int n ;
	cin >> n ;
	int a[n] , b[n];
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	b[n-1] = a[n-1] ;
	for(int i = n - 2; i >= 0 ; i--){
		b[i] = (b[i+1]|a[i]) ;
	}
	solve(a,b,n) ;
	return 0 ;
}

