
#ifndef __SOP_FABRICSDFGDEFORMER_H__
#define __SOP_FABRICSDFGDEFORMER_H__

#include <SOP/SOP_Node.h>
#include "FabricDFGOP.h"

#include <vector>

namespace OpenSpliceHoudini
{

class SOP_FabricDFGDeformer : public FabricDFGOP<SOP_Node>
{
public:
    static OP_Node* myConstructor(OP_Network*, const char*, OP_Operator*);

protected:
    SOP_FabricDFGDeformer(OP_Network* net, const char* name, OP_Operator* op);
    virtual ~SOP_FabricDFGDeformer();
    virtual OP_ERROR cookMySop(OP_Context& context);

    static void OnUpdateGraphCopyAttributes(OP_Network& node, DFGWrapper::Binding& binding);

private:
    static FabricCore::RTVal ConstructPositionsRTVal(const GU_Detail& gdpRef, SOP_FabricDFGDeformer& sopDeformerNode);
    static FabricCore::RTVal ConstructPolygonMeshRTVal(const GU_Detail& gdpRef, SOP_FabricDFGDeformer& sopDeformerNode);
    void setPointsPositions(OP_Context& context);
};

class OP_FabricDFGDeformer : public OP_Operator
{
public:
    OP_FabricDFGDeformer()
        : OP_Operator("fabricDFGDeformer",                   // Internal name
                      "Fabric Deformer",                     // UI name
                      SOP_FabricDFGDeformer::myConstructor,  // How to build the SOP
                      SOP_FabricDFGDeformer::myTemplateList, // My parameters
                      1,                                     // Min # of node inputs
                      1)                                     // Max # of node inputs
    {
    }
};

} // End namespace OpenSpliceHoudini
#endif // __SOP_FABRICSDFGDEFORMER_H__
