#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	string s ;
	cin >> s ;
	int cnt = 0 ;
	for(auto i : s){
		cnt += i - '0' ;
	}
	cout << ( cnt % 9 ? "No" : "Yes") ;
	return 0 ;
}

