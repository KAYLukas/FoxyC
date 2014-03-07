//
//  Class.h
//  FoxyC
//
//  Created by Kay Lukas on 06-03-14.
//  Copyright (c) 2014 Kay Lukas. All rights reserved.
//

#ifndef FoxyC_Class_h
#define FoxyC_Class_h
#include "Object.h"
#include "../Macros/Classes.h"


foxy(
    class (Class)
    {
        Class const * const super;
        char const * const name;
        const size_t size;
    }
)

foxy(a $ b)

#endif
