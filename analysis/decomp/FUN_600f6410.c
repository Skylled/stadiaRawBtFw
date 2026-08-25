// 600f6410  FUN_600f6410  size=262 bytes
// --- callers ---
//   600ae4e0 FUN_600ae4e0
//   600ae670 FUN_600ae670
//   600ae90c FUN_600ae90c
// --- callees ---
//   600af9fc FUN_600af9fc


undefined1
FUN_600f6410(char param_1,ushort *param_2,undefined4 *param_3,short *param_4,ushort *param_5,
            ushort *param_6)

{
  int iVar1;
  byte *local_18;
  ushort local_12;
  ushort local_10;
  ushort local_e;
  ushort local_c;
  undefined1 local_9;
  
  local_9 = 0;
  local_c = 0;
  local_e = 0;
  local_10 = *param_2;
  local_18 = (byte *)*param_3;
  if (3 < local_10) {
    local_c = (ushort)local_18[1] * 0x100 + (ushort)*local_18;
    local_e = (ushort)local_18[3] * 0x100 + (ushort)local_18[2];
    local_18 = local_18 + 4;
    local_10 = local_10 - 4;
    if (((local_e < local_c) || (local_c == 0)) || (local_e == 0)) {
      local_9 = 1;
    }
    else if (((param_1 == '\x10') || (param_1 == '\x06')) || (param_1 == '\b')) {
      if ((local_10 < 2) || (param_4 == (short *)0x0)) {
        local_9 = 4;
      }
      else {
        local_12 = local_10;
        if (param_1 == '\x06') {
          local_12 = 2;
        }
        iVar1 = FUN_600af9fc(param_4,local_12,&local_18);
        if ((iVar1 == 0) || (*param_4 == 0)) {
          local_9 = 4;
        }
        else {
          local_10 = local_10 - *param_4;
        }
      }
    }
  }
  *param_3 = local_18;
  *param_2 = local_10;
  *param_5 = local_c;
  *param_6 = local_e;
  return local_9;
}


