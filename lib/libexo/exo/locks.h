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

/*
  Authors:
  Copyright (C) 2013, Daniel G. Waddington <d.waddington@samsung.com>
*/

#ifndef __EXO_LOCKS_H__
#define __EXO_LOCKS_H__

#include <pthread.h>

/* Wrappers for various non-spin lock types */

namespace Exokernel
{
  class RW_lock {
  private:
    pthread_rwlock_t _lock;
  public:
    RW_lock() {
      pthread_rwlock_init(&_lock,NULL);
    }
    ~RW_lock() {
      pthread_rwlock_destroy(&_lock);
    }

    inline int rdlock() {
      return pthread_rwlock_rdlock(&_lock);
    }

    inline int wrlock() {
      return pthread_rwlock_wrlock(&_lock);
    }

    inline int try_rdlock() {
      return pthread_rwlock_tryrdlock(&_lock);
    }

    inline int try_wrlock() {
      return pthread_rwlock_trywrlock(&_lock);
    }
    
    inline void unlock() {
      pthread_rwlock_unlock(&_lock);
    }
  };
}

#endif // __EXO_LOCKS_H__