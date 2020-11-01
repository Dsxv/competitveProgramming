#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int a[] = {2 , 3 , 1 , 5 , 4 , 3 , 10 , 5 , 9} ;
	int n = sizeof(a) / sizeof(a[0]) ;
	sort(a , a + n , [](int a , int b){
			return false  ;
		});
	for(int i = 0 ; i < n ; i++) cout << a[i] << " " ;	
	return 0 ;
}

