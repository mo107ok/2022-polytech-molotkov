#include <iostream> 
#include <iostream>
#include <string.h>
using namespace std;
 bool palindrom(char s[]);
int main() 
{   
    char txt[100];
    cout << "введите строку" << endl; 
    cin.getline(txt, 100);
    if(palindrom(txt))
       cout << "является палиндромом " << endl;
   else
       cout << "не является палиндромом " << endl;
    return 0;
}
 bool palindrom(char s[])
{
   int n = strlen(s); 
   bool k =true;
   for (int i = 0;  i < n / 2; i++ )
  {
      if(s[i]!=s[n-1-i])
      {
           k=false;
           break;
      }
  }
  return k;
}
