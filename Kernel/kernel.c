# include "include/kernel.h"
# include "include/kabuk.c"

void main(void)
{

	temizle();

	n1 nn = {10, 20, 2, 1, 0x10};
	n1 mm = {10, 20, 2, 21, 0x20};

	uint8_t * str;

	yazili_2boyut(1, 20, 1, 1, 0x01, "Girdi");
	yazili_2boyut(1, 20, 1, 21, 0x02, "Cikti");

	ciz(nn);
	ciz(mm);
	
	while(1)
	{
		gir(nn,mm);
	}
	
	return ;
}
