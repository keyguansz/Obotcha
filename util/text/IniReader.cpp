#include "IniValue.hpp"
#include "IniReader.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>



namespace obotcha {

_IniReader::_IniReader(const char * path) {
    filepath = createString(path);
}

_IniReader::_IniReader(String path) {
    filepath = path;
}

_IniReader::_IniReader(File file) {
    filepath = file->getAbsolutePath();
}

IniValue _IniReader::parse() {

    dictionary *dict = iniparser_load(filepath->toChars());
    iniparser_dump(dict, stdout);
    char *p = (char *)iniparser_getstring(dict,"quotes:h1","fff");
    printf("p is %s \n",p);
    return createIniValue(dict);
}


}