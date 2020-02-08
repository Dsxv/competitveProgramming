#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n , k , m ;
	cin >> n >> k >> m ;
	m *= n ;
	for(int i = 0 ; i < n  - 1; i++){
		int x ;
		cin >> x ;
		m -= x ;
	}
	if(m > k) cout << -1;
	else cout << max(0LL,m) ;
	return 0 ;
}

