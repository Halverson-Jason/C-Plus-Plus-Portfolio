/***********************************************************************
* Program:
*    Checkpoint 04a, CLASSES
*    Brother Alvey, CS165
* Author:
*    Jason Halverson
* Summary:
*    Write a C++ program that has a class for a book, prompts the user 
*    for the book's information, and then displays it back.
*
*    Estimated:  1.0 hrs
*    Actual:     1.5 hrs
*      The styleChecker and memorizing classes
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * Book class - Private members , title and author ,
 * Public members getTitleAuthor() , displayTitle()
 **********************************************************************/
class Book
{
   private:

      string title;
      string author;

   public:

      /**********************************************************************
       * Getter for Book class
       * Receives title and author
       **********************************************************************/
      void getTitleAuthor()
      {
         cout << "Title: ";
         getline(cin, title);
         cout << "Author: ";
         getline(cin, author);
      }

      /**********************************************************************
       * Display for Book class
       * displays title and author in desired format
       **********************************************************************/
      void displayTitle()
      {
         cout << "\"" << title << "\" by " << author << endl;
      }
};

/**********************************************************************
 * instantiate Book class
 * Call member functions getTitleAuthor and displayTitle
 ***********************************************************************/
int main()
{
   Book myBook;
   myBook.getTitleAuthor();
   myBook.displayTitle();
   return 0;
}
