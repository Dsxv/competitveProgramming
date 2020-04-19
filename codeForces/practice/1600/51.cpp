#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int  n; 
	cin >> n ;
	vector<int> v[n] ;
	for(int i = 0 ; i < n - 1 ; i++){
		int f , s ;
		cin >> f >> s ;
		f-- , s-- ;
		v[f].push_back(s) ;
		v[s].push_back(f) ;
	}
	bool ok = true ;
	for(int i = 0 ; i < n ; i++){
		if(v[i].size() == 2) ok = false ;
	}
	cout << (!ok ? "NO" : "YES") ;
	return 0 ;
}

