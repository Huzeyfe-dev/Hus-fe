# ifndef CEVIR_H
# define CEVIR_H
# endif

# ifndef TYPE_H
# include "type.h"
# endif

/*uint32_t char_int(uint8_t * chr, uint32_t tbn)
{
	uint32_t ret=0;
	uint32_t i,j,l,x;
	uint32_t tmp;
	uint32_t sayi[20];

	for(i=0; chr[i]; i++);
	
	l=i;
	
	for(j=0;j<20;j++) sayi[j]=0;

	for(j=0; j<i; j++)
	{
		for(x=0; x<tbn; x++)
		{
			if(chr[j]==sayilar_c[x])
			{
				sayi[j]=sayilar_i[x];
				break;
			}
		}
	}

	for(;i>=0;i--)
	{
		tmp = 1;
		
		for(j=0; j<l-i-1;j++)
		{
			tmp*=tbn;
		}

		ret += tmp * sayi[i];
	}

	return ret;
}
*/
// Sayıyı yazıya çevirir.
void itoc(uint32_t integer, uint8_t * ascii)
{
	uint32_t temp ,count=0, i, cnd=0;

	if(integer>>31)
	{
		integer=~integer+1;

		for(temp=integer;temp!=0;temp/=10,count++);

		ascii[0]=0x2D;
		count++;
		cnd=1;
	}

	else

	for(temp=integer;temp!=0;temp/=10,count++);

	for(i=count-1,temp=integer;i>=cnd;i--)
	{
		ascii[i]=(temp%10)+0x30;
		temp/=10;
	}
}