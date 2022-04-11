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
#include <getopt.h>

#include "intl/dialogue.h"

static struct option LONG_OPTIONS[] = {
	{ "help", 		no_argument,	 	0, 'h' },
	{ "version", 	no_argument,	 	0, 'v' },
	{ 0, 			0, 					0,  0  }
};

/**
 * @brief parse command-line arguments via getopt
 * 
 * @param _argc argc
 * @param _argv argv
 */
void parseargs(int *_argc, char *_argv[]);

/**
 * @brief main function
 * 
 */
int main(int argc, char *argv[]) {
	// parse arguments
	parseargs(&argc, argv);

	// if there are no arguments then just print help dialogue
	if (argc <= 1) {
		prhelp();
	}

	return 0;
}

/**
 * @brief parse command-line arguments via getopt
 * 
 * @param _argc argc
 * @param _argv argv
 */
void parseargs(int *_argc, char *_argv[]) {
	int c = 0;
	int optind = 0;

	while ((c = getopt_long(*_argc, _argv, "h", LONG_OPTIONS, &optind)) != -1) {
		switch (c) {
			case 'h':
				prhelp();
				break;
			case 'v':
				prvers();
				break;
			case '?':
				break;
			default:
				printf("devinit: getopt returned character code %o ??\n", c);
		}
	}
}