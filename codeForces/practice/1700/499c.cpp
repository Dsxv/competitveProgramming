#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int x , y , a , b ;
	cin >> x >> y >> a >> b ;
	int n ;
	cin >> n ;
	int count = 0 ;
	for(int i = 0 ; i < n ; i++){
		int p , q , r ;
		cin >> p >> q >> r ;
		int l1 = p*x + q*y + r ;
		l1 = l1/abs(l1) ;
		int l2 = p*a + q*b + r ;
		l2 = l2/abs(l2) ;
		count += l1*l2 < 0 ;
	}
	cout << count ;
	return 0 ;
}

