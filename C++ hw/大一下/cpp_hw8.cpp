#include<iostream>
#include<cstring>
using namespace std;

class student{
	protected:
		int no,total,rk;
		char name[10];
};

class cs_st : protected student{
		int pg,cp;
		cs_st *ptr;
	public:
		void w_no(int n){
			no=n;
		}	
		void w_pg(int n){
			pg=n;
		}
		void w_cp(int n){
			cp=n;
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
		int r_cp(){
			return cp;
		}
		void w_ptr(cs_st *p){
			ptr=p;
		}
		cs_st*r_ptr(){
			return ptr;
		}
		int r_total(){
			total=pg+cp;
			return total;
		}
		int r_rk(){
			return rk;
		}	
		void w_rk(int n){
			rk=n;
		}
		
};

class pe_st : protected student{					//��|�t 
		int pescore,run;
		pe_st *ptr;
	public:
		void w_no(int n){
			no=n;
		}	
		void w_pescore(int n){
			pescore=n;
		}
		void w_run(int n){
			run=n;
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
		int r_pescore(){
			return pescore;
		}
		int r_run(){
			return run;
		}
		void w_ptr(pe_st *p){
			ptr=p;
		}
		pe_st*r_ptr(){
			return ptr;
		}
		int r_total(){
			total=(100-run)+pescore;
			return total;
		}
		int r_rk(){
			return rk;
		}	
		void w_rk(int n){
			rk=n;
		}
};
//-------------------���O�]�w------------------------------ 

int menu(){
	int choice=0;
	int department=0;
	
	cout<<"\t�п��\n1.�s�W�ǥ͸��\n2.�R���ǥ͸��\n3.�d�߾ǥ͸��\n4.�C�L��C���\n5.�C�L���Z��\n0.���}"<<endl;
	cin>>choice;
	while(choice>5||choice<0){
		cout<<"��J���~�A�Э��s��J"<<endl;
		cout<<"\t�п��\n1.�s�W�ǥ͸��\n2.�R���ǥ͸��\n3.�d�߾ǥ͸��\n4.�C�L��C���\n5.�C�L���Z��\n0.���}"<<endl;
		cin>>choice;
	}
	if(choice){
		cout<<"\t�п�ܬ�t"<<endl;
		cout<<"1.���t	2.��|�t"<<endl;
		cin>>department;
		while(department<1||department>2){
			cout<<"�Э��s���"<<endl;
			cout<<"1.���t	 2.��|�t"<<endl;
			cin>>department;
		} 
	}
	choice=choice+department*10;
	return choice;
	
}

//----------���Ψ禡------------------- 


void cs_searchinfo(cs_st*q){			//�d��(�H�y��)��� 
	cs_st *searchpoint;
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
	cout<<"�y��\t�m�W\t�{�]���Z\t�p�����Z"<<endl;
	cout<<searchpoint->r_no()<<"\t"<<searchpoint->r_name()<<"\t"<<searchpoint->r_pg()<<"\t"<<searchpoint->r_cp()<<endl;
	}else{
		cout<<"�Ӿǥͤ��s�b"<<endl; 
	}
}

int cs_deleteinfo(cs_st*q){							//�R��(�H�y��)
	cs_st *deletea,*deleteb;
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
			cout<<"�ӵ���Ƥw�R��"<<endl; 
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

void cs_printinfo(cs_st*q){			//�C�L��C(�u���y��)
	cs_st *h;
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


void cs_printgrade(cs_st*q){					//�C�L���Z 
	int quantity=0,rank=1,orank=1;
	cs_st *current,*highest;
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
			
		cout<<"�y��\t�m�W\t�{�]���Z\t�p�����Z\t�`��"<<endl; //����rank��X 
		
		current=q;
		for(int i=quantity;i>0;i--){
		
		
			while(current){
				if(current->r_rk()==orank){
					cout<<current->r_no()<<"\t"<<current->r_name()<<"\t"<<current->r_pg()<<"\t"<<current->r_cp()<<"\t"<<current->r_total()<<endl;
				}
				current=current->r_ptr();
			} 
			orank=orank+1;
			current=q;
		}

	}

}
//---------------��|�Ψ禡------------------------------ 

void pe_searchinfo(pe_st*q){			//�d��(�H�y��)��� 
	pe_st *searchpoint;
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
	cout<<"�y��\t�m�W\t��|���Z\t100���u�]���Z"<<endl;
	cout<<searchpoint->r_no()<<"\t"<<searchpoint->r_name()<<"\t"<<searchpoint->r_pescore()<<"\t"<<searchpoint->r_run()<<endl;
	}else{
		cout<<"�Ӿǥͤ��s�b"<<endl; 
	}
}

int pe_deleteinfo(pe_st*q){							//�R��(�H�y��)
	pe_st *deletea,*deleteb;
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
			cout<<"�ӵ���Ƥw�R��"<<endl; 
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

void pe_printinfo(pe_st*q){			//�C�L��C(�u���y��)
	pe_st *h;
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


void pe_printgrade(pe_st*q){					//�C�L���Z 
	int quantity=0,rank=1,orank=1;
	pe_st *current,*highest;
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
			
		cout<<"�y��\t�m�W\t��|���Z\t100���u�]���Z\t�`��"<<endl; //����rank��X 
		
		current=q;
		for(int i=quantity;i>0;i--){
		
		
			while(current){
				if(current->r_rk()==orank){
					cout<<current->r_no()<<"\t"<<current->r_name()<<"\t"<<current->r_pescore()<<"\t"<<current->r_run()<<"\t"<<current->r_total()<<endl;
				}
				current=current->r_ptr();
			} 
			orank=orank+1;
			current=q;
		}

	}

}

//-------------�D�禡----------------------------------- 
int main(){
	cs_st *cs_n,*cs_q,*cs_a,*cs_b,*cs_searchpoint;									//cs_n->new  q->head
	pe_st *pe_n,*pe_q,*pe_a,*pe_b,*pe_searchpoint;	
	char cs_na[10],pe_na[10];
	cs_q=NULL;
	cs_a=NULL;
	cs_n=NULL;
	cs_b=NULL;
	cs_searchpoint=NULL;
	pe_q=NULL;
	pe_a=NULL;
	pe_n=NULL;
	pe_b=NULL;
	pe_searchpoint=NULL;
	int choice=1,cs_number,pg_score,cp_score,cs_cknode=0,pe_number,pe_score,run_score,pe_cknode=0,deleteno,ckdelete; 
	
	while(choice){
		choice=menu();
		if(choice==11){										//���J��� 
			if(cs_cknode==0){
				cs_n=new cs_st;											  //1st				
				cout<<"�п�J�y��"<<endl;
				cin>>cs_number;            				
				cs_n->w_no(cs_number);
				cs_n->w_ptr(NULL);
				cs_q=cs_n;	
				cout<<"�п�J�m�W"<<endl;							//��J��L���
				cin.get();
				cin.getline(cs_na,10);
				cs_n->w_name(cs_na);
				cout<<"�п�J�{�]���Z(0~100��)"<<endl;
				cin>>pg_score;
				while(pg_score<0||pg_score>100){
					cout<<"��J���~�cs_a�Э��s��J"<<endl; 
					cin>>pg_score;
				}
				cs_n->w_pg(pg_score);
				cout<<"�п�J�p�����Z(0~100��)"<<endl;														 
				cin>>cp_score;
				while(cp_score<0||cp_score>100){
					cout<<"��J���~�A�Э��s��J"<<endl; 
					cin>>cp_score;
				}
				cs_n->w_cp(cp_score);
				cs_cknode=1;
				
			}else{ 
				cs_n=new cs_st;
				cs_searchpoint=cs_q;
				cout<<"�п�J�y��"<<endl;
				cin>>cs_number;
				while(cs_searchpoint){					//�ˬd���L���Ʈy��						
					if(cs_searchpoint->r_no()==cs_number){
						cout<<"�y�����ơA�Э��s��J"<<endl;
						cin>>cs_number;
						cs_searchpoint=cs_searchpoint->r_ptr();
						cs_searchpoint=cs_q;
					}else{
					cs_searchpoint=cs_searchpoint->r_ptr();	
					}
					if(!cs_searchpoint){
						break;
					}
				}
				
				cs_n->w_no(cs_number);		
				
				cs_a=cs_q;
				cs_b=cs_q;

				cout<<"�п�J�m�W"<<endl;							//��J��L���
				cin.get();
				cin.getline(cs_na,10);
				cs_n->w_name(cs_na);
				cout<<"�п�J�{�]���Z(0~100��)"<<endl;
				cin>>pg_score;
				while(pg_score<0||pg_score>100){
					cout<<"��J���~�A�Э��s��J"<<endl; 
					cin>>pg_score;
				}
				cs_n->w_pg(pg_score);
				cout<<"�п�J�p�����Z(0~100��)"<<endl;														 
				cin>>cp_score;
				while(cp_score<0||cp_score>100){
					cout<<"��J���~�A�Э��s��J"<<endl; 
					cin>>cp_score;
				}
				cs_n->w_cp(cp_score);				
			
			while(cs_a->r_no()<cs_n->r_no()){								//���в��� 
				if(!cs_a->r_ptr()){ 									//����a���Ы��Vnull 
				break;
				}
				cs_b=cs_a;
				cs_a=cs_a->r_ptr(); 
			}	
			if(!cs_a->r_ptr()&&cs_a==cs_b){ 									//�Ĥ@�����J��� 
				if(cs_n->r_no()<cs_a->r_no()){
					cs_n->w_ptr(cs_q);			
					cs_q=cs_n;
				}else{
					cs_n->w_ptr(NULL);
					cs_b->w_ptr(cs_n);
				}
			}else if(!cs_a->r_ptr()&&cs_a->r_no()<cs_n->r_no()){ 			//�s��ƴ��J�̥k�� 
				cs_n->w_ptr(NULL);
				cs_a->w_ptr(cs_n);
			}else if(cs_a==cs_b){
				cs_n->w_ptr(cs_q);										//�s��ƴ��J�̥��� 
				cs_q=cs_n;		
			}else{													//�s��ƴ��J��C���� 
				cs_n->w_ptr(cs_a);
				cs_b->w_ptr(cs_n);
				cs_n=cs_q;
			}
			} 
			
		}else if(choice==13){											//�d�� 
			cs_searchinfo(cs_q);
		}else if(choice==12){											//�R�� 
			if(!cs_q){
				cout<<"��ƬO�Ū�"<<endl; 
			}else if(cs_q->r_ptr()==NULL){									//�u���@����� 
					cout<<"�п�J���R�����y��"<<endl; 
					cin>>deleteno;
					if(cs_q->r_no()==deleteno){
						cs_q=NULL;
						cout<<"�ӵ���Ƥw�R��"<<endl; 
						cs_cknode=0;
			}else{
				cout<<"�ӵ���Ƥ��s�b�A�L�k�R��"<<endl;
			}
			}else{														//�p�G�n�R�����O�Ĥ@����� 
				ckdelete=cs_deleteinfo(cs_q);				
				if(ckdelete==1){
					cs_q=cs_q->r_ptr();
					cout<<"�ӵ���Ƥw�R��"<<endl; 
				}
				ckdelete=0;
			}
		}else if(choice==14){										//�C�L��C 
			cs_printinfo(cs_q);
		}else if(choice==15){										//�C�L���Z�� 
			cs_printgrade(cs_q); 
		}else if(choice==21){										//���J��� 
			if(pe_cknode==0){
				pe_n=new pe_st;											  //1st				
			
				cout<<"�п�J�y��"<<endl;
				cin>>pe_number;            				
				pe_n->w_no(pe_number);
				pe_n->w_ptr(NULL);
				pe_q=pe_n;	
				cout<<"�п�J�m�W"<<endl;							//��J��L���
				cin.get();
				cin.getline(pe_na,10);
				pe_n->w_name(pe_na);
				cout<<"�п�J��|���Z(0~100��)"<<endl;
				cin>>pe_score;
				while(pe_score<0||pe_score>100){
					cout<<"��J���~�A�Э��s��J"<<endl; 
					cin>>pe_score;
				}
				pe_n->w_pescore(pe_score);
				cout<<"�п�J100���u�]���Z(0~100��)"<<endl;														 
				cin>>run_score;
				while(run_score<0){
					cout<<"��J���~�A�Э��s��J"<<endl; 
					cin>>run_score;
				}
				pe_n->w_run(run_score);
				pe_cknode=1;
				
			}else{ 
				pe_n=new pe_st;
				pe_searchpoint=pe_q;
				cout<<"�п�J�y��"<<endl;
				cin>>pe_number;
				while(pe_searchpoint){					//�ˬd���L���Ʈy��						
					if(pe_searchpoint->r_no()==pe_number){
						cout<<"�y�����ơA�Э��s��J"<<endl;
						cin>>pe_number;
						pe_searchpoint=pe_searchpoint->r_ptr();
						pe_searchpoint=pe_q;
					}else{
					pe_searchpoint=pe_searchpoint->r_ptr();	
					}
					if(!pe_searchpoint){
						break;
					}
				}
				
				pe_n->w_no(pe_number);		
				
				pe_a=pe_q;
				pe_b=pe_q;

				cout<<"�п�J�m�W"<<endl;							//��J��L���
				cin.get();
				cin.getline(pe_na,10);
				pe_n->w_name(pe_na);
				cout<<"�п�J��|���Z(0~100��)"<<endl;
				cin>>pe_score;
				while(pe_score<0||pe_score>100){
					cout<<"��J���~�A�Э��s��J"<<endl; 
					cin>>pe_score;
				}
				pe_n->w_pescore(pe_score);								//�� 
				cout<<"�п�J100���u�]���Z"<<endl;														 
				cin>>run_score;
				while(run_score<0){
					cout<<"��J���~�A�Э��s��J"<<endl; 
					cin>>run_score;
				}
				pe_n->w_run(run_score);				
			
			while(pe_a->r_no()<pe_n->r_no()){								//���в��� 
				if(!pe_a->r_ptr()){ 									//����a���Ы��Vnull 
				break;
				}
				pe_b=pe_a;
				pe_a=pe_a->r_ptr(); 
			}	
			if(!pe_a->r_ptr()&&pe_a==pe_b){ 									//�Ĥ@�����J��� 
				if(pe_n->r_no()<pe_a->r_no()){
					pe_n->w_ptr(pe_q);			
					pe_q=pe_n;
				}else{
					pe_n->w_ptr(NULL);
					pe_b->w_ptr(pe_n);
				}
			}else if(!pe_a->r_ptr()&&pe_a->r_no()<pe_n->r_no()){ 			//�s��ƴ��J�̥k�� 
				pe_n->w_ptr(NULL);
				pe_a->w_ptr(pe_n);
			}else if(pe_a==pe_b){
				pe_n->w_ptr(pe_q);										//�s��ƴ��J�̥��� 
				pe_q=pe_n;		
			}else{													//�s��ƴ��J��C���� 
				pe_n->w_ptr(pe_a);
				pe_b->w_ptr(pe_n);
				pe_n=pe_q;
			}
			} 
			
		}else if(choice==23){											//�d�� 
			pe_searchinfo(pe_q);
		}else if(choice==22){											//�R�� 
			if(!pe_q){
				cout<<"��ƬO�Ū�"<<endl; 
			}else if(pe_q->r_ptr()==NULL){									//�u���@����� 
					cout<<"�п�J���R�����y��"<<endl; 
					cin>>deleteno;
					if(pe_q->r_no()==deleteno){
						pe_q=NULL;
						cout<<"�ӵ���Ƥw�R��"<<endl; 
						pe_cknode=0;
			}else{
				cout<<"�ӵ���Ƥ��s�b�A�L�k�R��"<<endl;
			}
			}else{
				ckdelete=pe_deleteinfo(pe_q);
				if(ckdelete==1){
					pe_q=pe_q->r_ptr();
					cout<<"�ӵ���Ƥw�R��"<<endl; 
				}
			}
		}else if(choice==24){										//�C�L��C 
			pe_printinfo(pe_q);
		}else if(choice==25){										//�C�L���Z�� 
			pe_printgrade(pe_q); 
		}
	} 
	cout<<"�A��"<<endl; 
}



