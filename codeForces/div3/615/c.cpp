#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(map<int,int>& mp , int n){
	int t =  n;
	while((n%2) == 0) {
		mp[2]++ ;
		n /=2 ;
	}
	int l = sqrt(n) ;
	for(int i = 3 ; i <=  l ; i+= 2){
		while(n%i == 0){
			mp[i]++ ;
			n/=i;
		}
	}
	if(n > 1) mp[n]++ ;
	vector<int> v ;
	for(auto i : mp){
		for(int j = 0 ; j < i.second ; j++) v.push_back(i.first) ;
	}
	int a = v[0] , b = 1 , c = 1;
	for(int i = 1; i < v.size() ; i++){
		b *= v[i] ;
		int x = (t/(a*b)) ;
		if(a == b || b == x || x == a) continue ;
		else { c = x ; break ; }
	}
	if(c == 1) {cout << "NO" ; return ;}
	cout <<"YES\n"<< a << " " << b << " " << c ;
}
int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		map<int,int> mp;
		solve(mp,n) ;
		cout << endl ;
	}
	return 0 ;
}

