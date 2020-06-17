#include <bits/stdc++.h>
using namespace std ;

class CutTheCube{
	public :
	int findWinner(int L , int B , int H){
			if(L%2 == 0 || B % 2 == 0 || H % 2 == 0) return 1 ;
			else return 2 ;
		}
} ;

