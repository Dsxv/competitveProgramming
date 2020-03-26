#include <bits/stdc++.h>
using namespace std ;

//#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	for(int x = 1 ; x <= t ; x++){
		int n , b ;
		cin >> n >> b ;
		int a[n] ;
		for(int i = 0 ; i < n ; i++) cin >> a[i] ;
		sort(a,a+n) ;
		int ans = 0 ;
		for(int i = 0 ; i < n ; i++){
			b -= a[i] ;
			if(b < 0) break ;
			else ans++ ;
		}
		printf("Case #%d: %d\n",x,ans) ;
	}
	return 0 ;
}

