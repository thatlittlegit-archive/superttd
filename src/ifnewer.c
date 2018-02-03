#ifdef _WIN32
// On Windows, I don't really want to deal with WinAPI.
// Good first PR!
int main()
{
	return 0;
}

#pragma message( \
		"warning: Compiled on Windows, ifnewer is not Windows compatible! Using dummy main{return 0} function.")
#elif defined(__APPLE__) || defined(__linux) || defined(_POSIX_VERSION)
// We can be reasonably certain they'll follow UNIX practice.
#ifdef __linux__
#include <sys/types.h>
#endif

#include <sys/stat.h>
#include <fcntl.h>

#ifdef __linux__
#include <unistd.h>
#endif

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

char *prog;

void file_err(int fd)
{
	if (fd == -1) {
		fprintf(stderr, "%s: couldn't open a file: %s", prog, strerror(errno));
		exit(errno + 5);
	}
}

int main(int argc, char *argv[])
{
	prog = argv[0];
	if (argc == 1) {
		printf("%s: usage: %s [file1] [file2]\n", prog, prog);
	} else if (argc < 3) {
		fprintf(stderr, "%s: got too few args, expected 2!\n", prog);
		return 2;
	} else if (argc > 3) {
		fprintf(stderr, "%s: got too many args, expected 2!\n", prog);
		return 2;
	} else {
		int fd1 = open(argv[1], O_RDONLY);
		file_err(fd1);
		int fd2 = open(argv[2], O_RDONLY);
		file_err(fd2);

		struct stat stat1;
		struct stat stat2;

		fstat(fd1, &stat1);
		fstat(fd2, &stat2);

		close(fd1);
		close(fd2);

		return (long long)stat1.st_mtim.tv_sec >
			   (long long)stat2.st_mtim.tv_sec;
	}
}
#else
#error "No valid compiler found, is a header like __APPLE__ or __linux__ defined?"
#endif
