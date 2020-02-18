#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		string s ; cin >> s ;
		int n ;
		n = s.size() ;
		int l = 0 , r = n ;
		while(l < n && s[l] == '0') l++ ;
		while(r > l && s[r-1] == '0') r-- ;
		cout << r-l-count(s.begin()+l,s.begin()+r,'1') << endl ;
	}

	return 0 ;
}

