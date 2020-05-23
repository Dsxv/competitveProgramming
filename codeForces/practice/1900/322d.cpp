#include <bits/stdc++.h>
using namespace std ;

#define int long long
int n , m ;

bool ok(vector<int> atk , vector<int> def , vector<int> a){
	vector<pair<int,int>> t ;
	if(m < n) return 0 ;
	for(auto i : atk) t.push_back({i,0}) ;
	for(auto i : def) t.push_back({i,1}) ;
	sort(t.begin(),t.end(),greater<pair<int,int>>()) ;
	sort(a.begin(),a.end(),greater<int>()) ;
	for(int i = 0, j = 0; i < m && j < n ; i++){
		if(a[i] >= (t[j].first + t[j].second)) j++ ;
		else return 0 ;
	}
	return 1 ;
}

int32_t main(){
	cin >> n >> m ;
	vector<int> atk , def ;
	for(int i = 0 ; i < n ; i++){
		string s ;
		int n ;
		cin >> s >> n ;
		if(s == "ATK") atk.push_back(n) ;
		else def.push_back(n) ;
	}
	vector<int> a(m) ;
	for(int i = 0 ; i < m ; i++) cin >> a[i] ;
	int val = 0;
	if(ok(atk,def,a)){
		multiset<int> s(a.begin(),a.end()) ;
		for(auto i : def){
			s.erase(s.upper_bound(i)) ;
		}
		//for(auto i : s) cout << i << " " ;
		vector<int> rem(s.begin(),s.end()) ;
		val = accumulate(rem.begin() , rem.end() , 0LL) - accumulate(atk.begin() , atk.end(), 0LL) ;
	} 
	sort(atk.begin() , atk.end()) ;
	sort(a.begin() , a.end() , greater<int>()) ;
	int l = min(atk.size() , a.size()) ;
	int ans = 0 ;
	for(int i = 0 ; i < l ; i++) ans += max(0LL,a[i] - atk[i]) ;
	cout << max(val,ans) ;
	return 0 ;
}

