// Thomas Russel Carrel
//
// checklines.cpp
//
//  This short routine loads a test file and searches for any lines longer than
// eighty characters.  If any long lines are found it reproduces the line on
// screen along with line numbers.


#include<iostream>
#include<fstream>
#include<cctype>
#include<cmath>

using namespace std;

#include<dirent.h> //open directories

//  List of valid extensions seperated by periods(.).
// Just using an array of strings may be a simple solution.
static const string EXTENSIONS = 
"h.cpp.js.php.c.aspx.json.htm.xml.pl.bas.java.phtml.cc.c#.m.c++.py.txt";

int main()
{
    DIR* directory = opendir( "./" );
    struct dirent* dir_dat;
    string filename;

    int num_files = 0;
    int num_lines = 0;
    int num_long_lines = 0;
    cout << endl;

    cout << "\033[2J" << flush;
    cout << "\033[0;0H" << flush;

    ifstream in_file;

    while( dir_dat = readdir(directory) )
    {
        filename = dir_dat->d_name;
        size_t dot_loc = filename.find_last_of( '.' ); //for reading just an ext
        if( dot_loc != std::string::npos )
        {
            string extension = filename.substr( dot_loc + 1 );
            if( extension != "" &&
                    EXTENSIONS.find(extension) != std::string::npos )
            {
                int line_num = 0;
                num_files++;
                cout << "\033[4m" << filename << "\033[0m:" << endl;

                in_file.open( filename.c_str() );

                while( !in_file.eof() )
                {
                    ++line_num;

                    int chars = 0;
                    string text = "";
                    getline( in_file, text );
                    num_lines++;

                    while( text[chars] != 0 )
                    {
                        chars++;
                    }

                    if( chars > 80 )
                    {
                        cout << "\033[1;32m" << chars << " chars.";
                        cout << "\t\033[0;33m" << flush;
                        cout << line_num;
                        cout << "\033[0m" << flush;
                        cout << " " << text << endl;

                        num_long_lines++;
                    }
                }
                line_num--;


                cout << "\t\t\tFile was \033[4m" << line_num << "\033[0m line";
                if(line_num >= 2)
                    cout << "s";
                cout << " long." << endl << endl;

                in_file.close();
            }
        }
    }

    if( num_files > 0 )
    {
        // This line is intentionally too long to allow for testing.
        cout << " Checked " << num_lines - num_files <<
            " total lines over " << num_files <<
            " files." << endl << endl;

        if( num_long_lines == 0 ) 
        {
            cout << "\033[1;30;42m" << flush;
            cout << "                              " << endl;
            cout << "    No long lines detected.   " << endl;
            cout << "                              " << endl;
            cout << "\033[1;31;42m" << flush;
            cout << "          WELL DONE           " << endl;
            cout << "\033[1;30;42m" << flush;
            cout << "                              " << endl;
            cout << "  No lines need modification  " << endl;
            cout << "      before submission       " << endl;
            cout << "                              " << endl;
        }
        else
        {
            int line_length = 26;
            line_length +=
                floor(log10(num_long_lines)); //Adds num of chars in int
            string blank_line = string( line_length, ' ') + "\n";

            cout << "\033[1;37;41m" << flush;

            cout << blank_line;
            cout << "  ";
            cout << "\033[5;33;41m" << flush << num_long_lines 
                << "\033[1;37;41m" << flush;
            if( num_long_lines == 1 )
                cout << " long line detected.   " << endl;
            else
                cout << " long lines detected.  " << endl;
            cout << blank_line;
            cout << " Fix the lines listed"    
                << string( line_length - 21, ' ') << endl;
            cout << " above before you"        
                << string( line_length - 17, ' ') << endl;
            cout << " submit your assignment." 
                << string( line_length - 24, ' ') << endl;

            cout << blank_line;
        }
    }
    else
    {
        cout << "No were found to be checked.";
    }

    cout << "\033[0m" << endl << endl;
    return 0;
}
