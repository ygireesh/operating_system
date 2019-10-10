#include<stdio.h>
#include<conio.h>
int box[3];
int bf[3]={3,2,1};

int in(int a){
	int i;
	for(i=0;i<3;i++){
		if(box[i]==a){
			return 1;
		}
	}
	return 0;	
}

int findmax(){
	int i,max=bf[0];
	int maxi=0;
	for(i=1;i<3;i++){
        if(bf[i]>max){
           max=bf[i];
           maxi=i;
		}	
	}
	return maxi;
}

int reset(int index){
	bf[index]=0;
}

int increment(){
	int i;
	for(i=0;i<3;i++){
		bf[i]=bf[i]+1;
	}
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
	box[0]=pages[0];box[1]=pages[1];box[2]=pages[2];
 	int target;
 	for(i=3;i<np;i++){
 		if(in(pages[i])){
 			phits++;
		 }
		 else{
		 	pfaults++;
		 	target=findmax();
		 	box[findmax()]=pages[i];
		 	reset(target);
		 	increment();
		 }	
	 }
	 
	printf("\n THE PAGE HITS ARE %d and page faults are %d",phits,pfaults);
	return 0;
}
