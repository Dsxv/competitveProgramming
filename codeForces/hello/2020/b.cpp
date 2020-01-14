#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n ; cin >> n ;
	vector<int> a , b ;
	int ans = 0 ;
	while(n--){
		int k ;
		cin >> k ;
		int ar[k] ;
		for(int i = 0 ; i < k ; i++) cin >> ar[i] ;
		int x1 = *max_element(ar,ar+k) , x2 = *min_element(ar,ar+k) ;
		a.push_back(x1) ;
		b.push_back(x2) ;
		ans += x1 > x2 ;
	}
	sort(b.begin(),b.end()) ;
	for(auto i : b) cout << i << " " ;
	cout << endl ;
	for(auto i : a){
		int x = upper_bound(b.begin(),b.end(),i-1) - b.begin() ;
		cout << i << ":" << x << endl ;
		ans += x ;
	}
	cout << ans ;
	return 0 ;
}

