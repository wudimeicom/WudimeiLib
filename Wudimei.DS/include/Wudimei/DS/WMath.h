#ifndef WMATH_H
#define WMATH_H
#include "./DS.h"

namespace Wudimei{
    namespace DS{

        class DLL_EXPORT WMath
        {
            public:
                WMath();
                virtual ~WMath();

                static int ceil(double x);
            protected:
            private:
        };
    }
}

#endif // WMATH_H
