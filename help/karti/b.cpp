include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	string s , t ;
	getline(cin , s) ;
	getline(cin , t) ;
	istringstream temp(s) , temp2(t) ;
	map<string,int> mp1 , mp2 ;
	string word ;
	while(temp >> word){
		mp1[word]++ ;
	}
	while(temp2 >> word){
		mp2[word]++ ;
	}

	for(auto i : mp1){
		if(mp2.count(i.first)) continue ;
		cout << i.first ;
		return 0;
	}
	return 0 ;
}
