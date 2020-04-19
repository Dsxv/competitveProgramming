#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n , k ;
	cin >> n >> k ;
	set<int> s ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	sort(a,a+n) ;
	for(int i = n - 1 ; i >= 0 ; i--){
		if(!s.count(a[i]*k)) s.insert(a[i]) ;
	}
	cout << s.size() ;
	return 0 ;
}

