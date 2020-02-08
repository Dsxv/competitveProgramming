#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int p , m , n ;
		cin >> p >> m >> n ;
		if(n >= p-1) n = p - 1;
		n++ ;
		int x = (n-1)/m , y = (n-1)%m ;
		if(x == 0){
			if(y == 0) cout << 1 << endl ;
			else cout << m + y << endl ;
		} else {
			int z = 2 + (x-1)*m + ((x-1) != 0) ;
			if(y == 0) cout << z << endl ;
			else {
				int ans = z + m + y-1 ;
				if(ans > p){
					ans = 2 + x*m ;
				}
				cout << ans << endl ;
			}
		}
	}
	return 0 ;
}

