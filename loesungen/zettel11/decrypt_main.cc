#include <fstream>
#include <iostream>
#include <map>
#include <vector>

void init_zero (std::map<char, int> & map);

//  Print a map
template <class T, class S>
    void print(std::map<T, S> map)
    {
        for (auto it = map.begin(); it != map.end(); it++)
        {
            std::cout << it->first << " => " << it->second << std::endl;
        }
    }


int main()
{
    std::string file = "encrypted_text.txt";
    std::string output_file = "decrypted_text.txt";

    std::ifstream stream_in(file);
    std::string text;
    char in;


//  Read file to std::string text
    while (stream_in >> in)
    {
        text += in;
    }

    std::map <char, int> counts;
    init_zero(counts);
    for (char letter : text)
    {
        for (auto it = counts.begin(); it != counts.end(); it++)
            if (it->first == tolower(letter))
            {
                it->second += 1;
            }
    }

//  Print std::map counts
  print(counts);

//  c: Sort
    std::map<int, char> sorted;
    for (auto it = counts.begin(); it != counts.end(); it++)
    {
        sorted.insert(std::pair<int, char>(it->second, it->first));
    }

//  Print std::map sorted
  print(sorted);

    std::vector<char> letters = 
    {'z', 'j', 'q', 'x', 'k', 'v', 'b', 'y', 'g', 'p', 'w', 'f', 'm', 'c', 'u', 'l', 'd', 'r', 'h', 's', 'n', 'i', 'o', 'a', 't', 'e'};


//  Create and fill std::map decrypt
    std::map<char, char> decrypt;
    auto it_s = sorted.begin();
    auto it_l = letters.begin();

    while (it_s != sorted.end() && it_l != letters.end())
    {
        decrypt.insert(std::pair<char, char>(it_s->second, *it_l));
        decrypt.insert(std::pair<char,char>(toupper(it_s->second), toupper(*it_l)));
        it_s++;
        it_l++;
    }

//    print(decrypt);

    std::ofstream output(output_file, std::ofstream::out);
    std::string output_string = "";
    std::ifstream input_stream(file);
    std::string line = "";
    bool is_letter = false;

    while (!input_stream.eof())
    {
        std::getline (input_stream, line);
        for (auto sign : line)
        {
// Nach Buchstaben suchen
            is_letter = false;
            for (auto it = decrypt.begin(); it != decrypt.end(); it++)
                {
                    if (sign == it->first) 
                    {
                        output_string += decrypt.at(sign);
                        is_letter = true;
                        break;
                    }
                }

//  Zeichen ist kein Buchstabe? --> Satzzeichen direkt übernehmen.
            if (!is_letter) output_string += sign;
        }
//  Zeile ist zu Ende --> Zeilenumbruch einfügen.
        output_string+= "\n";
    }

//  Write output-file
    output << output_string;

//  print message
    std::cout << "Successfully decrypted text from '" << file << "'. to output file '" << output_file << "'." << std::endl
    << "using the following decryption map..." << std::endl;

    print(decrypt); 


    return 0;
} // END OF MAIN

void init_zero (std::map<char, int> & map)
{
    std::vector<char> alphabet = 
    {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    for (char letter : alphabet)
    {
        map.insert(std::pair<char, int>(letter, 0));
    }
}
