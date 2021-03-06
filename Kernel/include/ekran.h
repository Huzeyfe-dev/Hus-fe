# ifndef EKRAN_H
# define EKRAN_H
# endif

# ifndef TYPE_H
# include "type.h"
# endif

# ifndef HARF_H
# include "harf.h"
# endif

# ifndef PORT_H
# include "port.h"
# endif

# ifndef CEVIR_H
# include "cevir.h"
# endif

// Ekran adresini tanımlar

# ifndef VGA_ADRES
# define VGA_ADRES 0xB8000
# endif

// Klavyeyi tanımlar

# ifndef KLAVYE_ADRES
# define KLAVYE_ADRES 0x60
# endif

// genel değişkenler

uint16_t * terminal = (uint16_t *) VGA_ADRES;
uint32_t t_imlec = 0;
uint16_t _satir = 0;

void temizle()
{
	for(t_imlec = 0 ; t_imlec <80*25*2 ; t_imlec += 2)
	{
		terminal [t_imlec] = (uint8_t) ' ' | (uint16_t) 0x00<<8;
	}

	t_imlec = 0;
}

void satir_basi()
{
	t_imlec = _satir * 80;
}

void print_char(uint8_t ch, uint16_t renk)
{
	terminal [t_imlec] = (uint8_t) ch | (uint16_t) renk << 8;
	t_imlec++;
	if(t_imlec == 80)
	{
		_satir ++;
		satir_basi();
	}
}

void print_str(uint8_t * str, uint16_t renk)
{
	uint8_t index = 0;
	uint8_t ch = str[0];

	while(ch != '\0')
	{
		print_char(ch, renk);
		index++;
		ch = str[index];
	}
}

// ----- kutucuklar -----

// Ekrana yazılacak nesneler (kareler vs.) için veriler tutar.
typedef struct
{
	uint16_t boy;
	uint16_t en;
	uint16_t satir;
	uint16_t sutun;
	uint16_t renk;
}n1;

void _1boyut(uint8_t kenar, uint8_t satir, uint8_t sutun, uint16_t color)
{
	uint32_t imlec = sutun + satir*80;

	for(uint8_t i=0; i<kenar;i++)
	{
		terminal [imlec] = (uint8_t)' '|(uint16_t)color << 8;
		imlec++;
	}
}

void _2boyut(uint16_t boy, uint16_t en, uint16_t satir, uint16_t sutun, uint16_t color)
{	
	for(int i=0; i<boy; i++)
	{
		_1boyut(en, satir+i, sutun, color);
	}
}

void yazili_2boyut(uint16_t boy, uint16_t en, uint16_t satir, uint16_t sutun, uint16_t color, uint8_t *str)
{
	_2boyut(boy, en, satir, sutun, color);

	en+=sutun;
	boy+=satir;

	uint16_t i = sutun; 		// satır uzunluğunu tutar
	uint16_t j = satir;			// satır sayısınu tutar
	uint16_t index = 0;
	
	while(str[index]) 
	{
		terminal [i + j*80] = (uint16_t) str[index] | (uint16_t) color << 8;
		index++;
		i++;

		if (i == en)
		{
			i = sutun;
			j++;
		}

		if(j == boy)	j = satir;
	}
}

// nesneler için çizme fonksiyonları
void ciz(n1 nn)
{
	_2boyut (nn.boy, nn.en, nn.satir, nn.sutun, nn.renk);
}

void y_ciz(n1 nn, uint8_t * str)
{
	yazili_2boyut (nn.boy, nn.en, nn.satir, nn.sutun, nn.renk, str);
}

// Sisetemi say değeri kadar bekletir.
void uyut(uint32_t say)
{
	for (int i = 0; i < say; ++i)
	{
		asm volatile("nop");
	}
}


// klavyeden harf alır
uint8_t harf_al()
{
	uint8_t deger = inb(KLAVYE_ADRES);
	uint8_t tmp = shc(deger);

	if(tmp == '\0') return deger;

	return tmp;
}

uint8_t str_al(uint16_t renk)
{
	uint8_t * str;
	uint8_t harf;
	uint16_t i=0;

	while(1)
	{
		harf = harf_al();
		if(harf == ENTER) break;
		str[i] = harf;
		i++;
		print_char(harf, renk);
		uyut(0x02FFFFFF/2);
	}

	str[i+1] = '\0';

	return * str;

}

void _2b_girdi(n1 np, uint8_t * str)
{

	ciz(np);
	uint8_t harf;
	uint16_t x = 0;
	
	/*while(str[x]!='0')
	{
		str[x]=' ';
		x++;
	}

	str[x+1]='0';
*/
	uint8_t deger;
	uint16_t i = np.sutun;		// sütun
	uint16_t j = np.satir;		// satır

	while(1)
	{
		deger = inb(KLAVYE_ADRES);

		if(deger == ENTER)
		{
			break;
			//j++;
			//i=np.sutun;
		}

		//if(deger == ESC) break;

		harf = shc(deger);

		if(harf != '0')
		{
			str[x] = harf;
			x++;

			terminal [i + j*80] = (uint8_t) harf | (uint16_t) np.renk << 8;
			i++;

			if (i == np.en+1)
			{
				i = np.sutun;
				j++;
			}

			if(j == np.boy)
			{	
				j = np.satir;
				ciz(np);
			}
		}

		uyut(0x02FFFFFF/3);
	}

	str[x] = '\0';

	return;
}

