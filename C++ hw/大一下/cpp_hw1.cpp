#include<iostream>
#include<cstring>
using namespace std;
int iexc(int&a,int&b){
	int t;
		t=a;
		a=b;
		b=t;	
	} 


char cexc(char*a,char*b){					
	char t[10];
	strcpy(t,a);
	strcpy(a,b);
	strcpy(b,t);
}


int main(){
	int num[10];
	char name[10][10];
	char n;
	int pg[10];
	int rw[10];
	for(int j=0;j<10;j++){											 
		cout<<"�п�J�y��"<<endl;
		cin>>num[j];
		cout<<"�п�J�m�W"<<endl;
		while(getchar()!='\n');				 
		cin.getline(name[j],10);			
		cout<<"�п�J�{���]�p���Z"<<endl;
		cin>>pg[j];
		cout<<"�п�J�\Ū�P�g�@���Z"<<endl;
		cin>>rw[j];
		if(num[j]<0||pg[j]>100||pg[j]<0||rw[j]>100||rw[j]<0){
			cout<<"��J���~�A�Э��s��J"<<endl;
			j=j-1;
		}
		}
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			if(num[j]>num[j+1]){
				iexc(num[j],num[j+1]);
				iexc(pg[j],pg[j+1]);
				iexc(rw[j],rw[j+1]);
				cexc(name[j],name[j+1]);
			}
			
			
		}
		
	}	
		
		
		
	cout<<"�y��"<<"\t"<<"�W�r"<<"\t"<<"�{���]�p���Z"<<"\t"<<"�\Ū�P�g�@���Z"<<endl;
	for(int i=0;i<5;i++){												
		cout<<num[i]<<"\t"<<name[i]<<"\t"<<pg[i]<<"\t"<<rw[i]<<endl;	
		
	}


	}
	

