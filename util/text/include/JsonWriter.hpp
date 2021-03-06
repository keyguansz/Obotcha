#ifndef __JSON_WRITE_H__
#define __JSON_WRITE_H__

#include "Object.hpp"
#include "StrongPointer.hpp"
#include "String.hpp"
#include "Boolean.hpp"
#include "Integer.hpp"
#include "Float.hpp"
#include "Long.hpp"

#include "JsonValue.hpp"
#include "JsonArray.hpp"

#include "File.hpp"
#include "FileOutputStream.hpp"

namespace obotcha {

DECLARE_SIMPLE_CLASS(JsonWriter) {
public:
    _JsonWriter(File f);
    _JsonWriter(String path);

    void write(JsonValue value);
    void write(JsonArray value);

    void close();
    
private:
    FileOutputStream stream;    
};

}
#endif