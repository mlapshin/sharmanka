#include "shr/Prerequisites.hpp"
#include "shr/StringUtil.hpp"

//! Convert an int to hex value.  For urlencoding namesa and values.
int shr::IntFromHex(const wxString &chars)
{
  int nHi;        // holds high byte
  int nLo;        // holds low byte

  // Get the value of the first byte to Hi
  nHi = chars.GetChar(0);
  if (wxT('0') <= nHi && nHi <= wxT('9'))
    nHi -= wxT('0');
  else if (wxT('a') <= nHi && nHi <= wxT('f'))
    nHi -= (wxT('a')-10);
  else if (wxT('A') <= nHi && nHi <= wxT('F'))
    nHi -= (wxT('A')-10);

  // Get the value of the second byte to Lo
  nLo = chars.GetChar(1);
  if (wxT('0') <= nLo && nLo <= wxT('9'))
    nLo -= wxT('0');
  else if (wxT('a') <= nLo && nLo <= wxT('f'))
    nLo -= (wxT('a')-10);
  else if (wxT('A') <= nLo && nLo <= wxT('F'))
    nLo -= (wxT('A')-10);

  return ( nLo + (16 * nHi) );
}

//! URL Decode a string.
wxString shr::URLDecode(const wxString &value)
{
  wxString szDecoded;
  wxString szEncoded = value;

  unsigned int nEncodedPos = 0;

  // eliminiate + and replace with spaces...
  szEncoded.Replace(wxT("+"), wxT(" "));

  while( nEncodedPos < szEncoded.length() )
  {
    if(szEncoded.GetChar(nEncodedPos)==wxT('%'))
    {
      nEncodedPos++;
      if( isxdigit(szEncoded.GetChar(nEncodedPos)) && isxdigit(szEncoded.GetChar(nEncodedPos+1)) )
      {
        wxString szIntFromHex;
        szIntFromHex.Append( szEncoded.GetChar(nEncodedPos) );
        szIntFromHex.Append( szEncoded.GetChar(nEncodedPos+1) );
        szDecoded.Append( (wxChar) IntFromHex(szIntFromHex) );
        nEncodedPos += 2;
      }
    }
    else
    {
      szDecoded.Append(  szEncoded.GetChar(nEncodedPos++) );
    }
  }

  return szDecoded; // return std::string
}

//! URL encode a string.
wxString shr::URLEncode(const wxString &value)
{
  wxString szToReturn = wxT("");
  unsigned int nPos = 0;

  while( value.length() > nPos )
  {
    wxChar cChar = value.GetChar(nPos);

    if( ( isalpha( cChar )) || ( isdigit( cChar )) || (cChar == wxT('-')) || (cChar == wxT('@')) || (cChar == wxT('*')) || (cChar == wxT('_')) )
    {
      szToReturn.Append( cChar );
    }
    else
    {
      switch( cChar )
      {
        case wxT(' '):  szToReturn.Append(wxT('+')); break;
        case wxT('\n'): szToReturn.Append(wxT("%0D%0A")); break;
        default:
        {
          szToReturn.Append(wxT("%"));
          szToReturn += HexFromInt( cChar );
        }
      }
    }
    nPos++;
  }
  return szToReturn;
}

//! Convert HEX value to an int.  For URL Decoding.
wxString shr::HexFromInt(const int &value)
{
  wxString szHexHolder;

  if( value < 16)
    szHexHolder.Printf(wxT("0%x"), value );
  else
    szHexHolder.Printf(wxT("%x"), value );

  return szHexHolder.MakeUpper();
}
