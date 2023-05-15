//stream_iterators.cpp
//Illustrates STL input and output stream iterators.

#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;

int main()
{
    cout << "\nThis program illustrates the use of input and output "
        "stream iterators.\nFirst we look at output stream iterators.";
    cout << "\nPress Enter to continue ... ";  cin.ignore(80, '\n');

    int odds[]  = { 1, 3, 5, 7, 9  };
    int evens[] = { 2, 4, 6, 8, 10 };
    vector<int> v(5);

    cout << "\nWe begin by displaying the contents of an array of "
        "odd integers using the STL\ncopy algorithm and "
        "and an \"anonymous\" output stream iterator:\n";
    copy (odds, odds+5, ostream_iterator<int>(cout, " "));
    cout << "\nPress Enter to continue ... ";  cin.ignore(80, '\n');

    cout << "\nNext we copy the values from an array of even integers "
        "into a pre-sized vector\nof integers and then display the "
        "contents of the vector in the same way:\n";
    copy(evens, evens+5, v.begin());
    copy (v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << "\nPress Enter to continue ... ";  cin.ignore(80, '\n');

    cout << "\nNow we display the same vector contents again, this "
        "time using a named\noutput stream iterator which also "
        "uses a different value separator:\n";
    ostream_iterator<int> outStream(cout, " | ");
    copy (v.begin(), v.end(), outStream);
    cout << "\nPress Enter to continue ... ";  cin.ignore(80, '\n');

    cout << "\nFinally, we copy odd integers from an array and "
        "even integers from a vector\nto an output file and then "
        "display the file to confirm. The odd integers are\noutput "
        "one per line.";
    cout << "\nPress Enter to continue ... ";  cin.ignore(80, '\n');
    ofstream outFile("stream_iterators.dat");
    copy(odds, odds+5, ostream_iterator<int>(outFile, "\n"));
    copy(v.begin(), v.end(), ostream_iterator<int>(outFile, " ! "));
    outFile.close();  outFile.clear();
    cout << "\nHere are the contents of stream_iterators.dat:\n";
    system("type stream_iterators.dat | more"); //Portability alert!
    cout << "\nPress Enter to continue ... ";  cin.ignore(80, '\n');

    cout << "\nNow we turn our attention to input stream iterators.";
    cout << "\nPress Enter to continue ... ";  cin.ignore(80, '\n');

    cout << "\nFirst we read some integers entered from the keyboard, "
        "using an anonymous\ninput stream iterator connected to the "
        "standard input (the keyboard), and\ncopy those integers to a "
        "vector, then display vector contents to confirm.";
    cout << "\nPress Enter to continue ... ";  cin.ignore(80, '\n');  
    cout << "\nEnter 5 integers (terminate with end-of-file "
        "on a new line): ";
    copy(istream_iterator<int>(cin), istream_iterator<int>(), v.begin());
    cin.clear();
    cout << "\nHere are the vector contents: ";
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << "\nPress Enter to continue ... ";  cin.ignore(80, '\n');

    cout << "\nNext we read some more integers entered from the "
        "keyboard, write their square\nroots directly to a file, "
        "then display the file to confirm.";
    cout << "\nPress Enter to continue ... ";  cin.ignore(80, '\n');
    cout << "\nEnter any number of integers on the line below and "
        "\nterminate with an end-of-file on a new line:\n";
    outFile.open("stream_iterators.dat");
    transform(istream_iterator<int>(cin), istream_iterator<int>(),
        ostream_iterator<double>(outFile, "\n"), sqrt);
    outFile.close();  outFile.clear();
    cin.clear();
    cout << "\nHere are the contents of the file:\n";
    system("type stream_iterators.dat | more"); //Portability alert!
    cout << "\nPress Enter to continue ... ";  cin.ignore(80, '\n');

    cout << "\nNow we read the values from the previous output file, "
        "and write the ceiling\nof each value to the standard output, "
        "this time using named input and output\nstream iterators.";
    cout << "\nPress Enter to continue ... ";  cin.ignore(80, '\n');
    ifstream inFile("stream_iterators.dat");
    istream_iterator<double> inStream(inFile);
    istream_iterator<double> inStreamEOF;
    ostream_iterator<int> outputStream(cout, " ");
    cout << "\nHere are the resulting values:\n";
    transform(inStream, inStreamEOF, outputStream, ceil);
                   //___^___
                   //Same as using istream_iterator<double>() here.
    inFile.close();  inFile.clear();
    cout << "\nPress Enter to continue ... ";  cin.ignore(80, '\n');

    cout << "\nFinally, we simply display the contents of the file "
        "stream_iterators.dat by\nincrementing an input stream "
        "iterator connected to that file.";
    cout << "\nPress Enter to continue ... ";  cin.ignore(80, '\n');
    inFile.open("stream_iterators.dat");
    istream_iterator<double> anotherInStream(inFile);
    istream_iterator<double> anotherInStreamEOF;
    cout << "\nHere are the values from the file:\n";
    while (anotherInStream != anotherInStreamEOF)
        cout << *anotherInStream++ << " ";
    inFile.close();  inFile.clear();
    cout << "\nPress Enter to continue ... ";  cin.ignore(80, '\n');
}