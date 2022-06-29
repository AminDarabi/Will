#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <random>

void print_help() {

    std::cout << "OVERVIEW: WILL will help you on decision making in dilemmas.\n\n";
    std::cout << "USAGE: will [options] [CHOICE_1 CHOICE_2 ... | stdin]\n\n";
    
    std::cout << "OPTIONS and arguments:\n";
    std::cout << "--file, -f <file>\tWILL will read choices in <file>.\n";
    std::cout << "--input, -i\t\tWILL will read choices from stdin.\n";
    std::cout << "--shuffle, -s\t\tAll choices will print in a shuffled order.\n";
    std::cout << "--endline, -e\t\tchoices in stdin and files will separate by endline.\n";
    std::cout << "--newline, -n\t\tit works exactly like --endline.\n";
    std::cout << "--help, -h\t\thelp of usage will print.\n";
    
    return ;

}

void print_error_message(int error_number) {

    switch (error_number) {
        case 1: // NO choices error
            std::cerr << "THERE IS NO CHOICE, GO MAKE ONE!\n";
            break ;
        default:
            std::cerr << "AN ERROR OCCURRED!\n";
            break;
    }
    std::cerr << "for help page type: will --help\n";
    return ;

}

int main(int args, char ** argv) {

    std::vector<std::string> choices;
    bool shuffle = false, file = false, consol_input = false, end_line = false;

    for (size_t i = 1; i < args; i++) {
        if (argv[i] == std::string("-h") || argv[i] == std::string("--help")) {print_help(); return 0;}
        else if (argv[i] == std::string("-e") || argv[i] == std::string("--endline"))   end_line = true;
        else if (argv[i] == std::string("-n") || argv[i] == std::string("--newline"))   end_line = true;
        else if (argv[i] == std::string("-s") || argv[i] == std::string("--shuffle"))   shuffle = true;
        else if (argv[i] == std::string("-i") || argv[i] == std::string("--input"))     consol_input = true;
        else if (argv[i] == std::string("-f") || argv[i] == std::string("--file"))      file = true;
        else if (file) {
            file = false; std::ifstream file_in(argv[i]); std::string just_in;
            if (end_line) while (std::getline(file_in, just_in)) choices.push_back(just_in);
            else while (file_in >> just_in) choices.push_back(just_in);
        }
        else choices.push_back(argv[i]);
    }

    if (consol_input || !choices.size()) {
        std::string just_in;
        if (end_line) while (std::getline(std::cin, just_in) && just_in != "--1" && just_in != "--END")
            choices.push_back(just_in);
        else while (std::cin >> just_in && just_in != "--1" && just_in != "--END") choices.push_back(just_in);
    }

    std::random_device generator;
    if (shuffle) {
        std::shuffle(choices.begin(), choices.end(), generator);
        for (size_t i = 0; i < choices.size(); i++) std::cout << choices[i] << '\n';
    } else {
        std::uniform_int_distribution<size_t> distribution(0, choices.size() - 1);
        std::cout << choices[distribution(generator)] << '\n';
    }

    return 0;

}