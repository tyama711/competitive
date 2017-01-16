#include <stdio.h>
#include <memory.h>

#define TO_INDEX(a,b,c,d)	(((a)<<9) | ((b)<<7) | ((c)<<4) | (d))
#define NUM_OF_A2(index)	(((index)>>9) & 0x1)
#define NUM_OF_A3(index)	(((index)>>7) & 0x3)
#define NUM_OF_A4(index)	(((index)>>4) & 0x7)
#define NUM_OF_A5(index)	((index) & 0xf)
#define NUM_OF_PAPERS(index) ((NUM_OF_A2(index)) + (NUM_OF_A3(index)) + (NUM_OF_A4(index)) + (NUM_OF_A5(index)))

typedef struct _DATA {
	bool	processed;
	double	expt;
} DATA;

double solve(DATA* data, int index)
{
	if (data[index].processed)
		return data[index].expt;

	double expt = 0.0;
	if (NUM_OF_PAPERS(index) == 1)
		expt += 1.0;

	if (NUM_OF_A2(index) > 0) {
		expt += solve(data, TO_INDEX(NUM_OF_A2(index) - 1,
									 NUM_OF_A3(index) + 1,
									 NUM_OF_A4(index) + 1,
									 NUM_OF_A5(index) + 1))
			* ((double)NUM_OF_A2(index) / NUM_OF_PAPERS(index));
	}
	if (NUM_OF_A3(index) > 0) {
		expt += solve(data, TO_INDEX(NUM_OF_A2(index),
									 NUM_OF_A3(index) - 1,
									 NUM_OF_A4(index) + 1,
									 NUM_OF_A5(index) + 1))
			* ((double)NUM_OF_A3(index) / NUM_OF_PAPERS(index));
	}
	if (NUM_OF_A4(index) > 0) {
		expt += solve(data, TO_INDEX(NUM_OF_A2(index),
									 NUM_OF_A3(index),
									 NUM_OF_A4(index) - 1,
									 NUM_OF_A5(index) + 1))
			* ((double)NUM_OF_A4(index) / NUM_OF_PAPERS(index));
	}
	if (NUM_OF_A5(index) > 0) {
		expt += solve(data, TO_INDEX(NUM_OF_A2(index),
									 NUM_OF_A3(index),
									 NUM_OF_A4(index),
									 NUM_OF_A5(index) - 1))
			* ((double)NUM_OF_A5(index) / NUM_OF_PAPERS(index));
	}

	data[index].processed = true;
	data[index].expt = expt;

	return expt;
}

int main(void)
{
	DATA data[1024];
	memset(data, 0x00, sizeof(data));
	data[1].processed = true;
	data[1].expt = 0.0;

	printf("%.16lf\n", solve(data, TO_INDEX(1,1,1,1)));
}
