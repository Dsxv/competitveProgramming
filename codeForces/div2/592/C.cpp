#include <bits/stdc++.h>
using namespace std ;

#define int long long 

int32_t main(){
	int n , p , w , d ;
	cin >> n >> p >> w >> d ;
	// eqn 
	// x*w + y*d = p ... (1)
	// x + y + z = n ... (2)
	// y to be iterated from 0 to w-1 
	// because x*w + y*d == (x+d)*w + (y-w)*d , y can be minised to 0 to w-1
	// so iterate over all possible draw value and check val of p and n
	//
	//
	//
	// but why not conv when x >= d from x-d to y+w
	// reason being total win + total draw := x + y - (w-d)
	//  w >= d hence x + y - (+ve) which means x + y decrease which we
	//  want in eq2 
	for(int i = 0 ; i < w ; i++){

		if((p - i*d)%w == 0 && p >= i*d){
			int x = (p-i*d)/w ;
			if(x + i <= n) {
				cout << x << " " << i << " " << n-x-i ;
				return 0 ;
			}
		}
	}
	cout << -1 ;
	return 0 ;
}

