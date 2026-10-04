#include <internal/syscall.h>
#include <time.h>
#include <errno.h>

int nanosleep(const struct timespec *req, struct timespec *rem)
{
	long ret;
	ret = syscall(__NR_nanosleep, (long)req, (long)rem);
	if (ret < 0) {
		errno = -ret;
		return -1;
	}

	return 0;
}
