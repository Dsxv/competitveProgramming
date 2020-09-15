#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n; 
		cin >> n ;
		bitset<64> b(n) ;
		bool found = true  ;
		int last1 = 0 ;
		for(int i = 0 ; i < 63 ; i++) if(b[i]) last1 = i ;
		for(int i = 0 ; i < last1 ; i++){
			if((b[i]^b[i+1]) == 0){
			found = false ;
			}
		}
		if(!found) cout << "NO\n" ;
		else cout << "YES\n" ;
	}
	return 0 ;
}

