/*
 * Copyright (c) 2018, 2022, Red Hat, Inc. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 only, as
 * published by the Free Software Foundation.
 *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * You should have received a copy of the GNU General Public License version
 * 2 along with this work; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * Please contact Oracle, 500 Oracle Parkway, Redwood Shores, CA 94065 USA
 * or visit www.oracle.com if you need additional information or have any
 * questions.
 *
 */

#ifndef SHARE_GC_SHENANDOAH_SHENANDOAHRUNTIME_HPP
#define SHARE_GC_SHENANDOAH_SHENANDOAHRUNTIME_HPP

#include "memory/allStatic.hpp"
#include "oops/oopsHierarchy.hpp"

class JavaThread;
class oopDesc;

class ShenandoahRuntime : public AllStatic {
public:
  static void arraycopy_barrier_oop(oop* src, oop* dst, size_t length);
  static void arraycopy_barrier_narrow_oop(narrowOop* src, narrowOop* dst, size_t length);

  static void write_ref_field_pre(oopDesc* orig, JavaThread* thread);
  static void write_barrier_pre(oopDesc* orig);

  static oopDesc* load_reference_barrier_strong(oopDesc* src, oop* load_addr);
  static oopDesc* load_reference_barrier_strong_narrow(oopDesc* src, narrowOop* load_addr);

  static oopDesc* load_reference_barrier_weak(oopDesc* src, oop* load_addr);
  static oopDesc* load_reference_barrier_weak_narrow(oopDesc* src, narrowOop* load_addr);

  static oopDesc* load_reference_barrier_phantom(oopDesc* src, oop* load_addr);
  static oopDesc* load_reference_barrier_phantom_narrow(oopDesc* src, narrowOop* load_addr);

  static void clone_barrier(oopDesc* src);
};

#endif // SHARE_GC_SHENANDOAH_SHENANDOAHRUNTIME_HPP
