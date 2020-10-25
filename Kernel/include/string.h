# ifndef STRING_H
# define STRING_H
# endif

# ifndef TYPE_H
# include "type.h"
# endif

char kiyasla(uint8_t * str1, uint8_t * str2)
{
	uint16_t l1;
	uint16_t l2;
	uint16_t i=0;

	for(l1 = 0; str1[l1]!='\0'; l1++);
	for(l2 = 0; str2[l2]!='\0'; l2++);

	if(l1==l2)
	{
		while(str1[i]!='\0')
		{
			if(str1[i]!=str2[i]) return 2;
			i++;
		}

		return 1;
	}

	if(l1>l2) return 3;
	if(l2>l1) return 4;

	return 0;

}