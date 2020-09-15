#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int a,  b ;
	cin >> a >> b ;
	if(b < a) swap(a,b) ;
	if(b-a < 2 || (a%2 && b-a <= 2)) {
		cout << -1 ;
		return 0 ;
	}
	int x = a%2 ;
	cout << a + x << " " << a + x + 1 << " " << a + x + 2 ;
	return 0 ;
}

