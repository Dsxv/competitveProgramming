#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		vector<int> a[n] ;
		for(int i = 0 ; i < n ; i++){
			int k ;
			cin >> k ;
			a[i].resize(k) ;
			for(int j = 0 ; j < k ; j++){
				cin >> a[i][j] ;
				a[i][j]-- ;
			}
		}
		set<int> s ;
		for(int i = 0 ; i < n ; i++) s.insert(i) ;
		int pp[n] = {} ;
		for(int i = 0 ; i < n ; i++){
			bool found = false ;
			for(int j = 0 ; j < a[i].size() ; j++){
				if(found) break ;
				if(s.count(a[i][j])){
					pp[i] = 1 ;
					s.erase(a[i][j]) ;
					found = true ;
				}
			}
		}
		if(s.size() == 0){
			cout << "OPTIMAL\n" ;
			continue ;
		} 
		int a1 , a2 ;
		for(int i = 0 ; i < n ; i++){
			if(!pp[i]){
				a1 = i+1 ;
				a2 = (*s.begin()) + 1 ;
			}
		}
		cout << "IMPROVE\n" ;
		cout << a1 << " " << a2 << endl ;
	}
	return 0 ;
}

