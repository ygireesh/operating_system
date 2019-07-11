#include <iostream>
using namespace std;

int main() {
  int mem,i;
  cout<<"\nEnter the total available memory:\n";
  cin>>mem;
  cout<<"\nEnter the block size!";
  int bs;
  cin>>bs;
  int np;
  cout<<"\nEnter the number of processes";
  cin>>np;
  if(np*bs>mem){
    cout<<"\nSorry!!!!";
  }
  else{
  int p[np];
  int ifn=0,ef=0;
  cout<<"Enter the "<<np<<"number of processes!";
  for(i=0;i<np;i++){
    cin>>p[i];
    if(p[i]<=bs){
      ifn=ifn+(bs-p[i]);
    }
    else{
      ef=ef+bs;
    }
  }
  cout<<"\nThe internal fragmentation is "<<ifn;
  cout<<"\nThe external fragmentation is "<<ef;
}
  
  return 0;
}