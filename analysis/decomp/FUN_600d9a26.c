// 600d9a26  FUN_600d9a26  size=48 bytes
// --- callers ---
// --- callees ---


uint FUN_600d9a26(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 uVar4;
  undefined4 *puVar3;
  
  puVar2 = (undefined4 *)(param_1 + 4);
  uVar4 = param_4;
  do {
    puVar3 = puVar2 + 1;
    uVar1 = (**(code **)(*(int *)*puVar2 + 4))((int *)*puVar2,param_2,param_3,param_4,uVar4);
    if ((uVar1 & 0xff) != 0) {
      return uVar1;
    }
    puVar2 = puVar3;
  } while ((undefined4 *)(param_1 + 0x14) != puVar3);
  return 0;
}


