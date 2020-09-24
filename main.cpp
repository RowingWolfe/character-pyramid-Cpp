#include <iostream>
#include <string>

//Done.


std::string add_white_space(size_t len){
    std::string whitespace{};
    for(size_t i{0}; i<len; i++){
        whitespace += ' ';
    }
    return whitespace;
}

std::string reverse_string(std::string str){
    size_t n{str.length()};
    for (size_t i = 0; i < n / 2; i++)
            std::swap(str[i], str[n - i - 1]);
    //The first part of the string needs to be stripped out.
    //So I do it here.
    if (str.length() > 1)
        str.erase(0,1);
    return str;
}


int main()
{
    //So this has to take input and output a pyramid based on the input.
    //First we get the input
    std::string user_input{};
    getline(std::cin, user_input);

    //Output
    std::string output{};

    //Now we need a loop to go through the input from the user.
    for(size_t i{0}; i < user_input.length()+1; i++){
        //Create a line.
        std::string line{};
        //Add the whitespace based on length - i
        line += add_white_space(user_input.length() - i);

        //Create a string holding the chars to append
        std::string chars_to_append{};

        //Append each char of user_input up to i to the chars_to_append
        for(size_t j{0}; j < i; j++){
            chars_to_append += user_input[j];
        }

        //If the string is larger than 1 char, create add the reverse string starting at
        //index 1 as to avoid repeats.
        if(chars_to_append.length() > 1 ){
            chars_to_append += reverse_string(chars_to_append);
        }

        //Append the string to the line
        line += chars_to_append;

        //Add newline char.
        line += '\n';

        //Append line to output.
        output += line;


    }


    //Print output.
    std::cout << output;
    return 0;
}
