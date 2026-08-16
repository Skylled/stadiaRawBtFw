// 6005ad74  application_state__6005ad74  size=250 bytes
// src: application_state.cc
// --- callers ---
//   6005b8dc application_state__6005b8dc
// --- callees ---
//   6010165c FUN_6010165c
//   600d543c FUN_600d543c
//   60058bdc FUN_60058bdc
//   600d3df4 FUN_600d3df4


/* src: application_state.cc */

undefined4 application_state__6005ad74(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 local_4c;
  undefined4 uStack_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 uStack_30;
  undefined4 local_2c;
  undefined4 local_28;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  undefined4 local_14;
  
  iVar1 = DAT_6005ae64;
  if (param_2 == 1) {
    FUN_60058bdc(DAT_6005ae64);
    local_28 = 2;
    local_24 = iVar1;
    local_20 = 0x24;
    *(undefined4 *)(iVar1 + 8) = 0;
    FUN_600d3df4(2,iVar1,0x24);
    FUN_600d3df4(4,0,0);
    puVar3 = &local_4c;
    local_44 = 0;
    local_4c = 0;
    uStack_48 = 0;
  }
  else {
    if (param_2 != 2) {
      if (param_2 != 0) {
        FUN_6010165c(0x28,DAT_6005ae5c,0x31d,DAT_6005ae58);
      }
      FUN_600d3df4();
      FUN_600d3df4(1,0,0);
      FUN_600d543c(DAT_60058c2c,&stack0xfffffff0);
      return 0;
    }
    FUN_60058bdc(DAT_6005ae64);
    *(undefined4 *)(iVar1 + 8) = 1;
    local_1c = 2;
    local_14 = 0x24;
    local_18 = iVar1;
    FUN_600d3df4(2,iVar1,0x24);
    local_38 = 0;
    uStack_3c = 0;
    local_40 = 4;
    FUN_600d3df4(4,0,0);
    puVar3 = &local_34;
    local_2c = 0;
    local_34 = 0;
    uStack_30 = 0;
  }
  uVar2 = FUN_600d3df4(*puVar3,puVar3[1],puVar3[2]);
  return uVar2;
}


