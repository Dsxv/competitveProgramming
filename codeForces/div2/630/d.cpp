#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int k ;
	cin >> k ;
	int x = 1LL<<17 ;
	int f[2][3] = { {x + k , x , 0} ,
					{k , x + k , k} 
				 } ;
	cout << 2 << " " << 3 << endl ;
	for(int i = 0 ; i < 2 ; i++){
		for(int j = 0 ; j < 3 ; j++) cout << f[i][j] << " " ;
		cout << '\n' ;
	}
	return 0 ;
}

