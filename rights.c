#include "ft_ls.h"

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
}

		void	get_rights(t_fil *f, struct stat buf)
{
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