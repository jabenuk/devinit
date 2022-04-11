// -----------------------------------------------------------------------------
// Copyright (c) 2021 Jack Bennett
// -----------------------------------------------------------------------------
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY  KIND,  EXPRESS  OR
// IMPLIED, INCLUDING BUT NOT LIMITED  TO  THE  WARRANTIES  OF  MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT  SHALL  THE
// AUTHORS OR COPYRIGHT HOLDERS BE  LIABLE  FOR  ANY  CLAIM,  DAMAGES  OR  OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
// -----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

#include "intl/dialogue.h"
#include "intl/util.h"

#define __vprintf(urgency, str, ...)\
{\
if (urgency > SUPPRESSLVL && SUPPRESSLVL < 2) printf(str, __VA_ARGS__);\
}

static const struct option LONG_OPTIONS[] = {
	{ "pname",		required_argument,	0, 'p' },
	{ "language",	required_argument,	0, 'l' },
	{ "output",		required_argument,	0, 'o' },

	{ "quiet",		no_argument,		0, 'q' },
	{ "silent",		no_argument,		0, 'S' },

	{ "help", 		no_argument,	 	0, 'h' },
	{ "version", 	no_argument,	 	0, 'V' },
	{ 0, 			0, 					0,  0  }
};

char *PROJECT_NAME = "";
char *PROJECT_LANGUAGE = "";
static char *OUTPUT_DIR = "";
static unsigned char SUPPRESSLVL = 0;		// 0: all output | 1: quiet output (-q) | 2: no output (-S)

/**
 * @brief parse command-line arguments via getopt
 * 
 * @param _argc argc
 * @param _argv argv
 * 
 * @return -1 if the program should halt. 0 if not.
 */
int parseargs(int *_argc, char *_argv[]);

/**
 * @brief main function
 * 
 */
int main(int argc, char *argv[]) {
	// parse arguments
	// end the program if necessary
	switch (parseargs(&argc, argv)) {
		case -1:
			return 0;
		case -2:
			return 1;
		default:
			break;
	}

	// assert that there is no existing folder by the name of OUTPUT_DIR.
	if (direxists(OUTPUT_DIR)) {
		printf("devinit: directory '%s' already exists.\n", OUTPUT_DIR);
		return 1;
	}

	// download the appropriate template as a ZIP from GitHub.
	// unfortunately PROJECT_LANGUAGE is not integral; otherwise I would have used a switch-case statement.
	if (!strcmp(PROJECT_LANGUAGE, "C")) {
		system("wget https://github.com/jabenuk/devinit/archive/template_c.zip -O .devinit.template.zip 2>/dev/null");
	}
	if (!strcmp(PROJECT_LANGUAGE, "CXX")) {
		system("wget https://github.com/jabenuk/devinit/archive/template_cxx.zip -O .devinit.template.zip 2>/dev/null");
	}

	// create project folder
	__vprintf(2, "  => Creating %s project '%s'\n", PROJECT_LANGUAGE, PROJECT_NAME);
	mkdir(OUTPUT_DIR, S_IRWXU);
	
	// extract the zip into the project folder
	{
		char _unzip_command[100] = "unzip -qq .devinit.template.zip -d \"";
		strcat(_unzip_command, OUTPUT_DIR); 
		strcat(_unzip_command, "\""); 

		__vprintf(1, "  => Extracting template into '%s'...\n", OUTPUT_DIR);
		system(_unzip_command);
	}

	// delete the zip archive
	remove(".devinit.template.zip");

	// ---
	// some language templates have some extra work that needs to be done for the project directory.
	// this work is done below.

	// some stuff for C projects
	if (!strcmp(PROJECT_LANGUAGE, "C")) {
		chdir(OUTPUT_DIR);

		// ---
		// move the source code from the 'devinit-template_c' directory
		//
		__vprintf(1, "  => Organising project folder...\n", 0); // stupid macro needs a third argument so its just nul

		char _mv_command[100] = "mv ";
		strcat(_mv_command, "devinit-template_c/* ./");
		system(_mv_command);

		// delete the old 'devinit-template_c' folder
		system("rm -rf devinit-template_c/");
	}

	// some stuff for C++ projects
	if (!strcmp(PROJECT_LANGUAGE, "CXX")) {
		chdir(OUTPUT_DIR);

		// ---
		// move the source code from the 'devinit-template_c' directory
		//
		__vprintf(1, "  => Organising project folder...\n", 0); // stupid macro needs a third argument so its just nul

		char _mv_command[100] = "mv ";
		strcat(_mv_command, "devinit-template_cxx/* ./");
		system(_mv_command);

		// delete the old 'devinit-template_c' folder
		system("rm -rf devinit-template_cxx/");
	}

	return 0;
}

/**
 * @brief parse command-line arguments via getopt
 * 
 * @param _argc argc
 * @param _argv argv
 * 
 * @return -1 if the program should halt successfully, -2 if the program should halt with an error. 0 if the program can continue.
 */
int parseargs(int *_argc, char *_argv[]) {
	if (*_argc <= 1) {
		prhelp();
		return -1;
	}

	int c;

	while (1) {
		int index = 0;
		
		c = getopt_long(*_argc, _argv, "p:l:o:qSh", LONG_OPTIONS, &index);
		if (c == -1) {
			break;
		}

		switch (c) {
			case 'p':	// -p or --pname
				PROJECT_NAME = optarg;
				break;
			case 'l':	// -l or --language
				PROJECT_LANGUAGE = optarg;
				convupper(optarg);
				break;
			case 'o':	// -o or --output
				OUTPUT_DIR = optarg;
				break;

			case 'q': 	// -q or --quiet
				SUPPRESSLVL = 1;
				break;
			case 'S': 	// -S or --silent
				SUPPRESSLVL = 2;
				break;

			case 'h':	// -h or --help
				prhelp();
				return -1;
			case 'V':	// --version
				prvers();
				return -1;

			case '?':	// invalid
				return -2;
			default:	// getopt error
				printf("devinit: ?? getopt_long returned character code %o ??\n", c);
				return -2;
		}
	}
	
	// (-p | --pname) is required!
	if (PROJECT_NAME == "") {
		printf("devinit: no project name was passed\n");
		return -2;
	}

	// (-l | --language) is required!
	if (PROJECT_LANGUAGE == "") {
		printf("devinit: no project language was passed\n");
		return -2;
	}

	// if no output directory was used, make one with the name of the project
	if (OUTPUT_DIR == "") {
		OUTPUT_DIR = PROJECT_NAME;
	}

	return 0;
}