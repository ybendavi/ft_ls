#include "ft_ls.h"

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power >= 1)
	{
		return (nb * ft_recursive_power(nb, power - 1));
	}
	return (1);
}

void calculate_permission(unsigned char c, char *buffer, int modulo)
{

    buffer[0] = c / modulo >= 1 ? buffer[0] : '-';
    if (modulo != 1)
        calculate_permission(c % modulo, buffer + 1, modulo != 2 ? modulo - 2 : 1);
}

char    is_other(int i)
{
    char c;

    c = i == 0 ? 't' : 's';
    return (c);
}
void format_permissions(int mode, char *buff, int i, int sticky_bit)
{
    unsigned char   c;
    //int             sticky_bit;

    if (i == 3)
        return;
    format_permissions(mode / 8, buff - 3, i + 1, sticky_bit);
    sticky_bit = sticky_bit >> i;
    printf("sb0:%d\nsb1:%d\nsb2:%d\n",(sticky_bit >> 1) % 2, (sticky_bit >> 2) % 2 , (sticky_bit >> 3) % 2);
    c = mode % 8;
    ft_memcpy(buff, "rwx", 3);
    //printf("%s", buff);
    //printf("%s\n", &buff[i - 2]);
    printf("sticky:%d\n", sticky_bit);
    calculate_permission(c, buff, 4);
    if (sticky_bit & 1){
        buff[2] = buff[2] == 'x' ? is_other(i) : ft_toupper(is_other(i));
    }
    //printf("%s\n", &buff[i - 2]);
}
void get_infos(char *path)
{
    struct stat sb;
    struct passwd *owner;
    char buff[10];
    int             sticky_bit;

    ft_bzero(buff, 10);
    stat(path, &sb);
    printf("I-node number:            %ld\n",  sb.st_ino);
    printf("Mode:                     %o (octal)\n",
             sb.st_mode);
    printf("Link count:               %ld\n",  sb.st_nlink);
    printf("Ownership:                UID=%u   GID=%u\n",
             sb.st_uid,  sb.st_gid);
    owner = getpwuid(sb.st_uid);
    ft_printf("User:%s\n", owner->pw_name);
    printf("Preferred I/O block size: %ld bytes\n",
             sb.st_blksize);
    printf("File size:                %ld bytes\n",
             sb.st_size);
    printf("Blocks allocated:         %ld\n",
             sb.st_blocks);
    printf("Last status change:       %s\n", ctime(&sb.st_ctime));
    printf("Last file access:         %s\n", ctime(&sb.st_atime));
    printf("Last file modification:   %s\n", ctime(&sb.st_mtime));
    sticky_bit = (sb.st_mode / ft_recursive_power(8, 3)) % 8;
    //sticky_bit = (sticky_bit / ft_recursive_power(2, 8)) % 2;
    format_permissions(sb.st_mode, &buff[6], 0, sticky_bit );
    printf("%s\n", buff);
}

int main(int ac, char **av)
{
    if (ac <= 1)
        return (0);
    get_infos(av[1]);
    return (0);
}
// sticky bit a implementer, trouver des fichier pour le tester : find / -type f -perm /6000 -ls 2>/dev/null