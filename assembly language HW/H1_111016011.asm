;CF-> CY, AF-> AC, ZF->ZR, SF->PL, OF->OV
INCLUDE Irvine32.inc
;�@��:111016011����
;�ާ@����:��J�@��ƭ�,�����Ϊťչj�}�A�i�H�N��J���Ʀr���Ӽƭ�,�Ѥj��p�Ƨ�
;�۵�:100(�]�t�Ҧ��\��B�����W����)
.data
stringIn BYTE 100 DUP(0)		;�s���J
inputNum DWORD 100 DUP(0)		;�s����
count DWORD 0					;��Ƽƶq
wordTen WORD 0Ah				;�ΥHx10
isFirst byte 1					;�ΥH����O�_���Ĥ@�ӼƦr
temp DWORD 0					;�洫��
outputMsg BYTE "�п�J�Ʀr��",0
personalMsg1 Byte "�@��:111016011����",0
personalMsg2 Byte "�ާ@����:��J�@��ƭ�,�����Ϊťչj�}�A�i�H�N��J���Ʀr���Ӽƭ�,�Ѥj��p�Ƨ�",0
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


	mov ebx,OFFSET inputNum
	mov edx,OFFSET outputMsg
	call WriteString
	call Crlf

	mov edx,OFFSET stringIn			;edx�s�r��
	mov ecx,100
	call ReadString


	mov ecx,eax		;loop �r����צ�	
	mov eax,0
	push edx

processString:	
	mov edi,0
	movzx edi, byte ptr [edx]	;���o��e�r����ASCII�X
	add edx,1
									
	cmp edi,' ' 				
	jnz notSpace
	cmp edi,0					
	jz isSpace
								;�p�G���O�Ů�Aeax���򩹤U�����A����J��Ů�
	inc count
	mov [ebx],eax
	add ebx,type inputNum		;�s��}�C��

	mov isFirst,1
	mov eax,0
	jmp isSpace				;�J��ťո��L
notSpace: 
	push edx
	sub edi ,'0'			;��ASCII��^�Ʀr
		
	cmp isFirst,1
	jz First
	mul wordTen				;�p�G���O�Ĥ@���h*10�[�s�Ʀr
First: 
	add eax,edi
	mov isFirst,0
	pop edx
	
		
isSpace:
 	loop processString

	inc count
	mov [ebx],eax
	add ebx,type inputNum		;�s��}�C��
	pop edx

	;�Ƨ�
	mov ecx,count
	dec ecx
sortLoop2:				;�~�j��

;���j��
	push ecx
	mov ecx,count
	dec ecx
sortLoop1:
	;if(not (A[i]>A[i+1]))->dont swap
	push eax
	mov eax,[inputNum+ecx*4]
	cmp eax,[inputNum+ecx*4+4]
	pop eax
	jge notSwap	
	;�洫
	push eax
	push ebx
	mov eax,[inputNum+ecx*4]	
	mov ebx,[inputNum+ecx*4+4]
	mov [inputNum+ecx*4+4],eax
	mov [inputNum+ecx*4],ebx
	pop ebx
	pop eax
notSwap:
	sub ecx,1
	cmp ecx,0
	jge sortLoop1

	pop ecx
;�~�j��P�w
	sub ecx,1
	cmp ecx,0
	jge sortLoop2			;�^��~�j��̤W��

	;��X�}�C
	mov ebx,0			;for(ebx=n;ebx>0;ebx--)
outputArray:
	mov eax,[inputNum+ebx*4]		
	call writeint
	mov al,' '
	call writechar
	inc ebx
	cmp ebx,count
	jnz outputArray

Exit
main ENDP
END main