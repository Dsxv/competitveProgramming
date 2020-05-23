#include <bits/stdc++.h>
using namespace std ;

#define int long long

string ans = "" ;
vector<int> num;

int32_t main(){
	int a , b ;
	cin >> a >> b ;
	vector<int> v ;
	int count = 0 ;
	multiset<int,greater<int>> s ;
	while(a){
		s.insert(a%10) ;
		a /= 10 ;
	}
	while(b){
		v.push_back(b%10) ;
		b /= 10 ;
	}
	reverse(v.begin() , v.end()) ;
	if(v.size() > s.size()){
		for(auto i : s) cout << i;
		return 0 ;
	} else {
		string ans = "";
		bool oh = false;
		int x = -1 ;
		for(int i = 0 ; i < v.size() ; i++){
			if(oh) break ;
			for(auto j : s){
				if(j > v[i]) continue ;
				if(j == v[i]){
					multiset<int> temp(s.begin() , s.end()) ;
					temp.erase(temp.lower_bound(j)) ;
					bool ok = true ;
					for(int k = i + 1 ; k < v.size() ; k++){
						if((*temp.begin()) < v[k]) break ;
						if((*temp.begin()) > v[k]){
							ok = false ;
							break ;
						}
						temp.erase(temp.begin()) ;
					}
					if(ok) {
						ans += (j + '0') ;
						s.erase(s.lower_bound(j)) ;
						break ;
					}
				} else {
					oh = true ;
					x = j ;
					break ;
				}
			}
		}
		if(oh){
			s.erase(s.lower_bound(x)) ;
			vector<int> temp(s.begin() , s.end()) ;
			cout << ans << x ;
			for(auto i : temp) cout << i;
		} else {
			cout << ans ;
		}
	}
	return 0 ;
}

