#include <string>
#include <iostream>

enum Token{
    tok_eof = -1,

    // commands
    tok_def = -2,
    tok_extern = -3,

    // primary
    tok_identifier = -4,
    tok_number = -5
};

static std::string IdentifierStr;
static double Num;

// for reading the stream of chars

static int getTok(){
    
    static int lastChar = ' ';
    while(isspace(lastChar)){
        lastChar = getchar();
    }

    // We are dealing with an identifier
    if(isalpha(lastChar)){
        IdentifierStr = lastChar;
        while(isalnum((lastChar = getchar()))){
            // keeping adding to the var as long as input is alphanumeric(w/o spaces)
            IdentifierStr += lastChar;
        }

        if(IdentifierStr == "def") return tok_def;
        if(IdentifierStr == "extern") return tok_extern;
        return tok_identifier;
    }

    // dealing with a number [0-9.]
    if(isdigit(lastChar) || lastChar == '.'){
        std::string tmp;
        do{
            tmp += lastChar;
            lastChar = getchar();
        } while(isdigit(lastChar) || lastChar == '.');

        Num = strtod(tmp.c_str(),0);

        return tok_number;
    }

    // dealing with comments
    if(lastChar == '#'){
        // parse until EOL
        do{
            lastChar = getchar();
        } while(lastChar != EOF || lastChar != '\n');

        if(lastChar != EOF) return getTok();
    }

    if(lastChar == EOF) return tok_eof;

    int ret = int(lastChar);
    lastChar = getchar();
    return ret;
}

int main(){
    while(true){
        int tok = getTok();
        std::cout << "got " << tok << std::endl;
    }   
}


