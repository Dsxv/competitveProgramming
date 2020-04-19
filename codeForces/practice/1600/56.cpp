#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n;
	cin >> n ;
	int p[n] ;
	for(int i = 0 ; i < n ; i++) {
		int x ; 
		cin >> x ;
		p[x-1] = i ;
	}
	int count = 1 ;
	int ans = 1 ;
	for(int i = 1 ; i < n ; i++){
		if(p[i] > p[i-1]) count++ ;
		else count = 1 ;
		ans = max(ans,count) ;
	}
	cout << n - ans ;
	return 0 ;
}

