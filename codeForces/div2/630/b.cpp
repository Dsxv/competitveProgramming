#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n;
		int a[n] ;
		int col[n] = {} ;
		for(int i = 0 ; i < n ; i++) cin >> a[i] ;
		int prime[] = { 2 , 3 , 5 , 7 , 11 , 13 , 17 , 19 , 23 , 29 , 31} ;
		int count = 0 ;
		for(int j = 0 ; j < 11 ; j++){
			bool ok = false ;
			for(int i = 0 ; i < n ; i++){
				if(col[i] == 0 && (a[i]%prime[j] == 0)){
					ok = true ;
					col[i] = (ok + count) ;
				}
			}
			count += ok ;
		}
		cout << count << '\n' ;
		for(int i = 0 ; i < n ; i++) cout << col[i] << " " ;
	}
	return 0 ;
}

