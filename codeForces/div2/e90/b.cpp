#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		string s ;
		cin >> s ;
		int x = count(s.begin() , s.end() , '0') ;
		int y = s.size() - x ;
		int n = min(x,y) ;
		cout << (n%2 == 0? "NET\n" : "DA\n") ;
	}
	return 0 ;
}

