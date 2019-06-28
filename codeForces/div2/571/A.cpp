#include <bits/stdc++.h>
using namespace std ;

int32_t main(){
	int n , m , k ;
	cin >> n>> m >> k;
	if(min(n,m) >= k ){
		cout << "Yes" ;
	}else{
		cout << "No";
	}
	return 0 ;
}

