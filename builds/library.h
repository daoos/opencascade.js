typedef Handle(IMeshTools_Context) Handle_IMeshTools_Context;
typedef Handle(TColgp_HArray1OfPnt) Handle_TColgp_HArray1OfPnt;

class JSTools {
public:
  static std::string ConvertAsciiString(const TCollection_AsciiString& s) {
    return s.ToCString();
  }
  static std::string getExceptionMessage(intptr_t exceptionPtr) {
    return std::string(reinterpret_cast<std::exception *>(exceptionPtr)->what());
  }
};
