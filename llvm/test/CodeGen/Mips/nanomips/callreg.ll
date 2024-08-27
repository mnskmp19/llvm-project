; RUN: llc -mtriple=nanomips -asm-show-inst -verify-machineinstrs < %s | FileCheck %s

; Call a function jump and link with register.
define void @call_register(void (i32)* %f) {
; CHECK: jalrc $ra, $a1
; CHECK: JALRC_NM
  call void %f(i32 1)
; CHECK: jrc $ra
; CHECK: JRC_NM
  ret void
}
