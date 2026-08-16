// 600bdb7c  FUN_600bdb7c  size=162 bytes
// --- callers ---
//   600bd150 FUN_600bd150
//   600f6c4c FUN_600f6c4c
// --- callees ---
//   600bd848 FUN_600bd848
//   6006ddd8 FUN_6006ddd8
//   6006dbac FUN_6006dbac


undefined1 FUN_600bdb7c(undefined4 param_1,ushort param_2,undefined2 *param_3)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined2 *local_24;
  undefined1 *local_10;
  ushort local_a;
  
  puVar2 = (undefined1 *)FUN_6006dbac(0x200,DAT_600bdc20,0x351);
  if (puVar2 == (undefined1 *)0x0) {
    uVar1 = 0;
  }
  else {
    local_24 = param_3;
    local_10 = puVar2;
    for (local_a = 0; local_a < param_2; local_a = local_a + 1) {
      *local_10 = 0x19;
      puVar3 = local_10 + 2;
      local_10[1] = (char)((ushort)*local_24 >> 8);
      local_10 = local_10 + 3;
      *puVar3 = (char)*local_24;
      local_24 = local_24 + 1;
    }
    uVar1 = FUN_600bd848(param_1,1,6,(int)local_10 - (int)puVar2,puVar2);
    FUN_6006ddd8(puVar2,DAT_600bdc20,0x35f);
  }
  return uVar1;
}


