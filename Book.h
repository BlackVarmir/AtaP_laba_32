#ifndef BOOK_H
#define BOOK_H
#include <string>


class Book {
private:
    std::string titleBook;
    std::string authorBook;
    int yearBook;
    int totalPagesBook;
    double priceBook;
    double pricePaperBackBook = 25.0;

    void calculatePrice();
public:

    Book();

    Book(std::string title, std::string author, int year, int pages);

    std::string getTitle() const { return titleBook; }
    std::string getAuthor() const { return authorBook; }
    int getYear() const { return yearBook; }
    int getPages() const { return totalPagesBook; }
    double getPrice() const { return priceBook; }

    void setTitle(const std::string& title) { titleBook = title; }
    void setAuthor(const std::string& author) { authorBook = author; }
    void setYear(int year) { yearBook = year; }
    void setPages(int pages);

    void Create_Book();
    void Display() const;
};
#endif //BOOK_H
