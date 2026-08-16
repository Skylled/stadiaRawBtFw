// 60099fdc  FUN_60099fdc  size=298 bytes
// --- callers ---
//   600fa064 FUN_600fa064
// --- callees ---
//   6013d168 thunk_EXT_FUN_0000b554
//   60098ec8 FUN_60098ec8


ushort FUN_60099fdc(undefined4 param_1)

{
  int iVar1;
  undefined2 local_c;
  undefined2 local_a;
  
  iVar1 = FUN_60098ec8(param_1,1);
  local_a = 0;
  local_c = 0;
  if (iVar1 == 0) {
    iVar1 = thunk_EXT_FUN_0000b554(DAT_6009a108,param_1,6);
    if (iVar1 == 0) {
      local_a = *(ushort *)(DAT_6009a10c + 0xaf0);
    }
  }
  else {
    local_a = *(ushort *)(iVar1 + 2);
  }
  if (local_a != 0) {
    if ((local_a & 0x2000) == 0) {
      local_c = 0x3fd;
    }
    else if ((local_a & 0x1000) == 0) {
      local_c = 0x2a7;
    }
    else if ((local_a & 0x200) == 0) {
      local_c = 0x228;
    }
    else if ((short)local_a < 0) {
      local_c = 0x153;
    }
    else if ((local_a & 0x100) == 0) {
      local_c = 0x16f;
    }
    else if ((local_a & 0x4000) == 0) {
      if ((local_a & 0x800) == 0) {
        if ((local_a & 0x400) == 0) {
          if ((local_a & 4) == 0) {
            local_c = 0x53;
          }
          else if ((local_a & 2) == 0) {
            local_c = 0x36;
          }
          else if ((local_a & 0x10) == 0) {
            if ((local_a & 8) != 0) {
              local_c = 0x11;
            }
          }
          else {
            local_c = 0x1b;
          }
        }
        else {
          local_c = 0x79;
        }
      }
      else {
        local_c = 0xb7;
      }
    }
    else {
      local_c = 0xe0;
    }
  }
  if (*(ushort *)(DAT_6009a110 + 0x58) < local_c) {
    local_c = *(ushort *)(DAT_6009a110 + 0x58);
  }
  return local_c;
}


