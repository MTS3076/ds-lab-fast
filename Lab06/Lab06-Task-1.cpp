#include<iostream>
using namespace std;

void reverse(string str,int n){
	if (n==0){
		return;
	}
	cout<<str[n-1];
	reverse(str,n-1);
}
int main(){
	reverse("Hello",5);
	
}
