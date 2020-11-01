#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int a , b , x , y , n ;
		cin >> a >> b >> x >> y >> n ;
		int val1 = max(x , a - n) ;
		int val2 = max(y , b - n) ;
		if(val1 > val2) {
			swap(x , y) ; swap(a , b) ;
			swap(val1 , val2) ;
		}
		n -= a - val1 ;
		a = val1 ;
		b = max(y , b - n) ;
		cout << a * b << '\n' ;
	}
	return 0 ;
}

