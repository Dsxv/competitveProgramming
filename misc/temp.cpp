#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n ;
	cin >> n ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	set<int> s ;
	for(int i = 0 ; i < n ; i++){
		set<int> k = s ;
		for(auto j : k){
			s.insert(abs(j-a[i])) ;
		}
		s.insert(a[i]) ;
	}
	cout << *s.begin() ;
	return 0 ;
}

