#include <iostream>
using namespace std;
int main() {
  int mem;
  int flag=1,ps;
  cout<<"Enter the memory\n";
  cin>>mem;
  while(flag){
    cout<<"\nEnter the process size:";
    cin>>ps;
    if(mem-ps>=0)
      mem=mem-ps;
    else{
      cout<<"\nThe external fragmentation is "<<mem;
      flag=0;
    }
  }
  return 0;
}