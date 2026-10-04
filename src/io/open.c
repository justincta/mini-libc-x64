// SPDX-License-Identifier: BSD-3-Clause

#include <errno.h>
#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>

int open(const char *filename, int flags, ...) {
	mode_t mode = 0;
	// in cazul in care fisierul nu exista
	// trebuie totusi transmise permisiuni in syscall
	if (flags & O_CREAT) {
		va_list args;
		va_start(args, flags);
		mode = va_arg(args, mode_t);
		va_end(args);
	}
	int ret;
	if (mode)
ret = syscall(__NR_open, filename, flags, mode);
	else
		ret = syscall(__NR_open, filename, flags);
	if (ret < 0) {
		errno = -ret; // valuarea lui eerno semnifica ceva
		return -1;
	}
	return ret;
}
