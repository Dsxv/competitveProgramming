#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int N = 1026 ;
int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		int a[n] ;
		int c[N] = {} ;
		for(int i = 0 ; i < n ; i++){
			cin >> a[i] ;
			c[a[i]]++ ;
		}
		int ans = -1 ;
		for(int j = 1 ; j < N ; j++){
			int b[N] = {} ;
			bool found = true ;
			for(int i = 0 ; i < n ; i++){
				if((a[i]^j) < N)
					b[a[i]^j]++ ;
				else found = false ;
			}
			for(int i = 0 ; i < N ; i++){
				if(b[i] != c[i]) found = false ;
			}
			if(found) {ans = j ; break ;}
		}
		cout << ans << '\n' ;
	}
	return 0 ;
}

