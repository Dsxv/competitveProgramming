#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		string a , b ;
		cin >> a >> b ;
		int x = a.size() , y = b.size() ;
		int ind = -1 ;
		int l = min(x,y) ;
		bool check = false ;
		for(int i = 0 ; i < l ; i++){
			if(a[i] > b[i]){
				ind = i ;
				break ;
			}else if(a[i] < b[i]){
				check = true ;
				break ;
			}
		}
		if(ind == -1) {
			if(x < y) check = true ;
			else ind = y -1 ;
		}
		if(check){
			cout << a << '\n';
		} else {
			bool ok = false ;
			for(int i = ind + 1 ; i < x ; i++){
				if(a[i] < b[ind]) {
					ok = true ;
					swap(a[i],a[ind]) ;	
					break ;
				}
			}
			if(!ok) cout << "---\n" ;
			else cout << a << '\n' ;
		}
	}

	return 0 ;
}

