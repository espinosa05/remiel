#ifndef _FMT_FMT_H
#define _FMT_FMT_H

#define HEX_CHARS		"0123456789abcdef"
#define DEC_CHARS		"0123456789"
#define CAPITALISE	0x20 // we need to subtract 32 from the hex chars,
							 // starting from index 10 (a),
							 // to get the capitalized ASCII values

int _get_digit_count(int num);
char _num_digit_to_char(int num, int digit_index);
void __sprint_num_base(char *buff, int num, int base);
#define TABSIZE 0x4
#define sprint_hex( BUFF, NUM ) __sprint_num_base(BUFF, NUM, 16)
#define sprint_dec( BUFF, NUM ) __sprint_num_base(BUFF, NUM, 10)

// print hexadecimal values with this macro
#define print_hex(BUFF, NUM)  sprint_hex(BUFF, NUM);\
	printf(#BUFF)\

// print decimal values with this macro
#define print_dec(BUFF, NUM)  sprint_dec(BUFF, NUM);\
	printf(#BUFF)



#endif // _FMT_FMT_H
