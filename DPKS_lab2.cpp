#include <stdlib.h>
#include <stdio.h>
#include <string>
#include "getopt.h"

using namespace std;

int main(int argc, char* argv[]) {

	const char* args = ":hvm::M:";

	const struct option args_long[] = {
		{"help", no_argument, 0, 'h'},
		{"version", no_argument, 0, 'l'},
		{"mode", optional_argument, 0, 'm'},
		{"modify", required_argument, 0, 'M'},
		{ 0, 0, 0 }
	};

	int a;
	int index;

	bool help_activated = false;
	bool version_activated = false;
	bool mode_activate = false;
	bool modify_activate = false;

	while ((a = getopt_long(argc, argv, args, args_long, &index)) != -1)
	{
		switch (a) {
		case 'h': {
			if (help_activated == false)
			{
				printf("Arguments: help\n");
				help_activated = true;
			}
			break;
		};

		case 'v': {
			if (version_activated == false)
			{
				printf("Arguments: version\n");
				version_activated = true;
			}
			break;
		};

		case 'm': {
			if (mode_activate == false)
			{
				if (optarg == NULL)
				{
					printf("Arguments: mode\n");
					mode_activate = true;
				}
				else
				{
					printf("Arguments: mode = %s\n", optarg);
					mode_activate = true;
				}
			}
			break;
		};

		case 'M': {
			if (modify_activate == false)
			{
				if ((optarg[0] < '0') || (optarg[0] > '9'))
				{
					printf("Missing argument for -M (--value)\n");
					break;
				}
				else
				{
					printf("Arguments: Modify = %s\n", optarg);
					modify_activate = true;
				}
			}
			break;
		};

		case '?': {
			printf("Unknown option: %c\n", optopt);
			break;
		}

		case ':': {
			printf("Missing argument for %c\n", optopt);
			break;
		}
		};
	};
	return 0;
};
