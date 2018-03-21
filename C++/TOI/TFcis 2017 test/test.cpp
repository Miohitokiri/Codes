#include<bits/stdc++.h>
using namespace std;
int main ()
{
  string str ="This is a simple string";
  char * pch;
  /* 找尋 simple 字串 */
  pch = strstr (str,"simple");
  cout << *pch << endl;
  return 0;
}