#include <iostream>
#include "Book.h"

using namespace std;

Book::Book() : titleBook("Unknown"), authorBook("Яцько О."), yearBook(2023), totalPagesBook(0), priceBook(0.0) {}

Book::Book(string title, string author, int year, int pages)
    : titleBook(title), authorBook(author), yearBook(year), totalPagesBook(pages) {
    calculatePrice();
}

void Book::calculatePrice() {
    double costPerPage = 0.0;
    if (totalPagesBook < 100) {
        costPerPage = 1.0;
    } else if (totalPagesBook > 300) {
        costPerPage = 0.8;
    } else {
        costPerPage = 0.9;
    }
    priceBook = (costPerPage * totalPagesBook) + pricePaperBackBook;
}

void Book::setPages(int pages) {
    totalPagesBook = pages;
    calculatePrice();
}

void Book::Create_Book() {
    cout << "Enter book title: ";
    cin >> titleBook;
    cout << "Enter author: ";
    cin >> authorBook;
    cout << "Enter year of publication: ";
    cin >> yearBook;
    cout << "Enter number of pages: ";
    cin >> totalPagesBook;
    calculatePrice();
}

void Book::Display() const {
    cout << "Title: " << titleBook << endl;
    cout << "Author: " << authorBook << endl;
    cout << "Year: " << yearBook << endl;
    cout << "Total pages: " << totalPagesBook << endl;
    cout << "Price: " << priceBook << " UAH" << endl;
}