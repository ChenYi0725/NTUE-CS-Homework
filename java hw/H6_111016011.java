import java.util.*;//d�Bf
/*
  �@��:��G�� ���� 111016011
  �ާ@����:���ƿ�J�@�ӼƦr�A�t�η|�N��֥[�ÿ�X�A���Xq�ɫh�|�����J
  �۵�:100 �\��Ҧ��F��
  �B�~�\��:�i���ƨϥ�
 */
public class H6_111016011{
	public static void main(String args[]){
		Scanner scan=new Scanner(System.in);
		String re;									//���ƨϥ�	
		String input="0";							//��J�r��
		float num=0,total=0;						//����J��B�I�ơA���Ӽƥ[�`����

		while(true){
			num=0;													//�N�W���ϥΪ��ܼƳ]�^��l��
			total=0;
			for(int i=1;i<6;i++){									//���ƿ�J���ӼƦr
				System.out.println("�п�J�� "+i+" �ӼƦr");	
				input=scan.nextLine();								//��J
				if(input.contains("q")&&input.length()==1){			//��Jq�����{��
					break;									
				}
				
				if(input.contains("d")||input.contains("f")){		//�Y��J���̫�@�Ӧr����d��f�ɤ��|���X�ҥ~�A�ҥH�[�@�ӧP�_������
					System.out.println("��J���~�A�Э��s��J�@�ӼƦr");	
					i--;											//���o����J���p��
					continue;
				}
				
				try{
					num=Float.valueOf(input);						//String ��float
						
				}catch(Exception e){
					System.out.println("��J���~�A�Э��s��J�@�ӼƦr");	
					i--;											//���o����J���p��
					continue;
				}
				total=total+num;									//�[�`��J����
				
			}
			
			System.out.println("�`�X���G"+total);
//----------------------------���ƨϥ�			
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
//----------------------------���ƨϥ�			
			
		}
		System.out.println("�P�±z���ϥ�");	

	}
}