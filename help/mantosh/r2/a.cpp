#include <bits/stdc++.h>
using namespace std ;

char * contains(char *input1 , char *input2){
	char *p = strstr(input1 , input2) ;
	char *ans ;
	if(p){
		ans = new char[3] ;
		ans[0] = 'y' , ans[1] = 'e' , ans[2] = 's' ;
	} else {
		ans = new char[2] ;
		ans[0] = 'n' , ans[1] = 'o' ;
	}
	return ans ;
}

int32_t main(){
	char a[] = "abab" , b[] = "baaa" ;
	cout << contains(a , b) ;
	return 0 ;
}

