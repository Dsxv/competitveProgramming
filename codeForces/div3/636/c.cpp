#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		int a[n] ;
		for(int i = 0 ; i < n ; i++) cin >> a[i] ;
		vector<int> v ;
		v.push_back(a[0]) ;
		for(int i = 1 ; i < n ; i++){
			if(a[i] > 0 && v.back() > 0 || (a[i] < 0 && v.back() < 0)){
				int x = v.back() ;
				v.pop_back() ;
				v.push_back(max(a[i],x))  ;
			} else {
				v.push_back(a[i]) ;
			}
		}
		cout << accumulate(v.begin() , v.end() , 0LL) << '\n' ;
	}
	return 0 ;
}

