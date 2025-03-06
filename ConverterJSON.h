//
// Created by user on 18.02.2025.
//

#ifndef CONVERTERJSON_H
#define CONVERTERJSON_H

#include <fstream>
#include <iostream>
#include "nlohmann/json.hpp"
#include <vector>
#include "SearchServer.h"


class ConverterJSON {
public:
    ConverterJSON();
    std::vector<std::string> GetTextDocuments();
    int GetResponsesLimit();
    std::vector<std::string> GetRequests();
    void putAnswers(std::vector<std::vector<RelativeIndex>>answers);
};



#endif //CONVERTERJSON_H
