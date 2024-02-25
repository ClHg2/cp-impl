#ifndef DIV_H
#define DIV_H

#include "templ/main.h"

ttt > il T cdiv(T a, T b) { return a / b + (a % b && (a ^ b) > 0); }
ttt > il T fdiv(T a, T b) { return a / b - (a % b && (a ^ b) < 0); }

#endif
