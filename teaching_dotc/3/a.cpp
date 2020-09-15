#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n , x ;
	cin >> n >> x ;
	double v = x*n/100.0 ;
	int ans = 0 ;
	while(n) ans += n / 5 , n /= 5 ;
	cout << fixed << setprecision(2) <<  ans*v;
	return 0 ;
}

