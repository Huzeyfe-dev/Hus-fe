# ifndef KERNEL_H
# define KERNEL_H
# endif

// Ekran adresini tanımlar

# ifndef VGA_ADRES
# define VGA_ADRES 0xB8000
# endif

// Renkler
enum renk {r0, r1, r2, r3, r4};

// ----- değişken tipleri
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
// -----

// ----- terminal ekranı

uint16_t * terminal;
uint32_t t_imlec = 0;
uint16_t _satir = 0;


void temizle()
{
	for(t_imlec = 0 ; t_imlec <80*25*2 ; t_imlec += 2)
	{
		terminal [t_imlec] = (uint8_t) ' ';
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

// -----

// ----- nesneler

typedef struct
{
	uint16_t boy;
	uint16_t en;
	uint16_t satir;
	uint16_t sutun;
	uint16_t renk;
}n1;

/*
	n1 * nn;
	nn -> boy = 10;
	nn -> en = 20;
	nn -> satir = 10;
	nn -> sutun = 20;
	nn -> renk = 0x10;
*/

void _1boyut(uint8_t kenar, uint8_t satir, uint8_t sutun, uint16_t color)
{
	t_imlec = sutun + satir*80;

	for(uint8_t i=0; i<kenar;i++)
	{
		terminal [t_imlec] = (uint8_t)' '|(uint16_t)color << 8;
		t_imlec++;
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
		terminal [i + j*80] = (uint8_t) str[index] | (uint16_t)color << 8;
		index++;
		i++;

		if (i == en)
		{
			i = sutun;
			j++;
		}

		if(j == boy)
		{
			j = satir;
		}
	}
}

void ciz(n1 * nn)
{
	_2boyut (nn->boy, nn->en, nn->satir, nn->sutun, nn->renk);
}

void y_ciz(n1 * nn, uint8_t * str)
{
	yazili_2boyut (nn->boy, nn->en, nn->satir, nn->sutun, nn->renk, str);
}


// -----