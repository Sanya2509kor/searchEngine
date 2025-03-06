#include "ConverterJSON.h"
#include "InvertedIndex.h"
#include "SearchServer.h"

int main(){
    try
    {
        ConverterJSON converter_json;
        InvertedIndex inverted_index;
        SearchServer search_server(inverted_index, converter_json.GetResponsesLimit());

        std::cout << "To start, type \"start\"" << std::endl;
        std::cout << "If you have changed the json document, type \"update\"" << std::endl;
        std::cout << "To change the number of responses, enter \"responses\"" << std::endl;
        std::cout << "To finish, enter \"exit\"" << std::endl;

        while (true) {
            std::string input;
            std::cin >> input;
            if (input == "start" || input == "update") {
                auto doc = converter_json.GetTextDocuments();
                inverted_index.UpdateDocumentBase(doc);
                auto answers = search_server.search(converter_json.GetRequests());
                converter_json.putAnswers(answers);
                std::cout << "Finished" << std::endl;

            } else if (input == "responses") {
                std::cout << "Enter the number of responses: ";
                std::string count;
                std::cin >> count;
                int count_responses = std::stoi(count);
                search_server.setResponsesLimit(count_responses);

            } else if (input == "exit") {
                std::cout << "Goodbye" << std::endl;
                break;

            } else {
                std::cerr << "Incorrect input!!!" << std::endl;
                std::cerr << "Repeat the input" << std::endl;
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

