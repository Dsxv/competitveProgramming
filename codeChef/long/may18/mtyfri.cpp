#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int  t;
	cin >> t ;
	while(t--){
		int n ,  k ;
		cin >> n >> k ;
		vector<int> a , b ;
		for(int i = 0 ; i < n ; i++){
			int x ;  cin >> x ;
			if(i%2 == 0) a.push_back(x) ;
			else b.push_back(x) ;
		}
		sort(a.begin(), a.end()) ;
		sort(b.begin(), b.end()) ;
		int l = a.size() - 1 ;
		for(int i = 0 ; i < min(k,(int)b.size()) ; i++){
				if(l < 0) break ;
				if(b[i] >= a[l]) break ;
				swap(a[l--],b[i]) ;
		}
		if(accumulate(a.begin(),a.end(),0) < accumulate(b.begin(),b.end(),0)){
				cout << "YES\n" ;
		} else {
				cout << "NO\n" ;
		}
	}
	return 0 ;	
}

