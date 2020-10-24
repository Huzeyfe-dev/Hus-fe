# include "include/kernel.h"

void main(void)
{

	

	//uint8_t * yazi1 = "Merhaba, bu basit bir isletim sistemidir. Pek bir sey yapamaz. ";
	uint8_t * yazi2 = "Su anda bir program icinde calisan bir isletim sistemine bakmaktasiniz. Guvenlik amaciyla dogrudan calistirilmadi.";
	uint8_t * yazi3 = "Gelecege karar vermek istiyorsan, kodlamayi ogrenmek zorundasin. -Ali Yildirim-";
	uint8_t * yazi4 = "'Derleme tamamlandi' cumlesi kadar guzel baska bir cumle yoktur.";
	uint8_t * ben   = "-Huzeyfe Cagilci-";

	temizle();

	//_2boyut(25,80,0,0,0x10);

	n1 nnn = {10,20,1,1,0x2F};
	n1 mmm = {5,20,11,1,0x3F};

	//yazili_2boyut(10, 20, 1, 1, 0x2F, yazi1);
	yazili_2boyut(10, 20, 1, 23, 0x3F, yazi3);
	yazili_2boyut(10, 20, 1, 45, 0x53, yazi4);
	yazili_2boyut(1, 20, 10, 45, 0x7F, ben);
	yazili_2boyut(5, 78, 19, 1, 0x4F, yazi2);

	y_ciz(mmm, "Burasi cikti");
	uint8_t * girdi;
	while(1)
	{
		_2b_girdi(nnn, girdi);
		y_ciz(mmm, girdi);

		uyut(0x02FFFFFF);
	}


	return ;
}
