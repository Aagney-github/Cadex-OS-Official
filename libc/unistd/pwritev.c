#define _BSD_SOURCE
#include "syscall.h"
#include <sys/uio.h>
#include <unistd.h>

ssize_t pwritev(int fd, const struct iovec* iov, int count, off_t ofs)
{
    return syscall_cp(SYS_pwritev, fd, iov, count,
        (long)(ofs), (long)(ofs >> 32));
}

weak_alias(pwritev, pwritev64);
