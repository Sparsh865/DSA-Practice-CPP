#include<bits/stdc++.h>
using namespace std;

//Count Number of Digits
// int main(){
//     int a;
//     cin>>a;
//     int count=0;
//     while(abs(a)>0){ //abs used for negative integers
//         count++;
//         a=a/10;
//     }
//     cout<<count;
//     return 0;
// }

//Revere a number
// int main(){
//     int a;
//     cin>>a;
//     int rev = 0;
//     while(abs(a)>0){ //abs used for negative integers
//         int temp = a%10;
//         rev= rev*10 + temp;
//         a=a/10;
//     }
//     cout<<rev;
// }

//Check Palindrome

// bool palindrome(int a){
//     int temp=a;
//     int rev=0;
//     while(abs(temp)>0){ //check for negative integers
//         int rem = temp%10;
//         rev=rev*10 +rem;
//         temp=temp/10;
//     }
//     if(a==rev) return true;
//     return false;
// }

// int main(){
//     int a;
//     cin>>a;
//     if(palindrome(a)) cout<<"Palindrome";
//     else cout<<"Not Palindrome";
//     return 0;
// }


//Find Greatest Common Divisor
// Euclidean Algorithm
// int gcd(int a,int b){
//     while(a>0 && b>0){
//         if(a>b) a=a%b;
//         else b=b%a;
//     }
//     if(a==0) return b;
//     return a;
// }

// int main(){
//     int a,b;
//     cin>>a>>b;
//     cout<<gcd(a,b);
// }

//Check Armstrong
// bool armstrong(int a){
//     int temp =a;
//     int sum_cubes=0;
//     while(temp>0){
//         int rem = temp%10;
//         sum_cubes= sum_cubes + pow(rem,3);
//         temp=temp/10;
//     }
//     if(a==sum_cubes) return true;
//     return false;
// }

// int main(){
//     int a;
//     cin>>a;

//     if(armstrong(a)) cout<<"Armstrong";
//     else cout<<"Not Armstrong";

//     return 0;
// }

//Prime Number

bool checkPrime(int a){
    int count=0;
    for(int i = 1;i<sqrt(a);i++){
        if(a%i==0){
            count++;
            if(a/i!=i){
                count++;
            }
        }
    }
    if(count==2){
        return true;
    }
    return false;
}

int main(){
    int a;
    cin>>a;
    if(checkPrime(a)) cout<<"Prime Number";
    else cout<<"Not Prime Number";

    return 0;
}