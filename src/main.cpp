// the kng command line interface
#include <cxxopts.hpp>
#include "common.h"

int main(int argc, char** argv) {

    cxxopts::Options options("kng cli", "The kng cli");

    options.add_options()
        ("c,compile", "Compile to target", cxxopts::value<bool>()->default_value("false"))
        ("t,target", "Compilation target (clr, x86, x64, llvm)", cxxopts::value<std::string>())
        ("d,debug", "Enable debugging", cxxopts::value<bool>()->default_value("false"))
        ("h,help", "Print usage")
        ;

    auto result = options.parse(argc, argv);

    if (result.count("help")){
        std::cout << options.help() << std::endl;
        exit(0);
    }
    bool debug = result["debug"].as<bool>();
    if (debug)
        log("kng compiler debug enabled!");

    if(result.count("compile")){
        if (result.count("target")) {
            // allow the user to specify a target
            auto target = result["target"].as<std::string>();
            log("compiling to {}", target);
        }
        else {
            // default target is kng clr
            log("compiling to kng clr");
        }
    } else {
        // compile and run on the kng vm
        log("running");
    }


    return 0;
}