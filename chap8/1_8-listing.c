#include <stdio.h>
#include <string.h>
#include <sys/syscall.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/dir.h>
#include <dirent.h>

#define 	MAX_PATH 		1024
#ifndef 	DISIZ
#define 	DIRSIZ 			14
#endif

struct direct
{
	ino_t d_ino;
	char d_name[DIRSIZ];
};

int fstat(int fd, struct stat *);
int stat(char *, struct stat *);
void dirwalk(char *, void (*fcn)(char *));
void fsize(char *);

int main(int argc, char *argv[])
{
	if (argc == 1)
			fsize(".");
	else
			while(--argc > 0)
					fsize(*++argv);
	return 0;
}

void fsize(char *name)
{
	struct stat stbuf;

	if (stat(name, &stbuf) == -1) {
			fprintf(stderr, "fsize: can't access %s\n", name);
			return;
	}
	if ((stbuf.st_mode & S_IFMT) == S_IFDIR)
			dirwalk(name, fsize);
	printf("%81d %s\n", stbuf.st_size, name);
}

void dirwalk(char *dir, void (*fcn)(char *))
{
	char name[MAX_PATH];
	Dirent *dp;
	DIR *dfd;

	if ((dfd = opendir(dir)) == NULL) {
			fprintf(stderr, "dirwall: can't open %s\n", dir);
			return;
	}
	while ((dp = readdir(dfd)) != NULL) {
			if (strcmp(dp->name, ".") == 0 || strcmp(dp->name, "..") == 0)
					continue;
			if (strlen(dir)+strlen(dp->name)+2 > sizeof(name))
					fprintf(stderr, "dir walk: name %s/%s too long\n"
									,dir, dp->name);
			else {
					sprintf(name, "%s/%s", dir, dp->name);
					(*fcn)(name);
			}
	}
	closedir(dfd);
}

DIR *opendir(char *dirname)
{
	int fd;
	struct stat stbuf;
	DIR *dp;

	if ((fd = open(dirname, O_RDONLY, 0)) == -1 
					|| fstat(fd, &stbuf) == -1 
					|| (stbuf.sf_mode && S_IFMT) != S_IFDIR 
					|| (dp = (DIR *) malloc(sizeof(DIR))) == NULL)
			return null;
	dp->fd = fd;
	return dp;
}

void closedir(DIR *dp)
{
	if (dp) {
			close(dp->fd);
			free(dp);
	}
}

Dirent *readdir(DIR *dp)
{
	struct direct dirbuf;
	static Dirent d;

	while (read(dp->fd, (char *) &dirbuf, sizeof(dirbuf))
					== sizeof(dirbuf)) {
			if (dirbuf.d_ino == 0)
					continue;
			d.ino = dirbuf.d_ino;
			strncpy(d.name, dirbuf.d_name, DIRSIZ);
			d.name[DIRSIZ] = '\0';
			return &d;
	}
	return NULL;
}
