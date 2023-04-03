#include "element.h"

void Apple::accept(Visitor* visitptr){
    visitptr->visit(this);
}

void Badge::accept(Visitor* visitptr){
    visitptr->visit(this);
}