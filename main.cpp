#include "XmlConfigParser.h"
#include "../sources/XmlInterpreter.cpp"

#include <iostream>
#include <map>
#include <iomanip>
#include <tuple>

int main()
{
    XmlConfigParser configParser;
    std::map<std::string, std::string> config;

    try
    {
        config = configParser.ParseConfig("/home/operator/config-files/config-xmls/config2.xml");
    } catch (const std::exception& e)
    {
        std::cerr << "Error parsing config: " << e.what() << "\n";
        return 1;
    }

    if (config.size() == 0)
    {
        std::cerr << "No configuration values found. Check your XML file." << "\n";
        return 1;
    }

    //Peek the XML file's structure in order to use interpret method
    for (const auto& pair : config)
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << "\n";

    // Create an instance of the XmlInterpreter
    XmlInterpreter interpreter(config);

    // Use the interpret method to retrieve values
    double range = interpreter.interpret<double>("alfa.range");
    int temperature = interpreter.interpret<int>("beta.temperature");
    std::string status = interpreter.interpret<std::string>("gama.status");
    std::vector<std::string> friends = interpreter.interpret<std::vector<std::string>>("delta.friends");
    std::vector<std::string> enemies = interpreter.interpret<std::vector<std::string>>("epsilon.enemies");
    std::vector<int> nodes = interpreter.interpret<std::vector<int>>("digama.nodes");
    std::tuple<int, float, double> tuple = interpreter.interpret<std::tuple<int, float, double>>("zeta.tuple");
    std::pair<double, std::string> pair = interpreter.interpret<std::pair<double, std::string>>("heta.pair");
    std::vector<std::tuple<int, float>> vecOfTuples = interpreter.interpret<std::vector<std::tuple<int, float>>>("eta.vecOfTup");
    std::vector<std::pair<int, float>> vecOfPairs = interpreter.interpret<std::vector<std::pair<int, float>>>("teta.vecOfPair");
    std::vector<std::vector<int>> vecOfVecs = interpreter.interpret<std::vector<std::vector<int>>>("yota.vecOfVec");
    //std::vector<std::vector<std::vector<float>>> vecOfVecOfVecs = interpreter.interpret<std::vector<std::vector<std::vector<float>>>>("kapa.vecOfVecOfVec");
    //std::vector<std::vector<std::vector<std::vector<std::string>>>> vecOfVecOfVecOfVecs = interpreter.interpret<std::vector<std::vector<std::vector<std::vector<std::string>>>>>("lamda.vecOfVecOfVecOfVec");

    // Print the retrieved values
    std::cout << "Range: " << range << "\n";

    std::cout << "Temperature: " << temperature << "\n";

    std::cout << "Status: " << status << "\n";

    std::cout << "Friends: ";
    for (const auto& friendName : friends) {
        std::cout << friendName << " ";
    }
    std::cout << "\n";

    std::cout << "Enemies: ";
    for (const auto& enemyName : enemies) {
        std::cout << enemyName << " ";
    }
    std::cout << "\n";

    std::cout << "Nodes: ";
    for(const auto& node : nodes)
        std::cout << node << " ";
    std::cout << "\n";

    std::cout << "Tuple: ("
              << std::get<0>(tuple) << ", "
              << std::get<1>(tuple) << ", "
              << std::get<2>(tuple) << ")"
              << "\n";

    std::cout << "Pair: ("
              << pair.first << ", "
              << pair.second << ")"
              << "\n";

    std::cout << "Vector of Tuples:" << "\n";
    for (const auto& t : vecOfTuples) {
        std::cout << "(" << std::get<0>(t) << ", " << std::get<1>(t) << ") ";
    }
    std::cout << "\n";

    std::cout << "Vector of Pairs:" << "\n";
    for (const auto& p : vecOfPairs) {
        std::cout << "(" << p.first << ", " << p.second << ") ";
    }
    std::cout << "\n";

    std::cout << "Vector of Vectors:" << "\n";
    for (const auto& vec : vecOfVecs) {
        for (int val : vec) {
            std::cout << val << " ";
        }
        std::cout << "| ";  // Separator for inner vectors
    }
    std::cout << "\n";

//    std::cout << "Vector of vector of vectors:" << "\n";
//    for (const auto& vecOfVec : vecOfVecOfVecs) {
//        for (const auto& vec : vecOfVec) {
//            for (float value : vec) {
//                std::cout << value << " ";
//            }
//            std::cout << "| ";  // Separator for inner vectors
//        }
//        std::cout << "/ " << "\n";  // Separator for inner vectors
//    }
//    std::cout << "\n";

//    std::cout << "Vector of vector of vector of vectors:" << "\n";
//    for (const auto& vecOfVecOfVecs : vecOfVecOfVecOfVecs) {
//        for (const auto& vecOfVecs : vecOfVecOfVecs) {
//            for (const auto& vec : vecOfVecs) {
//                for (const auto& value : vec) {
//                    std::cout << value << " ";
//                }
//                std::cout << "| ";  // Separator for inner vectors
//            }
//            std::cout << "|| \n";  // Separator for inner vectors
//        }
//        std::cout << "/ \n\n";  // Separator for inner vectors
//    }
//    std::cout << "\n";


    return 0;
}
