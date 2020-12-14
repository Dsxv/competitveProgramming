#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n , q ;
		cin >> n >> q ;
		string s ;
		cin >> s ;
		while(q--){
			int l , r ;
			cin >> l >> r ;
			l-- , r-- ;
			bool found = false ;
			for(int i = 0 ; i < l ; i++){
				if(s[i] == s[l]){
					found = true ;
				}
			}
			for(int j = r + 1 ; j < n ; j++){
				if(s[j] == s[r]){
					found = true ;
				}
			}
			if(found){
				cout << "YES\n" ;
			} else {
				cout << "NO\n" ;
			}
		}
	}
	return 0 ;
}

