import java.util.Scanner;
/*
  �@��:��G�� ���� 111016011
  �ާ@����:�|���ͤ@�ե�4�Ӥ����ƼƦr�զ����Ʀr��A�ϥΪ̥i��J�ۦP�榡���Ʀr��A�C����J�����t�γ��|�i�����G�A
  		   (A:�q��ƭȤΦ�m B:�q��ƭȦ���m����), ����q���̲q�אּ��,�çi���@�q�F�h�֦�, �Y�W�L10��,�h��ܵ�
  		   �רõ����{��
  �۵�:100 �\��Ҧ��F���B�ॿ�T�B�@�B��P�O��J�O�_���T�A�B�୫�ư���1
  �B�~�\��:�i���s��J�A�B��P�_��J�O�_���T
 */
public class H3_111016011{
	public static void main(String args[]){
		Scanner scan = new Scanner(System.in);
		String re;					//���ƨϥ�
		int ans[];
		int a=0;
		int b=0;
		boolean anscorrect;			//�O�_����
		boolean inputincorrect=false;		//�O�_��J���T
		while(true){
			anscorrect=false;
			ans=new int[4];
			for(int i=0;i<ans.length;i++){			//�����D��(0~9�������ƼƦr)
				ans[i]=(int)(Math.random()*10);
				for(int j=0;j<i;j++){		//�Y���ƫh���s����
					if(ans[i]==ans[j]){
						i--;
					}
				}
			}		
			
			System.out.print("ans:");				//�[���
			for(int i=0;i<ans.length;i++){
				System.out.print(ans[i]);
			}		
			System.out.print("\n");		
	//-------------------��J		
			for(int t=0;t<10;t++){										//�q�D10��
				System.out.print("�п�J4��Ʀr: ");
				String[] guess = scan.nextLine().split("");	 //��J�r��+��r�ꤺ�C�ӼƦr����		
				if(guess.length!=4){						//�Y��J�W�L4�ӼƦr
						inputincorrect=true;
					}
							
				int num[]=new int[4];
				
				
				for(int i=0;i<guess.length;i++){			//��r�ꤺ�C�ӼƦr���X
					try{
						num[i] = Integer.parseInt(String.valueOf(guess[i]));
					}catch(Exception e){
						inputincorrect=true;
						break;
					}				
				}
				for(int l=0;l<3;l++){				//��靈�L���ƼƦr14 13 12 24 23 34
					for(int r=3;r>l;r--){
						if(num[r]==num[l]){
							inputincorrect=true;
						}
					}
				}
				if(inputincorrect){							//�p�G��J���~�h����
					System.out.println("��J���~�A���T�榡��������4�ӼƦr");
					System.out.println("example:0123");
				}
				
				while(inputincorrect){							//�p�G��J���~�h���s��J
					inputincorrect=false;
					System.out.print("�п�J4��Ʀr: ");
					guess = scan.nextLine().split("");	 	//��J�r��+��r�ꤺ�C�ӼƦr����		
					if(guess.length!=4){					//�Y��J�W�L4�ӼƦr
							inputincorrect=true;
						}				
					for(int i=0;i<guess.length;i++){		//���J���r��}�C�ন���
						try{
							num[i] = Integer.parseInt(String.valueOf(guess[i]));
						}catch(Exception e){
							inputincorrect=true;
							break;
						}
					}
					for(int l=0;l<3;l++){				//��靈�L���ƼƦr14 13 12 24 23 34
						for(int r=3;r>l;r--){
							if(num[r]==num[l]){	
								inputincorrect=true;
							}
						}
					}
					if(inputincorrect){							//�p�G��J���~�h����
						System.out.println("��J���~�A���T�榡��������4�ӼƦr");
						System.out.println("example:0123");
					}
				}	
	//-------------------��J			
	//-------------------�P�_�XA�XB	
				for(int i=0;i<guess.length;i++){		//�qnum�Y�]���
					for(int j=0;j<ans.length;j++){					//�qans�Y�]���
						if(num[i]==ans[j]){							//�p�G���ۦP�hB+1�B�ˬd��m�O�_�ۦP
							b++;
							if(i==j){
								b--;
								a++;
							}
						}	
					}
				}
				if(a==4){				//�p�G����
					anscorrect=true;
					System.out.print("���ߵ���A���׬�");
					a=0;										//���mAB
					b=0;
					for(int i=0;i<ans.length;i++){
						System.out.print(ans[i]);
					}		
					System.out.print("\n");
						break;
				}
	//-------------------�P�_�XA�XB		
	//-------------------��X	
				System.out.println(a+"A"+b+"B\t�ѤU"+(9-t)+"�����|");
				a=0;										//���mAB
				b=0;
			}
			
			if(!anscorrect){				//�Y���D���ƥκɥB�S�q�쥿�T����
				System.out.print("�q�D���ƥκɡA���׬�");
				a=0;										//���mAB
				b=0;
				for(int i=0;i<ans.length;i++){
					System.out.print(ans[i]);
				}		
				System.out.print("\n");			
			}
	//-------------------��X
			System.out.println("�O�_�A�ϥΤ@��(��J1�~��A��J0�h�X)");	//���s��J�j��
			re=scan.nextLine();
			
			while(!(re.contains("1")||re.contains("0"))||re.length()!=1){						//�ˬd�O�_��1��0
				System.out.println("�Э��s��J");
				re=scan.nextLine();
				if((re.contains("1")||re.contains("0"))&&re.length()==1){
					break;
				}				
			}
			
			if(re.contains("0")){			//0��������
				break;
			}
		}
		System.out.println("�P�±z���ϥ�");			
	}
}