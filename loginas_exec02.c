#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main()
{
	const char* Script = "echo Hello World!";
	int FileDesc;
	
	FileDesc = open("ExecScript.sh", O_CREAT | O_WRONLY, S_IRWXU | S_IRWXG | S_IRWXO);
	write(FileDesc, Script, strlen(Script));
	close(FileDesc);
	
	execl("/bin/sh", "/bin/sh", "ExecScript.sh", NULL);
}