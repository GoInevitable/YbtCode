/** 
 * @file    bc.cpp
 * @author  Jane Smith
 * @date    2024-11-21
 * @version 1.0
 * @license MIT
 * USE AI
 */
#include <iostream>
#include <filesystem>
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>

namespace fs = std::filesystem;

class CppCompiler {
private:
    std::vector<std::string> cppFiles;
    std::string compilerFlags;

public:
    CppCompiler(const std::string& flags = "-std=c++17 -O2 -Wall") : compilerFlags(flags) {}

    // Find all .cpp files in current directory
    bool findCppFiles() {
        cppFiles.clear();
        
        try {
            for (const auto& entry : fs::directory_iterator(".")) {
                if (entry.is_regular_file()) {
                    std::string filename = entry.path().filename().string();
                    if (filename.length() > 4 && 
                        filename.substr(filename.length() - 4) == ".cpp") {
                        cppFiles.push_back(filename);
                    }
                }
            }
            
            // Sort files by name
            std::sort(cppFiles.begin(), cppFiles.end());
            
            return !cppFiles.empty();
        }
        catch (const fs::filesystem_error& ex) {
            std::cerr << "Filesystem error: " << ex.what() << std::endl;
            return false;
        }
    }

    // Compile a single .cpp file
    bool compileFile(const std::string& filename) {
        // Get filename without extension
        std::string baseName = filename.substr(0, filename.length() - 4);
        std::string exeName = baseName + ".exe";
        
        // Build compilation command
        std::string command = "g++ " + compilerFlags + " -o \"" + exeName + "\" \"" + filename + "\"";
        
        std::cout << "Compiling: " << filename << " -> " << exeName << std::endl;
        std::cout << "Command: " << command << std::endl;
        
        // Execute compilation command
        int result = std::system(command.c_str());
        
        if (result == 0) {
            std::cout << "✓ Success: " << exeName << std::endl;
            return true;
        } else {
            std::cerr << "✗ Failed: " << filename << " (Error code: " << result << ")" << std::endl;
            return false;
        }
    }

    // Compile all found .cpp files
    void compileAll() {
        if (!findCppFiles()) {
            std::cout << "No .cpp files found!" << std::endl;
            return;
        }
        
        std::cout << "Found " << cppFiles.size() << " .cpp files:" << std::endl;
        for (const auto& file : cppFiles) {
            std::cout << "  - " << file << std::endl;
        }
        std::cout << std::endl;
        
        int successCount = 0;
        int totalCount = cppFiles.size();
        
        for (const auto& file : cppFiles) {
            std::cout << "========================================" << std::endl;
            if (compileFile(file)) {
                successCount++;
            }
            std::cout << std::endl;
        }
        
        std::cout << "Compilation completed! Success: " << successCount << "/" << totalCount << std::endl;
    }

    // Set compiler flags
    void setCompilerFlags(const std::string& flags) {
        compilerFlags = flags;
    }

    // Show current compiler flags
    void showCompilerFlags() {
        std::cout << "Current compiler flags: " << compilerFlags << std::endl;
    }
};

// Display help information
void showHelp() {
    std::cout << "C++ Batch Compiler" << std::endl;
    std::cout << "Function: Compile all .cpp files in current directory to separate .exe files" << std::endl;
    std::cout << "Default compiler flags: -std=c++17 -O2 -Wall" << std::endl;
    std::cout << std::endl;
    std::cout << "Usage:" << std::endl;
    std::cout << "  Run without arguments: Compile all files with default flags" << std::endl;
    std::cout << "  Arguments:" << std::endl;
    std::cout << "    -h, --help     Show this help message" << std::endl;
    std::cout << "    -d, --debug    Compile in debug mode (-g flag)" << std::endl;
    std::cout << "    -f FLAGS       Custom compiler flags" << std::endl;
    std::cout << "    -l, --list     List files only, do not compile" << std::endl;
}

int main(int argc, char* argv[]) {
    CppCompiler compiler;
    
    // Process command line arguments
    bool justList = false;
    
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        
        if (arg == "-h" || arg == "--help") {
            showHelp();
            return 0;
        }
        else if (arg == "-d" || arg == "--debug") {
            compiler.setCompilerFlags("-std=c++17 -g -Wall");
        }
        else if (arg == "-f" && i + 1 < argc) {
            compiler.setCompilerFlags(argv[++i]);
        }
        else if (arg == "-l" || arg == "--list") {
            justList = true;
        }
        else {
            std::cerr << "Unknown argument: " << arg << std::endl;
            std::cerr << "Use -h for help" << std::endl;
            return 1;
        }
    }
    
    std::cout << "C++ Batch Compiler starting..." << std::endl;
    compiler.showCompilerFlags();
    std::cout << std::endl;
    
    if (justList) {
        if (compiler.findCppFiles()) {
            return 0;
        } else {
            std::cout << "No .cpp files found." << std::endl;
            return 1;
        }
    }
    
    compiler.compileAll();
    
    std::cout << std::endl << "Press Enter to exit...";
    std::cin.get();
    
    return 0;
}