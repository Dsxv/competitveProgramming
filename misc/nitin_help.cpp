#include <bits/stdc++.h>
using namespace std ;

#define int long long
int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		pair<int,int> a[n] ;
		for(int i = 0 ; i < n ; i++){
			cin >> a[i].first ;
			a[i].second = i + 1 ;
		}
		sort(a,a+n) ;
		int count = 0 , val = 0 ;
		for(int i = 0 ; i < n ; i++){
				if(a[i].first >= val){
					double amt = a[i].first - val + 1 ;
					int cnt = ceil(amt/a[i].second) ;
					count += cnt ;
					val += cnt*a[i].second ;
				}
		}
		cout << count << endl;
	}
	return 0 ;
}

