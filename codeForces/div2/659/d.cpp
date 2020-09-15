#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		int a[32] = {} ;
		for(int i = 0 ; i < n ; i++){
			int x ; cin >> x ;
			for(int j = 0 ; j <= 30 ; j++){
				if((1LL<<j)&x) a[j]++ ;
			}
		}
		bool win = false , loose = false ;
		for(int j = 30 ; j >= 0 ; j--){
			if((a[j])%2 == 0){
				continue ;
			}
			if((a[j]-1)%4 == 0){
				win = true ;
				break ;
			} else if((a[j]-1)%2 == 0){
				if((n-a[j])%2) win = true ;
				else loose = true ;
			}
			break ;
		}
		if(win) {
			cout << "WIN\n" ;
		}
		else if(loose){
			cout << "LOSE\n" ;
		} else {
			cout << "DRAW\n" ;
		}
	}
	return 0 ;
}

