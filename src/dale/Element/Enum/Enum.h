#ifndef DALE_ELEMENT_ENUM
#define DALE_ELEMENT_ENUM

#include <string>
#include <map>

#include "../../llvm_Module.h"

#define ENUM_NOTFOUND -2

namespace dale
{
namespace Element
{
/*! Enum

    A class for storing the details of an enumerated type.  Element
    indices begin at zero.
*/
class Enum
{
public:
    /* The enumerated type's integral type. */
    llvm::Type *type;
    /* The index of the last member. */
    int last_index;
    /* A map from member name to index. */
    std::map<std::string, int64_t> *member_to_index;
    /* The once tag of this type. */
    std::string once_tag;
    /* The linkage of this type. */
    int linkage;
    /* Whether the type should be serialised. */
    bool serialise;

    Enum();
    ~Enum();

    /*! Check whether a given member exists.
     *  @param name The name of the potential member.
     */
    bool existsMember(const char *name);
    /*! Add a new member to the enumerated type.
     *  @param name The name of the new member.
     */
    int addMember(const char *name);
    /*! Add a new member to the enumerated type at a specific index.
     *  @param name The name of the new member.
     *  @param index The index of the new member.
     */
    int addMember(const char *name, int64_t index);
    /*! Retrieve the index of the member with the given name.
     *  @param name The name of the member.
     */
    int64_t memberToIndex(const char *name);
};
}
}

#endif
