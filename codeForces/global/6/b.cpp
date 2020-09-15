#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t; 
	while(t--){
		int x ;
		cin >> x ;
		if(x < 15) {cout << "NO\n" ;continue ;}
		bool found = false ;
		for(int i = 1 ; i <= 6 ; i++){
			if((x-i)%14 == 0){
				cout << "YES\n" ;
				found = true ;
			}
		}
		if(!found) cout << "NO\n" ;
	}
	return 0 ;
}

