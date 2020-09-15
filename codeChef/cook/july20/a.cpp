#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n; 
		cin >> n ;
		int ch[26] = {} ;
		for(int i = 0 ; i < n ; i++){
			char x ; cin >> x ;
			ch[x-'a']++ ;
		}
		bool found = true ;
		for(int i = 0 ; i < 26 ; i++){
			found &= (ch[i]%2 == 0) ;
		}
		cout << (found ? "YES\n" : "NO\n") ;
	}
	return 0 ;
}

