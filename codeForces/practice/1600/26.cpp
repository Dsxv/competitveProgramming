#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ; 
		cin >> n ;
		int a[n] ;
		set<int> s ;
		for(int i = 0 ; i < n ; i++) {
			cin >> a[i] ;
			s.insert(a[i]) ;
		}
		sort(a,a+n) ;
		int x = a[0]*a[n-1] ;
		set<int> fact ;
		int l = sqrt(x) ;
		for(int i = 1 ; i <= l ; i++){
			if(x%i == 0){
				fact.insert(i) ;
				fact.insert(x/i) ;
			}
		}
		s.insert(1) ; s.insert(x) ;
		if(s == fact){
			cout << x ;
		} else {
			cout << -1 ;
		}
		cout << endl ;
	}
	return 0 ;
}

