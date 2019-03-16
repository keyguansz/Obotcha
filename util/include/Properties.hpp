#ifndef __PROPERTIES_HPP__
#define __PROPERTIES_HPP__

#include "Object.hpp"
#include "StrongPointer.hpp"

#include "String.hpp"
#include "HashMap.hpp"
#include "File.hpp"

namespace obotcha {

DECLARE_SIMPLE_CLASS(Properties) {

public:
    _Properties();
    
    void set(String key,String value);
    
    String get(String key);

    void load(File file);

    void save(String path);

private:
    HashMap<String,String> mProps;

    const static String gPropEqualString;
    
    const static String gPropEnterString;

};

}
#endif