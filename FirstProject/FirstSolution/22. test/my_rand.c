unsigned int next;

int my_rand()
{
	extern next;

	next = next * 1103515245 + 1234;
	next = (unsigned int)(next / 65536) % 32768;

	return next;
}

void my_srand(unsigned int seed)
{
	extern next;
	next = seed;
}