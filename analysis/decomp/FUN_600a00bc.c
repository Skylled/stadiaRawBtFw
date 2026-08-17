// 600a00bc  FUN_600a00bc  size=140 bytes
// --- callers ---
//   600a014c FUN_600a014c
// --- callees ---
//   600a2338 FUN_600a2338


void FUN_600a00bc(void)

{
  undefined1 local_d;
  code *local_c;
  
  local_d = 0xc;
  FUN_600a2338();
  if (*(int *)(DAT_600a0148 + 0x738) != 0) {
    local_c = *(code **)(DAT_600a0148 + 0x738);
    *(undefined4 *)(DAT_600a0148 + 0x738) = 0;
    if (local_c != (code *)0x0) {
      (*local_c)(0);
    }
  }
  if (*(int *)(DAT_600a0148 + 0x754) != 0) {
    local_c = *(code **)(DAT_600a0148 + 0x754);
    *(undefined4 *)(DAT_600a0148 + 0x754) = 0;
    if (local_c != (code *)0x0) {
      (*local_c)(&local_d);
    }
  }
  if (*(int *)(DAT_600a0148 + 0x770) != 0) {
    local_c = *(code **)(DAT_600a0148 + 0x770);
    *(undefined4 *)(DAT_600a0148 + 0x770) = 0;
    if (local_c != (code *)0x0) {
      (*local_c)(&local_d);
    }
  }
  return;
}


