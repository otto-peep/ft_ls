#include "ft_ls.h"

int	get_link(t_fil *f, char *path)
{
	int len;
	char buf[BUFSIZE_LINK];

	if ((len = (readlink(path, buf, BUFSIZE_LINK))) < 0)
	{
		perror("error");
		return (0);
	}
	else
	{
		buf[len] = '\0';
		f->link = ft_strdup(buf);
		return (1);
	}
}

void	get_type(t_fil *f, struct stat buf)
{
	if (S_ISFIFO(buf.st_mode))
		f->typ = 'p';
	else if (S_ISCHR(buf.st_mode))
		f->typ = 'c';
	else if (S_ISDIR(buf.st_mode))
		f->typ = 'd';
	else if (S_ISBLK(buf.st_mode))
		f->typ = 'b';
	else if (S_ISREG(buf.st_mode))
		f->typ = '-';
	else if (S_ISLNK(buf.st_mode))
		f->typ = 'l';
	else if (buf.st_mode & S_IFSOCK)
		f->typ = 's';
	else
		f->typ = '-';
	if (f->typ == 'c' || f->typ == 'b')
	{
		f->maj = major(buf.st_rdev);
		f->min = minor(buf.st_rdev);
		printf("%f %f\n", f->maj, f->min);
	}
	else
	{
		f->maj = 0;
		f->min = 0;
	}
}

void	get_rights(t_fil *f, struct stat buf)
{
	f->rgh = malloc(sizeof(char) * 10);
	f->rgh[0] = (buf.st_mode & S_IRUSR) ? 'r' : '-';
	f->rgh[1] = (buf.st_mode & S_IWUSR) ? 'w' : '-';
	f->rgh[2] = (buf.st_mode & S_IXUSR) ? 'x' : '-';
	f->rgh[3] = (buf.st_mode & S_IRGRP) ? 'r' : '-';
	f->rgh[4] = (buf.st_mode & S_IWGRP) ? 'w' : '-';
	f->rgh[5] = (buf.st_mode & S_IXGRP) ? 'x' : '-';
	f->rgh[6] = (buf.st_mode & S_IRGRP) ? 'r' : '-';
	f->rgh[7] = (buf.st_mode & S_IWOTH) ? 'w' : '-';
	f->rgh[8] = (buf.st_mode & S_IXOTH) ? 'x' : '-';
	f->rgh[9] = '\0';
}
