#include<iostream>
#include<cstring>
using namespace std;

class st_node{
	public:
		int no;
		char name[10];
		int pg;
		int rw;
		st_node *ptr;	
	};


int main(){
	int i=0;
	st_node *p,*q;
	q=NULL;
	for(i=0;i<10;i++){
		p=new st_node;
		
		cout<<"�п�J�y��"<<endl;
		cin>>p->no;
		while(p->no<=0){
			cout<<"��J���~�A�Э��s��J"<<endl;
			cin>>p->no;
		}
		cout<<"�п�J�m�W"<<endl;
		cin.get();
		cin.getline(p->name,10);
		cout<<"�п�J�{���]�p���Z"<<endl;
		cin>>p->pg;
		while(p->pg<0||p->pg>100){
			cout<<"��J���~�A�Э��s��J"<<endl;
			cin>>p->pg;
		}
		cout<<"�п�J��妨�Z"<<endl;
		cin>>p->rw;
		while(p->rw<0||p->rw>100){
			cout<<"��J���~�A�Э��s��J"<<endl;
			cin>>p->rw;
		}			
		
		p->ptr=q;
		q=p;									//�ϦV 
	}
	
	cout<<"�y��"<<"\t"<<"�W�r"<<"\t"<<"�{���]�p���Z"<<"\t"<<"��妨�Z"<<endl;

	while(q){
		cout<<q->no<<"\t"<<q->name<<"\t"<<q->pg<<"\t"<<q->rw<<endl;
	
		q=q->ptr;
	}
	
}
