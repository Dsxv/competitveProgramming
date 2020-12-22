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
		int sum = accumulate(a , a + n , 0LL) ;
		int l = sqrt(sum) ;
		vector<int> v ;
		for(int i = 1 ; i <= l ; i++){
			if(sum % i) continue ;
			if(i * i == sum){
				v.push_back(i) ;
			} else {
				v.push_back(i) ;
				v.push_back(sum / i) ;
			}
		}
		sort(v.begin() , v.end()) ;
		for(int i = 0 ; i < v.size() ; i++){
			int csum = 0 ;
			bool found = true ;
			int cnt = 0 ;
			for(int j = 0 ; j < n ; j++){
				csum += a[j] ;
				if(csum > v[i]) {
					found = false ;
				}
				if(csum == v[i]){
					csum = 0 ;
					cnt++ ;
				}
			}
			if(found){
				cout << n - cnt << '\n' ;
				break ;
			}
		}
	}
	return 0 ;
}

