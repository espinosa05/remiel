#include <fmt/fmt.h>

int
___get_digit_count(int num, int base)
{
	int i = 0, digit = 1;
	
	while ( num < (i += base) ) 
	{
		digit++;
	}

	return digit;	
}


void
__sprint_num_base(char *buff, int num, int base)
{
	
	for (int i = 0; i <= ___get_digit_count(num); i++)
	{
		*buff = ___num_digit_to_char(num, i);	
		buff++;
	}
	
}


char
___num_digit_to_char(int num, int digit_index)
{
		
	return;
}
