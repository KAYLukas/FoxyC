//
//  Object.c
//  FoxyC
//
//  Created by Kay Lukas on 06-03-14.
//  Copyright (c) 2014 Kay Lukas. All rights reserved.
//

#include <stdio.h>
#include "Object.h"
#include "Class.h"

const Class Object_CLASS = {
    getClass(Class),
    NULL,
    "Object",
    sizeof(Object)
};
