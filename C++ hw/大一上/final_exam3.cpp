#include<iostream>
#include<stdlib.h>
#include<time.h> 
using namespace std;
int menu(){
	int y;
	cout<<"�п�ܤU�C������"<<endl;
	cout<<"1.������l�I��\n2.����5�Ӥ���100��200����5������\n3.�q�j�ܤp\n0.���}\n�п��(1,2,3,0)"<<endl;
	cin>>y;
	while(y>3||y<0){ 
		cout<<"��J���~�A�Э��s��J"<<endl;  
		cout<<endl;  
		cout<<"�п�ܤU�C������"<<endl;
		cout<<"1.������l�I��\n2.����5�Ӥ���100��200����5������\n3.�q�j�ܤp\n0.���}\n�п��(1,2,3,0)"<<endl;
	 	cin>>y;
		}	 
	return y;
	}


void sort1(int*x){
	int t;
	int j=0;
	for(int i=0;i<5;i++){
		for(j=0;j<5;j++){
			if(x[j]<x[j+1]){	
				t=x[j];
				x[j]=x[j+1];
				x[j+1]=t;
			}
		}
	}
}

void dice(){
	int d;
	d=(rand()%6)+1;
	cout<<"��l�I�Ƭ� "<<d<<endl; 
	cout<<endl;
}

void option2(int*a){
	int s;
	for(int i=0;i<5;i++){
	s=5*(rand()%20)+100;
	a[i]=s;
	for(int j=0;j<i;j++)
	    if(a[i]==a[j]){
            i--;
             }
	}
	cout<<"�����X�������ƼƦr�� "; 
	for(int i=0;i<5;i++){
	cout<<a[i]<<" ";
	}
	cout<<endl;
	cout<<endl;
}


int main(){
	srand(time(NULL));	
	int a[5];	
	int o;
	o=menu();
	while(o!=0){
	switch(o)
	{	case 1 :
		dice();
		break;
		case 2 :
		option2(a);
		break;
		case 3:
		sort1(a);
		cout<<"�Ƨǧ��� ";
		for(int i=0;i<5;i++){
		cout<<a[i]<<" ";
	}

		break;
		default:
		break;
	}
	o=menu();
}
	cout<<"�A��"<<endl;  
}

