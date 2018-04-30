#ifndef OPT_H
#define OPT_H

namespace opt {

    class Logger;

    enum ReturnCode {
        NO_ERRORS,
        DIFFERENT_DIMENSIONS,
        MEMORY_ALLOCATION,
        OUT_OF_RANGE
    };

    enum TypeNorm {
        NORM1,
        NORM2
    };

    enum opt::Type{
            COMPACT,
            VECTOR,
            FAKE_TYPE
    };
}

#endif // OPT_H
