#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n , m ;
		cin >> n >> m ;
		int a[n] ;
		for(int i = 0 ; i < n ; i++) cin >> a[i] ;
		cout << min(m,accumulate(a,a+n,0LL)) << endl;
	}
	return 0 ;
}

