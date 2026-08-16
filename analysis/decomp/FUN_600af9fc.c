// 600af9fc  FUN_600af9fc  size=334 bytes
// --- callers ---
//   600f4920 FUN_600f4920
//   600f6410 FUN_600f6410
//   600ac9a4 FUN_600ac9a4
//   600ae4e0 FUN_600ae4e0
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572
//   6013cf90 thunk_EXT_FUN_0000b5ba


undefined1 FUN_600af9fc(undefined2 *param_1,short param_2,int *param_3)

{
  bool bVar1;
  byte *local_10;
  byte local_b;
  undefined1 local_a;
  
  local_a = 1;
  local_10 = (byte *)*param_3;
  thunk_EXT_FUN_0000b5ba(param_1,0,0x14);
  if (param_2 == 2) {
    *param_1 = 2;
    param_1[2] = (ushort)local_10[1] * 0x100 + (ushort)*local_10;
    *param_3 = *param_3 + 2;
  }
  else if (param_2 == 0x10) {
    bVar1 = true;
    for (local_b = 0; local_b < 0xc; local_b = local_b + 1) {
      if (local_10[local_b] != *(byte *)(DAT_600afb4c + (uint)local_b)) {
        bVar1 = false;
        break;
      }
    }
    if (bVar1) {
      if ((local_10[0xf] == 0) && (local_10[0xe] == 0)) {
        *param_1 = 2;
        param_1[2] = (ushort)local_10[0xd] * 0x100 + (ushort)local_10[0xc];
        local_10 = local_10 + 0xe;
      }
      else {
        *param_1 = 4;
        *(uint *)(param_1 + 2) =
             (uint)local_10[0xc] + (uint)local_10[0xd] * 0x100 + (uint)local_10[0xe] * 0x10000 +
             (uint)local_10[0xf] * 0x1000000;
        local_10 = local_10 + 0x10;
      }
    }
    if (!bVar1) {
      *param_1 = 0x10;
      thunk_EXT_FUN_0000b572(param_1 + 2,local_10,0x10);
    }
    *param_3 = *param_3 + 0x10;
  }
  else if (param_2 != 0) {
    local_a = 0;
  }
  return local_a;
}


