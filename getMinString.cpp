#include<bits/stdc++.h>
using namespace std;

int main(){
  string s="bbcad";
  int iterator=0;
   while(iterator<s.length() and s[iterator]=='a'){
    iterator++;
  }
  while(iterator<s.length() and s[iterator]!='a'){
      s[iterator]=s[iterator]-1;
      iterator++;
  }
  cout<<s;
}
