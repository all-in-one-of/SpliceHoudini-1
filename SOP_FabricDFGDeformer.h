
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
    static int bindPointPositionsCallback(void* data, int index, float time, const PRM_Template* tplate);
    static OP_TemplatePair* buildTemplatePair(OP_TemplatePair* prevstuff);

protected:
    SOP_FabricDFGDeformer(OP_Network* net, const char* name, OP_Operator* op);
    virtual ~SOP_FabricDFGDeformer();
    virtual OP_ERROR cookMySop(OP_Context& context);

private:
    void addExternalArrayGraphPointPositions();
    void setExternalArrayPoint(OP_Context& context, const char* name);
    void setPointPositions(OP_Context& context);

    std::vector<UT_Vector3F> m_array;
};

class OP_FabricDFGDeformer : public OP_Operator
{
public:
    OP_FabricDFGDeformer()
        : OP_Operator("fabricDFGDeformer",                         // Internal name
                      "Fabric Deformer",                           // UI name
                      SOP_FabricDFGDeformer::myConstructor,        // How to build the SOP
                      SOP_FabricDFGDeformer::buildTemplatePair(0), // My parameters
                      1,                                           // Min # of node inputs
                      1)                                           // Max # of node inputs
    {
    }
};

} // End namespace OpenSpliceHoudini
#endif // __SOP_FABRICSDFGDEFORMER_H__
