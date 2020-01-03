#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int a , b ;
		cin >> a >> b ;
		bitset<100> x(a) , y(b) , ans(0);
	    for(int i = 99 ; i >= 0 ; i--){
	   		if(y[i]){
				if(x[i]){
					ans[i] = 1 ;
				} else {
					int count = 0;
					for(int j = i ; j >= 0 ; j--) count += y[j] ;
				   if(count > i){
				   		for(int j = i ; j >= 0 ; j--) ans[j] = y[j] ;
				 	} else{
						for(int j = i-1 ; j >= 0 ; j--) ans[j] = 1 ;
					}		   
					break ;
				}
			}
	   }
	   cout << ans.to_ullong() << endl ;
	}
	return 0 ;
}

