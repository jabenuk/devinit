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

#include "util.h"
#include <string.h>
#include <sys/stat.h>

/**
 * @brief Convert a given string to UPPERCASE.
 * 
 * @param lower the string to convert.
 */
void convupper(char *lower) {
	for (unsigned int i = 0; lower[i] != '\0'; i++) {
		if (lower[i] >= 'a' && lower[i] <= 'z') {
			lower[i] -= 32;
		}
	}
}

/**
 * @brief Check if a directory (at path) exists.
 * 
 */
unsigned char direxists(const char *path) {
	struct stat stats;

	stat(path, &stats);

	if (S_ISDIR(stats.st_mode)) {
		return 1;
	}
	return 0;
}