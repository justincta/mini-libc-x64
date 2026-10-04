// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int close(int fd)
{
	/* TODO: Implement close(). */
	long ret;

	ret = syscall(__NR_close, (long)fd);
	if (ret < 0) {
		errno = -ret;
		return -1;
	}

	return (int)ret;
}
