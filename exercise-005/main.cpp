#include <fmt/format.h>
#include <fmt/chrono.h>

#include "list.hpp"

int main(int argc, char** argv)
{
    fmt::print("Starting {}\n", argv[0]);

    // Neue Liste anlegen
    List_t* list = NewList();

    // Drei neue Listenknoten erzeugen
    ListNode_t* a = NewListNode();
    ListNode_t* b = NewListNode();
    ListNode_t* c = NewListNode();

    a->data = 10;
    b->data = 20;
    c->data = 30;

    // Einfügen am Ende
    InsertIntoLinkedList(list, a);
    InsertIntoLinkedList(list, b);

    // Einfügen nach einem Knoten (b -> c)
    InsertIntoLinkedListAfterNode(list, b, c);

    // Liste ausgeben
    fmt::println("Liste nach dem Einfügen:");
    for (ListNode_t* n = GetNext(list, NULL); n != NULL; n = GetNext(list, n)) {
        fmt::print("{} ", n->data);
    }
    fmt::print("\n");

    // Ein Element entfernen
    RemoveFromList(list, b);

    // Ausgabe nach Entfernen
    fmt::println("Liste nach Remove(b):");
    for (ListNode_t* n = GetNext(list, NULL); n != NULL; n = GetNext(list, n)) {
        fmt::print("{} ", n->data);
    }
    fmt::print("\n");

    // Liste freigeben
    FreeList(list);

    return 0;
}
