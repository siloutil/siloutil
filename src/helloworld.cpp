#include "gettext.h"

#include <silo.h>
#include <boost/python.hpp>

#define _(STRING) gettext(STRING)

char const* ver()
{
   return DBVersion();
}

char const* greet()
{
   return _("Hello");
}


BOOST_PYTHON_MODULE(siloutil)
{
    using namespace boost::python;
    def("greet", greet);
}
