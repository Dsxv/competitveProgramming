#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t;
	cin >> t ;
	while(t--){
		int n , a , b , c , d ;
		cin >> n >> a >> b >> c >> d ;
		int x = (a-b)*n ;
		int y = (a+b)*n ;
		if(x <= (c+d) & y >= (c-d)) {
			cout << "Yes\n" ;
		} else {
			cout << "No\n" ;
		}
	}
	return 0 ;
}

