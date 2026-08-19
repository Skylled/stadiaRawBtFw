// 600d8ae8  FUN_600d8ae8  size=82 bytes
// --- callers ---
//   6006a944 gatt_server__6006a944
// --- callees ---
//   600d8a7a FUN_600d8a7a
//   6006a448 FUN_6006a448


undefined4 FUN_600d8ae8(int param_1,undefined4 param_2,undefined2 *param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar3 = *(int *)(param_1 + 0x1714);
  iVar5 = param_1 + 0x230;
  iVar4 = 0;
  while( true ) {
    if (iVar3 == iVar4) {
      if (7 < iVar3 + 1U) {
        return 8;
      }
      uVar2 = FUN_600d8a7a(param_1,param_2,param_3,param_4);
      return uVar2;
    }
    iVar1 = FUN_6006a448(param_2,iVar5);
    iVar5 = iVar5 + 0x11c;
    if (iVar1 != 0) break;
    iVar4 = iVar4 + 1;
  }
  *param_3 = (short)iVar4;
  return 0;
}


