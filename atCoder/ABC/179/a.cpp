#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	string s ;
	cin >> s ;
	if(s.back() == 's'){
		cout << s + "es" ;
	} else {
		cout << s + "s" ;
	}
	return 0 ;
}

