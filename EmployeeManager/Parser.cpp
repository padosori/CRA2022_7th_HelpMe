#include <sstream>
#include "Parser.h"
#include <iostream>
using namespace std;

Command Parser::getCommand(string str) {
    if (str == "ADD") { return Command::ADD; }
    else if (str == "DEL") { return Command::DEL; }
    else if (str == "SCH") { return Command::SCH; }
    else if (str == "MOD") { return Command::MOD; }
    else { throw invalid_argument("Parser::getCommand, invalid command:" + str); }
}

Option Parser::getOption(string str) {
    if (str == "-p") { return Option::PRINT; }
    else if (str == "-f") { return Option::FIRST_NAME; }
    else if (str == "-l") { return Option::LAST_NAME_AND_PHONE_NUM; }
    else if (str == "-m") { return Option::MIDDLE_PHONE_NUM_AND_MONTH; }
    else if (str == "-y") { return Option::YEAR; }
    else if (str == "-d") { return Option::DAY; }
    else if (str == " ") { return Option::NONE; }
    else { throw invalid_argument("Parser::getOption, Parser::getOption, invalid option:" + str); }
}

ParsedLine Parser::parseLine(string str_line) {
    string column;
    ParsedLine parsed_line;
    stringstream str_stream(str_line);
    string word;

    for (int i = 0; getline(str_stream, word, ','); i++) {
        if (i == 0) {
            parsed_line.command = getCommand(word);
            parsed_line.command_str = word;
        }
        else if (i == 1 || i == 2 || i == 3) {
            parsed_line.options.emplace_back(getOption(word));
            parsed_line.options_str.emplace_back(word);
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

void Parser::addMoreInform(ParsedLine& parsed_line) {
    if (parsed_line.command == Command::ADD) {
        stringstream name_stream(parsed_line.informs[1].value);
        string name_first, name_last;
        getline(name_stream, name_first, ' ');
        getline(name_stream, name_last, ' ');
        parsed_line.informs.emplace_back(Inform{ "name_first", name_first });
        parsed_line.informs.emplace_back(Inform{ "name_last", name_last });
        
        stringstream phone_num_stream(parsed_line.informs[3].value);
        string phone_num_first, phone_num_middle, phone_num_last;
        getline(phone_num_stream, phone_num_first, '-');
        getline(phone_num_stream, phone_num_middle, '-');
        getline(phone_num_stream, phone_num_last, '-');
        parsed_line.informs.emplace_back(Inform{ "phoneNum_middle", phone_num_middle });
        parsed_line.informs.emplace_back(Inform{ "phoneNum_last", phone_num_last });

        string birthday = parsed_line.informs[4].value;
        parsed_line.informs.emplace_back(Inform{ "birthday_year", birthday.substr(0, 4) });
        parsed_line.informs.emplace_back(Inform{ "birthday_month", birthday.substr(4, 2) });
        parsed_line.informs.emplace_back(Inform{ "birthday_day", birthday.substr(6, 2) });
    }
}

void Parser::transformParsedLineCommand(ParsedLine& parsed_line) {
    if (parsed_line.command == Command::ADD) {
        parsed_line.informs[0].column = "employeeNum";
        parsed_line.informs[1].column = "name";
        parsed_line.informs[2].column = "cl";
        parsed_line.informs[3].column = "phoneNum";
        parsed_line.informs[4].column = "birthday";
        parsed_line.informs[5].column = "certi";
    }
}

void Parser::addYearPrefix(string& str) {
    string year_str = str.substr(0, 2);
    int year = stoi(year_str);
    if (year >= 0 && year <= 21) { str = "20" + str; }
    else if (year >= 69 && year <= 99) { str = "19" + str; }
    else { throw invalid_argument("Parser::addYearPrefix, invalid year:" + str); }
}

void Parser::transformParsedLineValue(ParsedLine& parsed_line) {
    if (parsed_line.command == Command::ADD) { addYearPrefix(parsed_line.informs[0].value); }
    else if (parsed_line.command == Command::DEL || parsed_line.command == Command::SCH) {
        if (parsed_line.informs[0].column == "employeeNum") { addYearPrefix(parsed_line.informs[0].value); }
    }
    else if (parsed_line.command == Command::MOD) {
        if (parsed_line.informs[0].column == "employeeNum") { addYearPrefix(parsed_line.informs[0].value); }
        if (parsed_line.informs[1].column == "employeeNum") { addYearPrefix(parsed_line.informs[1].value); }
    }
    else { throw invalid_argument("Parser::transformParsedLineValue, invalid value" + makeStrParsedLine(parsed_line)); }
}

string Parser::makeStrParsedLine(ParsedLine parsed_line) {
    string str;
    str = parsed_line.command_str + ",";
    for (auto option_str : parsed_line.options_str) {
        str = str + option_str + ",";
    }

    for (auto inform : parsed_line.informs) {
        str = str + inform.column + "," + inform.value + ",";
    }
    return str;
}

void Parser::transformParsedLineOption(ParsedLine& parsed_line) {
    if (parsed_line.options[1] == Option::FIRST_NAME) {
        if (parsed_line.informs[0].column == "name") { parsed_line.informs[0].column = "name_first"; }
    }
    else if (parsed_line.options[1] == Option::LAST_NAME_AND_PHONE_NUM) {
        if (parsed_line.informs[0].column == "phoneNum") { parsed_line.informs[0].column = "phoneNum_last"; }
        else if (parsed_line.informs[0].column == "name") { parsed_line.informs[0].column = "name_last"; }
    }
    else if (parsed_line.options[1] == Option::MIDDLE_PHONE_NUM_AND_MONTH) {
        if (parsed_line.informs[0].column == "phoneNum") { parsed_line.informs[0].column = "phoneNum_middle"; }
        else if (parsed_line.informs[0].column == "birthday") { parsed_line.informs[0].column = "birthday_month"; }
    }
    else if (parsed_line.options[1] == Option::YEAR) {
        if (parsed_line.informs[0].column == "birthday") { parsed_line.informs[0].column = "birthday_year"; }
    }
    else if (parsed_line.options[1] == Option::DAY) {
        if (parsed_line.informs[0].column == "birthday") { parsed_line.informs[0].column = "birthday_day"; }
    }
}

void Parser::transformParsedLine(ParsedLine& parsed_line) {
    transformParsedLineCommand(parsed_line);
    transformParsedLineValue(parsed_line);
    transformParsedLineOption(parsed_line);
    addMoreInform(parsed_line);
}

unique_ptr<vector<ParsedLine>> Parser::parse(const vector<string>& str) {
    auto parsed_lines = make_unique<vector<ParsedLine>>();

    for (auto str : str) {
        parsed_lines->emplace_back(parseLine(str));
    }

    // TODO: validate pared_lines

    for (auto& parsed_line : *parsed_lines) {
        transformParsedLine(parsed_line);
    }

    return move(parsed_lines);
}