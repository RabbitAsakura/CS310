# Lab1.2

.hpp files were made for instructor, student and person to make things easier as the actual .cpp files would just need to inherit it while all of the code needed is in the .hpp file. There was a lot of classes as well of inheritance so that the other files like instructor would also get thrown exceptions if there was anything that wasn't filled out or was just left blank in the function. 


Exceptions for person object are thrown when the email is invalid(i.e. empty string), when id is less than 0 (must be positive), and when there isn't a name(i.e. empty string).
Exceptions for instructor object are thrown when office is empty and everything else that was inherited from person object.
Exceptions for student object are thrown when the graduation year is less than 2000 and everything else that was inherited from person object as well.

CSV works depending on the quotation used. Speifically double quotations used, would tell the parser to treat the content as a single field. If that data is enclosed with double quotations it would also contain a double quote within its value. With that it makes the internal double quotes "escape".