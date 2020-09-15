#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 5e5 + 10 , mod = 998244353 ;
int fact[N] ;


int32_t main(){
	fact[0] = 1 ;
	for(int i = 1 ; i <  N ; i++){
		fact[i] = (i*fact[i-1]) % mod ;
	}
	int n ; 
	cin >> n ;
	map<int,int> mp1 , mp2;
	map<pair<int,int> , int> mp12 ;
	vector<pair<int,int>> v ;
	for(int i = 0 ; i < n ; i++){
		int f , s ;
		cin >> f >> s ;
		v.push_back({f,s}) ;
		mp1[f]++ ; mp2[s]++ ;
		mp12[{f,s}]++ ;
	}
	int ans = fact[n] ;
	int ans1 = 1 , ans2 = 1 , ans12 = 1 ;
	for(auto i : mp1){
		ans1 = (ans1*fact[i.second]) % mod ;
	}
	for(auto i : mp2){
		ans2 = (ans2*fact[i.second]) % mod ;
	}
	for(auto i : mp12){
		ans12 = (ans12*fact[i.second]) % mod ;
	}
	sort(v.begin() , v.end() , [&]( pair<int,int> a , pair<int,int> b ){
			if(a.first != b.first) return a.first < b.first ;
			return a.second < b.second ;
			}) ;
	vector<int> temp ;
	for(auto i : v) temp.push_back(i.second) ;
	ans12 *= is_sorted(temp.begin() , temp.end()) ;
	cout << (ans - ans1 - ans2 + ans12 + 3*mod) % mod ;
	return 0 ;
}

