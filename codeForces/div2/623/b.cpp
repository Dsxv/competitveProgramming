#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t; 
	cin >> t; 
	while(t--){
		int n , x , y ;
		cin >> n >> x >> y ;
		int worst = min(n-x,y-1) + min(n-y,x-1) + 1 ;
		int a = x - 1 , b = y - 1 ;
		a -= min(n-y-1,a) ;
		if(a) {
			y = max(a + 1, y - a) ;
			b = y - 1 ;
		}
		b -= min(n-x-1,b) ;
		cout << a + b + 1  << " " << worst << '\n' ;
	}
	return 0 ;
}

