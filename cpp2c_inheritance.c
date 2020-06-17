/*
 * Created by hn on 6/16/20.
 */

#include <stdio.h>
#include "cpp2c_defs_inheritance.h"

void Z11doMaterialsv()
{
    Materials mat;
    typedef struct MatTest { Materials mat; Material_t mat_t; }MatTest;
    Material_t mat1;
    Material_t mat2;
    const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };

    printf("\n--- Start doMaterials() ---\n\n");

    printf("Size of Materials: %lu\n", sizeof(Materials));
    printf("Size of mat: %lu\n", sizeof(mat));
    printf("Size of Materials::Types: %lu\n", sizeof(Types));
    printf("Size of Material_t: %lu\n", sizeof(Material_t));

    printf("Size of Materials + Material_t: %lu\n", sizeof(MatTest));

    mat1.material = OTHER;
    printf("Material created, set to %s\n", names[mat1.material]);
    mat2.material = METAL;
    printf("Material created, set to %s\n", names[mat2.material]);

    printf("\n--- End doMaterials() ---\n\n");
}

void Z13doPhysicalBoxv()
{
    PhysicalBox pb1, pb2, pb3, pb4;

    printf("\n--- Start doPhysicalBox() ---\n\n");

    ZN11PhysicalBoxC1EdddN9Materials5TypesE(&pb1, 8, 6, 4, PLASTIC);
    ZN11PhysicalBoxC1EN9Materials5TypesE(&pb2, WOOD);
    ZN11PhysicalBoxC1Eddd(&pb3, 7, 7, 7);

    printf("\npb4 is copy-constructed from pb1\n");
    pb4 = pb1;
    ZNK11PhysicalBox6printpEv(&pb4);
    ZNK11PhysicalBox6printpEv(&pb1);
    printf("pb4 %s pb1\n", pb4.box.height == pb1.box.height && pb4.box.width == pb1.box.width &&
            pb4.box.length == pb1.box.length && pb4.material.material == pb1.material.material ? "equals" : "does not equal");

    printf("\npb4 is copy-assigned from pb3\n");
    pb4 = pb3;
    ZNK11PhysicalBox6printpEv(&pb4);
    ZNK11PhysicalBox6printpEv(&pb3);
    printf("pb4 %s pb3\n", pb4.box.height == pb3.box.height && pb4.box.width == pb3.box.width &&
            pb4.box.length == pb3.box.length && pb4.material.material == pb3.material.material ? "equals" : "does not equal");

    printf("\n--- End doPhysicalBox() ---\n\n");

    ZN11PhysicalBoxD1Ev(&pb4);
    ZN11PhysicalBoxD1Ev(&pb3);
    ZN11PhysicalBoxD1Ev(&pb2);
    ZN11PhysicalBoxD1Ev(&pb1);
}

void Z11doWeightBoxv()
{
    WeightBox pw1, pw2, pw3, pw4;
    printf("\n--- Start doWeightBox() ---\n\n");

    ZN9WeightBoxC1Edddd(&pw1, 8, 6, 4, 25);
    ZN9WeightBoxC1Edddd(&pw2, 1, 2, 3, 0.0);
    ZN9WeightBoxC1Edddd(&pw3,10, 20, 30, 15);

    printf("\npw4 is copy-constructed from pw1\n");
    ZN9WeightBoxC1ERKS(&pw4, &pw1);
    ZNK9WeightBox6printwEv(&pw4);
    ZNK9WeightBox6printwEv(&pw1);
    printf("pw4 %s pw1\n", pw4.box.height == pw1.box.height && pw4.box.width == pw1.box.width &&
            pw4.box.length == pw1.box.length && pw4.weight == pw1.weight ? "equals" : "does not equal");

    printf("\npw4 is copy-assigned from pw3\n");
    ZN9WeightBoxaSERKS(&pw4, &pw3);
    ZNK9WeightBox6printwEv(&pw4);
    ZNK9WeightBox6printwEv(&pw3);
    printf("pw4 %s pw3\n", pw4.box.height == pw1.box.height && pw4.box.width == pw1.box.width &&
            pw4.box.length == pw1.box.length && pw4.weight == pw1.weight ? "equals" : "does not equal");

    printf("\n--- End doWeightBox() ---\n\n");

    ZN9WeightBoxD1Ev(&pw4);
    ZN9WeightBoxD1Ev(&pw3);
    ZN9WeightBoxD1Ev(&pw2);
    ZN9WeightBoxD1Ev(&pw1);
}

int main()
{
    printf("\n--- Start main() ---\n\n");

    Z11doMaterialsv();

    Z13doPhysicalBoxv();

    Z11doWeightBoxv();

    printf("\n--- End main() ---\n\n");

    return 1;
}