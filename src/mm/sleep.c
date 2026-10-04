#include <time.h>
#include <errno.h>

int nanosleep(const struct timespec *req, struct timespec *rem);

unsigned int sleep(unsigned int seconds)
{
	struct timespec req, rem;

	req.tv_sec = (time_t)seconds;
	req.tv_nsec = 0;

	int ret = nanosleep(&req, &rem);

	if (ret == -1) {
		return rem.tv_sec;
	}

	return 0;
}
