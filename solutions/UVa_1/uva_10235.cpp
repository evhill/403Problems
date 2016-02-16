/* UVa problem: 10235 - Simply Emirps
 * Topic: Number Theory
 *
 * Brief problem description: 
 *   Reverse a prime and see if that number is  prime.
 *
 * Solution Summary:
 *   Reversed the number with some simple arithmetic operations using this logic: 
 *   you find the remainder of a number when you % 10 it which decreases the number 
 *   by a decimal place (17%10 -> 7). Now you multiply a new number (reverse) by 10 
 *   to increase the decimal and add the remainder onto the end. Then you divide the 
 *   original number by 10 and repeat this until your original number is 0. 
 *   
 *   ex) num=17, remainder=17%10=7, reverse=0*10=0+7 = 7, 17/10=1, 1%10 = 1, 
 *   reverse = 7*10=70+1=71, 1/10 = 0 done
 *
 */

#include <iostream>
using namespace std;

#define ONEPRIME 0

//UALBERTA Code Archive
int isPrime(int x){
  int i;
  if( x == 1 ) return ONEPRIME;
  if( x == 2 ) return 1;
  if( x % 2 == 0) return 0;

  for(i = 3; i*i <= x; i+=2)
    if( x % i == 0) return 0;
  return 1;
}

int reverseInt(int num){
	int remainder=0, reverse=0;
	while(num > 0){
		remainder = num % 10;
		reverse = (reverse*10) + remainder;
		num/=10;
	}
	return reverse;
}

int main(){
  int x=0;
  int a=0;
  while(cin >> x){
	  if(isPrime(x)){
		  a = reverseInt(x);
		  //if prime and not the same number once reversed
		  if(isPrime(a) && (a != x)){
			  cout << x << " is emirp." << endl;
		  } else{
			  cout << x << " is prime." << endl;
		  }
	  }
	  else {
		  cout << x << " is not prime." << endl;
	  }
  }
  return 0;
}


