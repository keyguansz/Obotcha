#ifndef __XML_READER_H__
#define __XML_READER_H__

#include "Object.hpp"
#include "StrongPointer.hpp"
#include "IniValue.hpp"
#include "File.hpp"
#include "rapidxml.hpp"
#include "XmlValue.hpp"

using namespace rapidxml;

namespace obotcha {

DECLARE_SIMPLE_CLASS(XmlReader) {

public:
    _XmlReader(const char* path);

    _XmlReader(String path);

    _XmlReader(File file);

    XmlValue parse();

private:
    File xmlfile;

    xml_document<>  doc;
};

}

#endif