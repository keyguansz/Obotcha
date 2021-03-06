#ifndef __ZIP_INPUT_STREAM_HPP__
#define __ZIP_INPUT_STREAM_HPP__

#include <fstream>
#include <iostream>

#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

extern "C" {
#include "zlib.h"
#include "zip.h"
#include "unzip.h"
}

#include "Object.hpp"
#include "StrongPointer.hpp"

#include "String.hpp"
#include "File.hpp"
#include "InputStream.hpp"
#include "ByteArray.hpp"

namespace obotcha {

DECLARE_SIMPLE_CLASS(ZipStream) IMPLEMENTS(InputStream) {
public:

    _ZipStream();

    int read();

    int read(ByteArray buffer);

    bool open();

    void close();

    void compress(String src,String dest);

    void compressWithPassword(String src,String dest,String password);


    int uncompress(const char *src);

    int uncompress(const char *src,const char *dest);

    int uncompressWithPassword(const char *src,const char *dest,const char *password);

    int uncompress(String src);

    int uncompress(String src,String dest);

    int uncompressWithPassword(String src,String dest,String password);


private:
    String mPath;

    std::ifstream fstream;     

    int writeInZipFile(zipFile zFile,File file);

    int minizip(File src, File dest,String zipfolder,char *password);

    String combine(String parent,String current);

    uLong filetime(const char *file, tm_zip *tmzip, uLong *dt);

    int getFileCrc(const char* filenameinzip,char*buf,unsigned long size_buf,unsigned long* result_crc);

    int isLargeFile(const char* filename);

    //uncompress interface
    int do_extract_currentfile(unzFile uf,char *dest,const int* popt_extract_without_path,int* popt_overwrite,const char* password);

    int do_extract(unzFile uf,char *dest,int opt_extract_without_path,int opt_overwrite,const char* password);
/*
    int do_extract_onefile(unzFile uf,char *dest,const char* filename,int opt_extract_without_path,int opt_overwrite,const char* password);
*/
    int mymkdir(const char* dirname);

    int makedir (char *newdir);

    void change_file_date(const char *filename,uLong dosdate,tm_unz tmu_date);
};

}
#endif
