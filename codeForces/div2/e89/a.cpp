#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int a , b ;
		cin >> a >> b ;
		if(!a || !b) cout << 0 << '\n' ;
		else cout << min(min(a,b) , (a+b)/3) << '\n' ;
	}
	return 0 ;
}

