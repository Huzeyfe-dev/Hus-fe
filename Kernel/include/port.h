# ifndef PORT_H
# define PORT_H
# endif


void outb(uint16_t port, uint8_t data)		// port adresine veri gönderir
{
	asm volatile("outb %0, %1" : "=a"(data) : "d"(port));
}

uint8_t inb(uint16_t port)		// Verilen port adresinden veri alır.
{
	uint8_t ret;
	asm volatile("inb %1, %0" : "=a"(ret) : "d"(port));
	return ret;
}