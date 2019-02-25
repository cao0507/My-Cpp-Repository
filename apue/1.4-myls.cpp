#include <iostream>
#include <dirent.h>

int main(int argc, char **argv){
	DIR *dp;
	dirent *dirp;
	if (argc != 2){
		std::cerr << "usage: ls directory_name" << std::endl;
		return 0;
	}
	if ( (dp = opendir(argv[1])) == NULL ){
		std::cerr << "can't open " << argv[1] << std::endl;
		return 0;
	}
	while ( (dirp = readdir(dp)) != NULL )
		std::cout << dirp->d_name << std::endl;

	closedir(dp);
	return 0;
}
