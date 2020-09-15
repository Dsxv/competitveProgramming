#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	string s ;
	cin >> s ;
	sort(s.begin() , s.end() , greater<char>()) ;
	cout << s ;
	return 0 ;
}

