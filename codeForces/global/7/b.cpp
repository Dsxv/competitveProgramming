#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n ;
	cin >> n;
	int x ;
	cin >> x ;
	cout << x << " ";
	for(int i = 0 ; i < n - 1; i++){
		int y ;
		cin >> y ;
		cout << y + x << " " ;
		x = max(x,y+x) ;
	}
	return 0 ;
}

