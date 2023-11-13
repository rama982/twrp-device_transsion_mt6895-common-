#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <android-base/properties.h>

#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>

using android::base::GetProperty;
using std::string;

void property_override(string prop, string value)
{
    auto pi = (prop_info *)__system_property_find(prop.c_str());

    if (pi != nullptr)
        __system_property_update(pi, value.c_str(), value.size());
    else
        __system_property_add(prop.c_str(), prop.size(), value.c_str(), value.size());
}

void vendor_load_properties()
{
    string prop_partitions[] = {"", "vendor.", "odm."};
    for (const string &prop : prop_partitions)
    {
        property_override(string("ro.product.") + prop + string("brand"), "infinix");
        property_override(string("ro.product.") + prop + string("name"), "Infinix-X678B");
        property_override(string("ro.product.") + prop + string("device"), "Infinix-X678B");
        property_override(string("ro.product.") + prop + string("model"), "Infinix-X678B");
        property_override(string("ro.product.") + prop + string("marketname"), "Infinix Note 30 Pro");
    }
    property_override("ro.bootimage.build.date.utc", "1609430400");
    property_override("ro.build.date.utc", "1609430400");
}