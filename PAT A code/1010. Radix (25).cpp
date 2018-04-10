//一下代码来自网络，自己写的代码总是有奇怪的问题。
#include<iostream>
#include<string>
using namespace std;
long long  Values(char c)
{
  if (c <= '9')
    return (c - '0');
  else return (c - 'a' + 10);
}
long long  dexx(string N)
{
  long long  radix =0, t2 = 0, temp = 0;
  while (N[temp])
  {
    t2 = Values(N[temp]) + 1;
    if (t2>radix)
      radix = t2;
    temp++;
  }
  return radix;
}
int CompareN(string N, long long   radix, long long  sum)
{
  long long  t2 =0, temp = 0;
  while (N[t2])
  {
    temp = temp*radix+ Values(N[t2]) ; 
    t2++;
    if (temp>sum)return 1;
  }
  if (temp == sum)return 0;
  else if (temp>sum)return 1;
  else return -1;
}
int main()
{
  int tag;
  long long  temp;
  long long sum, radix, radix2, mid;
  bool sign;
  string N[2];
  cin >> N[0] >> N[1] >> tag >> radix;
  tag--; 
  sum = 0;
  temp = 0;
  while (N[tag][temp])
  {
    sum = sum*radix + Values(N[tag][temp]);
    temp++;
  } 
  tag = 1 - tag;
  radix = dexx(N[tag]);
  radix2 = radix>sum ? radix : sum;
  sign = true; 
  mid = radix;
  while (sign&&radix<=radix2)
  {
    temp = CompareN(N[tag], mid, sum);
    if (temp >0)
      radix2 = mid - 1;
    else if ( temp<0)
      radix = mid + 1; 
    else  
    {
      sign = false;
      radix = mid;
    } 
    mid = (radix + radix2) / 2;
  }
  if (sign)cout << "Impossible" << endl; 
  else cout << radix << endl;
  system("pause");
  return 0;
}