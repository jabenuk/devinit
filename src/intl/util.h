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

#ifndef __DEVINIT_UTIL_H__
#define __DEVINIT_UTIL_H__

/**
 * @brief Convert a given string to UPPERCASE.
 * 
 * @param lower the string to convert.
 */
void convupper(char *lower);

/**
 * @brief Check if a directory (at path) exists.
 * 
 */
unsigned char direxists(const char *path);

/**
 * @brief Check if string val is in an array of strings.
 * 
 */
unsigned char valinarray(const char *val, const char *arr[], unsigned int arrsize);

#endif