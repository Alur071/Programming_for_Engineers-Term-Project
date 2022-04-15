# Programming_for_Engineers-Term-Project
Table of Content
ABSTRACT 
INTRODUCTION
USER INTERFACE
FUNCTIONALITY OF THE SYSTEM4


ABSTRACT
By using the language C++, a System is created which enables the buying, selling, adding of 
Books in a Book Store. This System first prints out a menu of 4 different choices after the 
execution. These choices include the Customer, Employee, Dealer, and a way to exit the 
store. After the Selection the System moves forward accordingly. If exit was selected it exits 
the Code. For the other 3 choices it prints new menus in which the System can execute the 
wanted Functions. By accessing one of these user types, the System opens new menus 
according to the chosen user type. Each of the menus include functions to go back to the 
Initial Menu. Using this Method, new Books or Customers entering the Book Store can be 
initialized and served. These Menus and Methos are all clearly and detailed explained in the 
Project Report.
INTRODUCTION
Why a management system is important for companies? A management system's quality 
directly affects the efficiency of the company. What happens without a management system 
in any company? Mixing names, quantities or prices of products can have significant 
negative consequences for the company, keeping track of the new delivery could be 
disturbed, updating the new products could be harder and more confusing and with that, the 
lack of professionalism of the employees can be seen without a proper management system. 
And the lack of professionalism that comes with affects customers, which naturally affects 
sales. A management system is all about preventing that. For these reasons, a management 
system has been developed.
USER INTERFACE
After the Execution of the Program there are 4 Choices displayed. Customer, Employee,
Dealer, and Exit.
Entering Customer displays a new menu of Methods. These are 1. Initializing Customer 
Name, Customer Age, Customer Money. 2. Displaying the whole Queue with the Empty ones 
included. 3. Display a selected line of the Queue. 4. To Display the Books in the Book Store.
Entering Employee display another new menu of Methods. 1. For adding a Book with Book 
Name, Book Price, Book Amount. 2,3,4 initialize Book Name, Book Price, Book Amount 
separately. 5. To display selected position of the Books in the Book Store. 6. To display all 
Books in Book Store empty Spaces included. 7. Is to serve Customer but Initially there are 
no Customers they need to get initialized using Customer CPP. 8. To go back to the initial
menu.
Entering Dealer display menu of the Dealer. 1. to show the Employee the sellable books of 
the Dealer. 2. To sell an agreed book to Employee. 3. To go back to initial menu.

FUNCTIONALITY OF THE SYSTEM
A Book Store System was designed to be able to buy, sell , add Books which are bought 
from a Book Dealer and sold to Customers. After the execution of the code 4 Choices are 
presented. These are Customer, Employee, Dealer and Exit. Choosing to Exit closes the 
code. The Customer CPP has methods called setCustomerName(), setCustomerAge(), 
setCustomerMoney are used to initialize new Customers. getCustomerName(), 
getCustomerAge(), getCustomerMoney(), getAll_Customers() are used to display each 
Information of the Customers. sizeOfQueue() returns the size of the Queue. The Book Store 
CPP setBookName(), setBookPrice(), setBookAmount() are used to add new Books. 
setBookAfterSell() is used to increase the Amount of the Book which is bought from the 
Dealer. getBookName(),getBookPrice(), getBookAmount() are used to display each 
Information of the Books. IsThereAnyBook() looks if the bookname exist in Stock. getAll() 
display all positions of the Bookshelf. InitialBooks() initializes 5 books. Buy_Book() increases 
the Amount of the bought book and Sell_Book() decreases the Amount of the sold Book. 
getBook() returns the Information of the Book inputted. addBook() adds a new Book with 
each of their Information. The Dealer CPP InnitialBooksOfDealer() initialize 3 books. 
setBookNameDealer(), setBookPriceDealer (), setBookAmountDealer () adds new books. 
getBookNameDealer(), getBookPriceDealer (), getBookAmountDealer () displays the 
Information. getAll_Dealer() displays all information of all Books. Sell() decreases the Book 
Amount of the Dealer and increase the Book Amount of the Book Store.
