#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int ans = 0 ;
	int n ; cin >> n ;
	for(int i = 1 ; i <= n ; i++){
		bool ok = true ;
		int j = i ;
		while(j){
			if(j % 10 == 7) ok = false ;
			j /= 10 ;
		}
		j = i ;
		bool ok2 = true ;
		while(j){
			if(j % 8 == 7) ok = false ;
			j /= 8 ;
		}
		ans += ok * ok2 ;
	}
	cout << ans ;
	return 0 ;
}

