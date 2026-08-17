// 6009ac8c  FUN_6009ac8c  size=112 bytes
// --- callers ---
//   600f800a FUN_600f800a
//   600fd442 FUN_600fd442
// --- callees ---
//   600b1898 FUN_600b1898
//   60098ec8 FUN_60098ec8


undefined4 FUN_6009ac8c(undefined4 param_1,ushort param_2)

{
  undefined2 *puVar1;
  undefined4 uVar2;
  undefined2 local_16;
  
  puVar1 = (undefined2 *)FUN_60098ec8(param_1,2);
  if (((*(byte *)(DAT_6009acfc + 0x831) & 0x20) == 0) ||
     ((*(byte *)((int)puVar1 + 0x13d) & 0x20) == 0)) {
    uVar2 = 6;
  }
  else if (puVar1 == (undefined2 *)0x0) {
    uVar2 = 6;
  }
  else {
    if (param_2 < 0xfc) {
      local_16 = param_2;
      if (param_2 < 0x1b) {
        local_16 = 0x1b;
      }
    }
    else {
      local_16 = 0xfb;
    }
    FUN_600b1898(*puVar1,local_16,0x848);
    uVar2 = 0;
  }
  return uVar2;
}


