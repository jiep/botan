/*
* RIPEMD-160
* (C) 1999-2007 Jack Lloyd
*
* Distributed under the terms of the Botan license
*/

#ifndef BOTAN_RIPEMD_160_H__
#define BOTAN_RIPEMD_160_H__

#include <botan/mdx_hash.h>

namespace Botan {

/**
* RIPEMD-160
*/
class BOTAN_DLL RIPEMD_160 : public MDx_HashFunction
   {
   public:
      void clear();
      std::string name() const { return "RIPEMD-160"; }
      HashFunction* clone() const { return new RIPEMD_160; }

      RIPEMD_160() : MDx_HashFunction(20, 64, false, true), M(16), digest(5)
         { clear(); }
   private:
      void compress_n(const byte[], size_t blocks);
      void copy_out(byte[]);

      SecureVector<u32bit> M, digest;
   };

}

#endif
