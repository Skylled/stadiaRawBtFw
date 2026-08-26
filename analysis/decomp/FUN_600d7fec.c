// 600d7fec  FUN_600d7fec  size=34 bytes
// --- callers ---
//   60067ddc logging__60067ddc
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572


uint FUN_600d7fec(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = param_3 - 1U;
  if (*(uint *)(param_1 + 0x6c) <= param_3 - 1U) {
    uVar2 = *(uint *)(param_1 + 0x6c);
  }
  iVar1 = thunk_EXT_FUN_0000b572(param_2,param_1 + 0xc,uVar2);
  *(undefined1 *)(iVar1 + uVar2) = 0;
  return uVar2;
}


