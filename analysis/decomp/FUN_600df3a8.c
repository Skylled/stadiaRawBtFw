// 600df3a8  FUN_600df3a8  size=48 bytes
// --- callers ---
// --- callees ---


undefined4 FUN_600df3a8(int param_1,undefined4 param_2,uint param_3)

{
  undefined4 uVar1;
  undefined4 local_10;
  uint uStack_c;
  
  if ((*(char *)(*(int *)(param_1 + 4) + 0x1e) == '\0') &&
     (param_3 < *(ushort *)(*(int *)(param_1 + 4) + 0x1c))) {
    uVar1 = 3;
  }
  else {
    local_10 = param_2;
    uStack_c = param_3;
    uVar1 = (**(code **)(param_1 + 0x34))(*(undefined4 *)(param_1 + 0x38),&local_10);
  }
  return uVar1;
}


