#include <stdio.h>

int main()
{
	int i = 0;
	int ret = 0;
	char str = 'a';

	for (i = 0; i < 8; i++)
	{
		ret = (str & (0x01 << i));
		if (ret != 0)
			printf("1");
		else
			printf("0");
	}
	
}