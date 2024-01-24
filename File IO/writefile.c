#include <stdio.h>
#include <string.h>

int main()
{

	FILE* filePointer;
	char dataToBeWritten[50] = "HELLO FRANDS MY NAME IS FLAMIE";
	filePointer = fopen("file.txt", "w");

	if (filePointer == NULL) {
		printf("file failed to open.");
	}
	else {

		printf("The file is now opened.\n");

		if (strlen(dataToBeWritten) > 0) {

			fputs(dataToBeWritten, filePointer);
			fputs("\n", filePointer);
		}
	}
	return 0;
}
