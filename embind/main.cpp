#include <emscripten/bind.h>
using namespace emscripten;

// BRepBuilderAPI
#include "BRepBuilderAPI_BndBoxTreeSelector.hxx"
#include "BRepBuilderAPI_CellFilter.hxx"
#include "BRepBuilderAPI_Collect.hxx"
#include "BRepBuilderAPI_Collect.hxx"
#include "BRepBuilderAPI_Command.hxx"
#include "BRepBuilderAPI_Command.hxx"
#include "BRepBuilderAPI_Copy.hxx"
#include "BRepBuilderAPI_Copy.hxx"
#include "BRepBuilderAPI.hxx"
#include "BRepBuilderAPI_EdgeError.hxx"
#include "BRepBuilderAPI_FaceError.hxx"
#include "BRepBuilderAPI_FastSewing.hxx"
#include "BRepBuilderAPI_FastSewing.hxx"
#include "BRepBuilderAPI_FindPlane.hxx"
#include "BRepBuilderAPI_FindPlane.hxx"
#include "BRepBuilderAPI_GTransform.hxx"
#include "BRepBuilderAPI_GTransform.hxx"
#include "BRepBuilderAPI.hxx"
#include "BRepBuilderAPI_MakeEdge2d.hxx"
#include "BRepBuilderAPI_MakeEdge2d.hxx"
#include "BRepBuilderAPI_MakeEdge.hxx"
#include "BRepBuilderAPI_MakeEdge.hxx"
#include "BRepBuilderAPI_MakeFace.hxx"
#include "BRepBuilderAPI_MakeFace.hxx"
#include "BRepBuilderAPI_MakePolygon.hxx"
#include "BRepBuilderAPI_MakePolygon.hxx"
#include "BRepBuilderAPI_MakeShape.hxx"
#include "BRepBuilderAPI_MakeShape.hxx"
#include "BRepBuilderAPI_MakeShell.hxx"
#include "BRepBuilderAPI_MakeShell.hxx"
#include "BRepBuilderAPI_MakeSolid.hxx"
#include "BRepBuilderAPI_MakeSolid.hxx"
#include "BRepBuilderAPI_MakeVertex.hxx"
#include "BRepBuilderAPI_MakeVertex.hxx"
#include "BRepBuilderAPI_MakeWire.hxx"
#include "BRepBuilderAPI_MakeWire.hxx"
#include "BRepBuilderAPI_ModifyShape.hxx"
#include "BRepBuilderAPI_ModifyShape.hxx"
#include "BRepBuilderAPI_NurbsConvert.hxx"
#include "BRepBuilderAPI_NurbsConvert.hxx"
#include "BRepBuilderAPI_PipeError.hxx"
#include "BRepBuilderAPI_Sewing.hxx"
#include "BRepBuilderAPI_Sewing.hxx"
#include "BRepBuilderAPI_Sewing.hxx"
#include "BRepBuilderAPI_ShapeModification.hxx"
#include "BRepBuilderAPI_ShellError.hxx"
#include "BRepBuilderAPI_Transform.hxx"
#include "BRepBuilderAPI_Transform.hxx"
#include "BRepBuilderAPI_TransitionMode.hxx"
#include "BRepBuilderAPI_VertexInspector.hxx"
#include "BRepBuilderAPI_WireError.hxx"

// BRepFilletAPI
#include "BRepFilletAPI_LocalOperation.hxx"
#include "BRepFilletAPI_MakeChamfer.hxx"
#include "BRepFilletAPI_MakeFillet2d.hxx"
#include "BRepFilletAPI_MakeFillet.hxx"

// BRepPrimAPI
#include "BRepPrimAPI_MakeBox.hxx"
#include "BRepPrimAPI_MakeCone.hxx"
#include "BRepPrimAPI_MakeCylinder.hxx"
#include "BRepPrimAPI_MakeHalfSpace.hxx"
#include "BRepPrimAPI_MakeOneAxis.hxx"
#include "BRepPrimAPI_MakePrism.hxx"
#include "BRepPrimAPI_MakeRevol.hxx"
#include "BRepPrimAPI_MakeRevolution.hxx"
#include "BRepPrimAPI_MakeSphere.hxx"
#include "BRepPrimAPI_MakeSweep.hxx"
#include "BRepPrimAPI_MakeTorus.hxx"
#include "BRepPrimAPI_MakeWedge.hxx"

// GC
#include "GC_MakeArcOfCircle.hxx"
#include "GC_MakeArcOfEllipse.hxx"
#include "GC_MakeArcOfHyperbola.hxx"
#include "GC_MakeArcOfParabola.hxx"
#include "GC_MakeCircle.hxx"
#include "GC_MakeConicalSurface.hxx"
#include "GC_MakeCylindricalSurface.hxx"
#include "GC_MakeEllipse.hxx"
#include "GC_MakeHyperbola.hxx"
#include "GC_MakeLine.hxx"
#include "GC_MakeMirror.hxx"
#include "GC_MakePlane.hxx"
#include "GC_MakeRotation.hxx"
#include "GC_MakeScale.hxx"
#include "GC_MakeSegment.hxx"
#include "GC_MakeTranslation.hxx"
#include "GC_MakeTrimmedCone.hxx"
#include "GC_MakeTrimmedCylinder.hxx"
#include "GC_Root.hxx"

// gp
#include "gp_Ax1.hxx"
#include "gp_Ax22d.hxx"
#include "gp_Ax2d.hxx"
#include "gp_Ax2.hxx"
#include "gp_Ax3.hxx"
#include "gp_Circ2d.hxx"
#include "gp_Circ.hxx"
#include "gp_Cone.hxx"
#include "gp_Cylinder.hxx"
#include "gp_Dir2d.hxx"
#include "gp_Dir.hxx"
#include "gp_Elips2d.hxx"
#include "gp_Elips.hxx"
#include "gp_EulerSequence.hxx"
#include "gp_GTrsf2d.hxx"
#include "gp_GTrsf.hxx"
#include "gp.hxx"
#include "gp_Hypr2d.hxx"
#include "gp_Hypr.hxx"
#include "gp_Lin2d.hxx"
#include "gp_Lin.hxx"
#include "gp_Mat2d.hxx"
#include "gp_Mat.hxx"
#include "gp_Parab2d.hxx"
#include "gp_Parab.hxx"
#include "gp_Pln.hxx"
#include "gp_Pnt2d.hxx"
#include "gp_Pnt.hxx"
#include "gp_Quaternion.hxx"
#include "gp_QuaternionNLerp.hxx"
#include "gp_QuaternionSLerp.hxx"
#include "gp_Sphere.hxx"
#include "gp_Torus.hxx"
#include "gp_Trsf2d.hxx"
#include "gp_TrsfForm.hxx"
#include "gp_Trsf.hxx"
#include "gp_TrsfNLerp.hxx"
#include "gp_Vec2d.hxx"
#include "gp_Vec.hxx"
#include "gp_VectorWithNullMagnitude.hxx"
#include "gp_XY.hxx"
#include "gp_XYZ.hxx"

// TopExp
#include "TopExp_Explorer.hxx"
#include "TopExp.hxx"
#include "TopExp_Stack.hxx"

// TopoDS
#include "TopoDS_AlertWithShape.hxx"
#include "TopoDS_Builder.hxx"
#include "TopoDS_Compound.hxx"
#include "TopoDS_CompSolid.hxx"
#include "TopoDS_Edge.hxx"
#include "TopoDS_Face.hxx"
#include "TopoDS_FrozenShape.hxx"
#include "TopoDS_HShape.hxx"
#include "TopoDS.hxx"
#include "TopoDS_Iterator.hxx"
#include "TopoDS_ListIteratorOfListOfShape.hxx"
#include "TopoDS_ListOfShape.hxx"
#include "TopoDS_LockedShape.hxx"
#include "TopoDS_Shape.hxx"
#include "TopoDS_Shell.hxx"
#include "TopoDS_Solid.hxx"
#include "TopoDS_TCompound.hxx"
#include "TopoDS_TCompSolid.hxx"
#include "TopoDS_TEdge.hxx"
#include "TopoDS_TFace.hxx"
#include "TopoDS_TShape.hxx"
#include "TopoDS_TShell.hxx"
#include "TopoDS_TSolid.hxx"
#include "TopoDS_TVertex.hxx"
#include "TopoDS_TWire.hxx"
#include "TopoDS_UnCompatibleShapes.hxx"
#include "TopoDS_Vertex.hxx"
#include "TopoDS_Wire.hxx"

#include "BRepBuilderAPI/BRepBuilderAPI_MakeEdge.hxx"
#include "BRepPrimAPI/BRepPrimAPI_MakeTorus.hxx"
#include "GC/GC_MakeArcOfCircle.hxx"
#include "GC/GC_MakeSegment.hxx"

#define Standard_EXPORT
#define Standard_NODISCARD
#define DEFINE_STANDARD_ALLOC

#define really_unparen(...) __VA_ARGS__
#define invoke(expr) expr
#define unparen(args) invoke(really_unparen args)

#define overloadedConstructor(baseClass, overloadedClass, parameterFull, parameterNames, parameterTypes) \
  struct overloadedClass : public baseClass { \
    overloadedClass(unparen(parameterFull)) : baseClass(unparen(parameterNames)) {} \
  }; \
  class_<overloadedClass, base<baseClass>>(#overloadedClass) \
    .constructor<unparen(parameterTypes)>();

EMSCRIPTEN_BINDINGS(opencascadejs) {
  #include "./BRepBuilderAPI.h"
  #include "./GC.h"
  #include "./gp.h"
  #include "./TopoDS.h"
}
