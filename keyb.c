unsigned char Keyb_Get_Scan_Code()
{
	_asm 
		{
		mov ah,01h
		int 16h
		jz buffer_empty
		mov ah,00h
		int 16h
		mov al,ah
		xor ah,ah
		jmp done

	buffer_empty:
		xor ax,ax

	done:
		}
}

unsigned int Get_Shift_State(unsigned char mask)
{
	_asm 
	{
		mov ah,02h
		int 16h
		mov ah, BYTE PTR mask
		test al,ah
		jnz passedTest
		xor ax,ax
		jmp done

	passedTest:
		mov ax, 01h

	done:
	}
}
