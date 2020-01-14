#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n ;
	cin >> n ;
	int m , c ;
	cin >> m >> c ;
	int a = 0 , b = 0 ;
	while(n--){
		int x , y , p ;
		cin >> x >> y >> p ;
		int fx = m*x - y + c ;
		if(fx < 0) a += p ;
		else b += p ;
	}
	cout << max(a,b) ;
	return 0 ;
}

