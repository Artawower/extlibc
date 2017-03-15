/*
 * This file is part of extlibc.
 *
 * extlibc is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * extlibc is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with extlibc. If not, see <http://www.gnu.org/licenses/>.
 *
 * Copyright (C) 2017 Artem Kozlov
 * Contacts: <artemix-dev@yandex.ru>
 */

#ifndef _LIST_H_
#define _LIST_H_

#include <stdint.h>

// ---------- Structures ----------

typedef void * DATA_TYPE;

typedef struct _list_node
{
    DATA_TYPE data;
    struct _list_node *next, *prev;
} list_node;

typedef struct
{
    list_node *first, *last;
} list;

// ---------- Functions ----------

#define RESULT_OK 0x00
#define NODE_IS_NULL 0x01

// Initialize list.
void list_init(list *list_ptr);

// Get list length.
uint32_t list_length(list *list_ptr);

// Get node in list by index.
list_node *list_get(list *list_ptr, uint32_t index);

// Push ready and allocated node to back.
uint8_t list_push_node(list *list_ptr, list_node *node);

// Push value to back. New node will be created.
uint8_t list_push(list *list_ptr, DATA_TYPE data);

#endif /* _LIST_H_ */
