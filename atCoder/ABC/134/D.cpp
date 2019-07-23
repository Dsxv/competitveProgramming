#include <bits/stdc++.h>
using namespace std ;

using pii = pair<int,int> ;
using pll = pair<long,long> ;
using umpii = unordered_map<int,int> ;
using mpii = map<int,int> ;

#define f first
#define s second

int32_t main(){
	int n ;
	cin >> n ;
	int a[n+1] ; bool ans[n+1] = {0} ;
	for(int i = 1 ; i <= n ; i++) cin >> a[i] ;
	for(int i = n ; i >= 1 ; i--){
		int sum = 0 ;
		for(int j = 2*i ; j <= n ; j += i){
			sum += ans[j] ;
		}
		if(sum%2 != a[i]) ans[i] = 1 ;
	}
	vector<int> v ;
	for(int i = 1 ; i <= n ; i++) if(ans[i]) v.push_back(i) ;
	cout << v.size() << endl ;
	for(auto i : v) cout << i <<" " ;
	return 0 ;
}

