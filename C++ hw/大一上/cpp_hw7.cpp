#include<iostream>
#include<stdlib.h>
#include<time.h> 
using namespace std;
int menu(int&y){
	cout<<"\t��l�C��"<<endl;
	cout<<"1.��j\n2.��p\n3.���}\n�п��"<<endl;
	cin>>y;
	while(y>3||y<1){ 
		cout<<"�Э��s��J"<<endl;  
		cout<<"1.��j\n2.��p\n3.���}\n�п��"<<endl;
	 	cin>>y;
	} 
}
game(int&x){
	int p,c,w;
	p=(rand()%6)+1;
	c=(rand()%6)+1;
	if (x==1){
		cout<<"�A���Ʀr��"<<p<<endl;
		 cout<<"�q�����Ʀr��"<<c<<endl;
		if(p>c)
		 cout<<"�AĹ�F\n";
		if(c>p)
	 	 cout<<"�A��F\n";
		if(c==p)
		 cout<<"����\n"; 
	}
	if (x==2){
		cout<<"�A���Ʀr��"<<p<<endl;
	 	cout<<"�q�����Ʀr��"<<c<<endl;
		if(p<c)
	 	cout<<"�AĹ�F\n";
		if(c<p)
		cout<<"�A��F\n";
		if(c==p)
		cout<<"����\n";
	}
}

int main(){	
	srand(time(NULL));
	int m=1;
	while(1){
		menu(m);
		if (m==3){ 
	    	cout<<"�A��"<<endl;
		    break;
		} 
		
		game(m);
		system("pause");
	}
}

