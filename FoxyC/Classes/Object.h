//
//  Object.h
//  FoxyC
//
//  Created by Kay Lukas on 06-03-14.
//  Copyright (c) 2014 Kay Lukas. All rights reserved.
//

#ifndef FoxyC_Object_h
#define FoxyC_Object_h

//Assume the definition of the Class class
typedef struct Class Class;
//Root object is defined raw, as our macros assume a super class always exist
typedef struct Object Object;
struct Object {
    Class const * const class;
};

extern const Class Object_CLASS;

#endif
