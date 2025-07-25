#include "ft_ls.h"

char    is_other(int i)
{
    char c;

    c = i == 0 ? 't' : 's';
    return (c);
}

void who_has_permissions(int mode, char *buff, int count, int sticky_bit)
{
    if (count > 8)
        return;
    buff[0] = mode & 1 ? buff[0] : '-';
    if (sticky_bit & 1 && !(count % 3)){
        buff[0] = buff[0] == 'x' ? is_other(count) : ft_toupper(is_other(count));
        sticky_bit = sticky_bit >> 1;
    }
    who_has_permissions(mode >> 1, buff - 1, count + 1, sticky_bit);
}

char get_type(int mode)
{
    switch(mode & S_IFMT)
    {
        case S_IFREG:
            return ('-');
        case S_IFDIR:
            return ('d');
        case S_IFLNK:
            return ('l');
        case S_IFCHR:
            return ('c');
        case S_IFBLK:
            return ('b');
        case S_IFIFO:
            return ('p');
        case S_IFSOCK:
            return ('s');
        default:
            return ('?');
    }
}

void format_permissions(int mode, char *buff)
{
    int sticky_bit;
    buff[0] = get_type(mode);
    sticky_bit = (mode / (8 * 8 * 8)) % 8;
    ft_memcpy(&buff[1], "rwxrwxrwx", 9);
    who_has_permissions(mode, &buff[9], 0, sticky_bit);
}

void    print_infos(char *buff, struct stat sb, struct passwd *owner, struct group *growner, char *path)
{
    char *lmt;
    unsigned char res;

    lmt = ctime(&sb.st_mtime);
    lmt = &lmt[4];
    lmt[12] = 0;
    res = 0;
    res = owner ? res + 1 : res;
    res = growner ? res + 2 : res;
    switch (res)
    {
        case 0:
            ft_printf("%s %d %d %d %d %s %s\n", buff, sb.st_nlink, sb.st_uid, sb.st_gid, sb.st_size, lmt, path);
            break;
        case 1:
            ft_printf("%s %d %d %d %d %s %s\n", buff, sb.st_nlink, sb.st_uid, growner->gr_name, sb.st_size, lmt, path);
            break;
        case 2:
            ft_printf("%s %d %d %d %d %s %s\n", buff, sb.st_nlink, sb.st_uid, sb.st_gid, sb.st_size, lmt, path);
            break;
        case 3:
            ft_printf("%s %d %s %s %d %s %s\n", buff, sb.st_nlink, owner->pw_name, growner->gr_name, sb.st_size, lmt, path);
            break;
        default:
            break;
    } 
}

void get_infos(char *path)
{
    struct stat sb;
    struct passwd *owner;
    struct group    *growner;
    char buff[12];
    //int             sticky_bit;

    ft_bzero(buff, 12);
    if (lstat(path, &sb) == -1)
    {
        perror("lstat");
        return;
    }
    /*printf("I-node number:            %ld\n",  sb.st_ino);
    printf("Mode:                     %o (octal)\n",
             sb.st_mode);
    printf("Link count:               %ld\n",  sb.st_nlink);
    printf("Ownership:                UID=%u   GID=%u\n",
             sb.st_uid,  sb.st_gid);*/
    owner = getpwuid(sb.st_uid);
    growner = getgrgid(sb.st_gid);
/*
    ft_printf("User:%s\n", owner->pw_name);
    printf("Preferred I/O block size: %ld bytes\n",
             sb.st_blksize);
    printf("File size:                %ld bytes\n",
             sb.st_size);
    printf("Blocks allocated:         %ld\n",
             sb.st_blocks);
    printf("Last status change:       %s\n", ctime(&sb.st_ctime));
    printf("Last file access:         %s\n", ctime(&sb.st_atime));
    printf("Last file modification:   %s\n", ctime(&sb.st_mtime));*/
    format_permissions(sb.st_mode, buff);
    print_infos(buff, sb, owner, growner, path);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void test_get_infos(const char *filename) {
    char cmd[256];
    char ls_output[1024];
    char my_output[1024];
    FILE *fp;

    // Récupère la sortie de ls -l
    snprintf(cmd, sizeof(cmd), "ls -l %s | awk '{print $1,$2,$3,$4,$5,$6,$7,$8,$9}'", filename);
    fp = popen(cmd, "r");
    if (!fp) {
        perror("popen ls");
        return;
    }
    if (!fgets(ls_output, sizeof(ls_output), fp)) {
        pclose(fp);
        fprintf(stderr, "Erreur lecture ls\n");
        return;
    }
    pclose(fp);

    // Redirige stdout vers un fichier temporaire
    int saved_stdout = dup(1);
    FILE *tmp = fopen("tmp_out.txt", "w+");
    if (!tmp) {
        perror("fopen tmp");
        return;
    }
    dup2(fileno(tmp), 1);

    // Appelle get_infos
    get_infos((char *)filename);

    // Restaure stdout
    fflush(stdout);
    dup2(saved_stdout, 1);
    close(saved_stdout);

    // Lit la sortie de get_infos
    rewind(tmp);
    if (!fgets(my_output, sizeof(my_output), tmp)) {
        fclose(tmp);
        fprintf(stderr, "Erreur lecture tmp_out.txt\n");
        return;
    }
    fclose(tmp);

    // Affiche les deux sorties pour comparaison
    printf("ls -l : %s", ls_output);
    printf("get_infos : %s", my_output);

    // Optionnel : comparaison simple
    if (strncmp(ls_output, my_output, 20) == 0)
        printf("Test OK\n");
    else
        printf("Test KO\n");
}


int main(int ac, char **av)
{

        test_get_infos(av[1]);
        return 0;
    if (ac <= 1)
        return (0);
    get_infos(av[1]);
    return (0);
}