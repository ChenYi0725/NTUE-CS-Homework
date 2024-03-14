#include<iostream>
#include<cstring>
#include<string>
#include<fstream>
#include<cstdlib>
#include<typeinfo>
#include<iomanip>
#include <stdio.h>
#include <string.h>
using namespace std;
using std::string;

class basic{
	protected:
		char id[7];
		int b_time=0;
		bool state=0;
		int order;	
	public:
		void w_order(int n){
			order=n;
		}
		int r_order(){
			return order;
		}
		void w_id(char*a){
			strcpy(id,a);
		}
		void add_b_time(){
			b_time=b_time+1;
		}
		void w_b_time(int a){
			b_time=a;
		}
		void change_state(){
			state=!state;
		}
		char* r_id(){
			return id;
		}
		int r_b_time(){
			return b_time;
		}
		bool r_statebool(){
			return state;
		}
		string r_state(){
			string n;
			if(state){
				n="�w�Q�ɥX";
			}else{
				n="���Q�ɥX"; 
			}
			return n;
		}
		void w_state(bool b){
			state=b;
		}
		
};

class Book:public basic{
	string bname;
	string author;
	Book *ptr;
	public:
		void w_bname(string a){
			bname=a;
		}
		void w_author(string a){
			author=a;
		}
		string r_bname(){
			return bname;
		}
		string r_author(){
			return author;
		}
		Book*r_ptr(){
			return ptr;
		} 
		void w_ptr(Book *p){
			ptr=p;
		}
};

class DVD:public basic{
	string dname;
	int size;
	DVD*ptr;
	public:
		void w_dname(string a){
			dname=a;
		}
		void w_size(int n){
			size=n;
		}
		string r_dname(){
			return dname;
		}
		int r_size(){
			return size; 
		} 
		DVD*r_ptr(){
			return ptr;
		} 
		void w_ptr(DVD *p){
			ptr=p;
		}
		
};
//-----------------class--------------

class menu{
	int choice;
	public:
		int callmenu(){
			cout<<"\t�п��\n1.�s�W�]��\n2.�C�L�]��\n3.�d���]��(�ѽs��)\n4.�R���]��\n5.�����]��\n6.�j�M�]��(������r)\n7.�x�s���\n8.�M�Ÿ��\n0.�x�s�����}"<<endl;
		  	cin>>choice;
	  		return choice;
	 	}			
	 	
		Book *add(Book *q){
			string idstr,setstr; 			//setstr->�@�̡B 
			char idarray[7],idnoarray[6];	//idarray�}�C idnoarray�u���Ʀr idno��ƫ��O 
			int idno;
			bool check=1;						//�T�{�s���榡 1=ok
			Book *n,*f,*b,*h;				//new forward backward
			h=q;
			f=q;
			b=q;
			n=new Book;
			cout<<"��J�s��(��:B00001)"<<endl;
			while(check){						//�T�{�榡		
				cin>>idstr;
				idstr.copy(idarray,6,0);		//string->array
				if(idstr.length()!=6||idarray[0]!='B'){	//�T�{�榡��6�X�BB�}�Y 
					check=0;
				} 
				for(int i=1;i<7;i++){			//array->noarray
					idnoarray[i-1]=idarray[i];
				}
				for(int i=0;i<5;i++){					//�T�{���X�Ҭ��Ʀr 				
					if((int)idnoarray[i]<48||(int)idnoarray[i]>57){		//���XASCII��
					check=0;
					}
				}
				if(!check){
					cout<<"�s���榡���~�A�Э��s��J"<<endl;
				}
				check=!check;	
			}
			idno=atoi(idnoarray);
			n->w_id(idarray);
			n->w_order(idno);
			if(!q){	
				q=n;
				q->w_ptr(NULL);
				cout<<"�п�J�ѦW"<<endl;
				cin.get();
				getline(cin,setstr);
				q->w_bname(setstr);
				cout<<"�п�J�@��"<<endl;
				getline(cin,setstr);
				q->w_author(setstr);
			}else{
				f=q;
				b=q;
				while(f){					//�ˬd���L���Ʈy��
					if(f->r_order()==idno){
						cout<<"�s�����ơA�Э��s��J"<<endl;	
						check=1;			
						while(check){								
							cin>>idstr;
							idstr.copy(idarray,6,0);		
							if(idstr.length()!=6||idarray[0]!='B'){	 
								check=0;
							} 	
							for(int i=1;i<7;i++){		
								idnoarray[i-1]=idarray[i];
							}
							for(int i=0;i<5;i++){					 				
								if((int)idnoarray[i]<48||(int)idnoarray[i]>57){		
								check=0;
								}
							}
							if(!check){
								cout<<"�s���榡���~�A�Э��s��J"<<endl;
							}
							check=!check;	
						}
						idno=atoi(idnoarray);
						n->w_id(idarray);
						n->w_order(idno);
						f=q;
					}else{
						f=f->r_ptr();
					}
					if(!f){
						break;
					}
				}
				f=q;
				cout<<"�п�J�ѦW"<<endl;
				cin.get();
				getline(cin,setstr);
				n->w_bname(setstr);
				cout<<"�п�J�@��"<<endl;
				getline(cin,setstr);
				n->w_author(setstr);
				while(f->r_order()<n->r_order()){								//���в��� 
					if(!f->r_ptr()){ 									//����f���Ы��Vnull 
						break;
					}
					b=f;
					f=f->r_ptr(); 
				}
				if(!f->r_ptr()&&f==b){ 									//�Ĥ@�����J��� 
					if(n->r_order()<f->r_order()){
						n->w_ptr(q);			
						q=n;
					}else{
						n->w_ptr(NULL);
						b->w_ptr(n);
					}
				}else if(!f->r_ptr()&&f->r_order()<n->r_order()){ 			//�s��ƴ��J�̥k�� 
					n->w_ptr(NULL);
					f->w_ptr(n);
				}else if(f==q){
					n->w_ptr(q);										//�s��ƴ��J�̥��� 
					q=n;		
				}else{													//�s��ƴ��J��C���� 
					n->w_ptr(f);
					b->w_ptr(n);
					} 
				}
				return q;
			}
		
		
		DVD *add(DVD *q){
			string idstr,setstr; 			//setstr->�@�̡B�s�� 
			char idarray[7],idnoarray[6],sizearray[10];	//idarray�}�C idnoarray�u���Ʀr idno��ƫ��O 
			int idno,size,i;
			bool check=1;						//�T�{�s���榡 1=ok
			DVD *n,*f=q,*b=q;				//new forward backward
			n=new DVD;
			
			cout<<"��J�s��(��:D00001)"<<endl;
			while(check){						//�T�{�榡		
				cin>>idstr;
				idstr.copy(idarray,6,0);		//string->array
				if(idstr.length()!=6||idarray[0]!='D'){	//�T�{�榡��6�X�BBorD�}�Y 
					check=0;
				} 
				for(int i=1;i<7;i++){			//array->noarray
					idnoarray[i-1]=idarray[i];
				}
				for(int i=0;i<5;i++){					//�T�{���X�Ҭ��Ʀr 				
					if((int)idnoarray[i]<48||(int)idnoarray[i]>57){		//���XASCII��
					check=0;
					}
				}
				if(!check){
					cout<<"�s���榡���~�A�Э��s��J"<<endl;
				}
				check=!check;	
			}
			idno=atoi(idnoarray);
			n->w_order(idno);
			n->w_id(idarray);
			
			if(!q){	
				q=n;
				cout<<"�п�J���W"<<endl;
				cin.get();
				getline(cin,setstr);
				q->w_dname(setstr);
				cout<<"�п�J����"<<endl;
				cin>>sizearray;
				while(isdigit(sizearray[i])||i<10){						//�ˬd�����O�_����� 
					if(sizearray[i]=='-'){
						cout<<"�������o���t�ơA�Э��s��J"<<endl;
						cin>>sizearray;
					}else{
						if(sizearray[i]=='\0'){
							break;
						}		
						if(!isdigit(sizearray[i])){
							cout<<"����������ơA�Э��s��J"<<endl;
							cin>>sizearray;
							i=-1;
						}
					}
					i=i+1;
				}
				size=atoi(sizearray);
				q->w_size(size);
				q->w_ptr(NULL);
			}else{
				f=q;
				b=q;
				while(f){					//�ˬd���L���Ʈy��
					if(f->r_order()==idno){
						cout<<"�s�����ơA�Э��s��J"<<endl;	
						check=1;			
						while(check){								
							cin>>idstr;
							idstr.copy(idarray,6,0);		
							if(idstr.length()!=6||idarray[0]!='D'){	 
								check=0;
							} 	
							for(int i=1;i<7;i++){		
								idnoarray[i-1]=idarray[i];
							}
							for(int i=0;i<5;i++){					 				
								if((int)idnoarray[i]<48||(int)idnoarray[i]>57){		
								check=0;
								}
							}
							if(!check){
								cout<<"�s���榡���~�A�Э��s��J"<<endl;
							}
							check=!check;	
						}
						idno=atoi(idnoarray);
						n->w_id(idarray);
						n->w_order(idno);
						f=q;
					}else{
						f=f->r_ptr();
					}
					if(!f){
						break;
					}
				}
				f=q;
				cout<<"�п�J���W"<<endl;
				cin.get();
				getline(cin,setstr);
				n->w_dname(setstr);
				cout<<"�п�J����"<<endl;
				i=0;
				cin>>sizearray;
				while(isdigit(sizearray[i])||i<10){						//�ˬd�����O�_����� 
					if(sizearray[i]=='-'){
						cout<<"�������o���t�ơA�Э��s��J"<<endl;
						cin>>sizearray;
					}else{
						if(sizearray[i]=='\0'){
							break;
						}		
						if(!isdigit(sizearray[i])){
							cout<<"����������ơA�Э��s��J"<<endl;
							cin>>sizearray;
							i=-1;
						}
					}
					i=i+1;
				}
				size=atoi(sizearray);
				n->w_size(size);
				while(f->r_order()<n->r_order()){								//���в��� 
					if(!f->r_ptr()){ 									//����f���Ы��Vnull 
						break;
					}
					b=f;
					f=f->r_ptr(); 
				}
				if(!f->r_ptr()&&f==b){ 									//�Ĥ@�����J��� 
					if(n->r_order()<f->r_order()){
						n->w_ptr(q);			
						q=n;
					}else{
						n->w_ptr(NULL);
						b->w_ptr(n);
					}
				}else if(!f->r_ptr()&&f->r_order()<n->r_order()){ 			//�s��ƴ��J�̥k�� 
					n->w_ptr(NULL);
					f->w_ptr(n);
				}else if(f==q){
					n->w_ptr(q);										//�s��ƴ��J�̥��� 
					q=n;		
				}else{													//�s��ƴ��J��C���� 
					n->w_ptr(f);
					b->w_ptr(n);
					} 
				}
				return q;
		}
		
		
		void print(Book*q,DVD*p){			//�C�L��C(����) 		
			int sizea,sizeb,digit=0,t;
			Book* a;
			DVD* b;
			a=q;
			b=p;
			sizea=0;
			sizeb=0;
			if(!q){
				cout<<"���y��ƬO�Ū�"<<endl;
			}else{
				sizea=a->r_bname().length();
				sizeb=a->r_author().length();
				while(a){												//�̫᪺��X�j��
					if(a->r_bname().length()>sizea){					//��X��Ƥ��̪����r�� 
						sizea=a->r_bname().length();
					}			
					if(a->r_author().length()>sizeb){
						sizeb=a->r_author().length();
					}		
					a=a->r_ptr();
				}
				if(sizea<4){
					sizea=4;
				}
				if(sizeb<4){
					sizeb=4;
				}
				cout<<left<<setw(10)<<"�s��"<<setw(sizea+4)<<"�ѦW"<<setw(sizeb+4)<<"�@��"<<setw(12)<<"���ɪ��A"<<"���ɦ���"<<endl;
				while(q){												//�̫᪺��X�j��
					cout<<left<<setw(10)<<q->r_id()<<setw(sizea+4)<<q->r_bname()<<setw(sizeb+4)<<q->r_author()<<setw(12)<<q->r_state()<<q->r_b_time()<<endl;
					q=q->r_ptr();
					}
			}
			cout<<endl;
			if(!p){
				cout<<"�v����ƬO�Ū�"<<endl;
			}else{
				sizea=b->r_dname().length();
				t=b->r_size();
				while(t>0){
           			t=t/10;
		            digit=digit+1;
    			}
				sizeb=digit;

				while(b){												//���׳]�w 
					digit=0;
					if(b->r_dname().length()>sizea){					//��X��Ƥ��̪����r�� 
						sizea=b->r_dname().length();
					}			
					t=b->r_size();
					while(t>0){
	           			t=t/10;
			            digit=digit+1;
	    			}					
					if(digit>sizeb){
						sizeb=digit;
					}		
					b=b->r_ptr();
				}
				if(sizea<4){
					sizea=4;
				}
				cout<<"Sizeb"<<sizeb<<endl;
				cout<<left<<setw(10)<<"�s��"<<setw(sizea+4)<<"���W"<<setw(sizeb+7)<<"����"<<setw(12)<<"���ɪ��A"<<"���ɦ���"<<endl;	
				while(p){												
					cout<<left<<setw(10)<<p->r_id()<<setw(sizea+4)<<p->r_dname()<<setw(sizeb)<<p->r_size()<<setw(7)<<" ����"<<setw(12)<<p->r_state()<<p->r_b_time()<<endl;
					p=p->r_ptr();
				}
			}
		}
		
		void search(Book*p,DVD*q){			//�d��(�H�s��) qp���P 
			Book *searchbook;
			DVD *searchdvd;
			int sizea,sizeb,digit=0,t;
			string idstr;
			searchdvd=q;
			searchbook=p;
			char idarray[7],idnoarray[6];
			int idno;
			bool exist=0,check;
			cout<<"�п�J���d�߽s��(��:B00001�BD99999)"<<endl;
			check=1;		
			while(check){						//�T�{�榡		
				cin>>idstr;
				idstr.copy(idarray,6,0);		//string->array
				if(!(idstr.length()==6&&(idarray[0]=='B'||idarray[0]=='D'))){	//�T�{�榡��6�X�BBorD�}�Y 
					check=0;
				} 	
				for(int i=1;i<7;i++){			//array->noarray
					idnoarray[i-1]=idarray[i];
				}
				for(int i=0;i<5;i++){					//�T�{���X�Ҭ��Ʀr 				
					if((int)idnoarray[i]<48||(int)idnoarray[i]>57){		//���XASCII��
						check=0;
					}
				}
				if(!check){
					cout<<"�s���榡���~�A�Э��s��J"<<endl;
				}
				check=!check;	
			}
			idno=atoi(idnoarray);
			if(idarray[0]=='B'){									//�ѥ� 
				while(searchbook){								//�d�߫��в���				
				if(searchbook->r_order()==idno){
					exist=1;
					break;
				}
				searchbook=searchbook->r_ptr();
				}
				if(exist==1){
						sizea=searchbook->r_bname().length();
						sizeb=searchbook->r_author().length();	
					cout<<left<<setw(10)<<"�s��"<<setw(sizea+4)<<"�ѦW"<<setw(sizeb+4)<<"�@��"<<setw(12)<<"���ɪ��A"<<"���ɦ���"<<endl;
					cout<<left<<setw(10)<<searchbook->r_id()<<setw(sizea+4)<<searchbook->r_bname()<<setw(sizeb+4)<<searchbook->r_author()<<setw(12)<<searchbook->r_state()<<searchbook->r_b_time()<<endl;
				}else{
					cout<<"�d�L���"<<endl; 
				}
			}else if(idarray[0]=='D'){									//dvd 
				while(searchdvd){								//�d�߫��в���				
				if(searchdvd->r_order()==idno){
					exist=1;
					break;
				}
				searchdvd=searchdvd->r_ptr();
				}
				if(exist==1){
					sizea=searchdvd->r_dname().length();
					t=searchdvd->r_size();
					while(t>0){
	           			t=t/10;
			            digit=digit+1;
	    			}
					sizeb=digit;
					cout<<left<<setw(10)<<"�s��"<<setw(sizea+4)<<"���W"<<setw(sizeb+7)<<"����"<<setw(12)<<"���ɪ��A"<<"���ɦ���"<<endl;	
					cout<<left<<setw(10)<<searchdvd->r_id()<<setw(sizea+4)<<searchdvd->r_dname()<<setw(sizeb)<<searchdvd->r_size()<<setw(7)<<" ����"<<setw(12)<<searchdvd->r_state()<<searchdvd->r_b_time()<<endl;
				}else{
					cout<<"�d�L���"<<endl;
				}
			}
		}
		
		Book *del(Book*q){									//�R�� 
			Book *f,*b;
			string idstr;
			f=q;
			b=q;
			char idarray[7],idnoarray[6];
			int idno;
			bool exist=0,check=1;
			cout<<"�п�J�n�R�����s��"<<endl;
			while(check){						//�T�{�榡		
				cin>>idstr;
				idstr.copy(idarray,6,0);		//string->array
				if(!(idstr.length()==6&&(idarray[0]=='B'||idarray[0]=='D'))){	//�T�{�榡��6�X�BBorD�}�Y 
					check=0;
				} 	
				for(int i=1;i<7;i++){			//array->noarray
					idnoarray[i-1]=idarray[i];
				}
				for(int i=0;i<5;i++){					//�T�{���X�Ҭ��Ʀr 				
					if((int)idnoarray[i]<48||(int)idnoarray[i]>57){		//���XASCII��
						check=0;
					}
				}
				if(!check){
					cout<<"�s���榡���~�A�Э��s��J"<<endl;
				}
				check=!check;	
			}
			idno=atoi(idnoarray);	
				
			while(f->r_order()!=idno){								//���в��� 
				if(f->r_order()==idno){								//��� 
					exist=1; 
					break; 
				}
				if(!f->r_ptr()){ 									//����f���Ы��Vnull 
					break;
				}
				b=f;
				f=f->r_ptr(); 
			}
			if(f->r_order()==idno){								//����Ĥ@����ƴN��� 
				exist=1; 
			}
			
			
			if(!exist){
				cout<<"�d�L���"<<endl;		
				
			}else{											//���ŦX��� 
				if(!f->r_ptr()&&f==b){						//��C�O�_�u���@����� 
					q=NULL;
				}else if(f==q){							//�R���̥����� 
					q=q->r_ptr();	
				}else{				
					b->w_ptr(f->r_ptr());
				} 
				cout<<"�ӵ���Ƥw���Q�R��"<<endl;
			}
			
			return q;		
		}
		
		DVD *del(DVD*q){									//�R�� 
			DVD *f,*b;
			string idstr;
			f=q;
			b=q;
			char idarray[7],idnoarray[6];
			int idno;
			bool exist=0,check=1;
			cout<<"�п�J�n�R�����s��"<<endl;
			while(check){						//�T�{�榡		
				cin>>idstr;
				idstr.copy(idarray,6,0);		//string->array
				if(!(idstr.length()==6&&(idarray[0]=='B'||idarray[0]=='D'))){	//�T�{�榡��6�X�BBorD�}�Y 
					check=0;
				} 	
				for(int i=1;i<7;i++){			//array->noarray
					idnoarray[i-1]=idarray[i];
				}
				for(int i=0;i<5;i++){					//�T�{���X�Ҭ��Ʀr 				
					if((int)idnoarray[i]<48||(int)idnoarray[i]>57){		//���XASCII��
						check=0;
					}
				}
				if(!check){
					cout<<"�s���榡���~�A�Э��s��J"<<endl;
				}
				check=!check;	
			}
			idno=atoi(idnoarray);	
				
			while(f->r_order()!=idno){								//���в��� 
			if(f->r_order()==idno){								//��� 
				exist=1; 
				break; 
			}
			if(!f->r_ptr()){ 									//����f���Ы��Vnull 
				break;
			}
			b=f;
			f=f->r_ptr(); 
			}
			if(f->r_order()==idno){								//����Ĥ@����ƴN��� 
				exist=1; 
			}
			if(!exist){
				cout<<"�d�L���"<<endl;		
				
			}else{											//���ŦX��� 
				if(!f->r_ptr()&&f==b){						//��C�O�_�u���@����� 
					q=NULL;
				}else if(f==q){							//�R���̥����� 
					q=q->r_ptr();	
				}else{				
					b->w_ptr(f->r_ptr());
				} 
				cout<<"�ӵ���Ƥw���Q�R��"<<endl;
			}
			return q;		
		}
				
		void state(Book*p,DVD*q){			//���� 
			Book *searchbook;
			DVD *searchdvd;
			string idstr;
			searchdvd=q;
			searchbook=p;
			char idarray[7],idnoarray[6];
			int idno,action;
			bool exist=0,check=1,state;
			cout<<"\t�п�ܰ��涵��"<<endl;
			cout<<"1.�ɥX\t2.�٦^"<<endl; 
			cin>>action;
			while(action>2||action<1){
				cout<<"��J���~�A�Э��s��J"<<endl;
				cin>>action;
			}
			switch(action){
				case 1:
					cout<<"�п�J�n���ɪ��s��"<<endl;
					while(check){						//�T�{�榡		
						cin>>idstr;
						idstr.copy(idarray,6,0);		//string->array
						if(!(idstr.length()==6&&(idarray[0]=='B'||idarray[0]=='D'))){	//�T�{�榡��6�X�BBorD�}�Y 
							check=0;
						} 	
						for(int i=1;i<7;i++){			//array->noarray
							idnoarray[i-1]=idarray[i];
						}
						for(int i=0;i<5;i++){					//�T�{���X�Ҭ��Ʀr 				
							if((int)idnoarray[i]<48||(int)idnoarray[i]>57){		//���XASCII��
								check=0;
							}
						}
						if(!check){
							cout<<"�s���榡���~�A�Э��s��J"<<endl;
						}
						check=!check;	
					}
					idno=atoi(idnoarray);
					if(p){
						if(idarray[0]=='B'){
							while(searchbook){								//�d�߫��в���				
								if(searchbook->r_order()==idno){
									exist=1;
									break;
								}
								searchbook=searchbook->r_ptr();
							}
							
							if(exist==1&&!searchbook->r_statebool()){
								cout<<"�s�� "<<searchbook->r_id()<<" �w���Q����"<<endl;
								searchbook->change_state();
								searchbook->add_b_time();
							}else if(exist==1&&searchbook->r_statebool()){
								cout<<"�ʧ@���ѡA�ӮѤw�Q�ɥX"<<endl;
							}else{
								cout<<"�d�L���"<<endl; 
							}
						}
					}else if(idarray[0]=='B'){
						cout<<"�d�L���"<<endl;
					}	 
					if(q){
						if(idarray[0]=='D'){
							while(searchdvd){								//�d�߫��в���				
								if(searchdvd->r_order()==idno){
									exist=1;
									break;
								}
								searchdvd=searchdvd->r_ptr();
							}
							if(exist==1&&!searchdvd->r_statebool()){
								cout<<"�s�� "<<searchdvd->r_id()<<" �w���Q�ɥX"<<endl;
								searchdvd->change_state();
								searchdvd->add_b_time();
							}else if(exist==1&&searchdvd->r_statebool()){
								cout<<"�ʧ@���ѡA��DVD�w�Q�ɥX"<<endl;
							}else{
								cout<<"�d�L���"<<endl;
							}
						}
					}else if(idarray[0]=='D'){
						cout<<"�d�L���"<<endl;
					}
					break;
				case 2:
					cout<<"�п�J�n�k�٪��s��"<<endl; 
					while(check){						//�T�{�榡		
						cin>>idstr;
						idstr.copy(idarray,6,0);		//string->array
						if(!(idstr.length()==6&&(idarray[0]=='B'||idarray[0]=='D'))){	//�T�{�榡��6�X�BBorD�}�Y 
							check=0;
						} 	
						for(int i=1;i<7;i++){			//array->noarray
							idnoarray[i-1]=idarray[i];
						}
						for(int i=0;i<5;i++){					//�T�{���X�Ҭ��Ʀr 				
							if((int)idnoarray[i]<48||(int)idnoarray[i]>57){		//���XASCII��
								check=0;
							}
						}
						if(!check){
							cout<<"�s���榡���~�A�Э��s��J"<<endl;
						}
						check=!check;	
					}
					idno=atoi(idnoarray);
					if(p){
						if(idarray[0]=='B'){
							while(searchbook){								//�d�߫��в���				
								if(searchbook->r_order()==idno){
									exist=1;
									break;
								}
							searchbook=searchbook->r_ptr();
							}
							if(exist==1&&searchbook->r_statebool()){
								cout<<"�s�� "<<searchbook->r_id()<<" �w���Q�k��"<<endl;
								searchbook->change_state(); 
							}else if(exist==1&&!searchbook->r_statebool()){
								cout<<"�ʧ@���ѡA�ثe�w�Q�k��"<<endl;
							}else{
								cout<<"�d�L���"<<endl;
							}
						}
					}else if(idarray[0]=='B'){
						cout<<"�d�L���"<<endl;
					}	 
					if(q){
						if(idarray[0]=='D'){
							while(searchdvd){								//�d�߫��в���				
							if(searchdvd->r_order()==idno){
								exist=1;
								break;
							}
							searchdvd=searchdvd->r_ptr();
							}
							if(exist==1&&searchdvd->r_statebool()){
								cout<<"�s�� "<<searchdvd->r_id()<<" �w���Q�k��"<<endl;
								searchbook->change_state();
							}else if(exist==1&&!searchdvd->r_statebool()){
								cout<<"�ʧ@���ѡA�ثe�w�Q�k��"<<endl;
							}else{
								cout<<"�d�L���"<<endl;
							}
						}
					}else if(idarray[0]=='D'){
						cout<<"�d�L���"<<endl;
					}	 
					break;
			}			
		}
		
		
		
		void keyword(Book*p,DVD*q){			//�d��(�H�s��)			//�䤣��L�^�� 
			Book *searchbook,*bout,*mb;	
			DVD *searchdvd,*dout,*md;
			bout=NULL;
			dout=NULL;
			int sizea=0,sizeb=0,digit=0,t;
			string str;
			searchdvd=q;
			searchbook=p;
			bool existbook=0,existdvd=0;
			cout<<"�п�J���d�ߦW��"<<endl;
			cin>>str;		
			
			if(!q&&!p){
				cout<<"�d�L���"<<endl;
			}else{
				
				while(searchbook){								//�d�߫��в���				
					if(searchbook->r_bname().find(str)!=string::npos){				//�ˬd�W�� * 
						mb=searchbook;	
						searchbook=searchbook->r_ptr();						
						if(!bout){
							bout=mb;
							mb->w_ptr(NULL);
						}else{
							mb->w_ptr(bout->r_ptr());
							bout->w_ptr(mb);		
						}								
					}else{
						searchbook=searchbook->r_ptr();
					}
				}		
				if(bout){
					existbook=1;
					searchbook=bout;
					while(searchbook){				
						if(searchbook->r_bname().length()>sizea){					//��X��Ƥ��̪����r�� 
							sizea=searchbook->r_bname().length();
						}			
						if(searchbook->r_author().length()>sizeb){
							sizeb=searchbook->r_author().length();
						}
						searchbook=searchbook->r_ptr();
					}
					cout<<left<<setw(10)<<"�s��"<<setw(sizea+4)<<"�ѦW"<<setw(sizeb+4)<<"�@��"<<setw(12)<<"���ɪ��A"<<"���ɦ���"<<endl;
					while(bout){
						cout<<left<<setw(10)<<bout->r_id()<<setw(sizea+4)<<bout->r_bname()<<setw(sizeb+4)<<bout->r_author()<<setw(12)<<bout->r_state()<<bout->r_b_time()<<endl;
						bout=bout->r_ptr();
					}	
				}
				sizea=0;
				sizeb=0;
				cout<<endl;					
				while(searchdvd){								//�d�߫��в���				
					if(searchdvd->r_dname().find(str)!=string::npos){	//�ˬd�W�� *			 
						md=searchdvd;							
						searchdvd=searchdvd->r_ptr();
						if(!dout){
							dout=md;
							md->w_ptr(NULL);
						}else{
							md->w_ptr(dout->r_ptr());
							dout->w_ptr(md);		
						}								
					}else{
						searchdvd=searchdvd->r_ptr();
					}
				}
					
				if(dout){
					existdvd=1;
					searchdvd=dout;
					while(searchdvd){
						digit=0;
						if(searchdvd->r_dname().length()>sizea){					//��X��Ƥ��̪����r�� 
							sizea=searchdvd->r_dname().length();
						}			
						t=searchdvd->r_size();
						while(t>0){
			        		t=t/10;
					        digit=digit+1;
			    			}					
						if(digit>sizeb){
							sizeb=digit;
						}
						searchdvd=searchdvd->r_ptr();
					}
						cout<<left<<setw(10)<<"�s��"<<setw(sizea+4)<<"���W"<<setw(sizeb+7)<<"����"<<setw(12)<<"���ɪ��A"<<"���ɦ���"<<endl;	
					while(dout){
						cout<<left<<setw(10)<<dout->r_id()<<setw(sizea+4)<<dout->r_dname()<<setw(sizeb)<<dout->r_size()<<setw(7)<<" ����"<<setw(12)<<dout->r_state()<<dout->r_b_time()<<endl;
						dout=dout->r_ptr();
					}	
				}						
				if(!existdvd&&!existbook){
					cout<<"�L�ŦX���"<<endl; 
				}				
			}
			cout<<endl;
		}
							
		
		void upload(Book *q,DVD *p){
			fstream f("exam.txt",ios_base::out/*||ios_base::trunc*/); 
			char divider[7]="000000";	
			if(!f){
				cout<<"�ɮ�Ū������"<<endl;
			}else{
				if(q){
					while(q){												//�g�J�ѥ���� 
						f<<q->r_id()<<"\n"<<q->r_bname()<<"\n"<<q->r_author()<<"\n"<<q->r_statebool()<<"\n"<<q->r_b_time()<<"\n"<<q->r_order()<<"\n";
						q=q->r_ptr();
					}
				}
				f<<divider<<endl;													//�g�J���j�u 
				if(p){
					while(p){												//�g�JDVD��� 
						f<<p->r_id()<<"\n"<<p->r_dname()<<"\n"<<p->r_size()<<"\n"<<p->r_statebool()<<"\n"<<p->r_b_time()<<"\n"<<p->r_order()<<"\n";
						p=p->r_ptr();
					}
				}
				f<<divider<<endl;
				cout<<"��Ƥw�x�s"<<endl;
				f.close();
			} 

		}
		
		Book *download(Book *q){
			fstream f;
			f.open("exam.txt",ios_base::in);
			Book*n,*e;
			int s=2000000;
			e=q;
			int interger;
			bool boolean;
			char array[s],divider[7]="000000",end;
			string str;
			if(!f){
				cout<<"�ɮ�Ū������"<<endl;
			}else{
				if(!f.get(end).eof()){				//�p�Gf�����Ť�r�� 
					f.seekg(0);
					while(1){						//�ĤG���Xbug ���ճ̫�@�Өϥ�string��int \n 
						n=new Book;		
						f.getline(array,7,'\n');			//���X�s��
						if(strncmp(array,divider,6)==0){		//�p�G���X000000 	
							break;
						}
						n->w_id(array);
						getline(f,str,'\n');			//���X�W��
						n->w_bname(str);
						getline(f,str,'\n');			//���X�@��
						n->w_author(str);				
						f>>boolean;		
						n->w_state(boolean);			//���X���A 
						f>>interger;					//���X���ɦ��� 
						n->w_b_time(interger);
						f>>interger;					//���X���ǽs�� 
						n->w_order(interger);
						f.get();
						
						if(!q){
							q=n;
							q->w_ptr(NULL);
						}else{
							e=q;
							while(e){
								if(!e->r_ptr()){
									break;
								}
								e=e->r_ptr();
							}
							e->w_ptr(n);
							n->w_ptr(NULL);
						} 					
					}			
				}
				f.close();
			} 			
			return q;
		}		
		
		DVD *download(DVD *q){
			fstream f("exam.txt",ios_base::in);
			DVD*n,*e;
			int interger;
			bool boolean;
			int s=2000000;
			char array[s],divider[7]="000000",end;
			char order[7];
			string str;
			if(!f){
				cout<<"�ɮ�Ū������"<<endl;
			}else{
				if(!f.get(end).eof()){								//�p�Gf�����Ť�r�� 
					f.seekg(0);
					f.getline(array,7,'\n');
					while(!(strncmp(array,divider,6)==0)){			//��000000	//�S�g�L 
						if(strncmp(array,divider,6)==0){		//�p�G���X000000 	
							break;
						}
						f.getline(array,s,'\n');
					} 
					while(1){
						n=new DVD;	
						f.getline(array,7,'\n');			//���X�s��
						if(strncmp(array,divider,6)==0){		//�p�G���X000000
							
							break;
						}		
						

						n->w_id(array);
						getline(f,str,'\n');			//���X�W��
						n->w_dname(str);
						f>>interger;							//���X�@��
						n->w_size(interger);				
						f>>boolean;		
						n->w_state(boolean);			//���X���A 
						f>>interger;					//���X���ɦ��� 
						n->w_b_time(interger);
						f>>interger;					//���X���� 
						n->w_order(interger);
						f.get(); 

						if(!q){
							q=n;
							q->w_ptr(NULL);
						}else{
							e=q;
							while(e){
								if(!e->r_ptr()){
									break;
								}
								e=e->r_ptr();
							}
							e->w_ptr(n);
							n->w_ptr(NULL);
						} 				
					}
				}				
				f.close();
			} 			
			return q;
		}
		
		Book *clear(Book*q){
			char c[7];
			char con[6]="clear";
			cout<<"�п�Jclear�H�T�w�M�Ÿ��"<<endl;
			cin>>c;
			if(strcmp(con,c) == 0) {
				q=NULL;
		        cout<<"�ѥ���Ƥw�M��"<<endl;
		    }
		    return q;
		}
		
		DVD *clear(DVD*q){
			char c[7];
			char con[6]="clear";
			cout<<"�п�Jclear�H�T�w�M�Ÿ��"<<endl;
			cin>>c;
			if(strcmp(con,c) == 0) {
				q=NULL;
		        cout<<"DVD��Ƥw�M��"<<endl;
		    }
		    return q;
		}
				
};

//---------------menu--------------- 

int main(){
	menu *m;
	int menuchoice=1,addchoice;					//menuchoice����menu�^�ǭ� 
	char choice[1];
	m=new menu;
	Book *b_q;				//new head forward backward
	DVD *d_q;
	b_q=NULL;
	d_q=NULL;
	b_q=m->download(b_q);
	d_q=m->download(d_q);

		
	while(menuchoice){
		menuchoice=m->callmenu();
		switch(menuchoice){ 
		    case 0:
		    	break;
			case 1:  							//�s�W 
	            cout<<"�п�ܱ��s�W����"<<endl; 
	            cout<<"1.��\t2.DVD\t0.�^����"<<endl;
	            cin>>choice;
				while((int)choice[0]<48||(int)choice[0]>50){
	            	cout<<"��J���~�A�Э��s��J"<<endl;
					cout<<"1.��\t2.DVD\t0.�^����"<<endl; 
					cin>>choice;
				}
				switch(choice[0]){
					case 49:
						b_q=m->add(b_q);
						break;
					case 50:
						d_q=m->add(d_q);
						break;
					default:
						break;
				}	
	            break;
			case 2: 
				m->print(b_q,d_q);		//�C�L 
				break;
	        case 3: 
	            m->search(b_q,d_q);		//�d��(�G�X�@) 
	            break; 
	        case 4: 
	            cout<<"�п�ܱ��R������"<<endl; 
	            cout<<"1.��\t2.DVD\t0.�^����"<<endl;
	            cin>>choice;
				while((int)choice[0]<48||(int)choice[0]>50){	//���XASCII��					
					cout<<"��J���~�A�Э��s��J"<<endl;
					cout<<"1.��\t2.DVD\t0.�^����"<<endl; 	
					cin>>choice;
				}
				switch(int(choice[0])){
					case 49:
						if(b_q){
							b_q=m->del(b_q);
						}else{
							cout<<"�L�ѥ����"<<endl; 
						}
						break;
					case 50:
						if(d_q){
							d_q=m->del(d_q);
						}else{
							cout<<"�LDVD���"<<endl;
						}
						break;
					default:
						break;
				}	
	            break;
	        case 5: 
	            m->state(b_q,d_q); 		//���A���� 
	            break; 
	        case 6:
				m->keyword(b_q,d_q);
				break;
			case 7:
				m->upload(b_q,d_q);
				break;
			case 8:
	            cout<<"�п�ܱ��M�ź���"<<endl; 
	            cout<<"1.��\t2.DVD\t0.�^����"<<endl;
	            cin>>choice;
				while((int)choice[0]<48||(int)choice[0]>50){
	            	cout<<"��J���~�A�Э��s��J"<<endl;
					cout<<"1.��\t2.DVD\t0.�^����"<<endl; 
					cin>>choice;
				}
					switch(choice[0]){
						case 49:
							b_q=m->clear(b_q);
							break;
						case 50:
							d_q=m->clear(d_q);
							break;
						default:
							break;
					}
				break;		
			default: 
	            cout<<"��J���~�A�Э��s��J"<<endl;
				menuchoice=m->callmenu();
	            break;
    	} 
	}
	m->upload(b_q,d_q);
	cout<<"�A��"<<endl;
	system("pause");
	}
