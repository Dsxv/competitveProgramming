#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	string s ;
	cin >> s ;
	vector<int> a, b; 
	for(int i = 0 ; i < s.size() ; i++){
		if(s[i] == '(') a.push_back(i) ;
		else b.push_back(i) ;
	}
	sort(b.begin(),b.end(),greater<int>()) ;
	vector<int> ans ;
	int i = 0 , j = 0 ;
	while(i < a.size() && j < b.size()){
		if(a[i] > b[j]) break ;
		ans.push_back(a[i]) ;
		ans.push_back(b[j]) ;
		i++ , j++;
	}
	sort(ans.begin(),ans.end()) ;
	if(ans.size() == 0){
		cout << 0 ;
		return 0 ;
	}
	cout << 1 << endl <<(int)ans.size() << endl;
	for(auto i : ans) cout << i+1 <<" " ;
	return 0 ;
}

