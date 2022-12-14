#include "DBFile.h"

string DBFile::getFileName() {
    return FILE_NAME;
}

bool DBFile::isFileEmpty() {
    bool isEmpty = true;
    fstream textFile;
    textFile.open(getFileName().c_str(), ios::app);

    if (textFile.good() == true) {
        textFile.seekg(0, ios::end);
        if (textFile.tellg() != 0)
            isEmpty = false;
    }

    textFile.close();
    return isEmpty;
}
