#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define BYTE_MASK 0xff // ...0000 0000 1111 1111

// shift
// signed integer라면 right shift 에서 새로 생기는 왼쪽 공간을 1로 채움.
// unsigend integer라면 right shift 에서 새로 생기는 왼쪽 공간을 0으로 채움.

int main()
{
	unsigned int rgba_color = 0x66CDAAFF;
	//0110 0110 1100 1101 1010 1010 1111 1111
	//6    6    C    D    A    A    F    F
	//red:hex:66(dec:102) green:hex:CD(dec:205) blue:hex:AA(dec:170) alpha:hex:FF(dec:255)
	// 4bytes, medium aqua marine (102, 205, 170, 255)

	unsigned char red, green, blue, alpha;
	//use right shift >> operator
	alpha = rgba_color >> 0 & BYTE_MASK;
	blue =	rgba_color >> 8 & BYTE_MASK;
	green = rgba_color >> 16 & BYTE_MASK;
	red =	rgba_color >> 24 & BYTE_MASK;

	// >>를 이용해서 추출할 특정 자릿수(16진수로 2자리, 2진수로 8자리)를 맨 오른쪽으로 옮기기
	// 오른쪽 끝자리 2진수 8자리만(16진수로 2자리) 남겨두고 나머지 다 0으로 만들기 : ... 0000 0000 1111 1111로 되어있는 BYTE_MASK와 &를 이용.

	printf("(R, G, B, A) = (%hhu, %hhu, %hhu, %hhu)\n", red, green, blue, alpha);
}
