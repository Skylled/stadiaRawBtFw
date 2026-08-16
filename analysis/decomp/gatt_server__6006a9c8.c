// 6006a9c8  gatt_server__6006a9c8  size=300 bytes
// src: gatt_server.cc
// --- callers ---
//   600695dc adapter__600695dc
// --- callees ---
//   600d8bea FUN_600d8bea
//   6006a634 gatt_server__6006a634
//   600d3b3a FUN_600d3b3a
//   600d37ac FUN_600d37ac
//   600d8ac6 FUN_600d8ac6
//   600d37b8 FUN_600d37b8
//   600d3b24 FUN_600d3b24
//   6006a448 FUN_6006a448
//   60051120 FUN_60051120
//   600d8b6c FUN_600d8b6c
//   601016f0 FUN_601016f0


/* src: gatt_server.cc */

void gatt_server__6006a9c8
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined1 auStack_bc [152];
  
  iVar3 = FUN_600d8b6c(param_1,param_3);
  uVar2 = DAT_6006ab10;
  uVar1 = DAT_6006ab0c;
  if (iVar3 == 0) {
    local_c4 = DAT_6006aaf4;
    local_c0 = 0x57;
    FUN_600d3b3a(auStack_bc);
    FUN_600d37ac(auStack_bc,DAT_6006aaf8);
    FUN_600d8ac6(auStack_bc,param_3);
    FUN_600d37ac(auStack_bc,DAT_6006aafc);
    FUN_600d8bea(auStack_bc,param_2);
    FUN_600d37b8(&local_c4);
  }
  else {
    piVar6 = (int *)(iVar3 + 0x18);
    for (uVar7 = 0; uVar7 < *(uint *)(iVar3 + 0x118); uVar7 = uVar7 + 1) {
      iVar5 = *piVar6;
      iVar4 = FUN_6006a448(*(int *)(iVar5 + 4) + 4,param_2);
      if (iVar4 != 0) {
        if (*(short *)(iVar5 + 8) == 0) {
          uVar7 = gatt_server__6006a634(param_1,iVar5,param_4);
          if ((uVar7 & 0xff) == 0) {
            return;
          }
          FUN_60051120(&local_c4,DAT_6006aaf4,0x66,uVar7);
          FUN_600d37ac(auStack_bc,DAT_6006ab00);
          FUN_600d37b8(&local_c4);
          return;
        }
        local_c4 = DAT_6006aaf4;
        local_c0 = 0x61;
        FUN_600d3b3a(auStack_bc);
        FUN_600d37ac(auStack_bc,uVar1);
        FUN_600d8bea(auStack_bc,param_2);
        FUN_600d37ac(auStack_bc,uVar2);
        FUN_600d8ac6(auStack_bc,*(undefined2 *)(*piVar6 + 8));
        FUN_600d3b24(&local_c4);
      }
      piVar6 = piVar6 + 1;
    }
    local_c4 = DAT_6006aaf4;
    local_c0 = 0x71;
    FUN_600d3b3a(auStack_bc);
    FUN_600d37ac(auStack_bc,DAT_6006ab04);
    FUN_600d8bea(auStack_bc,param_2);
    FUN_600d37ac(auStack_bc,DAT_6006ab08);
    FUN_600d8bea(auStack_bc,iVar3);
    FUN_601016f0(0x1e,local_c4,local_c0,auStack_bc);
  }
  return;
}


