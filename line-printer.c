#define _POSIX_C_SOURCE 199309L

#include <stdio.h>
#include <string.h>
#include <time.h>

void process(char c, int *i);

void
process(char c, int *i)
{
	struct timespec ts;

	if (c != '\n')
	{
		putchar(c);
		fflush(stdout);
		/* 100,000,000 ns = 0.1 s */
		ts.tv_sec = 0;
		ts.tv_nsec = 100000000;
		nanosleep((const struct timespec *) &ts, NULL);
		++(*i);
	}
	else
	{
		/* 800,000,000 ns = 0.80 s */
		ts.tv_sec = 0;
		ts.tv_nsec = 800000000;
		nanosleep((const struct timespec *) &ts, NULL);

		while (*i > 0)
		{
			putchar('\b');
			putchar(' ');
			putchar('\b');
			fflush(stdout);
			/* 100,000,000 ns = 0.1 s */
			ts.tv_sec = 0;
			ts.tv_nsec = 100000000;
			nanosleep((const struct timespec *) &ts, NULL);
			--(*i);
		}
	}
}

int
main(int argc, char *argv[])
{
	int i;
	char c;
	FILE *fp;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s [FILE|-]\n", argv[0]);
		return 1 << 0;
	}

	if (strcmp(argv[1], "-") == 0)
	{
		i = 0;

		while ((c = (char) getchar()) != EOF)
			process(c, &i);
	}
	else
	{
		if ((fp = fopen(argv[1], "r")) == NULL)
		{
			fprintf(stderr, "Failed to open '%s'\n", argv[1]);
			return 1 << 1;
		}

		i = 0;

		while (fscanf(fp, "%c", &c) != EOF)
			process(c, &i);

		fclose(fp);
	}

	return 0;
}
