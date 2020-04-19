#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int r , g , b ;
	cin >> r >> g >> b ;
	int x0 = 0 , x1 = 0 , x2 = 0 ;
	x0 = r/3 + g/3 + b/3 ;
	if(r > 0 && g > 0 && b > 0) x1 = (r-1)/3 + (g-1)/3 + (b-1)/3 + 1 ;
	if(r > 1 && g > 1 && b > 1) x2 = (r-2)/3 + (g-2)/3 + (b-2)/3 + 2 ;
	cout << max({x0,x1,x2}) ;
	return 0 ;
}

