#ifndef PRETTY_ENTITY_H
#define PRETTY_ENTITY_H

#include "../express/entity.h"
#include "../express/expbasic.h"
#include "../express/express.h"

#include "pp.h"

char *ENTITYto_string(Entity e);
void   ENTITY_out(Entity e, size_t level);
void   ENTITYattrs_out(Linked_List attrs, int derived, size_t level);
void   ENTITYinverse_out(Linked_List attrs, size_t level);
void   ENTITYout(Entity e);
int    ENTITYto_buffer(Entity e, char *buffer, int length);
void   ENTITYunique_out(Linked_List u, size_t level);


#endif /* PRETTY_ENTITY_H */
