#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n ;
	cin >> n;
	pair<int,int> a[n] , b[n] ;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i].first >> b[i].first ;
		a[i].second = i , b[i].second = i ;
	}
	set<int> s ;
	for(int i = 1 ; i <= n ; i++) s.insert(i) ;
	sort(a,a+n) ;
	sort(b,b+n) ;
	int ans[n] ;
	int i = 0 , j = 0 ;
	while(i < n && j < n){
		if(a[i].first <= b[j].first){
			ans[a[i].second] = *s.begin() ;
			s.erase(s.begin()) ;
			i++ ;
		} else {
			s.insert(ans[b[j].second]) ;
			j++ ;
		}
	}
	cout << *max_element(ans , ans+n) << '\n' ;
	for(auto i : ans) cout << i << " " ;
	return 0 ;
}

