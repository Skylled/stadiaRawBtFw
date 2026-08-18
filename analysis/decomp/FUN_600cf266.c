// 600cf266  FUN_600cf266  size=44 bytes
// --- callers ---
//   6006ea44 FUN_6006ea44
//   600ce744 FUN_600ce744
// --- callees ---
//   60053864 FUN_60053864


undefined4
FUN_600cf266(undefined4 param_1,undefined4 *param_2,undefined4 *param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if (*(char *)(param_2 + 0xb) == '\x01') {
    uVar1 = 0x514;
  }
  else {
    *param_2 = *param_3;
    uVar1 = param_3[1];
    param_2[1] = uVar1;
    param_2[2] = uVar1;
    *(undefined1 *)(param_2 + 0xb) = 1;
    FUN_60053864(param_1,0x800000,param_3,1,param_4);
    uVar1 = 0;
  }
  return uVar1;
}


