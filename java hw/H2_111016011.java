import java.util.Scanner;
/*
 �@��:��G�� ���� 111016011
 �ާ@����:��J�h�Ӿ�ơA�����H�Ů���}�A�|�N�o�Ǿ�ƥH�p��j�ƦC
 �۵�:100 �\��Ҧ��F���B�ॿ�T�B�@�B���O��J�O�_����ơA�ƦC����k���Ѧҽҥ�6-3
 �B�~�\��:�i���s��J�A�B����뭫�s��J�O�_��1�B0�άO��L��J
 */

public class H2_111016011{
	public static void main(String[] args) {
			Scanner scan = new Scanner(System.in);
			boolean checkint=true;	//�T�{input�O�_����ƪ����L��
			String re;					//���ƨϥ�
			int min;
			int max;
			int point;
			while(true){
				while(checkint){
					checkint=false;
					System.out.println("�п�J�h�Ӿ��(������1�ӪŮ�j�})");
					
					String[] input= scan.nextLine().split(" "); //��J�åH�Ů���Φr��									
					int num[]=new int[input.length];			
					int output[]=new int[input.length];					
					for(int i=0;i<input.length;i++){				//�N�r��}�C�̧��ন��ư}�C�A���ˬd���L���~
						try{
							num[i] = Integer.parseInt(String.valueOf(input[i]));
							
						}catch(Exception e){		//�Y��J���~
							System.out.println("��J���~�A�Э��s��J");
							checkint=true;
							break;
						}
					}
					
					if(!checkint){										//�p�G�Ʀr�꥿�T�h�ƧǨÿ�X�A�Y�����T�h���L���B�J�í��s��J
						for(int i=0;i<input.length;i++){				//�N���ΥX���r��Hint�s�Jnum
							num[i] = Integer.parseInt(String.valueOf(input[i]));	
						}
						min=num[0];	
	//------------------------------------------�j�p�Ƨ�
						for(int i=0;i<num.length;i++){		//��X�̤p��min		
							if(min>num[i]){					
							min=num[i];
							}
						}
						
						for(int j=0;j<num.length;j++){			//�}�C�ƧǡA����̤j���M��̧ǩ�boutput�᭱
							max=min;
							point=0;
							for(int i=0;i<num.length;i++){		//��X�̤j�ȡA�ç�point�w���̤j�Ȧ�m
								if(max<num[i]){					
									max=num[i];
									point=i;
								}
								
							}	
							num[point]=min-1;							//���쪺�̤j�ȴ����̤p��-1
							output[output.length-1-j]=max;				//��̤j�ȱq�k�䩹����
														
						}
	//-------------------------------------------�j�p�Ƨ�
						for(int i=0;i<output.length;i++){			//��X
							System.out.print(output[i]+" ");
						}
						
						System.out.print("\n");							
					}
	
				}

				checkint=true;				
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
	}
}

