#include "../include/Wudimei/DS/WMath.h"

namespace Wudimei{
    namespace DS{

        WMath::WMath()
        {
            //ctor
        }

        WMath::~WMath()
        {
            //dtor
        }

        int WMath::ceil(double x){
            if( x>(int)x){
                return (int)x+1;
            }
            else{
                return (int)x;
            }
        }
    }
}
