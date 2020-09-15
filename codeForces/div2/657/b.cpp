#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int l , r , m ;
		cin >> l >> r >> m ;
		for(int i = l ; i <= r ; i++){
			int rem = m%i , mem = i - m%i ;
			if(i > m){
				rem = INT_MAX ; //case when we can't take the back
			}
			if(rem <= r - l){
				cout << i << " " << r << " " << r - rem << '\n' ;
				break ;
			}
			if(mem <= r - l){
				cout << i << " " << r - mem << " " << r << '\n' ;
				break ;
			}
		}
	}
	return 0 ;
}

