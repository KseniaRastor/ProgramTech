#include "Header.h"

regex p_regex(R"!!(<p>([^\/]+)<\/p>)!!");
regex h_regex(R"!!(<h\d>([^\/]+)<\/h\d>)!!");
//regex ref_regex(R"!!(<a\s+href="([^"]+)">)!!");
regex descrip_link_regex(R"!!(<a\s+href="([^"]+)">([^"]+)<\/a>)!!");


vector <string> V;
string line;

int main(int argc, char** argv) {
    setlocale(0, "rus");

    string file_name = argv[1];
    
    cout << "Исходный текст файла:\n";
    ifstream f(file_name);
    if (f.is_open()){
        while (getline(f, line)){
            cout << line << endl;
        }
    }
    f.close(); 


    f.open(file_name);
    if (f.is_open()){
        while (getline(f, line)){   
            func_h_regex(line, V, h_regex);
            func_p_regex(line, V, p_regex);
            func_ref_regex(line, V, descrip_link_regex);
        }
    }
   f.close();

   int i = 0;
   cout << endl << "\nВывод данных из контейнера:" << endl;
   for (vector<string>::iterator it = V.begin(); it != V.end(); ++it) {     
       cout << V[i] << endl;
       i++;
   }

    return 0;
}

//вывод пояснения к ссылке
//wikipedia запретить выводить ссылку
//путь ссылки длинее 100 симмволов - подсчет символов