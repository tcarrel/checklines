# checklines
Loads code files and checks for lines longer than 80 chars.

# Recommended setup
After compiling, give the executable the name of your choice if you don't like the pre-selected "lines".
Copy the file into your "~/bin" directory.

# Use and output
Type <lines> or whatever name you gave the executable.
If no lines longer than 80 chars are found, it wills say so along with a list of all the files checked, the number of lines in each file, and the total number of lines.
If lines longer than 80 chars are found, it will display the length of the line, the line number, and the contents of the line.


# To Do
- Make the code more object-oriented.
- Make selection of files that need to be read (i.e. files that contain code) "smarter."
- Add additional accessible options through command line arguments.
- - Check Specific file/directory.
- - Enable/Disable colored output.
- Red vim setup files like .vimrc so that line output matches vim's formatting.
- Recommended locations for newlines to bring line lengths down to under 80 chars.
- - Make it so that recommended locations for newlines match closely with c++ coding style guidelines.
- - Allow changes to files to be made from within the program through slection of lines.
