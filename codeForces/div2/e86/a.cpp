#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int x , y ;
		cin >> x >> y ;
		int a , b ;
		cin >> a >> b ;
		if(y < x) swap(x,y) ;
		cout << a*(y-x) + min(2*x*a , b*x) << '\n' ;
	}
	return 0 ;
}

