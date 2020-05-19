#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n , k ;
		cin >> n >> k ;
		int a[n] ;
		for(int i = 0 ; i < n ; i++) cin >> a[i] ;
		if(count(a,a+n,k) == 0){
			cout << "no\n" ;
			continue ;
		}
		if(n == 1){
			cout << "yes\n" ;
			continue ;
		}
		bool found = false ;
		for(int i = 0 ; i < n ; i++){
			if(a[i] >= k){
				if(i){
					if(a[i-1] >= k){
						found = true ;
						break ;
					}
				}
				if(i < n -1){
					if(a[i+1] >= k){
						found = true ;
						break ;
					}
				}
			}
		}
		int l = count(a,a+n,k) ;
		if(n > 2){
			for(int i = 0 ; i < n - 2 ; i++){
				vector<int> v ;
				for(int j = i ; j < i + 3 ; j++) v.push_back(a[j]) ;
				sort(v.begin(),v.end()) ;
				if(v[1] >= k){
					if(v[0] == k && l == 1) continue ;
					found = true ;
				}
			}
		}
		cout << (found?"yes\n":"no\n") ;
	}
	return 0 ;
}

