#include<stdio.h>
#include<conio.h>
int box[3];

int in(int a){
	int i;
	for(i=0;i<3;i++){
		if(box[i]==a){
			return 1;
		}
	}
	return 0;	
}


int main(){
	int np,ntp,i;
	printf("Enter the number of pages:");
	scanf("%d",&np);
	int pages[np];
	printf("Enter the number of types of pages");
	scanf("%d",&ntp);
	int tpages[ntp];
	printf("Enter the %d types of pages",ntp);
	for(i=0;i<ntp;i++){
		scanf("%d",&tpages[i]);
	}
	printf("\n Enter the %d pages:",np);
	for(i=0;i<np;i++){
		scanf("%d",&pages[i]);
	}
	int pfaults=3,phits=0;
	int trig=-1;
	box[0]=pages[0];box[1]=pages[1];box[2]=pages[2];
	for(i=3;i<np;i++){
		if (in(pages[i])){
			phits+=1;
		}
		else{
			box[(trig++)%3]=pages[i];
			pfaults++;
		}	
	}
	printf("\n THE PAGE HITS ARE %d and page faults are %d",phits,pfaults);
	return 0;
}
