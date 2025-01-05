#include <string>

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
}



