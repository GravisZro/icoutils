/* fileread.h - Offset checking routines for file reading
 *
 * Copyright (C) 1998-2005 Oskar Liljeblad
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#ifndef FILEREAD_H
#define FILEREAD_H

#include <stdbool.h>		/* POSIX/Gnulib */
#include "common/common.h"

#define RETURN_IF_BAD_POINTER(r, x) \
	if (!check_offset(fi->memory, fi->total_size, fi->name, &(x), sizeof(x))) { \
		/*printf("bad_pointer in %s:%d\n", __FILE__, __LINE__);*/ \
		return (r); \
	}
#define RETURN_IF_BAD_OFFSET(r, x, s) \
	if (!check_offset(fi->memory, fi->total_size, fi->name, x, s)) { \
		/*printf("bad_offset in %s:%d\n", __FILE__, __LINE__);*/ \
		return (r); \
	}

bool check_offset(char *, int, char *, void *, int);

#endif
