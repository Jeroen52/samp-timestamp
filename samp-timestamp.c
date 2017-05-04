#include <stdio.h>
#include <string.h>
#include <time.h>

//#define DEBUG

#define MAX_INCLUDE_LENGTH 172+2+1 //Adding two bytes for safety, and one for \0

#ifdef __unix__

#elif defined(_WIN32) || defined(WIN32)

	#ifdef DEBUG
		#define OS_Windows
	#endif
#endif

char static str[MAX_INCLUDE_LENGTH];

int main()
{
	strcpy(str, "#if defined _INC_TIMESTAMP\n");
	strcat(str, "	#endinput\n");
	strcat(str, "#endif\n\n");
	strcat(str, "/*\n");
	strcat(str, " * samp-timestamp 1.0.0 "\
		"(https://github.com/Jeroen52/samp-timestamp)\n");
	strcat(str, " */\n\n");
	strcat(str, "#define _INC_TIMESTAMP \"");
	AppendCurrentTimeToString(str);
	str[(strlen(str)-1)] = '\0';
	strcat(str, "\"");
	store_data("samp-timestamp.inc", str);
	#ifdef DEBUG
		printf("%d\n", strlen(str));
		#ifdef OS_Windows
			getchar();
		#endif
	#endif
}

AppendCurrentTimeToString(char *target)
{
	time_t rawtime;
	struct tm * timeinfo;

	time ( &rawtime );
	timeinfo = localtime ( &rawtime );
	strcat(str, asctime (timeinfo));
	return 1;
}

store_data(const char *filepath, const char *data)
{
	FILE *fp = fopen(filepath, "w");
	if (fp != NULL)
	{
		fputs(data, fp);
		fclose(fp);
		return 1;
	}
	return 0;
}