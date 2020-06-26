#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t;
	cin >> t ;
	while(t--){
		int a , b , c ;
		cin >> a >> b >> c ;
		if(a < c){
			cout << 1 << " " ;
		} else {
			cout << -1 << " " ;
		}
		int x = 1e9 ;
		int cnt = (x/b)*b ;
		if(cnt/b*c < cnt*a){
			cout << cnt << '\n' ;
		} else {
			cout << -1 << '\n' ;
		}
	}
	return 0 ;
}


