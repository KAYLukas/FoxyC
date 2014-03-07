//
//  Exception.h
//  FoxyC
//
//  Created by Kay Lukas on 06-03-14.
//  Copyright (c) 2014 Kay Lukas. All rights reserved.
//

#ifndef FoxyC_SyntaxLogic_Exceptions_h
#define FoxyC_SyntaxLogic_Exceptions_h

void _FoxyC_SyntaxLogic_Exception_throw(Exception* exception);

void _FoxyC_SyntaxLogic_Exception_try_setup(char *file,char *function,int line);

void _FoxyC_SyntaxLogic_Exception_try_post_iteration();

int _FoxyC_SyntaxLogic_Exception_try();

int _FoxyC_SyntaxLogic_Exception_catch(char *typeName);

int _FoxyC_SyntaxLogic_Exception_finally();

void _FoxyC_SyntaxLogic_Exception_exception_is_handled();

Exception* _FoxyC_SyntaxLogic_Exception_get_exception();

#endif
