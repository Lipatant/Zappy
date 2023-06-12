/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** linked_list
*/

#include "struct.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

buffer_t *create_node(char *str)
{
    buffer_t *node = malloc(sizeof(buffer_t));

    if (node == NULL) {
        perror("malloc");
        return NULL;
    }

    node->cmd = str;
    node->next = NULL;
    return node;
}

void delete_at_begining(buffer_t **head)
{
    buffer_t *current = *head;

    if (*head == NULL)
        return;
    *head = current->next;
    free(current);
}

void insert_at_end(buffer_t **head, char *str)
{
    buffer_t *newNode = create_node(str);
    buffer_t *current = *head;

    if (*head == NULL) {
        *head = newNode;
    } else {
        while (current->next != NULL)
            current = current->next;
        current->next = newNode;
    }
}

int size_list(buffer_t *head)
{
    int size = 0;
    buffer_t *current = head;

    while (current != NULL) {
        size++;
        current = current->next;
    }
    return size;
}
