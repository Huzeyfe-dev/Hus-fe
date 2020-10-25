# ifndef STRING_H	
# include "string.h"
# endif

extern void shutdown();

void hlt()
{
	__asm__ __volatile__ ("hlt");
}


char dene(uint8_t * str)
{
	if (kiyasla(str, "hlt")==1) hlt();
	//if (kiyasla(str, "std")==1) shutdown();
	return 0;
}

void gir(n1 nn, n1 mm)
{
	uint8_t * str;
	uint8_t * ckt;

	_2b_girdi(nn,str);
	y_ciz(nn,str);
	
	char ret = dene(str);
	
	if(ret==0) ckt = "kod taninmadi.";

	/*if(ret==0) ckt="Hata var.";
	if(ret==1) ckt="Yazilar esit.";
	if(ret==2) ckt="Yazilarin sadece uzunluklari esit.";
	if(ret==3) ckt="Ilk yazi ikinciden uzun.";
	if(ret==4) ckt="Ikinci yazi birinciden uzun.";
	*/
	
	y_ciz(mm,ckt);

	uyut(0x02FFFFFF);
}


