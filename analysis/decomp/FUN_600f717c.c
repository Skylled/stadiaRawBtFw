// 600f717c  FUN_600f717c  size=252 bytes
// --- callers ---
//   600f74a8 FUN_600f74a8
// --- callees ---
//   600b059c FUN_600b059c
//   600f139a FUN_600f139a
//   600b0548 FUN_600b0548
//   6009ca80 FUN_6009ca80


undefined1 FUN_600f717c(int param_1,undefined4 param_2,char param_3)

{
  char cVar1;
  undefined1 uVar2;
  byte local_d;
  int local_c;
  
  cVar1 = *(char *)(param_1 + 0x2c);
  local_c = FUN_600b0548(param_2);
  if (local_c == 0) {
    local_c = FUN_600b059c(param_2);
  }
  if (local_c != 0) {
    for (local_d = 0; local_d < 10; local_d = local_d + 1) {
      if (param_3 == '\0') {
        if (cVar1 == *(char *)((uint)local_d + local_c + 10)) {
          return 0;
        }
        if (*(char *)((uint)local_d + local_c + 10) == '\0') {
          if (*(char *)(param_1 + 0x2e) == -1) {
            *(undefined1 *)(param_1 + 0x2e) = 0;
          }
          *(char *)(param_1 + 0x2e) = *(char *)(param_1 + 0x2e) + '\x01';
          *(char *)((uint)local_d + local_c + 10) = cVar1;
          if (local_d == 0) {
            uVar2 = FUN_600f139a(1,param_2);
            return uVar2;
          }
          return 1;
        }
      }
      else {
        if (cVar1 == *(char *)(local_c + (uint)local_d)) {
          return 0;
        }
        if (*(char *)(local_c + (uint)local_d) == '\0') {
          *(char *)(local_c + (uint)local_d) = cVar1;
          if (local_d == 0) {
            uVar2 = FUN_6009ca80(1,param_2);
            return uVar2;
          }
          return 1;
        }
      }
    }
  }
  return 0;
}


