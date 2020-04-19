#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	string a , b ;
	cin >> a >> b ;
	if(a.size() != b.size()) {
		cout << "NO\n" ;
		return 0 ;
	} 
	bool x = false , y = false ;
	x = (string(a.size(),'0') == a) ;
	y = (string(b.size() ,'0') == b) ;
	if(x^y) {
		cout << "NO\n" ;
	} else {
		cout << "YES\n" ;
	}
	return 0 ;
}

