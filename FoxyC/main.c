//
//  main.c
//  FoxyC
//
//  Created by Kay Lukas on 06-03-14.
//  Copyright (c) 2014 Kay Lukas. All rights reserved.
//

#include <stdio.h>
#include "FoxyC.h"

int main(int argc, const char * argv[])
{
    const Class* const clazz = getClass(Class);
    const char * const str = clazz->class->class->name;
    
    //a = foxy(clazz $ getClass())
    //->
    //a = push(this) ? setThis(clazz) ? call(getClass()) ? pop() ? result() : NULL : NULL: NULL :NULL :NULL;
    1 ? 1 ? 1 : NULL : NULL;
    
    
    // insert code here...
    printf("Hello, World! %s\n", str);
    return 0;
}

