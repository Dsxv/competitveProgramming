#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int q ;
	cin >> q ;
	while(q--){
		int n ;
		cin >> n ;
		int a[n] ;
		for(int i = 0 ; i < n ; i++) cin >> a[i] ;
		int ind = 0 ;
		for(int i = 1 ; i < n ; i++){
			int pos = -1 ;
			for(int j = ind ; j < n ; j++){
				if(a[j] == i) {
					pos = j ; break ;
				}
			}
			if(pos == ind){
				ind++ ;
				continue ;
			}
			if(pos != -1){
				for(int j = pos ; j > ind ; j--){
					swap(a[j],a[j-1]) ;
				}
				ind = pos ;
			}
		}
		for(auto i : a) cout << i <<" " ;
		cout << '\n' ;
	}
	return 0 ;
}

