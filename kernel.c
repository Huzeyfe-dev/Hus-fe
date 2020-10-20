# include "h/kernel.h"

void main(void)
{

	terminal = (uint16_t *) VGA_ADRES;
	
	uint8_t * yazi = "Merhaba, bu basit bir isletim sistemidir. Pek bir sey yapamaz. ";

	temizle();
	yazili_2boyut(10,20,0,0, 0x10, yazi);

	n1 * nn;
	nn -> boy = 10;
	nn -> en = 20;
	nn -> satir = 0;
	nn -> sutun = 20;
	nn -> renk = 0xFA;

	//y_ciz(nn, "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");

	//yazili_2boyut(10,20,10,20,0x53, "aaaaaaaaaabbbbbbbbbbccccccccccddddddddddeeeeeeeeeeaaaaaaaaaabbbbbbbbbbccceeeeeeeeeaaaaaaaaaabbbbbbbbbbccccccccccddddddddddeeeeeeeeeeaaaaaaaaaabbbbbbbbbbccccccccccddddddddddeeeeeeeeeeaaaaaaaaaabbbbbbbbbbccccccccccddddddddddeeeeeeeeee");

	y_ciz(nn, yazi);

	return ;
}
