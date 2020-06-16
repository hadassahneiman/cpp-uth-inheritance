/*
 * Created by hn on 6/16/20.
 */

#ifndef CPP_UTH_INHERITANCE_HADASSAHNEIMAN_CPP2C_DEFS_H
#define CPP_UTH_INHERITANCE_HADASSAHNEIMAN_CPP2C_DEFS_H

#include <stdio.h>
#include "cpp2c_defs.h"

/** class Materials **/

typedef struct Materials
{
    char padding;
}Materials;

typedef enum Types
{
    PLASTIC,
    METAL,
    WOOD,
    PAPER,
    OTHER
}Types;

const char* ZN9Materials7getNameENS_5TypesE(Types type);


/** class Material_t **/

typedef struct Material_t
{
    Types material;
}Material_t;


/** class PhysicalBox **/

typedef struct PhysicalBox
{
    double length;
    double width;
    double height;
    Material_t material;
}PhysicalBox;

void ZN11PhysicalBoxC1Eddd(PhysicalBox* const this, double l, double w, double h);

void ZN11PhysicalBoxC1EdddN9Materials5TypesE(PhysicalBox* const this, double l, double w, double h, Types t);

void ZN11PhysicalBoxC1EN9Materials5TypesE(PhysicalBox* const this, Types t);

void ZN11PhysicalBoxD1Ev(PhysicalBox* const this);

void ZNK11PhysicalBox6printpEv(const PhysicalBox* const this);


/** class WeightBox **/

typedef struct WeightBox
{
    double length;
    double width;
    double height;
    double weight;
}WeightBox;

void ZN9WeightBoxC1Edddd(WeightBox* const this, double l, double w, double h, double wgt);

void ZN9WeightBoxC1ERKS(WeightBox* const this, const WeightBox* other);

void ZN9WeightBoxD1Ev(WeightBox* const this);

WeightBox ZN9WeightBoxaSERKS(WeightBox* const this, const WeightBox* other);

void ZNK9WeightBox6printwEv(const WeightBox* const this);


#endif /*CPP_UTH_INHERITANCE_HADASSAHNEIMAN_CPP2C_DEFS_H */
