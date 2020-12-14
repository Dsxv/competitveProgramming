#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		int temp = n ;
		int l = sqrt(n) ;
		int mxc = 0 , mxi = -1 ;
		for(int i = 2 ; i <= l ; i++){
			int cnt = 0 ;
			while(n % i == 0){
				n /= i ;
				cnt++ ;
			}
			if(cnt > mxc) {
				mxc = cnt ;
				mxi = i ;
			}
		}
		if(n > 1){
			int cnt = 1 ;
			if(cnt > mxc){
				mxc = cnt ;
				mxi = n ;
			}
		}
		vector<int> ans ;
		for(int i = 0 ; i < mxc ; i++){
			ans.push_back(mxi) ;
			temp /= mxi ;
		}
		ans[0] *= temp ;
		reverse(ans.begin() , ans.end()) ;
		cout << mxc << '\n' ;
		for(auto i : ans) cout << i << " " ;
		cout << endl ;
	}
	return 0 ;
}

