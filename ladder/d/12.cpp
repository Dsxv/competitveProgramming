#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int a , b , c , x , y , z;
	cin >> a >> b >> c; //vasya's pos
	int v[6] ;
	cin >> x >> y >> z ; // box vals
	for(int i = 0 ; i < 6 ; i++) cin >> v[i] ;
	int ans = 0 ;
	if(b < 0) ans += v[0] ;
	if(b > y) ans += v[1] ;
	if(c < 0) ans += v[2] ;
	if(c > z) ans += v[3] ;
	if(a < 0) ans += v[4] ;
	if(a > x) ans += v[5] ;
	cout << ans ;
	return 0 ;
}

