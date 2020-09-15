#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t;
	cin >> t; 
	while(t--){
		int n; 
		cin >> n ;
		int a[n] ;
		for(int i = 0 ; i < n ; i++) cin >> a[i] ;
		bool found = true ;
		set<int> s , f ;
		int cura = 0 , curb = 0 ;
		for(int i = 0 ; i < n ; i++){
			cura |= a[i] ;
			curb |= a[n-i-1] ;
			s.insert(cura) ;
			f.insert(curb) ;
		}
		if(s.size() == n && f.size() == n){
			cout << "YES\n" ;
		} else {
			cout << "NO\n" ;
		}
	}
	return 0 ;
}

