#include<iostream>
#include<stdlib.h>
#include<time.h> 
using namespace std;
int menu(){
	int y;
	cout<<"�п�ܤU�C������"<<endl;
	cout<<endl;  
	cout<<"1.������l�I��\n2.����5�Ӥ���100��200����5������\n3.�q�j�ܤp\n0.���}\n�п��(1,2,3,0)"<<endl;
	cin>>y;
	while(y!=0){
	while(y>3||y<0){ 
		cout<<"��J���~�A�Э��s��J"<<endl;  
		cout<<endl;  
		cout<<"�п�ܤU�C������"<<endl;
		cout<<"1.������l�I��\n2.����5�Ӥ���100��200����5������\n3.�q�j�ܤp\n0.���}\n�п��(1,2,3,0)"<<endl;
	 	cin>>y;
		}	 
	while(y<=3&&y>=1){
		cout<<"�п�ܤU�C������"<<endl;
		cout<<endl;
		cout<<"1.������l�I��\n2.����5�Ӥ���100��200����5������\n3.�q�j�ܤp\n0.���}\n�п��(1,2,3,0)"<<endl;
		cin>>y;
		}
	}
	cout<<"�A��"<<endl;  
}

int main(){	
	menu();
	

}

