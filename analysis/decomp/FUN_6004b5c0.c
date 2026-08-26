// 6004b5c0  FUN_6004b5c0  size=110 bytes
// --- callers ---
//   6004b62e FUN_6004b62e
// --- callees ---
//   6004b4aa FUN_6004b4aa


void FUN_6004b5c0(undefined4 *param_1,uint *param_2,uint param_3,uint param_4,uint param_5,
                 uint param_6)

{
  ulonglong uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  
  uVar1 = FUN_6004b4aa(param_3,param_5);
  uVar2 = FUN_6004b4aa(param_4,param_6);
  uVar3 = FUN_6004b4aa(param_3 ^ param_4,param_5 ^ param_6);
  uVar3 = uVar3 ^ uVar1 ^ uVar2;
  *param_1 = (int)uVar1;
  param_1[1] = (uint)(uVar1 >> 0x20) ^ (uint)uVar3;
  *param_2 = (uint)uVar2 ^ (uint)(uVar3 >> 0x20);
  param_2[1] = (uint)(uVar2 >> 0x20);
  return;
}


