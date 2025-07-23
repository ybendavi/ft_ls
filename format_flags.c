#include "ft_ls.h"

void calculate_permission(unsigned char c, char *buffer, int modulo)
{

    buffer[0] = c / modulo >= 1 ? buffer[0] : '-';
    if (modulo != 1)
        calculate_permission(c % modulo, buffer + 1, modulo != 2 ? modulo - 2 : 1);
}
void format_permissions(int mode, char *buff, int i)
{
    unsigned char   c;

    if (i == 3)
        return;
    format_permissions(mode / 8, buff - 3, i + 1);
    c = mode % 8;
    ft_memcpy(buff, "rwx", 3);
    //printf("%s", buff);
    //printf("%s\n", &buff[i - 2]);
    calculate_permission(c, buff, 4);
    //printf("%s\n", &buff[i - 2]);
}
char *get_infos(struct dirent *dp)
{
    struct stat sb;
    struct passwd *owner;
    char buff[10];

    ft_bzero(buff, 10);
    ft_printf("%s\n", dp->d_name);
    stat(dp->d_name, &sb);
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
    format_permissions(sb.st_mode, &buff[6], 0);
    printf("%s\n", buff);
    return (dp->d_name);
}

int main(int ac, char **av)
{
    DIR *dirp;
    struct dirent *dp;

    (void)ac;
    (void)av;
    dirp = opendir(".");
    dp = readdir(dirp);
    while (dp && ft_strncmp(dp->d_name, av[1], 7))
    {
        dp = readdir(dirp);

    }
    get_infos(dp);
    closedir(dirp);
}