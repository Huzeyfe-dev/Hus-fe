# ifndef HARF_H
# define HARF_H
# endif

# ifndef TYPE_H
# include "type.h"
# endif

#define KEY_A 0x1E
#define KEY_B 0x30
#define KEY_C 0x2E
#define KEY_D 0x20
#define KEY_E 0x12
#define KEY_F 0x21
#define KEY_G 0x22
#define KEY_H 0x23
#define KEY_I 0x17
#define KEY_J 0x24
#define KEY_K 0x25
#define KEY_L 0x26
#define KEY_M 0x32
#define KEY_N 0x31
#define KEY_O 0x18
#define KEY_P 0x19
#define KEY_Q 0x10
#define KEY_R 0x13
#define KEY_S 0x1F
#define KEY_T 0x14
#define KEY_U 0x16
#define KEY_V 0x2F
#define KEY_W 0x11
#define KEY_X 0x2D
#define KEY_Y 0x15
#define KEY_Z 0x2C
#define SPACE 0x39
#define ENTER 0x1C
#define ESC 0x01
#define BACKSPACE 0x0E

uint8_t h_deger[] = {

KEY_A, KEY_B, KEY_C,
KEY_D, KEY_E, KEY_F,
KEY_G, KEY_H, KEY_I,
KEY_J, KEY_K, KEY_L,
KEY_M, KEY_N, KEY_O,
KEY_P, KEY_Q, KEY_R,
KEY_S, KEY_T, KEY_U,
KEY_V, KEY_W, KEY_X,
KEY_Y, KEY_Z, SPACE };

uint8_t harfler[] = {
'a','b','c','d','e',
'f','g','h','i','j',
'k','l','m','n','o',
'p','q','r','s','t',
'u','v','w','x','y',
'z',' '};

uint8_t shc(uint8_t deger) // Sayidan Harfe Çevir = shc
{
	uint16_t i;

	for(i = 0; i<27; i++)
	{
		if(h_deger[i]==deger)
		{
			return (uint8_t) harfler[i];
		}
	}

	return (uint8_t) '0';
}
