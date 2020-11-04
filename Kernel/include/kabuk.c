# ifndef STRING_H	
# include "string.h"
# endif

# ifndef TYPE_H
# include "type.h"
# endif

# ifndef EKRAN_H
# include "ekran.h"
# endif

typedef struct
{
	n1 * np;
	uint32_t imlec;
	uint32_t satir;
	uint32_t sutun;
}n2;



// yeni fonksiyon


void n2_print(n2 * np, uint8_t * str)
{
	n1 * tmp = np->np;
	np->imlec = 80*(tmp->satir+np->satir) + tmp->sutun + np->sutun;


	uint16_t index=0;
	//uint32_t i=0;; // sütun için

	while(str[index])
	{
		if(str[index]=='\n')
		{
			np->satir++;
			np->imlec = (np->satir+tmp->satir)*80 + tmp->sutun;
			np->sutun = 0;
		}
		
		else
		{
			terminal[np->imlec] = (uint8_t) str[index] | (uint16_t) tmp->renk << 8;
			np->imlec++;
			np->sutun++;
		}
		
		index++;
		
		if(np->sutun==tmp->en)
		{
			np->satir++;
			np->imlec = (np->satir+tmp->satir)*80 + tmp->sutun;
			np->sutun=0;;
		}

		if(np->satir==tmp->boy)
		{
			ciz(*tmp);
			np->satir=0;
			np->imlec = tmp->satir*80 + tmp->sutun;
			np->sutun=0;
		}
	}
}





void help(uint8_t * str)
{
	str = "Help\nCommands:\n- hlt : halts the cpu\n- help: shows these help";
}

void hlt()
{
	__asm__ __volatile__ ("hlt");
}


char dene(uint8_t * str, uint8_t * ckt)
{
	if (kiyasla(str, "hlt")==1) hlt();
	else if (kiyasla(str, "help")==1)
	{
		ckt = "Help\nCommands:\n- hlt : halts the cpu\n- help: shows these help";
		ckt[49]='\0';
		return 1;
	}
	return 0;
}

// eski fonksiyon

void gir(n1 nn, n2 * nn2)
{
	uint8_t * str;
	uint8_t * ckt;

	for(short i; i<50;i++)
	{
		str[i] = ' ';
		ckt[i] = ' ';
	}

	_2b_girdi(nn,str);
	//y_ciz(nn,str);
	
	char ret = dene(str, ckt);
	
	if(ret==0)
	{
		n2_print(nn2, "kod taninmadi:");
		n2_print(nn2, str);
		n2_print(nn2, "\n");
	}
	else
	{
		n2_print(nn2, ckt);
	}
	//y_ciz(mm,ckt);

	uyut(0x02FFFFFF);
}