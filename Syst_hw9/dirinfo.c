#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <sys/types.h>


int get_dir_size() {
	struct stat sb;
	DIR *dp;
	struct dirent *entry;
	dp = opendir("./");
	int size;
	
	while ((entry = readdir(dp)) != NULL) {
		stat(entry->d_name, &sb);
		size += sb.st_size;
	}
	
	closedir(dp);
	return size;
}

void scan_dir() {
  DIR *dp;
  struct dirent *entry;
  dp = opendir("./");
  
	
  printf("Directories:\n");
	while ((entry = readdir(dp)) != NULL) {
		if (entry->d_type == DT_DIR) {
			printf("\t%s\n", entry->d_name);
		}
	}
  
	rewinddir(dp);
	
	
  printf("Regular files:\n");
  while ((entry = readdir(dp)) != NULL) {
		if (entry->d_type == DT_REG) {
			printf("\t%s\n", entry->d_name);
		}
  }

  closedir(dp);
}

int main() {
	
  printf("Statistics for directory:\n");
  printf("Total Directory Size: %d bytes\n", get_dir_size());
  scan_dir();
  return 0;
}
