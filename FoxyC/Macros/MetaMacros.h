//
//  MetaMacros.h
//  FoxyC
//
//  Created by Kay Lukas on 06-03-14.
//  Copyright (c) 2014 Kay Lukas. All rights reserved.
//

#ifndef FoxyC_Macros_MetaMacros_h
#define FoxyC_Macros_MetaMacros_h

/**
 * Controls which define macro is selected depending on the amount of arguments given.
 * For example when you want to overload a define depending on the amount of arguments
 * you can select with this macro on the amount of arguments in __VAR_ARGS__ 
 * which macro is chosen.
 * For instance, #define min(...) _FOXYC_META_MACRO_SWITCH_3(__VAR_ARGS__, MIN3, MIN2, MIN1)
 * will select min 3 in case 3 arguments are given, 2 in case 2 arguments are given and
 * 1 in case 1 argument is given.
 */
#define _FOXYC_META_MACRO_SWITCH_0(NAME, ...) NAME
#define _FOXYC_META_MACRO_SWITCH_1(_1, ...) _FOXYC_META_MACRO_SWITCH_0(__VA_ARGS__)
#define _FOXYC_META_MACRO_SWITCH_2(_1, ...) _FOXYC_META_MACRO_SWITCH_1(__VA_ARGS__)
#define _FOXYC_META_MACRO_SWITCH_3(_1, ...) _FOXYC_META_MACRO_SWITCH_2(__VA_ARGS__)
#define _FOXYC_META_MACRO_SWITCH_4(_1, ...) _FOXYC_META_MACRO_SWITCH_3(__VA_ARGS__)
#define _FOXYC_META_MACRO_SWITCH_5(_1, ...) _FOXYC_META_MACRO_SWITCH_4(__VA_ARGS__)
#define _FOXYC_META_MACRO_SWITCH_6(_1, ...) _FOXYC_META_MACRO_SWITCH_5(__VA_ARGS__)
#define _FOXYC_META_MACRO_SWITCH_7(_1, ...) _FOXYC_META_MACRO_SWITCH_6(__VA_ARGS__)
#define _FOXYC_META_MACRO_SWITCH_8(_1, ...) _FOXYC_META_MACRO_SWITCH_7(__VA_ARGS__)
#define _FOXYC_META_MACRO_SWITCH_9(_1, ...) _FOXYC_META_MACRO_SWITCH_8(__VA_ARGS__)
#define _FOXYC_META_MACRO_SWITCH_10(_1, ...) _FOXYC_META_MACRO_SWITCH_9(__VA_ARGS__)
#define _FOXYC_META_MACRO_SWITCH_11(_1, ...) _FOXYC_META_MACRO_SWITCH_10(__VA_ARGS__)
#define _FOXYC_META_MACRO_SWITCH_12(_1, ...) _FOXYC_META_MACRO_SWITCH_11(__VA_ARGS__)
#define _FOXYC_META_MACRO_SWITCH_13(_1, ...) _FOXYC_META_MACRO_SWITCH_12(__VA_ARGS__)
#define _FOXYC_META_MACRO_SWITCH_14(_1, ...) _FOXYC_META_MACRO_SWITCH_13(__VA_ARGS__)
#define _FOXYC_META_MACRO_SWITCH_15(_1, ...) _FOXYC_META_MACRO_SWITCH_14(__VA_ARGS__)
#define _FOXYC_META_MACRO_SWITCH_16(_1, ...) _FOXYC_META_MACRO_SWITCH_15(__VA_ARGS__)


//Exports a define, this ensures that defines like __COUNTER__ are replaced correctly
#define _FOXYC_META_EXPORT(define) define

//Generates a new unique variable name

#define __PRIV_FOXYC_META_CONCAT(a, b) \
    a ## b //In this macre b == some number is concatenated with a.
#define _FOXYC_META_CONCAT(a, b) \
    _FOXYC_META_EXPORT(__PRIV_FOXYC_META_CONCAT(a,b))
#define _FOXYC_META_UNIQUE_NAME(prefix) \
    _FOXYC_META_EXPORT(_FOXYC_META_CONCAT(prefix, __COUNTER__))

#define __PRIV_FOXYC_META_OPTIONAL_COMMA(...)\
    , ##__VA_ARGS__

#define _FOXYC_META_OPTIONAL_COMMA(input) \
    _FOXYC_META_EXPORT(__PRIV_FOXYC_META_OPTIONAL_COMMA(input))


#define __PRIV_FOXYC_META_CONTROL_BLOCK2(before, count, after, variable) \
    for(int variable = 0 _FOXYC_META_OPTIONAL_COMMA(before); variable < count; variable++ _FOXYC_META_OPTIONAL_COMMA(after))

#define __PRIV_FOXYC_META_CONTROL_BLOCK1(before, count, after) \
    _FOXYC_META_EXPORT(\
        __PRIV_FOXYC_META_CONTROL_BLOCK2(before, count, after, _FOXYC_META_UNIQUE_NAME(__PRIV_FOXYC_META_LOCAL_VAR_NR_))\
        )

/*
 * Controls the next control block (i.e. statement or { ... } block)
 * The block can be controlled by executing the block a 'count' amount
 * of times, by executing a call before executing the next control block
 * and by executing a call after every time the control block is executed
 * @param Statement before The statement to be executed before the first time the control block is executed
 * @param int count The amount of times the next code block should be executed
 * @param Statement after The statement to be executed every time the next control block has been executed
 */
#define _FOXYC_META_CONTROL_BLOCK( before, count, after)\
    _FOXYC_META_EXPORT(__PRIV_FOXYC_META_CONTROL_BLOCK1(before, count, after))

#endif
