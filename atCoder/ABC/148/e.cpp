#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n ;
	cin >> n ;
	int x = 0, y = 0 ;
	for(long double i = 5 ; i <= n ; i*=5){
		for(long double j = 2 ; j <= n ; j *= 2){
			int p = i , q = j ;
			if(((p%2)*(q%2))%2 == n%2) {
				x += (int) (log(i)/log(5.0)) ;
				y += (int) (log(j)/log(2.0))  ;
			}
		}
	}
	cout << min(x,y) ;
	return 0 ;
}

