// 600ecbec  FUN_600ecbec  size=34 bytes
// --- callers ---
// --- callees ---
//   600ecb94 FUN_600ecb94


void FUN_600ecbec(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_600ecb94(param_1,param_2 + 0x10,param_3,param_4,param_4);
  if (puVar1 != (undefined4 *)0x0) {
    *(byte *)(puVar1 + 3) = *(byte *)(puVar1 + 3) & 0xfc;
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[2] = 1;
  }
  return;
}


