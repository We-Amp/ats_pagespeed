#ifndef ATS_USER_FILTER_FACTORY_H
#define ATS_USER_FILTER_FACTORY_H

#include <ts/ts.h>

namespace net_instaweb {
  class CommonFilter;
  class RewriteDriver;

  class UserFilterFactory {
  public:
    virtual CommonFilter *createUserFilter(RewriteDriver *driver, TSHttpTxn) = 0;
  };
}
#endif
