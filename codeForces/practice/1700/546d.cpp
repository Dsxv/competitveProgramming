#include <bits/stdc++.h>
using namespace std ;

const int N = 5e6 + 10 ;
vector<int> v[N] ;

int count(int n){
	int sum = 0 ;
	for(auto i : v[n]){
		while(n%i == 0){
			n/=i ;
			sum++ ;
		}
	}
	return sum ;
}
int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	for(int i = 2 ; i < N ; i++){
		if(v[i].size() == 0){
			v[i].push_back(i) ;
			for(int j = 2*i ; j < N ; j += i){
				v[j].push_back(i) ;
			}
		}
	}
	int ans[N] = {} ;
	for(int i = 2 ; i < N ; i++){
		ans[i] = count(i) + ans[i-1] ;
	}
	int t ;
	cin >> t ;
	while(t--){
		int a , b ;
		cin >> a >> b ;
		cout << ans[a] - ans[b] << '\n' ;
	}
	return 0 ;
}

