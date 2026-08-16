// 600c3450  FUN_600c3450  size=198 bytes
// --- callers ---
// --- callees ---
//   600962dc FUN_600962dc
//   6006dbac FUN_6006dbac
//   600a223c FUN_600a223c


void FUN_600c3450(int param_1)

{
  undefined4 uVar1;
  undefined1 local_120 [276];
  undefined2 *local_c;
  
  local_120[0] = *(undefined1 *)(param_1 + 8);
  (*(code *)*DAT_600c3518)(1,local_120);
  if (*(char *)(param_1 + 8) != '\0') {
    uVar1 = FUN_600a223c();
    DAT_600c3518[1] = uVar1;
    if (DAT_600c3518[1] != 0) {
      DAT_600c3518[2] = 0;
      local_c = (undefined2 *)FUN_6006dbac(0x140,DAT_600c351c,0x633);
      if (local_c == (undefined2 *)0x0) {
        return;
      }
      *local_c = 0x206;
      local_c[3] = 0x202;
      FUN_600962dc(local_c);
      return;
    }
  }
  DAT_600c3518[2] = 0;
  local_c = (undefined2 *)FUN_6006dbac(0x140,DAT_600c351c,0x63f);
  if (local_c != (undefined2 *)0x0) {
    *local_c = 0x206;
    local_c[3] = 0x202;
    FUN_600962dc(local_c);
  }
  return;
}


