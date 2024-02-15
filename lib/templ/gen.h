#ifndef GEN_H
#define GEN_H

#include <x86intrin.h>

#include <ext/random>

#include "templ/main.h"

using ui = unsigned;
const ui seed = __rdtsc();
__gnu_cxx::sfmt19937 rng{seed};
ttt > il T rand(T l, T r) { return uniform_int_distribution<T>{l, r}(rng); }

#endif
