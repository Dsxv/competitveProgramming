#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	string s , t ;
	cin >> s >> t ;
	reverse(s.begin() , s.end()) ;
	if(s == t){
		cout << "YES" ;
	} else {
		cout << "NO" ;
	}
	return 0 ;
}

