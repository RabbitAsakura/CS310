#include <iostream>
#include <string>
#include <stdexcept>

namespace LibSystem{
   using std::string;

  struct BookRecord
   {
    string title;
    string authour;
    int id;

      void setDetails(const string& t, const string& a, int i)
       {
        title = t;
        authour = a;
        id = i;
       }
 };