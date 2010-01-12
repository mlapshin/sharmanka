#ifndef _STRINGUTIL_H_
#define _STRINGUTIL_H_

namespace shr
{

int IntFromHex(const wxString &chars);
wxString URLDecode(const wxString &value);
wxString URLEncode(const wxString &value);
wxString HexFromInt(const int &value);


}

#endif /* _STRINGUTIL_H_ */
