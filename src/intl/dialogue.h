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

#ifndef __DEVINIT_DIALOGUE_H__
#define __DEVINIT_DIALOGUE_H__

#define VERSION "1.0.2"
#define LAST_COMPILE "12/04/2022"

/**
 * @brief Print a help dialogue based on the docopt standard
 * @sa http://docopt.org/
 * 
 */
void prhelp();

/**
 * @brief Print version information
 * 
 */
void prvers();

/**
 * @brief Print available langs
 * 
 */
void prlangs();

#endif