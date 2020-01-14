#include <bits/stdc++.h>
using namespace std ;

#define int long long
map<string,int> mp ;
vector<string> ans ;
stack<string> temp ;

string convert(int* a , int l){
	string s = "" ;
	for(int i = l-1 ; i >= 0 ; i--){
		string t(1,'a'+a[i]-1) ;
		s += t ;
	}
	return s ;
}

void solve(vector<string>& v , int count){
	int x = 0 ;
	int a[10] = {0} ;
	int l = 1 ;
	int k = 0 ;
	int c = 0 ;
	for(int i = 0 ; i < count ;){
		k++ ;
		if(k > pow(26,l)) l++ ;
		int c = 1 ;
		for(int j = 0; j < 10 ; j++){
			if(c == 0) break ;
			a[j] += c ;
			c = a[j]/27 ;
			a[j] %= 27 ;
			if(a[j] == 0) a[j] = 1 ;
		}
		string s = convert(a,l) ;
		if(!mp.count(s)){
			temp.push(s) ;
			mp[s] = 1;
			i++ ;
		}
	}
}

int32_t main(){
	int n;
	cin >>  n;
	vector<string> v ;
	for(int i = 0 ; i < n ; i++){
		string s ;
		cin >> s ;
		ans.push_back(s) ;
		if(s != "?") v.push_back(s) ;
	   mp[s] = 1 ;
	}
	solve(v,n-v.size()) ; 	
	for(auto i : ans) {
		if(i == "?"){
			cout << temp.top() << '\n' ;
			temp.pop() ;
		} else {
			cout << i << '\n' ;
		}
	}
	return 0 ;
}

