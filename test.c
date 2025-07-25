#include <string.h>

void expected_perm_str(int mode, char *buff) {
    const char *rwx = "rwx";
    buff[0] = get_type(mode);
    for (int i = 0; i < 3; ++i) {
        int perm = (mode >> (6 - 3 * i)) & 7;
        for (int j = 0; j < 3; ++j) {
            buff[1 + i * 3 + j] = (perm & (1 << (2 - j))) ? rwx[j] : '-';
        }
    }
    // setuid
    if (mode & 04000)
        buff[3] = (buff[3] == 'x') ? 's' : 'S';
    // setgid
    if (mode & 02000)
        buff[6] = (buff[6] == 'x') ? 's' : 'S';
    // sticky
    if (mode & 01000)
        buff[9] = (buff[9] == 'x') ? 't' : 'T';
    buff[10] = '\0';
}

int test_permissions()
{
    char buff[12];
    char expected[12];
    int failed = 0;
    printf("Test de format_permissions sur toutes les permissions (00000 à 07777):\n");
    for (int mode = 0; mode <= 07777; ++mode) {
        memset(buff, 0, sizeof(buff));
        memset(expected, 0, sizeof(expected));
        expected_perm_str(mode, expected);
        format_permissions(mode, buff);
        // On compare type + permissions + bits spéciaux
        if (strncmp(buff, expected, 10) == 0) {
            //printf("%05o: %s [OK]\n", mode, buff);
        } else {
            printf("%05o: %s [FAILED] (attendu: %s)\n", mode, buff, expected);
            failed++;
        }
    }
    printf("\nNombre de tests failed: %d\n", failed);
}