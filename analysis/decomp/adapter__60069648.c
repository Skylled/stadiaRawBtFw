// 60069648  adapter__60069648  size=122 bytes
// src: adapter.cc
// --- callers ---
// --- callees ---
//   600d8994 FUN_600d8994
//   6010165c FUN_6010165c
//   6006ab14 gatt_server__6006ab14


/* src: adapter.cc */

void adapter__60069648(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 local_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 local_24;
  
  iVar1 = FUN_600d8994(param_1 + 0x110);
  if (iVar1 == 0) {
    FUN_6010165c(0x28,PTR_s_adapter_cc_600696c8,0x355,
                 PTR_s_Cannot_execute__s_without_being_i_600696cc,
                 PTR_s_CharacteristicDescriptorAdded_600696c4);
  }
  else {
    local_34 = *(undefined4 *)(param_1 + 0x1e58);
    uStack_30 = *(undefined4 *)(param_1 + 0x1e5c);
    uStack_2c = *(undefined4 *)(param_1 + 0x1e60);
    uStack_28 = *(undefined4 *)(param_1 + 0x1e64);
    local_24 = *(undefined4 *)(param_1 + 0x1e68);
    iVar1 = *(int *)(param_1 + 0x1ab4);
    iVar2 = *(int *)(param_1 + 0x1ab8) * 0x1994 + iVar1;
    for (; iVar2 != iVar1; iVar1 = iVar1 + 0x1994) {
      gatt_server__6006ab14
                (iVar1 + 0x1c,&local_34,param_2,param_3,*(undefined2 *)(param_1 + 0x1f30),param_4);
    }
  }
  return;
}


