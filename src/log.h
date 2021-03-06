/**
 *    _______       _______            __        __
 *   / ____/ |     / / ___/____  _____/ /_____  / /_
 *  / / __ | | /| / /\__ \/ __ \/ ___/ //_/ _ \/ __/
 * / /_/ / | |/ |/ /___/ / /_/ / /__/ ,< /  __/ /_
 * \____/  |__/|__//____/\____/\___/_/|_|\___/\__/
 *
 * The MIT License (MIT)
 * Copyright (c) 2009-2016 Gerardo Orellana <hello @ goaccess.io>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef ERROR_H_INCLUDED
#define ERROR_H_INCLUDED

#define FATAL(fmt, ...) do {                                                  \
  fprintf (stderr, "\nFatal error has occurred");                             \
  fprintf (stderr, "\nError occured at: %s - %s - %d\n", __FILE__,            \
           __FUNCTION__, __LINE__);                                           \
  fprintf (stderr, fmt, ##__VA_ARGS__);                                       \
  fprintf (stderr, "\n\n");                                                   \
  exit(EXIT_FAILURE);                                                         \
} while (0)

#ifdef DEBUG
#define DEBUG_TEST 1
#else
#define DEBUG_TEST 0
#endif

#define LOG(x) do { if (DEBUG_TEST) dbg_printf x; } while (0)
/* access requests log */
#define ACCESS_LOG(x, ...) do { access_fprintf x; } while (0)

int access_log_open (const char *path);
void access_fprintf (const char *fmt, ...);
void access_log_close (void);
void dbg_printf (const char *fmt, ...);

#endif // for #ifndef ERROR_H
