#include <parser.h>

int main(int argc, char *argv[])
{
    Parser StartParse = Parser();
    StartParse.parse("test.txt", "delimeters.txt", "keywords.txt", "output.txt", "useridentifiers.txt", "userconstants.txt");
    return 0;
}

