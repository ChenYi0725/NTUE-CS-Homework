import java.util.Scanner;
/*
  �@��:��G�� ���� 111016011
  �ާ@����:�̧ǿ�J�~�B��B��A�t�η|��X�����P��Ѫ��P��
  �۵�:100 �\��Ҧ��F��
  �B�~�\��:�b���W�ХܥX��J����B�i���ƨϥΡB�i��O��J�O�_���~
 */
public class H4_111016011{
	public static void main(String args[]){
		Scanner scan=new Scanner(System.in);
		String re;					//���ƨϥ�
		int year=0,month,date,days;		//�ؼЦ~���B��릳�X��
		int shift=0,week=0,dweek=0;				//1�����첾�B�P�_�O�_���檺�ܼơB�ؼЪ��P��
		boolean input;
		while(true){						//���ƨϥ�
			shift=0;						//���s�]�w�ƭ�
			week=0;
			dweek=0;
			input=false;		
			System.out.println("�п�J�~��");
			while(true){
				try{
					year=scan.nextInt();
				}catch(Exception e){
					System.out.println("��J���~�A�Э��s��J");
					scan.nextLine();		//�������~��J
					continue;
				}		
				break;				
			}
			System.out.println("�п�J���");
			while(true){
				try{
					month= scan.nextInt();
				}catch(Exception e){
					System.out.println("��J���~�A�Э��s��J");
					scan.nextLine();		//�������~��J
					continue;
				}		
				if(month<1||month>12){
					System.out.println("��J���~�A�п�J1~12��");
					continue;	
				}
				break;				
			}		
	//------------�p���릳�X��	
			if(month<=7&&month%2!=0){
				days=31;
			}else if(month>=8&&month%2==0){
				days=31;
			}else if(month==2){
				if(year%4==0){			//�p�G�O�|�~
					days=29;
				}else{
					days=28;
				}
			}else{
				days=30;
			}
	//------------�p���릳�X��
			System.out.println("�п�J���");
			while(true){
				try{
					date= scan.nextInt();
				}catch(Exception e){
					System.out.println("��J���~�A�Э��s��J");
					scan.nextLine();		//�������~��J
					continue;
				}		
				if(date<1||date>days){
					System.out.println("��J���~�A"+month+"��u��"+days+"��");
					continue;	
				}
				break;				
			}			
	//------------�p��shift
			if(year>2018){				//�ؼЦb2018��(�]��2018��1/1��n�b�g�@)
				for(int i=2018;i<year;i++){
					if(i%4==0){
						shift=shift+2;
					}else{
						shift=shift+1;
					}
				}
			}else{
				for(int j=year;j<2018;j++){			//�ؼЦb2018�~��
					if(j%4==0){
						shift=shift+2;
					}else{
						shift=shift+1;
					}
				}
				shift=7-(shift%7);
			}
			
			switch (month){							//�p��C�Ӥ�v�Tshift���{�סAshift��[�W���Ʀr�O���e���Ҧ�������Ѽ�%7
				case 2:
					shift=shift+3;
					break;
				case 3:
					shift=shift+3;
					break;
				case 4:
					shift=shift+6;
					break;
				case 5:
					shift=shift+1;
					break;
				case 6:
					shift=shift+4;
					break;
				case 7:
					shift=shift+6;
					break;
				case 8:
					shift=shift+2;
					break;
				case 9:
					shift=shift+5;
					break;
				case 10:
					break;
				case 11:
					shift=shift+3;
					break;
				case 12:
					shift=shift+5;
					break;
				}
			if(month>2&&year%4==0){			//�p�G�O�|�~�A�B�b2���
				shift=shift+1;
			}
			
			shift=shift%7;			//�̫�T�Oshift<7	
			System.out.print("�@\t�G\t�T\t�|\t��\t��\t��\n");	//��X�P��
			for(int k=0;k<shift;k++){
				System.out.print("\t");
				week=week+1;
			}
			
			for(int l=1;l<days+1;l++){
				if(date==l){
					System.out.print("["+l+"]\t");		//�إX�ؼФ��
				}else if(l<10){							//��X���(�p�G�u���@���
					System.out.print(" "+l+"\t");
				}else{
					System.out.print(l+"\t");	
				}
				week=week+1;
				if(l==date){
					dweek=week;
				}
				if(week==7){
					week=0;
					System.out.print("\n");
				}
			}
			System.out.print("\n");
			System.out.print(year+"�~"+month+"��"+date+"��A�O�P��");	
			switch(dweek){						//�̷ӷ�骺�P����X��������
				case 1:
					System.out.println("�@");
					break;
				case 2:
					System.out.println("�G");
					break;
				case 3:
					System.out.println("�T");
					break;
				case 4:
					System.out.println("�|");
					break;
				case 5:
					System.out.println("��");
					break;
				case 6:
					System.out.println("��");
					break;
				case 7:
					System.out.println("��");
					break;
				
			}//switch
//---------------���ƨϥ�(��J�P�P�_)
			System.out.println("�O�_�A�ϥΤ@��(��J1�~��A��J0�h�X)");	//���s��J�j��
			re=scan.next();
			
			while(!(re.contains("1")||re.contains("0"))||re.length()!=1){						//�ˬd�O�_��1��0
				System.out.println("�Э��s��J");
				re=scan.next();
				if((re.contains("1")||re.contains("0"))&&re.length()==1){
					break;
				}				
			}
			if(re.contains("0")){			//0��������
				break;
			}
//---------------���ƨϥ�(��J�P�P�_)
		}//while	
	}
}