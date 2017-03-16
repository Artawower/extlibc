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

#include "list.h"
#include <stdlib.h>
#include <stdio.h>

void list_init(list *list_ptr)
{
    list_ptr->first = NULL;
    list_ptr->last = NULL;
}

uint32_t list_length(list *list_ptr)
{
    list_node *node = list_ptr->first;

    uint32_t length;
    for (length = 0; node != NULL; length++)
        node = node->next;

    return length;
}

list_node *list_get_node(list *list_ptr, uint32_t index)
{
    if (index > list_length(list_ptr) - 1)
        return NULL;

    list_node *node = list_ptr->first;


    for (uint32_t position = 0; position < index; position++)
        node = node->next;

    return node;
}

uint8_t list_push_node(list *list_ptr, list_node *node)
{
    if (node == NULL)
        return NODE_IS_NULL;

    node->prev = list_ptr->last;
    node->next = NULL;

    if (list_length(list_ptr) == 0)
        list_ptr->first = node;

    else
        list_ptr->last->next = node;

    list_ptr->last = node;

    return RESULT_OK;
}

uint8_t list_push(list *list_ptr, DATA_TYPE data)
{
    list_node *node = (list_node *)malloc(sizeof(list_node));
    if (node == NULL)
        return NODE_IS_NULL;

    node->data = data;

    return list_push_node(list_ptr, node);
}
