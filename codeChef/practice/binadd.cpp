#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		string a , b ;
		cin >> a >> b ;
		int l = max(a.size() , b.size()) ;
		b = string(l - b.size() , '0') + b ;
		a = string(l - a.size() , '0') + a ;
		vector<int> v1(l) , v2(l) ;
		for(int i = a.size() - 1 ; i >= 0 ; i--){
			v1[i] = (a[i] - '0')^(b[i] - '0') ;
			v2[i] = (a[i] - '0')&(b[i] - '0') ;
		}
		
		int ans = 0 ;
		if(count(b.begin() , b.end() , '1')) ans++ ;
		for(int i = l - 1 ; i >= 0 ; ){
			if(v2[i]){
				int cnt = 0 ;
				i-- ;
				while(i >= 0 && v1[i]){
					i-- ;
					cnt++ ;
				}
				ans = max(cnt + 2 , ans) ;
			} else i-- ;
		}
		cout << ans << '\n' ;
	}
	return 0 ;
}

