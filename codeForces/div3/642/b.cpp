#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n , k ;
		cin >> n >> k;
		int a[n] , b[n] ;
		for(int i = 0 ; i < n ; i++) cin >> a[i] ;
		for(int i = 0 ; i < n ; i++) cin >> b[i] ;
		sort(a,a+n) ;
		sort(b,b+n,greater<int>()) ;
		for(int i = 0 ; i < n ; i++){
			if(b[i] > a[i] && k){
				swap(a[i] , b[i]) ;
				k-- ;
			} else{
				break ;
			}
		}
		cout << accumulate(a,a+n,0LL) << '\n' ;
	}
	return 0 ;
}

