#include <bits/stdc++.h>
using namespace std ;

using pii = pair<int,int> ;
using pll = pair<long,long> ;
using umpii = unordered_map<int,int> ;
using mpii = map<int,int> ;
#define int long long
#define f first
#define s second

int32_t main(){
	int n ;
	cin >> n ;
	pii a[n] ;
	for(int i = 0 ; i < n ; i++) cin >> a[i].s >> a[i].f ;
	sort(a,a+n) ;
	int sum = 0 ;
	for(auto i : a ){
		sum += i.s ;
		if(sum > i.f){
			cout << "No" ;
			return 0 ;
		}
	}
	cout << "Yes" ;
	return 0 ;
}

