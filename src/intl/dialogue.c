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

#include "info.h"

/**
 * @brief Print a help dialogue based on the docopt standard
 * @sa http://docopt.org/
 * 
 */
void prhelp() {
	printf(	"devinit: a command suite for quickly initialising projects from templates hosted on GitHub.\n"
			"\n"
			"Usage:\n"
			//"  devinit -p <project name> -l <language>\n"
			//"  devinit -p <project name> -l <language> -o <output dir>\n"
			"  devinit -h | --help\n"
			"  devinit --version\n"
			"\n"
			"Options:\n"
			//"  -p, --pname		Specify the project name (required)\n"
			//"  -l, --language	Specify the project language (required)\n"
			//"  -o, --output		Explictly specify an output directory other than the current working directory.\n"
			"  -h, --help		Show this help dialogue.\n"
			"  --version		Give information about the command, such as version.\n"
	);
}

/**
 * @brief Print version information
 * 
 */
void prvers() {
	printf("devinit version %s: see Git repo at https://github.com/jabenuk/devinit. \n", VERSION);
}