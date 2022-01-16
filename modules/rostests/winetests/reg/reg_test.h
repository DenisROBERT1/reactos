/*
 * Copyright 2021 Hugh McMaster
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */

#ifndef __REG_TEST_H__
#define __REG_TEST_H__

#include <stdio.h>
#include <windows.h>
#include "wine/test.h"

/* Common #defines */
#define KEY_WINE "Software\\Wine"
#define KEY_BASE KEY_WINE "\\reg_test"
#define REG_EXIT_SUCCESS 0
#define REG_EXIT_FAILURE 1

/* Helper functions */
#define run_reg_exe(c,r) run_reg_exe_(__LINE__,c,r)
BOOL run_reg_exe_(unsigned line, const char *cmd, DWORD *rc);

#define verify_reg_nonexist(k,v) verify_reg_nonexist_(__LINE__,k,v)
void verify_reg_nonexist_(unsigned line, HKEY hkey, const char *value);

#define close_key(k) close_key_(__LINE__,k)
void close_key_(unsigned line, HKEY hkey);

#define verify_key(k,s) verify_key_(__LINE__,k,s)
void verify_key_(unsigned line, HKEY key_base, const char *subkey);

#define verify_key_nonexist(k,s) verify_key_nonexist_(__LINE__,k,s)
void verify_key_nonexist_(unsigned line, HKEY key_base, const char *subkey);

#define add_key(k,p,s) add_key_(__LINE__,k,p,s)
void add_key_(unsigned line, const HKEY hkey, const char *path, HKEY *subkey);

LONG delete_tree(const HKEY key, const char *subkey);

#define add_value(k,n,t,d,s) add_value_(__LINE__,k,n,t,d,s)
void add_value_(unsigned line, HKEY hkey, const char *name, DWORD type, const void *data, size_t size);

#endif /* __REG_TEST_H__ */