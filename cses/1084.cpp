#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n , m , k ;
	cin >> n >> m >> k ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	multiset<int> s ;
	for(int i = 0 ; i < m ; i++){
		int x ;
		cin >> x ;
		s.insert(x) ;
	}
	sort(a,a+n);
	int cnt = 0 ;
	for(int i = 0 ; i < n ; i++){
		int val = a[i] - k ;
		while(s.size() && val > *(s.begin())) {
			s.erase(s.begin()) ;
		}
		if(s.size() && (a[i] + k >= *(s.begin()))){
			s.erase(s.begin()) ;
			cnt++ ;
		}
	}
	cout << cnt ;
	return 0 ;
}

