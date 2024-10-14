#include "Header.h"

int func_h_regex(string line, vector<string>& V, regex h_regex) {
    auto words_begin = sregex_iterator(line.begin(), line.end(), h_regex);    
    auto words_end = sregex_iterator();
    for (sregex_iterator i = words_begin; i != words_end; ++i) {
        smatch match = *i;
        string match_str = match[1].str();
        V.push_back(match_str);
        cout << endl << "header      ";
        cout << "  " << match_str << '\n';
    }
    return 0;
}

int func_p_regex(string line, vector<string>& V, regex p_regex) {
    auto words_begin = sregex_iterator(line.begin(), line.end(), p_regex);
    auto words_end = sregex_iterator();
    for (sregex_iterator i = words_begin; i != words_end; ++i) {
        smatch match = *i;
        string match_str = match[1].str();
        V.push_back(match_str);
        cout << endl << "paragraph   ";
        cout << "  " << match_str << '\n';
    }
    return 0;
}

int func_ref_regex(string line, vector<string>& V, regex ref_regex) {
   
    regex ban_ref_regex("wikipedia");

    auto words_begin = sregex_iterator(line.begin(), line.end(), ref_regex);
    auto words_end = sregex_iterator();
    for (sregex_iterator i = words_begin; i != words_end; ++i) {
        smatch match = *i;
        string match_str_link = match[1].str();   
        string match_str_descrip = match[2].str();
        if (regex_search(line, ban_ref_regex)) {
            cout << endl << "---" << '\n';
        }
        else {
            V.push_back(match_str_link);
            V.push_back(match_str_descrip);
            if (match_str_link.length() > 100) {
                cout << endl << "Длина ссылки более 100 символов (" << match_str_link.length() << " символ):";
            }
            cout << endl << "link        ";
            cout << "  " << match_str_link << '\n';
            cout << endl << "description of link        ";
            cout << "  " << match_str_descrip << '\n';
        }
        
    }
    return 0;
}
