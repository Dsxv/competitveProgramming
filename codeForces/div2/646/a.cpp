#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n , xx;
		cin >> n >> xx;
		int odd  = 0 , even = 0 ;
		for(int i = 0 ; i < n ; i++){
			int x ;
			cin >> x ;
			if(x&1) odd++ ;
			else even++ ;
		}
		if(odd == 0 || (xx%2 == 0 && even == 0)){
			cout << "No\n" ;
			continue ;
		}
		if(odd%2 == 0) odd-- ;
		xx -= odd ;
		if(even < xx){
			cout << "No\n" ;
		} else {
			cout << "Yes\n" ;
		}
	}
	return 0 ;
}


