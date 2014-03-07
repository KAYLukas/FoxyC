//
//  Exception.h
//  FoxyC
//
//  Created by Kay Lukas on 06-03-14.
//  Copyright (c) 2014 Kay Lukas. All rights reserved.
//

#ifndef FoxyC_Macros_Exceptions_h
#define FoxyC_Macros_Exceptions_h

#include "MetaMacros.h"
#include "../SyntaxLogic/Exceptions.h"


#define THROW(exception) __CLIB_throw(exception)

#define TRY _DEFINES_CONTROL_BLOCK(__CLIB_try_setup(), 2, __CLIB_try_post_iteration())\
            if(__CLIB_try())

#define CATCH(typeName) else if(__CLIB_catch(#typeName))\
                    _DEFINES_CONTROL_BLOCK(typeName = __CLIB_get_exception(), 1, __CLIB_exception_is_handled())
#define CATCHALL(types, name) else if(__CLIB_catchall(#types)\
                    _DEFINES_CONTROL_BLOCK(Exception* name = __CLIB_get_exception(), 1, __CLIB_exception_is_handled())
#define FINALLY else if(__CLIB_finally())

#endif
