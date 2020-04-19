#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n , x ;
		cin >> n >> x ;
		int a[n] ;
		for(int i = 0 ; i < n ; i++){
			cin >> a[i] ;
		}
		sort(a,a+n,greater<int>()) ;
		double pref = 0 ; int  ans = 0 ;
		for(int i = 0 ; i < n ; i++){
			pref += a[i] ;
			if(pref/(i+1) >= x) ans++ ;
		}
		cout << ans << endl ;
	}
	return 0 ;
}

