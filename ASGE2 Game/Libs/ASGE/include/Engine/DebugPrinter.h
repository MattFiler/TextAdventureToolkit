/** 
 * @file
 * @brief Class @ref ASGE::DebugPrinter
 */

#ifndef ASGE_DEBUGPRINTER_H
#define ASGE_DEBUGPRINTER_H

#include <mutex>
#include <sstream>

/* https://stackoverflow.com/questions/18277304/using-stdcout-in-multiple-threadsThread */

namespace ASGE {
    /**
    *  \brief a thread safe version of cout
    *  
    *  Used to render text to the console. Ensures that only one instance
    *  of cout is accessed throughout all threads.
    *  
    *  Usage: PrintThread{} << "Hello World!" << std::endl;
    */
    class DebugPrinter :
            public std::ostringstream
    {
    public:
        DebugPrinter() = default;
        ~DebugPrinter() final;

    private:
        static std::mutex cout_mtx;
    };
}
#endif //ASGE_DEBUGPRINTER_H
