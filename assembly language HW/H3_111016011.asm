;CF-> CY, AF-> AC, ZF->ZR, SF->PL, OF->OV
INCLUDE Irvine32.inc
;�@��:111016011 ����
; �{���ާ@����: ���{���|��48��35���[��k�A�|����ܥ[�k(DAA)�����G�A�A��ܴ�k(DAS)
; �۵�����:100��	(�]�t�Ҧ��\��B�����W����)
.data
.code
main PROC		;�D�{��
	mov al, 35h
	add al, 48h
	call newDAA
	call DumpRegs	;��ܥثe���p

	mov al, 48h
	sub al, 35h
	call newDAS
	call DumpRegs
	INVOKE ExitProcess, 0
main ENDP

;==========�s�禡

newDAA PROC		;��DAA�A���[�k�̫�HPacked BCD��ܡA�ç��CF�BAF�X��
	mov bl, al
	lahf				;�� EFlag �C8bits �e�i AH
	mov cl, ah
	and bl, 00001111b	;�u�O�d��|��
	and cl, 00010000b	;�u�O�dcarry
	shr cl,4			;��carry ����Ĥ@��


	.IF bl > 9 || cl == 1	;if(al(lo)>0 or Carry == 1)
		add al, 6
		pushf
		or ah,00010000b		;Carry = 1
		popf
		sahf				;��AH��8bit�e��Eflag
	.ELSE
		pushf
		or ah,00000000b		;Carry = 0
		popf
		sahf				;��AH��8bit�e��Eflag
	.ENDIF

	lahf					
	mov cl, ah
	and cl, 00000001b

	mov bl, al
	and bl, 11110000b 
	shr bl,4			;��e 4bits����� 4bits



	.IF bl > 9 || cl == 1 ;if(al > 0 or Carry == 1)
		add al, 60h
		pushf
		or ah, 00000001b	;Carry = 1
		popf
		sahf				;��AH��8bit�e��Eflag
	.ELSE
		pushf
		or ah, 00000000b	;Carry = 0
		popf
		sahf				;��AH��8bit�e��Eflag
	.ENDIF

ret
newDAA ENDP

;=================DAS

newDAS PROC		;��DAS�A����k�̫�HPacked BCD��ܡA�ç��CF�BAF�X��
	mov bl, al
	lahf				;�� EFlag �C8bits �e�i AH
	mov cl, ah
	and bl, 00001111b	;�u�O�d��|��
	and cl, 00010000b	;�u�O�dcarry
	shr cl,4			;��carry ����Ĥ@��

	.IF bl > 9 || cl == 1	;if(al(lo)>0 or Carry == 1)
		sub al, 6
		pushf
		or ah,00010000b		;Carry = 1
		popf
		sahf				;�� AH �� 8 bit �e��Eflag
	.ELSE
		pushf
		or ah,00000000b		;Carry = 0
		popf
		sahf				;�� AH �� 8 bits �e�� Eflag
	.ENDIF


	lahf					
	mov cl, ah
	and cl, 00000001b



	.IF al > 9Fh || cl == 1 ;if(al > 0 or Carry == 1)
		sub al, 60h
		pushf
		or ah, 00000001b	;Carry = 1
		popf
		sahf				;��AH �� 8bits �e�� Eflag
	.ELSE
		pushf
		or ah, 00000000b	;Carry = 0
		popf
		sahf				;��AH �� 8bits �e�� Eflag
	.ENDIF

ret
newDAS ENDP


END main