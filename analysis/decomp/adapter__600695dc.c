// 600695dc  adapter__600695dc  size=96 bytes
// src: adapter.cc
// --- callers ---
// --- callees ---
//   600d8994 FUN_600d8994
//   6006a9c8 gatt_server__6006a9c8
//   6010165c FUN_6010165c


/* src: adapter.cc */

void adapter__600695dc(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  iVar3 = param_1;
  uVar4 = param_2;
  uVar5 = param_3;
  iVar1 = FUN_600d8994(param_1 + 0x110);
  if (iVar1 == 0) {
    FUN_6010165c(0x28,PTR_s_adapter_cc_60069640,0x346,
                 PTR_s_Cannot_execute__s_without_being_i_60069644,PTR_s_CharacteristicAdded_6006963c
                );
  }
  else {
    *(short *)(param_1 + 0x1f30) = (short)param_4;
    iVar1 = *(int *)(param_1 + 0x1ab4);
    iVar2 = *(int *)(param_1 + 0x1ab8) * 0x1994 + iVar1;
    for (; iVar2 != iVar1; iVar1 = iVar1 + 0x1994) {
      gatt_server__6006a9c8(iVar1 + 0x1c,param_2,param_3,param_4,iVar3,uVar4,uVar5);
    }
  }
  return;
}


