#include<iostream>
#include<cstring>
#include<string>

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
	cout<<"\t�п��\n1.�s�W�ǥ͸��\n2.�R���ǥ͸��\n3.�H�y���d�߾ǥ͸��\n4.�H�m�W�d�߾ǥ͸��\n5.�C�L��C���\n6.�C�L���Z��\n0.���}"<<endl;
	cin>>choice;
	while(choice>6||choice<0){
		cout<<"��J���~�A�Э��s��J"<<endl;
		cout<<"\t�п��\n1.�s�W�ǥ͸��\n2.�R���ǥ͸��\n3.�H�y���d�߾ǥ͸��\n4.�H�m�W�d�߾ǥ͸��\n5.�C�L��C���\n6.�C�L���Z��\n0.���}"<<endl;
		cin>>choice;
	}
	return choice;
}

void searchinfo(st_node*q){			//�d��(�H�y��)
	st_node *searchpoint;
	searchpoint=NULL;
	int exist=0,number;
	cout<<"�п�J���d�߮y��"<<endl;
	cin>>number; 
	searchpoint=q;
	while(searchpoint){											
		if(searchpoint->r_no()==number){
			exist=1;
			break;
		}
		searchpoint=searchpoint->r_ptr();
	}
	if(exist==1){
	cout<<"�y��\t�m�W\t�{�]���Z\t�\Ū�P�g�@���Z"<<endl;
	cout<<searchpoint->r_no()<<"\t"<<searchpoint->r_name()<<"\t"<<searchpoint->r_pg()<<"\t"<<searchpoint->r_rw()<<endl;
	}else{
		cout<<"�Ӿǥͤ��s�b"<<endl; 
	}
}

int deleteinfo(st_node*q){							//�R��(�H�y��)
	st_node *deletea,*deleteb;
	deletea=NULL;
	deleteb=NULL;
	int exist=0,number;
	
	if(q!=NULL){
	cout<<"�п�J���R�����y��"<<endl; 
	cin>>number;
	deletea=q;										
	deleteb=q;	
	if(q->r_no()==number){									//�Ĥ@����� 
		return 1;
	}
	
	while(deletea){										//���в��� 
		if(deletea->r_no()==number){					//��츹�X 
			deleteb->w_ptr(deletea->r_ptr());
			cout<<"�ӵ���Ƥw���\�R��"<<endl; 
			deleteb=NULL;
			deletea=NULL;
			break;
		}							
		deleteb=deletea;
		deletea=deletea->r_ptr(); 
		
		if(!deletea){ 						 
			deleteb,deletea=NULL;
			cout<<"�ӵ���Ƥ��s�b�A�L�k�R��"<<endl;
		}
	}
	}
}

void show(st_node*q){			//�C�L��C(�u���y��)
	st_node *h;
	h=q;
	cout<<"head->";
	while(q){												//�̫᪺��X�j��
		cout<<q->r_no();
		cout<<"->";
		q=q->r_ptr();
		}
	cout<<"||"<<endl;
	q=h;
}


void printinfo(st_node*q){			//�C�L��C(����) 
	st_node *h;
	
	h=q;
	if(q==NULL){
		cout<<"��ƬO�Ū�"<<endl;
	}else{
	cout<<"�y��\t�m�W\t�{�]���Z\t�\Ū�P�g�@���Z"<<endl;
	while(q){												//�̫᪺��X�j��
		cout<<q->r_no()<<"\t"<<q->r_name()<<"\t"<<q->r_pg()<<"\t"<<q->r_rw()<<endl;
		q=q->r_ptr();
		}
	}
	q=h;
}

void printgrade(st_node*q){
	int quantity=0,rank=1,orank=1;
	st_node *current,*highest;
	current=q;
	highest=q;			//set

	if(!q){
		cout<<"��ƬO�Ū�"<<endl; 
	}else{
		while(current){
			quantity=quantity+1;
			current->w_rk(0);				//�Ƽƶq�Brank�k0 ok
			current=current->r_ptr();
		}
		current=q;	
		
		for(int i=quantity;i>0;i--){		//�Ʀh�֤H 
			
			while(current){		
			
				if(current->r_rk()==0&&highest->r_rk()!=0){
					highest=current;
				}
				if(current->r_total()>highest->r_total()&&current->r_rk()==0){				//
					highest=current;
				}
				current=current->r_ptr();		
			}
			current=q;
			highest->w_rk(rank);
			rank=rank+1;	
		}
			
		cout<<"�y��\t�m�W\t�{�]���Z\t�\Ū�P�g�@���Z"<<endl; //����rank��X 
		
		current=q;
		for(int i=quantity;i>0;i--){
		
		
			while(current){
				if(current->r_rk()==orank){
					cout<<current->r_no()<<"\t"<<current->r_name()<<"\t"<<current->r_pg()<<"\t"<<current->r_rw()<<endl;
				}
				current=current->r_ptr();
			} 
			orank=orank+1;
			current=q;
		}

	}

}

void searchname(st_node*q){
	char name[10];
	int exist=0;
	st_node *searchpoint;
	searchpoint=NULL;
	
	
	
	cout<<"�п�J���d�ߩm�W"<<endl;
	cin.get();
	cin.getline(name,10);
	string target=string(name);
	
	
	searchpoint=q;
	while(searchpoint){											
		string currentname=string(searchpoint->r_name());
		
		if(currentname==target&&!exist){
			cout<<"�y��\t�m�W\t�{�]���Z\t�\Ū�P�g�@���Z"<<endl;
			cout<<searchpoint->r_no()<<"\t"<<searchpoint->r_name()<<"\t"<<searchpoint->r_pg()<<"\t"<<searchpoint->r_rw()<<endl;
			exist=1;
		}else if(currentname==target&&exist){
			cout<<searchpoint->r_no()<<"\t"<<searchpoint->r_name()<<"\t"<<searchpoint->r_pg()<<"\t"<<searchpoint->r_rw()<<endl;
		}
		searchpoint=searchpoint->r_ptr();
	}
	
	
	if(!exist){
		cout<<"�Ӿǥͤ��s�b"<<endl; 
	}
	
	
}

int main(){
	st_node *n,*q,*a,*b,*searchpoint,*g;									//n->new  q->head
	char na[10];
	q=NULL;
	a=NULL;
	n=NULL;
	b=NULL;
	searchpoint=NULL;
	g=NULL;
	int choice=1,number,pro,rd,cknode=0,deleteno,ckdelete;
	
	while(choice){
		choice=menu();
		if(choice==1){
			if(cknode==0){
				n=new st_node;											  //1st				
			
				cout<<"�п�J�y��"<<endl;
				cin>>number;            				
				n->w_no(number);
				n->w_ptr(NULL);
				q=n;	
				cout<<"�п�J�m�W"<<endl;							//��J��L���
				cin.get();
				cin.getline(na,10);
				n->w_name(na);
				cout<<"�п�J�{�]���Z(0~100��)"<<endl;
				cin>>pro;
				while(pro<0||pro>100){
					cout<<"��J���~�A�Э��s��J"<<endl; 
					cin>>pro;
				}
				n->w_pg(pro);
				cout<<"�п�J�\Ū�P�g�@���Z(0~100��)"<<endl;														 
				cin>>rd;
				while(rd<0||rd>100){
					cout<<"��J���~�A�Э��s��J"<<endl; 
					cin>>rd;
				}
				n->w_rw(rd);
				cknode=1;
				
			}else{ 
				n=new st_node;
				searchpoint=q;
				cout<<"�п�J�y��"<<endl;
				cin>>number;
				while(searchpoint){					//�ˬd���L���Ʈy��						
					if(searchpoint->r_no()==number){
						cout<<"�y�����ơA�Э��s��J"<<endl;
						cin>>number;
						searchpoint=searchpoint->r_ptr();
						searchpoint=q;
					}else{
					searchpoint=searchpoint->r_ptr();	
					}
					if(!searchpoint){
						break;
					}
				}
				
				n->w_no(number);		
				
				a=q;
				b=q;

				cout<<"�п�J�m�W"<<endl;							//��J��L���
				cin.get();
				cin.getline(na,10);
				n->w_name(na);
				cout<<"�п�J�{�]���Z(0~100��)"<<endl;
				cin>>pro;
				while(pro<0||pro>100){
					cout<<"��J���~�A�Э��s��J"<<endl; 
					cin>>pro;
				}
				n->w_pg(pro);
				cout<<"�п�J�\Ū�P�g�@���Z(0~100��)"<<endl;														 
				cin>>rd;
				while(rd<0||rd>100){
					cout<<"��J���~�A�Э��s��J"<<endl; 
					cin>>rd;
				}
				n->w_rw(rd);				
			
			while(a->r_no()<n->r_no()){								//���в��� 
				if(!a->r_ptr()){ 									//����a���Ы��Vnull 
				break;
				}
				b=a;
				a=a->r_ptr(); 
			}	
			if(!a->r_ptr()&&a==b){ 									//�Ĥ@�����J��� 
				if(n->r_no()<a->r_no()){
					n->w_ptr(q);			
					q=n;
				}else{
					n->w_ptr(NULL);
					b->w_ptr(n);
				}
			}else if(!a->r_ptr()&&a->r_no()<n->r_no()){ 			//�s��ƴ��J�̥k�� 
				n->w_ptr(NULL);
				a->w_ptr(n);
			}else if(a==b){
				n->w_ptr(q);										//�s��ƴ��J�̥��� 
				q=n;		
			}else{													//�s��ƴ��J��C���� 
				n->w_ptr(a);
				b->w_ptr(n);
				n=q;
			}
			} 
			
		}else if(choice==2){
			if(!q){
				cout<<"��ƬO�Ū�"<<endl; 
			}else if(q->r_ptr()==NULL){									//�u���@����� 
					cout<<"�п�J���R�����y��"<<endl; 
					cin>>deleteno;
					if(q->r_no()==deleteno){
						q=NULL;
						cout<<"�ӵ���Ƥw���\�R��"<<endl; 
						cknode=0;
			}else{
				cout<<"�ӵ���Ƥ��s�b�A�L�k�R��"<<endl;
			}
			}else{
				ckdelete=deleteinfo(q);
				if(ckdelete==1){
					q=q->r_ptr();
					cout<<"�ӵ���Ƥw���\�R��"<<endl; 
				}
			}
		}else if(choice==3){
			searchinfo(q);
		}else if(choice==4){
			searchname(q);
		}else if(choice==5){
			show(q);
		}else if(choice==6){
			printgrade(q); 
		}
	} 
	cout<<"�A��"<<endl; 
}



