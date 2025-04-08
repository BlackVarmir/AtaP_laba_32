#include <iostream>
#include "Book.h"
using namespace std;

void calculateStatistics(Book books[], int size) {
    if (size == 0) {
        cout << "No books to analyze." << endl;
        return;
    }

    double totalPages = 0;
    double minPrice = books[0].getPrice();
    double maxPrice = books[0].getPrice();

    for (int i = 0; i < size; i++) {
        totalPages += books[i].getPages();
        if (books[i].getPrice() < minPrice) {
            minPrice = books[i].getPrice();
        }
        if (books[i].getPrice() > maxPrice) {
            maxPrice = books[i].getPrice();
        }
    }

    double avgPrice = totalPages / size;
    cout << "Average number of pages: " << avgPrice << endl;
    cout << "Minimum price: " << minPrice << " UAH" << endl;
    cout << "Maximum price: " << maxPrice << " UAH" << endl;
}

void sortByPrice(Book books[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (books[j].getPrice() < books[j + 1].getPrice()) {
                Book temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }
}

int main() {
    Book defaultBook;
    cout << "Default Book:" << endl;
    defaultBook.Display();
    cout << endl;

    const int SIZE = 5;
    Book books[SIZE];

    cout << "Enter details for " << SIZE << " books:" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << "Book " << (i + 1) << ":" << endl;
        books[i].Create_Book();
        cout << endl;
    }

    cout << "List of Books:" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << "Book " << (i + 1) << ":" << endl;
        books[i].Display();
        cout << endl;
    }

    cout << "Statistics:" << endl;
    calculateStatistics(books, SIZE);
    cout << endl;

    sortByPrice(books, SIZE);
    cout << "Books sorted by price (ascending):" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << "Book " << (i + 1) << ":" << endl;
        books[i].Display();
        cout << endl;
    }

    return 0;
}
