<%@ page contentType="text/html; charset=Big5" %>
<%@page import="java.math.BigDecimal"%>		<!--import bigdecimal -->

<HTML>
<HEAD>
<TITLE>�p��L</TITLE>
<!--
	�m�W:����
    �Ǹ�:111016011
    �ާ@����:�p�Pwindows�p��L�A���[����H�Τ@�ǥ\����A�ѩ�ƪ������Y���K�h�]�p�F���v����
	�۵�����:100�A�@�~�n�D�Ҧ��F���A�䴩�Ҧ���ƹB��H�κ�Ǫ��p�ƹB��
 
-->
</HEAD>
<BODY style="background-color:#F5FFE8;">


<!--declarations-->
<%!
	boolean function=false;						//���U�|�h�B����
 	boolean calculate=false;						//�O�_�i��B��
 	boolean error=false;							//���k�O�_�����~
 	String pressedbtn="";			
 	String result="0";
 	String last="";
 	BigDecimal bd_last=new BigDecimal("0");
	BigDecimal bd_result=new BigDecimal("0");
	BigDecimal bd_zero=new BigDecimal("0");
	String history="";
	int arithmetic=0;							//�O���W�ӲŸ� 0->�S���ϥ� 1-> + |2-> - |3-> �� | 4-> ��
	boolean decimal_point=false;					//���L�ϥιL�p���I
%>
<!--scriptlets-->
<%
	if(request.getParameter("btn") != null){		//�p�G���U���s(�ƥ��ť)
					
		if(request.getParameter("btn").equals("C")){	
			result="0";	
			last="";	
			decimal_point=false;	
			arithmetic=0;	
		}else if(request.getParameter("btn").equals("CE")){
			result="0";		
			decimal_point=false;	
		}else if(request.getParameter("btn").equals(".")){	//�p���I
					
			if(!decimal_point){
				result=result+".";
			}		
			decimal_point=true;
					
		}else if(request.getParameter("btn").equals("+")){
			if(arithmetic==0){
				last=result+"+";
			}else{
				last=last.substring(0,last.length()-1)+"+";
			}
			result="0";
			arithmetic=1;
			decimal_point=false;
		}else if(request.getParameter("btn").equals("-")){
			if(arithmetic==0){
				last=result+"-";
			}else{
				last=last.substring(0,last.length()-1)+"-";
			}
			result="0";
			arithmetic=2;
			decimal_point=false;
		}else if(request.getParameter("btn").equals("��")){
			if(arithmetic==0){
				last=result+"��";
			}else{
				last=last.substring(0,last.length()-1)+"��";
			}
			result="0";
			arithmetic=3;
			decimal_point=false;
		}else if(request.getParameter("btn").equals("��")){			
			if(arithmetic==0){
				last=result+"��";
			}else{
				last=last.substring(0,last.length()-1)+"��";
			}
			result="0";
			arithmetic=4;
			decimal_point=false;
		}else if(request.getParameter("btn").equals("=")){				//����
			bd_result=new BigDecimal(result);
			bd_last=new BigDecimal(last.substring(0,last.length()-1));
			history="";
			history=history+last+result;
			switch(arithmetic){
				case 1:
					bd_result=bd_result.add(bd_last);
					break;
				case 2:
					bd_result=bd_last.subtract(bd_result);
					break;
				case 3:
					bd_result=bd_result.multiply(bd_last);
					break;
				case 4:
				
					try{
						bd_result=bd_last.divide(bd_result,8,BigDecimal.ROUND_HALF_UP);
					}catch(Exception e){
						error=true;
					}
					
					if(result.contains(".")){
						while(result.charAt(result.length()-1)=='0'){		//��p�ƫ�h�l��0�h��
							result=result.substring(0,result.length()-1);
						}		
						bd_result=new BigDecimal(result);
					}
					

					break;
			}
			

			
			if(error){
				result="���ణ�H0";
			}else{
				result=bd_result.toPlainString();
			}
						
			error=false;
			
			history=history+"="+result;
			last="";
			arithmetic=0;
			
			if(result.contains(".")){
				decimal_point=true;
			}else{
				decimal_point=false;
			}
			
			
			
		}else if(request.getParameter("btn").equals("-/+")){		//�ۤϼ�
			bd_result=new BigDecimal(result);
			bd_result=bd_zero.subtract(bd_result);	
			result=bd_result.toPlainString();
		
		}else if(request.getParameter("btn").equals("%")){			//�ʤ���
			bd_result=new BigDecimal(result);
			
			
			bd_result=bd_result.divide(new BigDecimal("100"));
			if(new BigDecimal(bd_result.intValue()).compareTo(bd_result)!=0){		//�p�G�B�z�L�ᦳ�p���I����
				decimal_point=true;							//���p���I
			}			
			result=bd_result.toPlainString();
			
		
		}else if(request.getParameter("btn").equals(" ��")){		//�R����
		
			if(result.charAt(result.length()-1)=='.'){
				decimal_point=false;
			}
			result=result.substring(0,result.length()-1);
			if(result.length()==0){
				result="0";
			}
		
		}else if(request.getParameter("btn").equals("1/x")){		//�˼�
			bd_result=new BigDecimal(result);
			
			try{
				bd_result=new BigDecimal("1").divide(bd_result);
			}catch(Exception e){
				bd_result=new BigDecimal("1").divide(bd_result,8,BigDecimal.ROUND_HALF_UP);
			}
			

			
			if(new BigDecimal(bd_result.intValue()).compareTo(bd_result)!=0){		//�p�G�B�z�L�ᦳ�p���I����
				decimal_point=true;							//���p���I
			}			
			result=bd_result.toPlainString();
		
		
		
		}else if(request.getParameter("btn").equals("x^2")){		//����
			bd_result=new BigDecimal(result);
			bd_result=bd_result.multiply(bd_result);
			result=bd_result.toPlainString();
		
		
		}else if(request.getParameter("btn").equals("��x")){		//�}�ڸ�
			bd_result=new BigDecimal(result);

			double a=bd_result.doubleValue();
			a=Math.pow(a,0.5);
			bd_result=new BigDecimal(a);
			
			if(new BigDecimal(bd_result.intValue()).compareTo(bd_result)!=0){		//�p�G�B�z�L�ᦳ�p���I����
				bd_result=new BigDecimal(a).setScale(8,BigDecimal.ROUND_HALF_UP);
				decimal_point=true;							//���p���I
			}
			result=bd_result.toPlainString();
		
		
		}else{							//�Ʀr��
		
			if(result=="0"&&request.getParameter("btn").equals("0")){
				result="0";
			}else if(result=="0"){		//�Ĥ@����J�ɱN0�M��
				result="";
				result=result+request.getParameter("btn");
			}else{
				result=result+request.getParameter("btn");
			
			}
			
		}

		
		
	}


%>



<!--�����]�p-->

<div style= "text-align:center;">
	<font face="DFKai-sb"; text-align:center; size="16" >
		�p��L
	</font>
</div>
<br>

<center>
	<font  size="4" color="555555">
	

		
		
	</font>
</center>
<br>
<form action="cal-111016011.jsp" method="post" name="form">
<table align="center" bgcolor="FFECEC" border="3">	<!--�̥~��-->
	<tr>
		<td><!--�p����]�p-->
			<table align="center" bgcolor="FFECEC" border="0">		<!--���b��-->
			<tr><!--�⦡��X��-->
				<td align='right' valign="middle" colspan="4" style= "height:10px">
					<font  size="3" color="555555" face="monospace">
					 	<%=last%>
			 		</font>
				</td>
			</tr>			   
			<tr><!--�Ʀr��X��-->
				<td align='right' valign="middle" colspan="4" style= "height:50px">
					<font  size="6" color="555555" face="monospace">
					 	<%=result%>
			 		</font>
				</td>
			</tr>
			   
			<tr><!--����-->
			     <td align='center' valign="middle">
			     	<input style= "background-color:#FFECF5;height:50px;width:75px;"type="submit" name="btn" value="%" >
			     </td>
			     <td align='center' valign="middle">
			     	<input style= "background-color:#FFECF5;height:50px;width:75px;"type="submit" name="btn" value="CE" >
			     </td>
			     <td align='center' valign="middle">
			     	<input style= "background-color:#FFECF5;height:50px;width:75px;"type="submit" name="btn" value="C" >
			     </td>
			     <td align='center' valign="middle">
			     	<input style= "background-color:#FFFCEC;height:50px;width:75px;"type="submit" name="btn" value=" ��" >
				</td>
			</tr>
			 
			<tr>
			     <td align='center' valign="middle">
			     	<input style= "background-color:#FFECF5;height:50px;width:75px;"type="submit" name="btn" value="1/x" >
			     </td>
			     <td align='center' valign="middle">
			     	<input style= "background-color:#FFECF5;height:50px;width:75px;"type="submit" name="btn" value="x^2" >
			     </td>
			     <td align='center' valign="middle">
			     	<input style= "background-color:#FFECF5;height:50px;width:75px;"type="submit" name="btn" value="��x" >
			     </td>
			     <td align='center' valign="middle">
			     	<input style= "background-color:#FFECF5;height:50px;width:75px;"type="submit" name="btn" value="��" >
			     </td>
			</tr> 
			
			<tr>
			     <td align='center' valign="middle">
			     	<input style= "background-color:#FFECF5;height:50px;width:75px;"type="submit" name="btn" value="7" >
			     </td>
			     <td align='center' valign="middle">
			     	<input style= "background-color:#FFECF5;height:50px;width:75px;"type="submit" name="btn" value="8" >
			     </td>
			     <td align='center' valign="middle">
			     	<input style= "background-color:#FFECF5;height:50px;width:75px;"type="submit" name="btn" value="9" >
			     </td>
			     <td align='center' valign="middle">
			     	<input style= "background-color:#FFECF5;height:50px;width:75px;"type="submit" name="btn" value="��">
			     </td>
			</tr> 

			<tr>
			     <td align='center' valign="middle">
			     	<input style= "background-color:#FFECF5;height:50px;width:75px;"type="submit" name="btn" value="4" >
			     </td>
			     <td align='center' valign="middle">
			     	<input style= "background-color:#FFECF5;height:50px;width:75px;"type="submit" name="btn" value="5" >
			     </td>
			     <td align='center' valign="middle">
			     	<input style= "background-color:#FFECF5;height:50px;width:75px;"type="submit" name="btn" value="6" >
			     </td>
			     <td align='center' valign="middle">
			     	<input style= "background-color:#FFECF5;height:50px;width:75px;"type="submit" name="btn" value="-">
			     </td>
			</tr> 

			<tr>
			     <td align='center' valign="middle">
			     	<input style= "background-color:#FFECF5;height:50px;width:75px;"type="submit" name="btn" value="1" >
			     </td>
			     <td align='center' valign="middle">
			     	<input style= "background-color:#FFECF5;height:50px;width:75px;"type="submit" name="btn" value="2" >
			     </td>
			     <td align='center' valign="middle">
			     	<input style= "background-color:#FFECF5;height:50px;width:75px;"type="submit" name="btn" value="3" >
			     </td>
			     <td align='center' valign="middle">
			     	<input style= "background-color:#FFECF5;height:50px;width:75px;"type="submit" name="btn" value="+">
			     </td>
			</tr> 

			<tr>
			     <td align='center' valign="middle">
			     	<input style= "background-color:#FFECF5;height:50px;width:75px;"type="submit" name="btn" value="-/+" >
			     </td>
			     <td align='center' valign="middle">
			     	<input style= "background-color:#FFECF5;height:50px;width:75px;"type="submit" name="btn" value="0" >
			     </td>
			     <td align='center' valign="middle">
			     	<input style= "background-color:#FFECF5;height:50px;width:75px;"type="submit" name="btn" value="." >
			     </td>
			     <td align='center' valign="middle">
			     	<input style= "background-color:#FFECF5;height:50px;width:75px;"type="submit" name="btn" value="=">
			     </td>
			</tr> 
			
			</table>
		</td>
		
		<td><!--�W�@������-->
			<table bgcolor="FFECEC" border="0">		<!--�k�b��-->
			   <tr>
				 <td align='center' valign="middle" style= "height:60px;width:220px;">
				 	<font  face="DFKai-sb"; size="6">
				 		�W���B��
				 	</font>
				 </td>
			   </tr>
			   
			   <tr>
				 <td align='center' valign="middle" style= "height:320px;">
				 	<font  face="DFKai-sb"; size="6">
				 		<%=history%>
				 	</font>
				 </td>
			   </tr>
			</table>
		</td>
	</tr>
</table>
</form>
</BODY>
</HTML>