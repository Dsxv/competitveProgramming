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
	int a[n] , count = 0 ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	for(int i = 0 ; i < n - 2 ; i++){
		vector<int> x ;
		for(int j = i ; j < i + 3 ; j++){
			x.push_back(a[j]) ;
		}
		sort(x.begin() , x.end()) ;
		if(x[1] == a[i+1]) count++ ;
	}
	cout << count ;
	return 0 ;
}

