// SPDX-License-Identifier: BSD-3-Clause

#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int open(const char *filename, int flags, ...)
{
	mode_t mode;

	va_list args;
	va_start(args, flags);
	mode = va_arg(args, mode_t);

	int ret = syscall(__NR_open, filename, flags, mode);

	if (ret < 0) {
		errno = -ret;
		return -1;
	}

	return ret;
}
