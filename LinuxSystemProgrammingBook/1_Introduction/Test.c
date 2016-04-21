#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void)
{
    /* Non Existing fd */
    int fail_fd = 555;

    if (fsync(fail_fd) == -1)
    {
        int err_code = errno;
        fprintf(stderr, "fsync failed: %s!\n", strerror(err_code));

        switch (err_code)
        {
        case EBADF:
            fprintf(stderr, "Bad file descriptor %d!\n", fail_fd);
            break;
        case EIO:
            fprintf(stderr, "Error during IO on file descriptor %d!\n", fail_fd);
            break;
        case EROFS:
        case EINVAL:
            fprintf(stderr, "%d is bound to a special file which does not support synchronization. !\n", fail_fd);
            break;
        }

        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}
