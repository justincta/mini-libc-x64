#include <unistd.h>
#include <string.h>
#include <internal/syscall.h>
#include <errno.h>

// primeam o avertizare de la iwus
// si doar asa am putut scapa de ea
#define IMPLEMENT_PUTS puts

int IMPLEMENT_PUTS(const char *s)
{
	const char *p = s;
	size_t len = 0;
	len = strlen(p);
	long ret;

	// apel
	ret = syscall(__NR_write, 1, s, len);
	if (ret < 0) {
		errno = -ret;
		return -1; // eof
	}

	// scriu newline
	ret = syscall(__NR_write, 1, "\n", 1);
	if (ret < 0) {
		errno = -ret;
		return -1;
	}

	return (int)(len + 1);
}
