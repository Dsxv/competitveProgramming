#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n ;
	cin >> n ;
	vector<int> a(n) , b(n) ;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i] >> b[i] ;
	}
	sort(a.begin() , a.end()) ;
	sort(b.begin() , b.end()) ;
	int i = 0 , j = 0 ;
	int ans = 0 , cur = 0 ;
	while(i < n && j < n){
		if(a[i] < b[j]){
			i++ ;
			cur++ ;
		} else {
			j++ ;
			cur-- ;
		}
		ans = max(ans , cur) ;
	}
	cout << ans ;
	return 0 ;
}

