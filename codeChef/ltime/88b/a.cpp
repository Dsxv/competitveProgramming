#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t; 
	cin >> t ;
	while(t--){
		int n;
		cin >> n ;
		int a[n] ;
		for(int i = 0 ; i < n ; i++) cin >> a[i] ;
		int sum = accumulate(a , a + n , 0LL) ;
		if(sum < 0) cout << "NO\n" ;
		else cout << "YES\n" ;
	}
	return 0 ;
}

