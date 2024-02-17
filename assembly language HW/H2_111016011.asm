;CF-> CY, AF-> AC, ZF->ZR, SF->PL, OF->OV
INCLUDE Irvine32.inc
;�@��:111016011 ����
;�ާ@����:��J�[����άA������ƹB�⦡, ���{���|�C�L�p�⵲�G
;�۵�:100(�]�t�Ҧ��\��B�����W����)
.data
stringIn BYTE 100 DUP(0)		;�s���J
inputNum DWORD 100 DUP(0)		;�s����
infixArray DWORD 100 DUP(0)		;�s�񤤧Ǧ��r��
postfixArray DWORD 100 DUP(0)	;�s���Ǧ��r��

wordTen WORD 0Ah				;�ΥHx10
stackAmount	DWORD 0				;�s��stack�����B��l�ƶq
count DWORD 0					;�B��l&�B�⤸�ƶq
temp DWORD 0					;�O�d�ƭȥ�
isFirst byte 1					;�ΥH����O�_���Ĥ@�ӼƦr
isLastNumber byte 0				;�ˬd�W�ӬO�_���Ʀr
inputLength DWORD 0				;��J����
parenthesesAmount DWORD 0		;�A���ƶq�A�ΥH����inputLength
sum DWORD 0						;����

outputMsg BYTE "�п�J�Ʀr��",0
personalMsg1 Byte "�@��:111016011����",0
personalMsg2 Byte "�ާ@����:��J�[����άA������ƹB�⦡, ���{���|�C�L�p�⵲�G",0
personalMsg3 Byte "�۵�:100(�]�t�Ҧ��\��B�����W����)",0

.code
main PROC
	mov edx,OFFSET personalMsg1
	call WriteString
	call Crlf
	mov edx,OFFSET personalMsg2
	call WriteString
	call Crlf
	mov edx,OFFSET personalMsg3
	call WriteString
	call Crlf

	mov edx,OFFSET outputMsg
	call WriteString
	call Crlf

	
	mov edx,OFFSET stringIn			;edx ���J������
	mov ecx,100
	call ReadString

	mov ebx,OFFSET infixArray		;ebx��infixArray�����w
	mov ecx,eax		;loop �r����צ�	
	mov eax,0



processString:
	inc inputLength				
	movzx edi, byte ptr [edx]	;���o��e�r����ASCII �X, �é�bedi
	inc edx						;inputString���w����

	cmp edi,'+'
	jz	isOperator
	cmp edi,'-'
	jz	isOperator
	cmp edi,'*'
	jz	isOperator
	cmp edi,'/'
	jz	isOperator
	cmp edi,'('
	jz	isOperator
	cmp edi,')'
	jz	isOperator
	
	jmp isOperand

isOperator:
	cmp isLastNumber,1
	jz LastIsNumber
	jmp endOfLastIsNumber
	LastIsNumber:
		push edi
		mov edi,' '
		mov [ebx],edi					;�s�JinfixArray
		pop edi
		add ebx,type infixArray		;���w����
		inc inputLength
	endOfLastIsNumber:
	mov [ebx],edi					;�s�JinfixArray
	add ebx,type infixArray		;���w����
	mov isLastNumber,0
	jmp endTurnInProcessing
isOperand:
	mov isLastNumber,1
	mov [ebx],edi					;�s�JinfixArray
	add ebx,type infixArray		;���w����
	jmp endTurnInProcessing

endTurnInProcessing:
	loop processString

	sub ebx,type infixArray
	mov eax,[ebx]

	cmp eax,'+'
	jz	endWithOperator
	cmp eax,'-'
	jz	endWithOperator
	cmp eax,'*'
	jz	endWithOperator
	cmp eax,'/'
	jz	endWithOperator
	cmp eax,'('
	jz	endWithOperator
	cmp eax,')'
	jz	endWithOperator

	add ebx,type infixArray
	mov edi,' '
	mov [ebx],edi
	inc inputLength
endWithOperator:
	
;==============�ΪŮ�N�Ʀr�P�Ÿ��j�} eg. 21/4 -> 21_/4
;inputLength: �]�t�Ů檺���סAinfixArray:��z�����}�C���Y

;��XinfixArray
;	mov ebx,OFFSET infixArray	;ebx�^��infix���Y
;	mov ecx,inputLength			;���j����
;outputinfix:	
;	mov eax,[ebx]
;	add ebx,4
;	call writeint
;	loop outputinfix
;
;	call crlf
;	call crlf

;�ѤFpop�X���٭n���

;==============�H�U������	
	mov eax,0
	mov ebx,OFFSET infixArray	;ebx�^��infix���Y
	mov edx,OFFSET postfixArray	;edx��postfix���Y
	mov ecx,0			;���j����			
turnPostfix:	
	mov edi,[ebx]
	add ebx,type infixArray

secondCompare:
	cmp edi,'+'				;if(edi == operator)else������X
	jz	postFixAddAndMinus
	cmp edi,'-'
	jz	postFixAddAndMinus
	cmp edi,'*'
	jz	postFixMulAndDiv
	cmp edi,'/'
	jz	postFixMulAndDiv
	cmp edi,'('
	jz	postFixLP
	cmp edi,')'
	jz	postFixRP				

	jmp postFixNumber		

postFixAddAndMinus:
	mov eax,[esp]		;��Xstack�̤W���A�p�G�D+-*/�h push�i

	cmp eax,'+'
	jz popOperator
	cmp eax,'-'
	jz popOperator
	cmp eax,'*'
	jz popOperator
	cmp eax,'/'
	jz popOperator

	push edi
	inc stackAmount
	
	jmp postfixEndTurn
postFixMulAndDiv:
	mov eax,[esp]		;��Xstack�̤W���A�p�G�D*/�h push�i
	cmp eax,'*'
	jz popOperator
	cmp eax,'/'
	jz popOperator

	push edi
	inc stackAmount

	jmp postfixEndTurn

postFixLP:
	push edi
	inc stackAmount
	add parenthesesAmount,2
	jmp postfixEndTurn

postFixRP:
	mov eax,[esp]		;��Xstack�̤W��
	
	cmp eax,'('
	jz meetLP
	pop eax			
	dec stackAmount
	mov [edx],eax
	add edx,type postfixArray
	jmp postFixRP
	meetLP:

	jmp postfixEndTurn

postFixNumber:		;������Jpostfix

	mov [edx],edi
	add edx,type postfixArray

	jmp postfixEndTurn
popOperator:
	pop eax			;��stack��top���X�A�A���W����i�h
	dec stackAmount
	mov [edx],eax
	add edx,type postfixArray
	jmp secondCompare


	jmp postfixEndTurn
postfixEndTurn:
	inc ecx
	cmp ecx,inputLength
	jnz turnPostfix

	mov ecx,parenthesesAmount 
	;sub stackAmount,ecx
;��Ѿl��pop �X��
	mov ecx,stackAmount
popTheRest:
	pop edi
	cmp edi,'('
	jz popLR
	mov [edx],edi
	add edx,type postfixArray
	popLR:
	loop popTheRest
	
	mov ecx,parenthesesAmount	;�ե��r�����
	sub inputLength,ecx			

;====================
;�T�{postfix�����e
;mov edx,offset postfixArray
;mov ecx,inputLength
;opn:
;	mov eax,[edx]
;	call writeint
;	add edx,type postfixArray
;	loop opn
;
;call crlf


;==================�p�⵲�G
mov eax,0
mov ebx,0
mov edi,offset postfixArray
mov ecx,inputLength

calculate:
	mov ebx,[edi]
	add edi,type postfixArray	

	cmp ebx,'+'
	jz cAdd
	cmp ebx,'-'
	jz cMinus
	cmp ebx,'*'
	jz cMul
	cmp ebx,'/'
	jz cDiv
	cmp ebx,' '
	jz cSpace
	jmp cNumber
cAdd:
	pop edx
	pop eax
	add eax,edx
	push eax

	mov eax,0
	mov edx,0
	jmp endCalculateTurn
cMinus:
	pop edx
	pop eax
	sub eax,edx
	push eax
	mov eax,0
	mov edx,0
	jmp endCalculateTurn
cMul:
	pop temp
	pop eax
	mul temp
	push eax
	mov eax,0
	mov temp,0
	jmp endCalculateTurn
cDiv:
	pop temp
	pop eax
	div temp
	push eax
	mov eax,0
	mov temp,0
	jmp endCalculateTurn
cSpace:
	push eax
	mov eax,0
	jmp endCalculateTurn
cNumber:
	mul wordTen
	sub ebx,'0'
	add eax,ebx
	jmp endCalculateTurn
endCalculateTurn:
	cmp ecx,0
	dec ecx
	jnz calculate

pop eax
call writeint


Exit
main ENDP
END main