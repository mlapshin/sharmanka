#ifndef _BYTEFLOW_HPP_
#define _BYTEFLOW_HPP_

// ByteFlow is some source of compressed sound
class ByteFlow {
  public:
    virtual int Read(unsigned int size, unsigned char *pdata) = 0;
};

#endif
