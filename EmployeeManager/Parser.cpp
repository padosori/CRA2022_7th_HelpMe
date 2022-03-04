#include <sstream>
#include "Parser.h"

Command Parser::getCommand(string str) {
    if (str == "ADD") { return Command::ADD; }
    else if (str == "DEL") { return Command::DEL; }
    else if (str == "SCH") { return Command::SCH; }
    else if (str == "MOD") { return Command::MOD; }
    else { throw invalid_argument("invalid command"); }
}

Option Parser::getOption(string str) {
    if (str == "-p") { return Option::PRINT; }
    else if (str == "-f") { return Option::FIRST_NAME; }
    else if (str == "-l") { return Option::LAST_NAME_AND_PHONE_NUM; }
    else if (str == "-m") { return Option::MIDDLE_PHONE_NUM_AND_MONTH; }
    else if (str == "-y") { return Option::YEAR; }
    else if (str == "-d") { return Option::DAY; }
    else if (str == " ") { return Option::NONE; }
    else { throw invalid_argument("invalid option"); }
}

ParsedLine Parser::parseLine(string str_line) {
    string column;
    ParsedLine parsed_line;
    stringstream str_stream(str_line);
    string word;

    for (int i = 0; getline(str_stream, word, ','); i++) {
        if (i == 0) {
            parsed_line.command = getCommand(word);
        }
        else if (i == 1 || i == 2 || i == 3) {
            parsed_line.options.emplace_back(getOption(word));
        }
        else {
            if (parsed_line.command == Command::ADD) {
                parsed_line.informs.emplace_back(Inform{ "none", word });
            }
            else {
                if (i % 2 == 0) { column = word; }
                else { parsed_line.informs.emplace_back(Inform{ column, word }); }
            }
        }
    }
    return parsed_line;
}

unique_ptr<vector<ParsedLine>> Parser::parse(const vector<string>& str) {
    auto parsed_file_vector = make_unique<vector<ParsedLine>>();
    
    for (auto str : str) {
        parsed_file_vector->emplace_back(parseLine(str));
    }
    return move(parsed_file_vector);
}