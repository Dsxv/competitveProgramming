#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	static int i = 5 ;
	if(--i){
		main() ;
		printf("%lld" , i) ;
	}
	return 0 ;
}

