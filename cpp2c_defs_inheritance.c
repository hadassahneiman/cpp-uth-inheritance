/*
 * Created by hn on 6/16/20.
 */

#include <stdio.h>
#include "cpp2c_defs_inheritance.h"

/* definitions of class PhysicalBox */

void ZN11PhysicalBoxC1Eddd(PhysicalBox* const this, double l, double w, double h)
{
    ZN3BoxC1Eddd((Box*)(this), l, w, h);
    this -> material.material = OTHER;
    printf("Material created, set to %s\n", "Other");
    ZNK11PhysicalBox6printpEv(this);
}

void ZN11PhysicalBoxC1EdddN9Materials5TypesE(PhysicalBox* const this, double l, double w, double h, Types t)
{
    const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
    ZN3BoxC1Eddd((Box*)(this), l, w, h);
    this -> material.material = t;
    printf("Material created, set to %s\n", names[this -> material.material]);
    ZNK11PhysicalBox6printpEv(this);
}

void ZN11PhysicalBoxC1EN9Materials5TypesE(PhysicalBox* const this, Types t)
{
    const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
    ZN3BoxC1Ed((Box*)(this), 1);
    this -> material.material = t;
    printf("Material created, set to %s\n", names[this -> material.material]);
    ZNK11PhysicalBox6printpEv(this);
}
void ZN11PhysicalBoxD1Ev(PhysicalBox* const this)
{
    const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
    printf("PhysicalBox dtor, %f x %f x %f, %s; ", this -> box.length, this -> box.width, this -> box.height,
           names[this -> material.material]);
    ZN3BoxD1Ev((Box*)this);
}

void ZNK11PhysicalBox6printpEv(const PhysicalBox* const this)
{
    const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
    printf("PhysicalBox, made of %s; ", names[this -> material.material]);
    ZNK3Box5printEv((Box*)this);
}

/* definitions of class WeightBox */

void ZN9WeightBoxC1Edddd(WeightBox* const this, double l, double w, double h, double wgt)
{
    ZN3BoxC1Eddd((Box*)this, l, w, h);
    this -> weight = wgt;
    ZNK9WeightBox6printwEv(this);
}

void ZN9WeightBoxC1ERKS(WeightBox* const this, const WeightBox* other)
{
    ZN3BoxC1Ed((Box*)this, 1);
    this -> weight = other -> weight;
    ZNK9WeightBox6printwEv(this);
}

void ZN9WeightBoxD1Ev(WeightBox* const this)
{
    printf("Destructing WeightBox; ");
    ZNK9WeightBox6printwEv(this);
    ZN3BoxD1Ev((Box*)this);
}

WeightBox ZN9WeightBoxaSERKS(WeightBox* const this, const WeightBox* other)
{
    this -> weight = other -> weight;
    return *this;
}

void ZNK9WeightBox6printwEv(const WeightBox* const this)
{
    printf("WeightBox, weight: %f; ", this -> weight);
    ZNK3Box5printEv((Box*)this);
}