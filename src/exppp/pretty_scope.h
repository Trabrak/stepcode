#ifndef PRETTY_SCOPE_H
#define PRETTY_SCOPE_H

#include <express/linklist.h>
#include <express/scope.h>

#include "pp.h"

void SCOPEadd_inorder(Linked_List list, Scope s);
void SCOPEalgs_out(Scope s, size_t level);
void SCOPEconsts_out(Scope s, size_t level);
void SCOPEentities_out(Scope s, size_t level);
void SCOPEfuncs_out(Scope s, size_t level);
void SCOPElocals_out(Scope s, size_t level);
void SCOPEprocs_out(Scope s, size_t level);
void SCOPErules_out(Scope s, size_t level);
void SCOPEtypes_out(Scope s, size_t level);


#endif /* PRETTY_SCOPE_H */
