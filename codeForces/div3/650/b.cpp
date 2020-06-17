#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n; 
		int a[n] ;
		int cnt[2] = {} ;
		for(int i = 0 ; i < n ; i++){
			cin >> a[i] ;
			cnt[a[i]%2] += a[i]%2 != i%2 ;
		}
		cout << (cnt[0] != cnt[1] ?-1:cnt[0]) << '\n' ;
	}
	return 0 ;
}

