/*
   eXokernel Development Kit (XDK)

   Based on code by Samsung Research America Copyright (C) 2013
 
   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.

   As a special exception, if you link the code in this file with
   files compiled with a GNU compiler to produce an executable,
   that does not cause the resulting executable to be covered by
   the GNU Lesser General Public License.  This exception does not
   however invalidate any other reasons why the executable file
   might be covered by the GNU Lesser General Public License.
   This exception applies to code released by its copyright holders
   in files containing the exception.  
*/




#include <exo/component.h>
#include "hello_itf.h"
#include <string.h>

/** 
 * Interface IHello implementation
 * 
 */
class IHello_impl : public IHello
{
public:
  void sayHello(unsigned x) {
    for(unsigned i=0;i<x;i++) {
      printf("Hello (%u)\n",i); 
    }
  }
};


/** 
 * Definition of the component
 * 
 */
class MyComponent : public Exokernel::Component_base,
                    public IHello_impl
{
public:  
  DECLARE_COMPONENT_UUID(0xae591c36,0x7988,0x11e3,0x9f1c,0xbc30,0x5bdc,0x754d);

  void * query_interface(Exokernel::uuid_t& itf_uuid) {
    if(itf_uuid == IHello::uuid()) {
      add_ref(); // implicitly add reference
      return (void *) static_cast<IHello *>(this);
    }
    else 
      return NULL; // we don't support this interface
  }
};


extern "C" void * factory_createInstance()
{
  return static_cast<void*>(new MyComponent());
}

