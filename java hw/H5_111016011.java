//import java.util.Scanner;
import java.util.*;
/*
  �@��:��G�� ���� 111016011
  �ާ@����:��J�@���Ǧ��A�t�η|��X��e�Ǧ�
  �۵�:100 �\��Ҧ��F���A�i�䴩�A��
  �B�~�\��:�i���ƨϥΡB�i��O��J�O�_���~
 */

public class H5_111016011{
	
    public static int priority(char a){		//�w�q�B��l�u������
        switch (a){
            case '+':
            	return 1;
            case '-':
                return 1;
            case '*':
            	return 2;
            case '/':
                return 2;
            default:
                return 0;
        }
    }	
    
    public static boolean legal(String a){			//�ˬd��J���Ǧ��O�_���T
    	int brackets=0;
    	boolean check=true;
    	char p;
    	char l=a.charAt(a.length()-1); 
	    if(l!='1'&&l!='2'&&l!='3'&&l!='4'&&l!='5'&&l!='6'&&l!='7'&&l!='8'&&l!='9'&&l!='0'&&l!=')'){	//�ˬd�̫�@��
			check=false;
	    }
	    l=a.charAt(0);
	    if(l!='1'&&l!='2'&&l!='3'&&l!='4'&&l!='5'&&l!='6'&&l!='7'&&l!='8'&&l!='9'&&l!='0'&&l!=')'){	//�ˬd�Ĥ@��
			check=false;
	    }
    	for (int i=0;i<a.length()-1;i++) {	//�@�Ӥ@���ˬd        	
    		if(a.charAt(i)=='+'||a.charAt(i)=='-'||a.charAt(i)=='*'||a.charAt(i)=='/'){	//�ˬd���L�s��|�h�B��l
    			if(a.charAt(i+1)=='+'||a.charAt(i+1)=='-'||a.charAt(i+1)=='*'||a.charAt(i+1)=='/'||a.charAt(i+1)==')'){
    				check=false;
    			}
    		}
	    	
	    }
	    for (int i=0;i<a.length();i++) {	//�@�Ӥ@���ˬd        	
 //---------------------------�ˬd�A��     	
    		if(a.charAt(i)=='(') {			//���A��+1
	        	brackets=brackets+1;
	        }
	        if(a.charAt(i)==')') {			//�k�A��-1
	        	brackets=brackets-1;
	        }
	        if(brackets<0){						//�p�G���k�A���񥪬A�����X�{->brackets�L�k����0
	            brackets= -2;
	        }
//---------------------------�ˬd�A�� 
	    }

	    
	   	if(brackets!=0){		//�p�G�A������
	    	check=false;
	    }
	    
    	return check;
    	
    }
	
	public static void main(String args[]){
		Scanner scan=new Scanner(System.in);
		String re;									//���ƨϥ�	
		String st;									//��X���|����
		char p;									//��e�ˬd�쪺�r��
		String input="";
		int brackets;						//�ˬd�A���O�_����
		Stack<String> output= new Stack();			//��X��stack
		Stack<String> reversedoutput= new Stack();
		Stack<Character> operator= new Stack();		//�x�s�B��l��stack
		
		while(true){								//���ƨϥΪ��j�j��
			while(true){				//�ˬd��J�O�_���T
				brackets=0;
				System.out.println("�п�J�@���Ǧ�");
				input=scan.nextLine();					
				
				if(legal(input)){		//�p�G��J���T(�ϥΫe��禡)
					String infix[]=new String[input.length()];		//�إߤ@�}�C�x�s�B�⤸�P�B��l
					infix=input.split("((?<=\\D)|(?=\\D))");		//�μƦr���ΨëO�d
								
					for(int i=infix.length-1;i>=0;i--){				//�q���ڶ}�lŪ
					//	System.out.println(infix[i]+" ");
						p=infix[i].charAt(0);						//��eŪ��r�ꪺ�Ĥ@�Ӧr��(�]�u�ݯS�O�P�_�B��l�A�ҥH�u���@��)
						
						if(p=='+'||p=='-'||p=='*'||p=='/'){				//�Y��e���B��l�B�D�A��
							
							if(operator.empty()){									//�p�Gstack�O�Ū�
								operator.push(p);
							}
							else if(priority(p)>=priority(operator.peek())){	//�u����>=���|�����hpush
								operator.push(p);
							}else{													//�Y�u����<���|����
								while(!operator.empty()){
									output.push(Character.toString(operator.pop()));	//����X���|
									
									if(operator.empty()){									//�p�Gstack�O�Ū�
										operator.push(p);
										break;
									}else if(priority(p)>=priority(operator.peek())){	//�u����>=���|����
										operator.push(p);
										break;
									}
									
								}
	
							}
																	
							
						}else if(p==')'){										//�Y��e�B��l���k�A��
							operator.push(p);
						
						
						}else if(p=='('){										//�Y��e�B��l�����A��
							while(!operator.empty()){
								output.push(Character.toString(operator.pop()));					
								if(operator.peek()==')'){
									operator.pop();
									break;
								}
							}
							
						}else{													//�Y��e���B�⤸
							output.push(infix[i]);				
						}
					}
					break;
				}else{					//�p�G��J���~
					System.out.println("���Ǧ���J���~�A�Э��s��J");
				}			
			}
			
			while(!operator.empty()){						//��operator����i�houtput
				output.push(Character.toString(operator.pop()));
			}
			
			System.out.print("�e�Ǧ�:");
			while(!output.empty()){					//��X
				System.out.print(output.pop()+" ");
			}
			
			
					
//------------------���s�ϥ�	
				
			System.out.println("\n�O�_�A�ϥΤ@��(��J1�~��A��J0�h�X)");	//���s��J�j��
			re=scan.nextLine();
			
			while(!(re.contains("1")||re.contains("0"))||re.length()!=1){						//�ˬd�O�_��1��0
				System.out.println("�Э��s��J(��J1�~��A��J0�h�X)");
				re=scan.nextLine();
				if((re.contains("1")||re.contains("0"))&&re.length()==1){
					break;
				}				
			}
			
			if(re.contains("0")){			//0��������
				break;
			}
		}
	System.out.println("���±z���ϥ�");
		
	}
}
