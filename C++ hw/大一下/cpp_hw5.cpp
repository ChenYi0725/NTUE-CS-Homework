
#include<iostream>
#include<cstring>
using namespace std;

class st_node{
		int no;
		st_node *ptr;
		public:
		void w_no(int n){
			no=n;
		}	
		int r_no(){
			return no;
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
	int x,y;							
	p=new st_node;				  //1st				
	cout<<"�п�J�y��(��J0����)"<<endl;
	cin>>x;            				//
	p->w_no(x);
	if(p->r_no()!=0){
		p->w_ptr(q);
		q=p;	
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
	while(p->r_no()){							
		p=new st_node;
		cout<<"�п�J�y��(��J0����)"<<endl;
		cin>>x;
		p->w_no(x);		
		if(!p->r_no()){  					//��J0���� 
			break;
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
	
	while(a->r_no()<p->r_no()){					//���в��� 
		if(!a->r_ptr()){ 					//����a���Ы��Vnull 
		break;
		}
		b=a;
		a=a->r_ptr(); 
	}	
	if(!a->r_ptr()&&a==b){ 				//�Ĥ@�����J��� 
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
		p->w_ptr(q);			//�s��ƴ��J�̥��� 
		q=p;		
	}else{					//�s��ƴ��J��C���� 
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
}



