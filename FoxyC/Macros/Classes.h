//
//  Classes.h
//  FoxyC
//
//  Created by Kay Lukas on 06-03-14.
//  Copyright (c) 2014 Kay Lukas. All rights reserved.
//

#ifndef FoxyC_Macros_Classes_h
#define FoxyC_Macros_Classes_h
#include "MetaMacros.h"
#include "../Classes/Object.h"
#include <stddef.h>

#define getClass(type) (&_FOXYC_META_CONCAT(type, _CLASS))


/**
 * We accept the following class definitions:
 * foxy(
 *  class(a)
 *  {
 *   //struct definiton
 *  }
 * )
 * or...
 * foxy(
 *    class(a extends b)
 *    {
 *      //struct definition
 *    }
 * )
 * In the first case the class will extend the class Object,
 * In the second case the class will extend the class b
 * The actual implementation is as follows:
 * class(a extends b) will be changed in to _CLASS(a extends b, --> _CLASS(a, b,
 * Secondly the last ')' from the foxy() will be used to include the struct definition
 * in the macro. After we have extracted those we have to close the first bracket from
 * the foxy declaration, we use an empty char to get rid of the brackets. (We can't
 * lead the bracket to a macro definition as the pre-processor works greedy...
 */
 //The main define, to which we want to morph our syntaxis
 //the definition argument is a block struct definition. (e.g. { int a; int b; } )
 #define _FOXYC_DEFINE_CLASS(type, superType, definition) \
    typedef struct type type;\
    struct type \
    { \
        struct superType;\
        struct definition;\
    };\
    extern const Class _FOXYC_META_CONCAT(type, _CLASS);
#define _FOXYC_DEFINE_IMPLEMENTATION(type, superType, definition) \
    const Class _FOXYC_META_CONCAT(type, _CLASS) = {\
        getClass(Class),\
        getClass(Object),\
        "Class",\
        sizeof(Class)\
        };
//Takes care of the foxy( statement
#define _FOXYC_CLASSES_BEGIN_FOXY \
    void _FOXYC_META_UNIQUE_NAME(_FoxyC_Macros_Class_IGNORE_)
#define _FOXYC_CLASSES_END_FOXY );



//Ends the foxy( statement with a bracket and defines the class
#define _FOXYC_CLASSES_CLASS3(type, superType, definition) \
    _FOXYC_CLASSES_END_FOXY\
    _FOXYC_DEFINE_CLASS(type, superType, definition)
#define _FOXYC_CLASSES_IMPLEMENTATION3(type, superType, definition) \
    _FOXYC_CLASSES_END_FOXY\
    _FOXYC_DEFINE_IMPLEMENTATION(type, superType, definition)


//To support the short hand
#define _FOXYC_CLASSES_CLASS2(type, definition)\
    _FOXYC_CLASSES_CLASS3(type, Object, definition)
#define _FOXYC_CLASSES_IMPLEMENTATION2(type, definition)\
    _FOXYC_CLASSES_IMPLEMENTATION3(type, Object, definition)


//Switch between short hand and full notation
#define _FOXYC_CLASSES_CLASS(...) _FOXYC_META_MACRO_SWITCH_3(__VA_ARGS__, _FOXYC_CLASSES_CLASS3, _FOXYC_CLASSES_CLASS2)(__VA_ARGS__)
#define _FOXYC_CLASSES_IMPLEMENTATION(...) _FOXYC_META_MACRO_SWITCH_3(__VA_ARGS__,\
     _FOXYC_CLASSES_IMPLEMENTATION3, _FOXYC_CLASSES_IMPLEMENTATION2)(__VA_ARGS__)


//The different environments for class definition and function calls
//Token paster used to prevent evaluating defines in x
#define _FOXYC_FOXY_CLASS_ENVIRONMENT(x) _FOXYC_CLASSES_BEGIN_FOXY(##x)
#define _FOXYC_FOXY_FUNCTION_CALL_ENVIRONMENT(this, function)


// --- KEYWORDS ---

#define implementation(x) _FOXYC_CLASSES_IMPLEMENTATION(x,
// Add a comma after the definition signature to add the definition to the FOXYC_CLASS_CLASS macro
#define class(x)  _FOXYC_CLASSES_CLASS(x,

//Will be replaced in the first macro call,
//(therefore the first macro with this as delimiter only has 1 argument)
#define extends ,
#define $ ,
//Switch between function call on object (2 params) and class definition (1 param)
//Actually, the foxy call always one argument, but this argument is expanded (the $ is expanded)
//in the macro call, therefore we actually check with this macro if it contains a '$'
//(or a 'extends', but this is not intended, just a side effect)
//The ## (token paster) operator ensures that we don't immediatly call any defines
//in x while outputting the define, we just transform the define to a new define.
//This ensure the sub-macros (class, for instance) can borrow the last ')' from foxy
#define foxy(x) \
    _FOXYC_META_MACRO_SWITCH_2(x,\
        _FOXYC_FOXY_FUNCTION_CALL_ENVIRONMENT,\
        _FOXYC_FOXY_CLASS_ENVIRONMENT)(##x)

//Now we have loaded all defines, and so we can run the class definition
#include "../Classes/Class.h"

#endif
