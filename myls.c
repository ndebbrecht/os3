#include "myheader.h"

int main(int argc, char* argv[]){

  char* myDir;
  DIR *dp;
  struct dirent *dptr;

  if(argc<2){ // get current dir
    myDir = getenv("PWD");
    if(myDir==NULL){
      printf("\nCurrent Directory could not be read!\n");
      return -1;
    }
  } else {
    if(strcmp("-a",argv[1])!=0 && strcmp("-l",argv[1])!=0 && strcmp("-al",argv[1])!=0){
      myDir = argv[1];
    } else {
      myDir = getenv("PWD");
      if(myDir==NULL){
        printf("\nCurrent Directory could not be read!\n");
        return -1;
      }
    }
  }

  dp = opendir(myDir);
  if(dp==NULL){
    printf("\nCurrent Directory could not be opened!\n");
    return -2;
  }

  printf("\n");
  int count = 0;
  while((dptr = readdir(dp)) != NULL){ //display all
    if(dptr->d_name[0]!='.' || checkArg(argc, argv, "-a")==1 || checkArg(argc, argv, "-al")==1){

      if(checkArg(argc, argv, "-l")==1 || checkArg(argc,argv,"-al")==1){

       struct stat st;




      // Call fstat to get the stat info about the file
      lstat(dptr->d_name, &st);


      // Check if a directory
      if(S_ISDIR(st.st_mode))
      {
      printf("d");
      }
      else
      {
          printf("-");
      }

      // Check the owner permission
      mode_t permission = st.st_mode & S_IRWXU;

      if(permission & S_IRUSR)
      {
          printf("r");
      }
      else
      {
          printf("-");
      }

      if(permission & S_IWUSR)
      {
          printf("w");
      }
      else
      {
          printf("-");
      }

      if(permission & S_IXUSR)
      {
          printf("x");
      }
      else
      {
          printf("-");
      }


      // CHeck the group permission
      permission = st.st_mode & S_IRWXG;

      if(permission & S_IRGRP)
      {
          printf("r");
      }
      else
      {
          printf("-");
      }

      if(permission & S_IWGRP)
      {
          printf("w");
      }
      else
      {
          printf("-");
      }

      if(permission & S_IXGRP)
      {
          printf("x");
      }
      else
      {
          printf("-");
      }


      // CHeck other's permission
      permission = st.st_mode & S_IRWXO;

      if(permission & S_IROTH)
      {
          printf("r");
      }
      else
      {
          printf("-");
      }

      if(permission & S_IWOTH)
      {
          printf("w");
      }
      else
      {
          printf("-");
      }

      if(permission & S_IXOTH)
      {
          printf("x");
      }
      else
      {
          printf("-");
      }

      // Print the number of hard links
      printf(" %d ", (int)st.st_nlink);

      // Get the user name
      struct passwd *pt = getpwuid(st.st_uid);
      printf("%s ",pt->pw_name);

      // Get the group name
      struct group *p = getgrgid(st.st_gid);
      printf("%s ",p->gr_name);

      // Get the file size
      printf("%lld ",(long long) st.st_size);

      // Get the date and time
      // Note that some logic is applied here
      // so as to remove the trailing newline.
      char date_time[100];
      memset(date_time,0,sizeof(date_time));
      strncpy(date_time, ctime(&st.st_ctime), sizeof(date_time));
      int c = 0;
      while(date_time[c] != '\0')
      {
          if(date_time[c] == '\n')
              date_time[c] = '\0';
          c++;
      }
      printf("%s ", date_time);
      }

      printf("%s\n",dptr->d_name);
    }
    ++count;
  }

  printf("\n");

  return 0;
}

int checkArg(int argc, char* argv[], char* arg){
  int i;
  for(i=0;i<argc;++i){
    if(strcmp(arg,argv[i])==0){
      return 1;
    }
  }
  return 0;
}
