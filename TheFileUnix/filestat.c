#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char *argv[]){
    if (argc < 2)
    {
        printf("Usage: ./filestat <file_path>\n");
    }
    
    const char *path = argv[1];
    struct stat inf;
    printf("Duong dan: %s\n", path);
    if (lstat(path, &inf)==0)
    {
        if (S_ISREG(inf.st_mode)==0)
        {
            printf("day la file regular\n");
            
        }
        else printf("day khong phai file regular\n");

        if (S_ISDIR(inf.st_mode))
        {
            printf("day la thu muc\n");
            
        }
        else printf("day khong phai thu muc\n");
        if (S_ISLNK(inf.st_mode)) 
        {
            printf("day la file symlink\n");
            
        }
        else printf("day khong phai symlink\n");
        printf("kich thuoc cua file nay la: %ld bytes\n", inf.st_size);
        printf("thoi gian chinh sua file la: %s", ctime(&inf.st_mtime));
        return 0;
    }
    else printf("loi khong doc duoc lsat\n");


}