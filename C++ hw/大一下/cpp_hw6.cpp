
#include<iostream>
#include<cstring>
using namespace std;

class st_node{
		int no,pg,rw;
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
	};



int main(){
	st_node *p,*q,*a,*b,*h;
	int x,y,pro,rd;				//x->�y�� 
	char na[10];									
	p=new st_node;											  //1st				
	cout<<"�п�J�y��(��J0����)"<<endl;
	cin>>x;            				
	p->w_no(x);
	if(p->r_no()!=0){
		p->w_ptr(NULL);
		q=p;	
		}
	
	cout<<"�п�J�m�W"<<endl;							//��J��L���
	cin.get();
	cin.getline(na,10);
	p->w_name(na);
	cout<<"�п�J�{���]�p���Z"<<endl;
	cin>>pro;
	p->w_pg(pro);
	cout<<"�п�J��妨�Z"<<endl;														 
	cin>>rd;
	p->w_rw(rd);
	 
		h=q;
	while(1){
		cout<<q->r_no()<<"->";
		if(!q->r_ptr()){
			break;
		}
		q=q->r_ptr();	//
	}
	cout<<"||"<<endl;
	q=h;				
					
	while(p->r_no()){										//���ƿ�J							
		p=new st_node;
		cout<<"�п�J�y��(��J0����)"<<endl;
		cin>>x;
		p->w_no(x);		
		if(!p->r_no()){  									//��J0���� 
			break;
		//��J��L��� 
	
		h=q;	
			while(1){
				y=q->r_no();
				cout<<y<<"->";
				if(!q->r_ptr()){
				break;
				}
			q=q->r_ptr();	
			}
			cout<<"||"<<endl;
			q=h;
		}
		
		a=q;
		b=q;
		
		cout<<"�п�J�m�W"<<endl;							//��J��L���
		cin.get();
		cin.getline(na,10);
		p->w_name(na);
		cout<<"�п�J�{���]�p���Z"<<endl;
		cin>>pro;
		p->w_pg(pro);
		cout<<"�п�J��妨�Z"<<endl;														 
		cin>>rd;
		p->w_rw(rd);				
	
	while(a->r_no()<p->r_no()){								//���в��� 
		if(!a->r_ptr()){ 									//����a���Ы��Vnull 
		break;
		}
		b=a;
		a=a->r_ptr(); 
	}	
	if(!a->r_ptr()&&a==b){ 									//�Ĥ@�����J��� 
		if(p->r_no()<a->r_no()){
			p->w_ptr(q);			
			q=p;
		}else{
			p->w_ptr(NULL);
			b->w_ptr(p);
		}
	}else if(!a->r_ptr()&&a->r_no()<p->r_no()){ 			//�s��ƴ��J�̥k�� 
		p->w_ptr(NULL);
		a->w_ptr(p);
	}else if(a==b){
		p->w_ptr(q);										//�s��ƴ��J�̥��� 
		q=p;		
	}else{													//�s��ƴ��J��C���� 
		p->w_ptr(a);
		b->w_ptr(p);
		p=q;
	}
	
	h=q;
	while(1){
		y=q->r_no();
		cout<<y<<"->";
		if(!q->r_ptr()){
			break;
		}
		q=q->r_ptr();	
	}
	cout<<"||"<<endl;
	q=h;
	}
	
	cout<<"�y��\t�m�W\t�{�]���Z\t��妨�Z"<<endl; 
	while(q){												//�̫᪺��X�j��
	cout<<q->r_no()<<"\t"<<q->r_name()<<"\t"<<q->r_pg()<<"\t"<<q->r_rw()<<endl;
	q=q->r_ptr();
	}
}



