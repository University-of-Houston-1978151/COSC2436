#include "Library.h"
#include <iostream>

Library::Library()
{
    numBooks = 0;
    firstBook = nullptr;
    lastBook = nullptr;
}

//Copy constructor
Library::Library(Library &other)
{
    //  implement this function
    numBooks = other.numBooks;
    firstBook = other.firstBook;
    lastBook = other.lastBook;
}

int Library::getnumBooks() const
{
    return numBooks;
}

LibraryBook *Library::getFirstBook()
{
    return firstBook;
}
LibraryBook *Library::getLastBook()
{
    return lastBook;
}

// return a pointer to the n'th book in the linked list
LibraryBook *Library::getBook(const int pos)
{
    // implement this function
    LibraryBook *curBook;
    curBook = firstBook;

    int count = 0;
    while (curBook != NULL)
    {
        if (count == pos)
        {
            return curBook;
        }
        curBook = curBook->next;
        count++;
    }

    return NULL;
}

// add a Book to the end of the linked list
void Library::addBook(Book book)
{
    // implement this function
    LibraryBook *newBook = new LibraryBook();

    newBook->book = book;

    if (firstBook == NULL)
    {
        firstBook = newBook;
        lastBook = newBook;
        numBooks++;
    }
    else
    {
        lastBook->next = newBook;
        newBook->prev = lastBook;
        lastBook = newBook;
        numBooks++;
    }
}

// Move a book to the front of the linked list
void Library::moveToFront(LibraryBook *entry)
{
    // implement this function
    if (entry == firstBook || firstBook == NULL || firstBook->next == NULL)
    {
        return;
    }
    else if (entry == lastBook)
    {
        LibraryBook *curBook = firstBook;
        LibraryBook *secLast = NULL;
        while (firstBook->next != NULL)
        {
            secLast = curBook;
            curBook = curBook->next;
        }
        secLast->next = NULL;
        curBook->next = firstBook;
        firstBook = curBook;
    }
    else
    {
        entry->prev->next = entry->next;
        entry->next->prev = entry->prev;
        firstBook->prev = entry;
        entry->next = firstBook;
        entry->prev = NULL;
        firstBook = entry;
    }
}

// print all Books
void Library::printAllBooks() const
{
    // implement this function
    LibraryBook *curBook;
    curBook = firstBook;

    while (curBook != NULL)
    {
        curBook->book.printBook();
        curBook = curBook->next;
    }
}

// print all Books of a single Genre
void Library::printBooksOfOneGenre(string genre)
{
    // implement this function
    LibraryBook *curBook;
    curBook = firstBook;

    while (curBook != NULL)
    {
        if (curBook->book.getGenre() == genre)
        {
            curBook->book.printBook();
        }
        curBook = curBook->next;
    }
}
