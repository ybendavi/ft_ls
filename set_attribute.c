// Petit programme pour tester les attributes

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/xattr.h>
#include <string.h>

int main() {
    const char *filename = "test";
    const char *attr_name = "user.test";
    const char *attr_value = "valeur";

    if (setxattr(filename, attr_name, attr_value, strlen(attr_value), 0) == -1) {
        perror("setxattr");
        return 1;
    }

    printf("Attribut ajouté !\n");
    return 0;
}
