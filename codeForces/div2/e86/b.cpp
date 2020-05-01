#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		string s ;
		cin >> s ;
		if(count(s.begin() , s.end() , '0') && count(s.begin(), s.end() , '1')) {
			for(int i = 0 ; i < s.size() ; i++){
				cout << "10" ;
			}
			cout << '\n' ;
		} else {
			cout << s << '\n' ;
		}
	}
	return 0 ;
}

