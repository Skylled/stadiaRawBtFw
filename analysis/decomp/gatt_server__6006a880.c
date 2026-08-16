// 6006a880  gatt_server__6006a880  size=182 bytes
// src: gatt_server.cc
// --- callers ---
//   600d89a6 FUN_600d89a6
// --- callees ---
//   600d8bea FUN_600d8bea
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600d3b3a FUN_600d3b3a
//   600d37ac FUN_600d37ac
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600d3b24 FUN_600d3b24
//   600957ec FUN_600957ec


/* src: gatt_server.cc */

void gatt_server__6006a880(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 local_144;
  undefined4 local_140;
  undefined4 uStack_13c;
  undefined4 uStack_138;
  undefined4 local_134;
  undefined4 local_130;
  undefined1 auStack_12c [256];
  undefined4 local_2c;
  
  uVar2 = DAT_6006a93c;
  uVar1 = DAT_6006a938;
  iVar4 = param_1 + 0x248;
  for (uVar5 = 0; uVar5 < *(uint *)(param_1 + 0x1714); uVar5 = uVar5 + 1) {
    iVar6 = iVar4 + -0x18;
    local_144 = uVar1;
    local_140 = 0x44;
    FUN_600d3b3a(&uStack_13c);
    FUN_600d37ac(&uStack_13c,uVar2);
    FUN_600d8bea(&uStack_13c,iVar6);
    FUN_600d3b24(&local_144);
    FUN_600957ec(*(undefined2 *)(*(int *)(iVar4 + -4) + 8));
    for (uVar3 = 0; uVar3 < *(uint *)(iVar4 + 0x100); uVar3 = uVar3 + 1) {
      *(undefined2 *)(*(int *)(iVar4 + uVar3 * 4) + 8) = 0;
    }
    iVar4 = iVar4 + 0x11c;
    local_144 = *DAT_6006a940;
    local_140 = DAT_6006a940[1];
    uStack_13c = DAT_6006a940[2];
    uStack_138 = DAT_6006a940[3];
    local_134 = DAT_6006a940[4];
    thunk_EXT_FUN_0000b5ba(auStack_12c,0,0x100);
    local_130 = 0;
    local_2c = 0;
    thunk_EXT_FUN_0000b572(iVar6,&local_144,0x11c);
  }
  *(uint *)(param_1 + 0x1714) = 0;
  *(undefined4 *)(param_1 + 0x228) = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  return;
}


