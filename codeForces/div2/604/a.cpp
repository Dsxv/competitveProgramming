#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t; 
	cin >> t ;
	while(t--) {
		string s ;
		cin >> s ;
		bool found = true ;
		for(int i = 0 ; i < s.size()  && found ; i++) {
			int c[3] = {0} ;
			if(s[i] == '?') {
				if(i - 1 >= 0 ) {
					c[s[i-1] - 'a']-- ;
				} 
				if(i + 1 < s.size() && s[i+1] != '?')
					c[s[i+1]-'a']-- ;
				for(int j = 0 ; j < 3 ; j++) {
					if(c[j] >= 0) s[i] = (char)('a' + j) ;
				}
			}
			if(i - 1 >= 0 ) {
				if(s[i-1] == s[i]) found = false ;
			}
		}
	if(found) cout << s ;
	else cout << -1 ;
	cout << endl ;
	}
	return 0 ;
}

