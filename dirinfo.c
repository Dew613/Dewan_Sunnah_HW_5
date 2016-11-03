#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

//print dir first and others later
int main() {
  DIR *stream = opendir(".");
  struct dirent *dewan;
  struct stat filestats;
  int size =0;//storage for bytes



  printf("Statistics for directory: . \n");
  while (dewan = readdir(stream)){//print bytes
    if(dewan->d_type == DT_REG){//checks if not a diretory
      stat(dewan->d_name,&filestats);//get stats
      size += filestats.st_size;//add to total size
    }
  }
  printf("Total Diectory Size: %d \n", size);
  closedir(stream);//close to restart



  printf("Directories: \n");
  opendir(".");
  while (dewan = readdir(stream)) {//next thing
    if (dewan->d_type == DT_DIR) //check if directory
      printf("\t %s \n", dewan->d_name);//print it
  }
  closedir(stream);

  //same as directories
  printf("Regular Files: \n");
  opendir(".");
  while((dewan=readdir(stream))){
    if(dewan->d_type == DT_REG)
      printf("\t %s \n",dewan->d_name);
  }
  closedir(stream);
  
  return 0;
}
