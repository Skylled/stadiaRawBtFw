// 6009b77c  FUN_6009b77c  size=306 bytes
// --- callers ---
//   600ac014 FUN_600ac014
// --- callees ---
//   6009ff18 FUN_6009ff18
//   6006dbac FUN_6006dbac
//   600f0a52 FUN_600f0a52
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600c09f0 FUN_600c09f0
//   6006ddd8 FUN_6006ddd8


char FUN_6009b77c(undefined4 param_1,int param_2,ushort param_3,undefined1 *param_4)

{
  int iVar1;
  undefined1 *puVar2;
  undefined1 *local_10;
  char local_9;
  
  local_9 = '\0';
  iVar1 = FUN_6009ff18(param_1);
  if (iVar1 != 0) {
    puVar2 = (undefined1 *)FUN_6006dbac(param_3 + 4,DAT_6009b8b0,0x8a2);
    if (puVar2 != (undefined1 *)0x0) {
      local_10 = puVar2;
      if (param_2 != 0) {
        thunk_EXT_FUN_0000b572(puVar2,param_2,param_3);
        local_10 = puVar2 + param_3;
      }
      *local_10 = (char)*(undefined4 *)(iVar1 + 0xe0);
      local_10[1] = (char)((uint)*(undefined4 *)(iVar1 + 0xe0) >> 8);
      local_10[2] = (char)((uint)*(undefined4 *)(iVar1 + 0xe0) >> 0x10);
      local_10[3] = (char)((uint)*(undefined4 *)(iVar1 + 0xe0) >> 0x18);
      *param_4 = (char)*(undefined4 *)(iVar1 + 0xe0);
      param_4[1] = (char)((uint)*(undefined4 *)(iVar1 + 0xe0) >> 8);
      param_4[2] = (char)((uint)*(undefined4 *)(iVar1 + 0xe0) >> 0x10);
      param_4[3] = (char)((uint)*(undefined4 *)(iVar1 + 0xe0) >> 0x18);
      local_9 = FUN_600c09f0(iVar1 + 0xbc,puVar2,param_3 + 4,8,param_4 + 4);
      if (local_9 == '\x01') {
        FUN_600f0a52(param_1,1);
      }
      FUN_6006ddd8(puVar2,DAT_6009b8b0,0x8f5);
    }
  }
  return local_9;
}


