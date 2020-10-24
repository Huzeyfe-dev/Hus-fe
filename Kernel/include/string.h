# ifndef STRING_H
# define STRING_H
# endif

# ifndef TYPE_H
# include "type.h"
# endif

int kiyasla(uint8_t * str1, uint8_t * str2)
{
	uint16_t index = 0;
	uint8_t harf;

	while((harf=str1[index])!='\0')
	{
		if(str2[index]!=harf) return 0;
	}

	return 1;

}