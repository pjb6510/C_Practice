#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int g_int = 0;
double g_arr[1000] = { 0.0, };
//전역변수의 R-value에 상수나 상수가 나오는 계산식은 들어갈 수 있지만, 변수는 들어갈 수 없음.

void fun()
{
	g_int += 10;
	printf("g int in fun() %d %p \n", g_int, &g_int);

}

void fun_sec();
//main함수 앞에 프로토타입을 선언해줌으로써 second.c의 함수를 링커가 찾아서 연결해 줌.

int main()
{
	extern int g_int;
	//블록 바깥 또는 파일 바깥의 g_int 변수를 사용하겠다! 선언. 권장사항임.
	//extern int g_int;를 선언하면 지역변수로 같은 이름 g_int를 선언할 수 없음.(name hiding방지)
	extern double g_arr[];
	//배열같은 경우 참조선언 할 때 메모리 크기를 기입하지 않아도 됨.(이미 결정되어있으니까)

	g_int += 1;
	printf("g int in main() %d %p \n", g_int, &g_int);

	fun();
	fun_sec();
}

