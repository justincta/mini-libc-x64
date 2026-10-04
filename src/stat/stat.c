// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/syscall.h>
#include <errno.h>


int stat(const char *pathname, struct stat *statbuf)
{
	/* TODO: Implement stat(). */
	int ret;

	ret = syscall(__NR_stat, pathname, statbuf);

	if (ret < 0) {
		errno = -ret;
		return -1;
	}

	return ret;
}
