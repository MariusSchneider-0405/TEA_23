#include "list.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <fmt/format.h>

// ----------------------------------------------------------
// 2.1 Knotenverwaltung
// ----------------------------------------------------------

ListNode_t* NewListNode(void) {
    fmt::println("in \"{}\"", __func__);

    ListNode_t* node = (ListNode_t*)malloc(sizeof(ListNode_t));
    if (!node) return NULL;

    node->data = 0;
    node->pNext = NULL;

    return node;
}

void FreeListNode(ListNode_t* elem) {
    fmt::println("in \"{}\"", __func__);
    free(elem);
}

// ----------------------------------------------------------
// 2.2 Listenverwaltung
// ----------------------------------------------------------

List_t* NewList(void) {
    fmt::println("in \"{}\"", __func__);

    List_t* list = (List_t*)malloc(sizeof(List_t));
    if (!list) return NULL;

    list->pHead = NULL;
    list->pTail = NULL;
    list->size = 0;

    return list;
}

void FreeList(List_t* list) {
    fmt::println("in \"{}\"", __func__);

    if (!list) return;

    ListNode_t* n = list->pHead;

    while (n != NULL) {
        ListNode_t* next = n->pNext;
        FreeListNode(n);
        n = next;
    }

    free(list);
}

// ----------------------------------------------------------
// 2.3 Einfügen
// ----------------------------------------------------------

int InsertIntoLinkedList(List_t* list, ListNode_t* elem) {
    fmt::println("in \"{}\"", __func__);

    if (!list || !elem)
        return EXIT_FAILURE;

    // Leere Liste
    if (list->pHead == NULL) {
        list->pHead = elem;
        list->pTail = elem;
    }
    else {
        // ans Ende hängen
        list->pTail->pNext = elem;
        list->pTail = elem;
    }

    elem->pNext = NULL;
    list->size++;

    return EXIT_SUCCESS;
}

int InsertIntoLinkedListAfterNode(List_t* list, ListNode_t* node, ListNode_t* elem) {
    fmt::println("in \"{}\"", __func__);

    if (!list || !node || !elem)
        return EXIT_FAILURE;

    elem->pNext = node->pNext;
    node->pNext = elem;

    // Falls hinter dem Tail eingefügt wird
    if (node == list->pTail) {
        list->pTail = elem;
    }

    list->size++;

    return EXIT_SUCCESS;
}

// ----------------------------------------------------------
// 2.4 Entfernen
// ----------------------------------------------------------

int RemoveFromList(List_t* list, ListNode_t* elem) {
    fmt::println("in \"{}\"", __func__);

    if (!list || !elem)
        return EXIT_FAILURE;

    if (list->pHead == NULL)
        return EXIT_FAILURE;

    // Sonderfall: Element ist Head
    if (list->pHead == elem) {
        list->pHead = elem->pNext;

        // War es gleichzeitig Tail?
        if (list->pTail == elem)
            list->pTail = NULL;

        FreeListNode(elem);
        list->size--;

        return EXIT_SUCCESS;
    }

    // Vorgänger suchen
    ListNode_t* prev = list->pHead;
    while (prev->pNext && prev->pNext != elem) {
        prev = prev->pNext;
    }

    if (prev->pNext != elem) {
        // Element nicht gefunden
        return EXIT_FAILURE;
    }

    // Entfernen
    prev->pNext = elem->pNext;

    // Tail aktualisieren
    if (elem == list->pTail) {
        list->pTail = prev;
    }

    FreeListNode(elem);
    list->size--;

    return EXIT_SUCCESS;
}

// ----------------------------------------------------------
// 2.5 Traversieren
// ----------------------------------------------------------

ListNode_t* GetNext(const List_t* list, ListNode_t* elem) {
    fmt::println("in \"{}\"", __func__);

    if (elem == NULL)
        return list->pHead;

    return elem->pNext;
}
