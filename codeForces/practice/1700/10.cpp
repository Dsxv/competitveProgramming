#include <bits/stdc++.h>
using namespace std ;

#define int long long
int32_t main(){
	int n ;
	cin >> n ;
	int a[n+2] = {} ;
	for(int i = 0 ; i < n ; i++) cin >> a[i+1] ;
	int l[n+2] = {} ;
	int r[n+2] = {} ;
	for(int i = 1 ; i <= n ; i++){
		l[i] = 1 ;
		if(a[i] > a[i-1]) l[i] += l[i-1] ;
	}
	for(int i = n ; i >= 1 ; i--){
		r[i] = 1 ;
		if(a[i] < a[i+1]) r[i] += r[i+1] ;
	}
	int mx = 0 ;
	for(int i = 1 ; i <= n ; i++){
		if(a[i-1]  + 1 < a[i+1]){
			mx = max(mx , l[i-1] + r[i+1] + 1) ;
		} else {
			mx = max({mx , l[i-1] + 1 , r[i+1] + 1}) ;
		}
	}
	cout << mx ;
	return 0 ;
}
