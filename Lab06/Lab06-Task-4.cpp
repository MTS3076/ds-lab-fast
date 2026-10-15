#include<iostream>
using namespace std;

int amount(int n){
	if (n==1){
		return 10;
	}
	return 2 * amount(n-1);
}
int main(){
	cout <<	amount(5);	
}
