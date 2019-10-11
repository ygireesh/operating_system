#include<stdio.h>
#include<iostream.h>
#include<conio.h>
#include<string.h>

int it;          //input string's trigger
char stac[4];   
char str[3]; 
int tos=0;      //top of the stack

void push(char a){
       tos=tos+1;
       stac[tos]=a;
}

void pop(){
	tos=tos-1;
}

void reduce(){
	if(stac[tos]=='S'){
		if(str[it]=='a'){
			pop();
			push('A');
			push('a');
		}
		else if(str[it]=='b'){
			pop();
			push('b');
		}
	}

	else if(stac[tos]=='A'){
		pop();
		push('a');
	}
}

void print(){
	int i;
	cout<<"\n   ";
	for(i=0;i<=tos;i++){
		cout<<stac[i];
	}
	cout<<"   ";
	for(i=it;i<=strlen(str);i++){
		cout<<str[i];
	}
}

int main(){
  clrscr();
  stac[0]='$';
  stac[1]='S';
  tos=1;
  cout<<"Enter a string :  ";
  cin>>str;
  if(strlen(str)>2){
	cout<<"\n can't parse the string !!!";
	return 0;
  }
  str[strlen(str)]='$';
  it=0;
  cout<<"\n The Parsing goes like this : ";
  print();
  while(!((stac[tos]=='$')&&(str[it]=='$')))
	{
	if((stac[tos]=='S')&&((str[it]=='a')||(str[it]=='b'))){
		reduce();
		print();
	}
	else if((stac[tos]=='A')&&(str[it]=='a')){
		reduce();
		print();
	}
	else if(stac[tos]==str[it]){
		pop();
		it=it+1;
		print();
	}
	else{
		cout<<"\n can't parse the string !!!";
		return 0;
	}
  }
  cout<<"\nString is successfully Parsed";// the strings which can be parsed for this grammar i.e., s->Aa/b , A->a are "aa" and "b"
  return 0;
}
