#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int a[1001] ;
	for(int i = 1 ; i <= 1000 ; i++) a[i] = 1 ;
	int n ; 
	cin >> n ;
	while(n--){
		int l , r ;
		cin >> l >>  r ;
		for(int i = l ; i <= r ; i++) a[i] = 0 ;
	}
	int cnt = 0 ;
	for(int i = 1 ; i <= 1000 ; i++) cnt += a[i] ;
	cout << cnt << " " ;
	for(int i = 1 ; i <= 1000 ; i++) if(a[i]) cout << i << " " ;
	return 0 ;
}

