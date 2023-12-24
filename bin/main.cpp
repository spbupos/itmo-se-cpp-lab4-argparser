/* #include <functional>
#include <lib/ArgParser.h>

#include <iostream>
#include <numeric>

struct Options {
    bool sum = false;
    bool mult = false;
};

int main(int argc, char** argv) {
    Options opt;
    std::vector<int> values;

    ArgumentParser::ArgParser parser("Program");
    parser.AddIntArgument("N").MultiValue(1).Positional().StoreValues(values);
    parser.AddFlag("sum", "add args").StoreValue(opt.sum);
    parser.AddFlag("mult", "multiply args").StoreValue(opt.mult);
    parser.AddHelp('h', "help", "Program accumulate arguments");

    if(!parser.Parse(argc, argv)) {
        std::cout << "Wrong argument" << std::endl;
        std::cout << parser.HelpDescription() << std::endl;
        return 1;
    }

    if(parser.Help()) {
        std::cout << parser.HelpDescription() << std::endl;
        return 0;
    }

    if(opt.sum) {
        std::cout << "Result: " << std::accumulate(values.begin(), values.end(), 0) << std::endl;
    } else if(opt.mult) {
        std::cout << "Result: " << std::accumulate(values.begin(), values.end(), 1, std::multiplies<int>()) << std::endl;
    } else {
        std::cout << "No one options had chosen" << std::endl;
        std::cout << parser.HelpDescription();
        return 1;
    }

    return 0;

} */

#include <iostream>
#include <lib/ArgParser.h>

int main() {
    ArgumentParser::ArgParser parser("test");

    int alpha, beta;
    std::string gamma, delta;
    bool flag = false;
    parser.AddIntArgument('a', "alpha").StoreValue(alpha);
    parser.AddIntArgument('b', "beta").StoreValue(beta);
    parser.AddStringArgument('g', "gamma").StoreValue(gamma);
    parser.AddStringArgument('d', "delta").StoreValue(delta);
    parser.AddFlag('f', "flag").StoreValue(flag);

    std::vector<std::string> to_parse = {"test", "--alpha=1", "-b", "2", "--gamma=str1", "-d", "str2", "--flag"};
    bool result = parser.Parse(to_parse);
    if (result) {
        std::cout << "alpha: " << alpha << '\n';
        std::cout << "beta: " << beta << '\n';
        std::cout << "gamma: " << gamma << '\n';
        std::cout << "delta: " << delta << '\n';
        std::cout << "flag: " << (flag ? "true" : "false") << '\n';
    }
    else {
        std::cout << "Error" << '\n';
    }
    return 0;
}
