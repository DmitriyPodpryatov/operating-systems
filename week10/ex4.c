#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 200

FILE *file;
FILE *fp;

int main() {

    // Open file to write output
    file = fopen("ex4.txt", "w");

    // vars to work with directory
    struct dirent *st;
    DIR *d = opendir("tmp");

    if (d == NULL) {
        printf("Cannot open directory\n");
        exit(1);
    }

    // Scan all files in directory
    struct stat fileStat;
    char fullpath[SIZE];
    while ((st = readdir(d)) != NULL) {
        // In Linux OS there are files . and .. in every directory
        // This if statement exclude them
        if (strcmp(st->d_name, ".") == 0 || strcmp(st->d_name, "..") == 0) {
            continue;
        }
        strcpy(fullpath, "/home/dpodpryatov/OS/operating-systems/week10/tmp");
        strcat(fullpath, "/");
        strcat(fullpath, st->d_name);
    
        if (stat(fullpath, &fileStat) == -1) {
            printf("Cannot get stat from file\n");
            exit(1);
        } 
        
        // If hard link count >= 2
        if (fileStat.st_nlink >= 2) {
            fprintf(file, "inode %lu\n", st->d_ino);
            // Read output from command
            char s[SIZE];
            strcpy(s, "find -inum ");
            sprintf(s, "%s %lu", s, st->d_ino);
            // Run command
            fp = popen(s, "r");

            if (fp == NULL) {
                printf("Error during execution of the command\n");
            }

            // Print outputto the file
            char buffer[SIZE];
            while (fgets(buffer, sizeof(buffer) - 1, fp) != NULL) {
                fprintf(file, "%s", buffer);
            }
            fprintf(file, "\n");
            
            fclose(fp);
        }
    }

    closedir(d);
    fclose(file);

    return 0;

}