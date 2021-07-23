#ifndef SC_STRTOULL_H
#define SC_STRTOULL_H

#include <limits.h>

#ifdef _WIN32
#  define strtoull _strtoui64
#endif

#endif /* SC_STRTOULL_H */
