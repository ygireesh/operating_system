#include<stdio.h>
#include<iostream.h>
#include<conio.h>
#include<string.h>

int it;          //input string's trigger
char stac[4];
char str[3];
int tos=0;

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

void printyaa(){
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
  cout<<"ENTER A STRING :  ";
  cin>>str;
  if(strlen(str)>2){
	cout<<"CAN'T PARSE";
	return 0;
  }
  str[strlen(str)]='$';
  it=0;
  cout<<"\n THE PARSING IS ";
  printyaa();
  while(!((stac[tos]=='$')&&(str[it]=='$')))
	{
	if((stac[tos]=='S')&&((str[it]=='a')||(str[it]=='b'))){
		reduce();
		printyaa();
	}
	else if((stac[tos]=='A')&&(str[it]=='a')){
		reduce();
		printyaa();
	}
	else if(stac[tos]==str[it]){
		pop();
		it=it+1;
		printyaa();
	}
	else{
		cout<<"\ncan't parse dudu";
		return 0;
	}
  }
  cout<<"\nSTRING SUCESSFULLY PARSED";// the strings that can parse are 'aa' and 'b' for this grammar
  return 0;
}