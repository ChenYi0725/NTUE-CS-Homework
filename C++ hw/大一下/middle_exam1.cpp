#include<iostream>
#include<cstring>
using namespace std;

class st_node{
		int no,pg,rw,total,rk;
		char name[10];
		st_node *ptr;
	public:
		void w_no(int n){
			no=n;
		}	
		void w_pg(int n){
			pg=n;
		}
		void w_rw(int n){
			rw=n;
		}
		void w_name(char*a){   				
			strcpy(name,a);
		}
		int r_no(){
			return no;
		}
		char* r_name(){
			return name;
		}
		int r_pg(){
			return pg;
		}
		int r_rw(){
			return rw;
		}
		void w_ptr(st_node *p){
			ptr=p;
		}
		st_node*r_ptr(){
			return ptr;
		}
		int r_total(){
			total=pg+rw;
			return total;
		}
		int r_rk(){
			return rk;
		}	
		void w_rk(int n){
			rk=n;
		}
	};

int menu(){
	int choice;
	cout<<"\t�п��\n1.�s�W�ǥ͸��\n2.�R���ǥ͸��\n3.�d�߾ǥ͸��\n4.�C�L��C���\n5.�C�L���Z��\n0.���}"<<endl;
	cin>>choice;
	while(choice>5||choice<0){			
		cout<<"��J���~�A�Э��s��J"<<endl;
		cout<<"\t�п��\n1.�s�W�ǥ͸��\n2.�R���ǥ͸��\n3.�d�߾ǥ͸��\n4.�C�L��C���\n5.�C�L���Z��\n0.���}"<<endl;
		cin>>choice;
	}
	return choice;
}

int main(){
	int choice=1;
	while(choice){
		choice=menu();
		if(choice==1){
			cout<<"�s�W�ǥ͸�ư��椤"<<endl;
			system("pause");
		}else if(choice==2){
			cout<<"�R���ǥ͸�ư��椤"<<endl;
			system("pause");
		}else if(choice==3){
			cout<<"�d�߾ǥ͸�ư��椤"<<endl;
			system("pause");
		}else if(choice==4){
			cout<<"�C�L��C��ư��椤"<<endl;
			system("pause");
		}else if(choice==5){
			cout<<"�C�L���Z����椤"<<endl;
			system("pause");
		}
	}
	cout<<"�A��"<<endl; 
}
