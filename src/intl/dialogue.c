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

#include "dialogue.h"
#include <stdio.h>

/**
 * @brief Print a help dialogue based on the docopt standard
 * @sa http://docopt.org/
 * 
 */
void prhelp() {
	printf(	"devinit: a command suite for quickly initialising projects from templates hosted on GitHub.\n"
			"\n"
			"Usage:\n"
			"  devinit -p \"<project name>\" -l <language>\n"
			"  devinit -p \"<project name>\" -l <language> -o <output dir>\n"
			"  devinit -h | --help\n"
			"  devinit -V | --version\n"
			"\n"
			"Options:\n"
			"  -l, --language	Specify the project language (required). Case insensitive.\n"
			"  -o, --output		Explictly specify an output directory other than the current working directory.\n"
			"  --override		Delete any previous directories of the same name as the output directory\n"
			"  -q, --quiet		Print less output.\n"
			"  -S, --silent		Print no output.\n"
			"  -h, --help		Show this help dialogue.\n"
			"  --version		Give information about the command, such as version.\n"
			"  --langs			Give information about available options for the --language flag.\n"
	);
}

/**
 * @brief Print version information
 * 
 */
void prvers() {
	printf("devinit version %s - last compiled %s\n", VERSION, LAST_COMPILE);
}

/**
 * @brief Print available langs
 * 
 */
void prlangs() {
	printf(	"Devinit supports the following languages:\n"
			"  - 'c': C projects\n"
			"  - 'cxx': C++ projects\n"
	);
}