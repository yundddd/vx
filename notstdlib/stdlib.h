#pragma once

#include "notstdlib/std.h"


/*
 * As much as possible, please keep functions alphabetically sorted.
 */

/* must be exported, as it's used by libgcc for various divide functions */
__attribute__((weak, unused, noreturn, section(".text.nolibc_abort"))) void
abort(void);

long atol(const char* s);

int atoi(const char* s);

void free(void* ptr);

/* getenv() tries to find the environment variable named <name> in the
 * environment array pointed to by global variable "environ" which must be
 * declared as a char **, and must be terminated by a nullptr (it is recommended
 * to set this variable to the "envp" argument of main()). If the requested
 * environment variable exists its value is returned otherwise nullptr is
 * returned. getenv() is forcefully inlined so that the reference to "environ"
 * will be dropped if unused, even at -O0.
 */
char* _getenv(const char* name, char** environ);

static inline __attribute__((unused, always_inline)) char* getenv(
    const char* name);

void* malloc(size_t len);

void* calloc(size_t size, size_t nmemb);

void* realloc(void* old_ptr, size_t new_size);

/* Converts the unsigned long integer <in> to its hex representation into
 * buffer <buffer>, which must be long enough to store the number and the
 * trailing zero (17 bytes for "ffffffffffffffff" or 9 for "ffffffff"). The
 * buffer is filled from the first byte, and the number of characters emitted
 * (not counting the trailing zero) is returned. The function is constructed
 * in a way to optimize the code size and avoid any divide that could add a
 * dependency on large external functions.
 */
int utoh_r(unsigned long in, char* buffer);
/* converts unsigned long <in> to an hex string using the static itoa_buffer
 * and returns the pointer to that string.
 */
static inline __attribute__((unused)) char* utoh(unsigned long in);
/* Converts the unsigned long integer <in> to its string representation into
 * buffer <buffer>, which must be long enough to store the number and the
 * trailing zero (21 bytes for 18446744073709551615 in 64-bit, 11 for
 * 4294967295 in 32-bit). The buffer is filled from the first byte, and the
 * number of characters emitted (not counting the trailing zero) is returned.
 * The function is constructed in a way to optimize the code size and avoid
 * any divide that could add a dependency on large external functions.
 */
int utoa_r(unsigned long in, char* buffer);

/* Converts the signed long integer <in> to its string representation into
 * buffer <buffer>, which must be long enough to store the number and the
 * trailing zero (21 bytes for -9223372036854775808 in 64-bit, 12 for
 * -2147483648 in 32-bit). The buffer is filled from the first byte, and the
 * number of characters emitted (not counting the trailing zero) is returned.
 */
int itoa_r(long in, char* buffer);

/* for historical compatibility, same as above but returns the pointer to the
 * buffer.
 */
static inline __attribute__((unused)) char* ltoa_r(long in, char* buffer);

/* converts long integer <in> to a string using the static itoa_buffer and
 * returns the pointer to that string.
 */
static inline __attribute__((unused)) char* itoa(long in);

/* converts long integer <in> to a string using the static itoa_buffer and
 * returns the pointer to that string. Same as above, for compatibility.
 */
static inline __attribute__((unused)) char* ltoa(long in);

/* converts unsigned long integer <in> to a string using the static itoa_buffer
 * and returns the pointer to that string.
 */
static inline __attribute__((unused)) char* utoa(unsigned long in);

/* Converts the unsigned 64-bit integer <in> to its hex representation into
 * buffer <buffer>, which must be long enough to store the number and the
 * trailing zero (17 bytes for "ffffffffffffffff"). The buffer is filled from
 * the first byte, and the number of characters emitted (not counting the
 * trailing zero) is returned. The function is constructed in a way to optimize
 * the code size and avoid any divide that could add a dependency on large
 * external functions.
 */
int u64toh_r(uint64_t in, char* buffer);
/* converts uint64_t <in> to an hex string using the static itoa_buffer and
 * returns the pointer to that string.
 */
static inline __attribute__((unused)) char* u64toh(uint64_t in);

/* Converts the unsigned 64-bit integer <in> to its string representation into
 * buffer <buffer>, which must be long enough to store the number and the
 * trailing zero (21 bytes for 18446744073709551615). The buffer is filled from
 * the first byte, and the number of characters emitted (not counting the
 * trailing zero) is returned. The function is constructed in a way to optimize
 * the code size and avoid any divide that could add a dependency on large
 * external functions.
 */
int u64toa_r(uint64_t in, char* buffer);

/* Converts the signed 64-bit integer <in> to its string representation into
 * buffer <buffer>, which must be long enough to store the number and the
 * trailing zero (21 bytes for -9223372036854775808). The buffer is filled from
 * the first byte, and the number of characters emitted (not counting the
 * trailing zero) is returned.
 */
int i64toa_r(int64_t in, char* buffer);

/* converts int64_t <in> to a string using the static itoa_buffer and returns
 * the pointer to that string.
 */
static inline __attribute__((unused)) char* i64toa(int64_t in);

/* converts uint64_t <in> to a string using the static itoa_buffer and returns
 * the pointer to that string.
 */
static inline __attribute__((unused)) char* u64toa(uint64_t in);