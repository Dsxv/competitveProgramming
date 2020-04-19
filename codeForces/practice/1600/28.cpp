#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	double n , m ;
	cin >> m >> n;
	long double ans = 0 ;
	for(int i = 1 ; i <= m ; i++){
		ans += (pow(i/m,n) - pow((i-1)/m,n))*i ;
	}
	cout << fixed << setprecision(10) << ans ;
	return 0 ;
}

