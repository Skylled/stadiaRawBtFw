// 600bda54  FUN_600bda54  size=86 bytes
// --- callers ---
//   600f6c4c FUN_600f6c4c
// --- callees ---
//   6006dbac FUN_6006dbac


undefined1 FUN_600bda54(undefined4 param_1,undefined2 param_2,ushort param_3,undefined2 *param_4)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined2 *local_2c;
  undefined1 *local_10;
  ushort local_a;
  
  puVar2 = (undefined1 *)FUN_6006dbac(0x200,DAT_600bdb10,0x269);
  if (puVar2 == (undefined1 *)0x0) {
    uVar1 = 0;
  }
  else {
    local_2c = param_4;
    local_10 = puVar2;
    for (local_a = 0; local_a < param_3; local_a = local_a + 1) {
      *local_10 = 0x19;
      puVar3 = local_10 + 2;
      local_10[1] = (char)((ushort)*local_2c >> 8);
      local_10 = local_10 + 3;
      *puVar3 = (char)*local_2c;
      if (0xfd < (int)local_10 - (int)puVar2) break;
      local_2c = local_2c + 1;
    }
    uVar1 = FUN_600bd848(param_1,param_2,6,(int)local_10 - (int)puVar2,puVar2);
    FUN_6006ddd8(puVar2,DAT_600bdb10,0x27e);
  }
  return uVar1;
}


