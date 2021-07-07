#include "philosophers.h"

long	get_utime(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_usec + time.tv_sec * 1000000);
}
