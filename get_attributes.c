// Petit programme pour tester les attributes

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/xattr.h>

int main() {
    const char *filename = "test";
    const char *attr_name = "user.test";
    char value[100] = {0};

    ssize_t ret = getxattr(filename, attr_name, value, sizeof(value));
    if (ret == -1) {
        perror("getxattr");
        return 1;
    }

    printf("Valeur de l'attribut %s : %s\n", attr_name, value);
    return 0;
}